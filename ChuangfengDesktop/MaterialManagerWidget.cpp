#include "MaterialManagerWidget.h"

#include <QKeyEvent>
#include <QMouseEvent>
#include <QRect>
#include <QPoint>
#include <QGridLayout>
#include <QPainter>
#include <QPen>
#include <QtMath>
#include "iconhelper.h"
#include "commomdef.h"
#include "AddMaterialWidget.h"
#include "DescMaterialWidget.h"
#include "globalVariable.h"
#include "SingletonHttpRequest.h"
#include "MsgPopWidget.h"

MaterialManagerWidget::MaterialManagerWidget(QWidget *parent)
	:MoveableFramelessWindow(parent)
, ui(new Ui::Material)

{
	ui->setupUi(this);
	connect(ui->material_cose_btn, &QPushButton::clicked, this, &QWidget::close);
	connect(ui->material_max_restore_btn, &QPushButton::clicked, this, &MaterialManagerWidget::updateMaximize);
	connect(ui->material_min_btn, &QPushButton::clicked, this, &QWidget::showMinimized);
	ui->material_max_restore_btn->setToolTip(QString::fromLocal8Bit("最大化"));
	//设置按钮的属性名为"maximizeProperty"
	ui->material_max_restore_btn->setProperty("maximizeProperty", "maximize");
	ui->material_max_restore_btn->setStyle(QApplication::style());
	initOption();
	initTableView();
	connect(ui->material_income_btn, &QPushButton::clicked, this, [this]()->void {
		AddMaterialWidget*pQtWidget = new AddMaterialWidget();
		connect(pQtWidget, SIGNAL(sig_commit(QString&, QString&, QString&, QString&, QString&, QString&, QString&, QString&, QString&)), this, SLOT(SlotAddMaterialDetail(QString&, QString&, QString&, QString&, QString&, QString&, QString&, QString&, QString&)));
		pQtWidget->setAttribute(Qt::WA_DeleteOnClose);
		pQtWidget->setWindowModality(Qt::ApplicationModal);
		pQtWidget->show();
	});
	connect(ui->material_out_btn, &QPushButton::clicked, this, [this]()->void {
		DescMaterialWidget*pQtWidget = new DescMaterialWidget();
		/*connect(pQtWidget, SIGNAL(sig_commit(QString&, QString&, QString&, QString&, QString&, QString&, QString&)), this, SLOT(SlotAddNopayDetail(QString&, QString&, QString&, QString&, QString&, QString&, QString&)));*/
		pQtWidget->setAttribute(Qt::WA_DeleteOnClose);
		pQtWidget->setWindowModality(Qt::ApplicationModal);
		pQtWidget->show();
	});
	ui->comboBox->addItem(QString::fromLocal8Bit("入库"));
	ui->comboBox->addItem(QString::fromLocal8Bit("出库"));
	ui->comboBox->setCurrentIndex(0);
	connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(comboBoxValueChanged()));
	ChangeDetailTableView();
	for (auto&kvp:g_areaList)
	{
		ui->area_comboBox->addItem(kvp.second.areaName);
	}
	connect(this, SIGNAL(sig_NotifyMsg(QString, int)), this, SLOT(SlotPopMsg(QString, int)));
}


MaterialManagerWidget::~MaterialManagerWidget()
{
}

void MaterialManagerWidget::updateMaximize()
{
	QWidget *pWindow = this->window(); //获得标题栏所在的窗口
	pWindow->isMaximized() ? pWindow->showNormal() : pWindow->showMaximized();  //窗口最大化/还原显示
	if (pWindow->isTopLevel())
	{
		bool bMaximize = pWindow->isMaximized(); //判断窗口是不是最大化状态，是则返回true，否则返回false
		if (bMaximize)
		{
			//目前窗口是最大化状态，则最大化/还原的toolTip设置为"Restore"
			ui->material_max_restore_btn->setToolTip(QString::fromLocal8Bit("还原"));
			//设置按钮的属性名为"maximizeProperty"
			ui->material_max_restore_btn->setProperty("maximizeProperty", "restore");
		}
		else
		{
			//目前窗口是还原状态，则最大化/还原的toolTip设置为"Maximize"
			ui->material_max_restore_btn->setToolTip(QString::fromLocal8Bit("最大化"));
			//设置按钮的属性名为"maximizeProperty"
			ui->material_max_restore_btn->setProperty("maximizeProperty", "maximize");
		}

		ui->material_max_restore_btn->setStyle(QApplication::style());
	}
}

void MaterialManagerWidget::SlotOptionClick()
{
	NavButton *btn = (NavButton *)sender();
	for (int i = 0; i < m_NavButtonList.count(); i++) {
		if (m_NavButtonList.at(i) == btn)
		{
			ui->material_stackedWidget->setCurrentIndex(i);
			m_NavButtonList.at(i)->setChecked(true);
		}
		else {
			m_NavButtonList.at(i)->setChecked(false);
		}
	}
}

void MaterialManagerWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
	Q_UNUSED(event); //没有实质性的作用，只是用来允许event可以不使用，用来避免编译器警告
	emit ui->material_max_restore_btn->clicked();
}

void MaterialManagerWidget::paintEvent(QPaintEvent *event)
{
	QPainterPath path;
	path.setFillRule(Qt::WindingFill);
	path.addRect(0, 0, this->width(), 40);
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing, true);
	painter.fillPath(path, QBrush(QColor(41, 57, 85)));
	{
		QPainterPath path;
		path.setFillRule(Qt::WindingFill);
		path.addRect(0, 40, this->width(), this->height());
		QPainter painter(this);
		painter.setRenderHint(QPainter::Antialiasing, true);
		//painter.fillPath(path, QBrush(QColor(68, 71, 77)));
		painter.fillPath(path, QBrush(QColor(54, 78, 111)));
	}
}

QWidget* MaterialManagerWidget::getDragnWidget()
{
	return ui->child_widget_title;
}

void MaterialManagerWidget::initOption()
{
	m_NavButtonList << ui->material_detail_opt << ui->material_incom_opt << ui->fixacc_opt;
	QList<QChar> pixChar;
	pixChar << 0xf509 << 0xf571 << 0xf2a3;
	QColor normalBgColor = QColor("#364E6F");
	QColor hoverBgColor = QColor("#478CB6");
	QColor checkBgColor = QColor("#478CB6");
	QColor normalTextColor = QColor("#FFFFFF");
	QColor hoverTextColor = QColor("#FFFFFF");
	QColor checkTextColor = QColor("#FFFFFF");

	for (int i = 0; i < m_NavButtonList.count(); i++) {

		m_NavButtonList.at(i)->setLineColor(QColor("#029FEA"));
		///mNavButtonList.at(i)->setShowLine(true);
		m_NavButtonList.at(i)->setTextAlign(NavButton::TextAlign_Left);
		m_NavButtonList.at(i)->setTrianglePosition(NavButton::TrianglePosition_Right);
		//mNavButtonList.at(i)->setLinePosition(NavButton::LinePosition_Top);

		m_NavButtonList.at(i)->setPaddingLeft(5);
		m_NavButtonList.at(i)->setLineSpace(1);
		m_NavButtonList.at(i)->setLineWidth(5);
		m_NavButtonList.at(i)->setLineColor(QColor(255, 107, 107));
		m_NavButtonList.at(i)->setShowTriangle(true);

		m_NavButtonList.at(i)->setShowIcon(true);
		m_NavButtonList.at(i)->setIconSpace(ICOSPACE);
		m_NavButtonList.at(i)->setIconSize(QSize(ICONSIZE, ICONSIZE));

		//分开设置图标
		QChar icon = pixChar.at(i);
		QPixmap iconNormal = IconHelper::Instance()->getPixmap(normalTextColor.name(), icon, ICONFONTSIZE, PIXMAPSIZE, PIXMAPSIZE);
		QPixmap iconHover = IconHelper::Instance()->getPixmap(hoverTextColor.name(), icon, ICONFONTSIZE, PIXMAPSIZE, PIXMAPSIZE);
		QPixmap iconCheck = IconHelper::Instance()->getPixmap(checkTextColor.name(), icon, ICONFONTSIZE, PIXMAPSIZE, PIXMAPSIZE);

		m_NavButtonList.at(i)->setIconNormal(iconNormal);
		m_NavButtonList.at(i)->setIconHover(iconHover);
		m_NavButtonList.at(i)->setIconCheck(iconCheck);

		m_NavButtonList.at(i)->setNormalBgColor(normalBgColor);
		m_NavButtonList.at(i)->setHoverBgColor(hoverBgColor);
		m_NavButtonList.at(i)->setCheckBgColor(checkBgColor);
		m_NavButtonList.at(i)->setNormalTextColor(normalTextColor);
		m_NavButtonList.at(i)->setHoverTextColor(hoverTextColor);
		m_NavButtonList.at(i)->setCheckTextColor(checkTextColor);

		connect(m_NavButtonList.at(i), &QPushButton::clicked, this, &MaterialManagerWidget::SlotOptionClick);
	}
	m_NavButtonList.at(0)->setChecked(true);
}

void MaterialManagerWidget::initTableView()
{
	m_pViewHeadDeleagteDetail = new CCheckBoxHeaderView(0, Qt::Horizontal, ui->material_detail_tableView);
	ui->material_detail_tableView->setHorizontalHeader(m_pViewHeadDeleagteDetail);
	connect(m_pViewHeadDeleagteDetail, SIGNAL(sig_AllChecked(bool)), this, SLOT(slotCheckBoxStateChanged(bool)));
	m_pViewModelDetail = new QStandardItemModel();
	ui->material_detail_tableView->setModel(m_pViewModelDetail);
	m_pViewModelDetail->setColumnCount(9);
	m_pViewModelDetail->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit(""));
	m_pViewModelDetail->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("用途"));
	m_pViewModelDetail->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("类别"));
	m_pViewModelDetail->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("物品名称"));
	m_pViewModelDetail->setHeaderData(4, Qt::Horizontal, QString::fromLocal8Bit("物品规格"));
	m_pViewModelDetail->setHeaderData(5, Qt::Horizontal, QString::fromLocal8Bit("单位"));
	m_pViewModelDetail->setHeaderData(6, Qt::Horizontal, QString::fromLocal8Bit("成本单价"));
	m_pViewModelDetail->setHeaderData(7, Qt::Horizontal, QString::fromLocal8Bit("数量"));
	m_pViewModelDetail->setHeaderData(8, Qt::Horizontal, QString::fromLocal8Bit("总价值"));
	onSetTableAttribute(ui->material_detail_tableView, 9,false);
	ui->material_detail_tableView->setColumnWidth(0, 30);
	ui->material_detail_tableView->setColumnWidth(1, 100);
	ui->material_detail_tableView->setColumnWidth(2, 180);

	m_pViewHeadDeleagteinout = new CCheckBoxHeaderView(0, Qt::Horizontal, ui->material_in_out_detail_tableview);
	ui->material_in_out_detail_tableview->setHorizontalHeader(m_pViewHeadDeleagteinout);
	connect(m_pViewHeadDeleagteinout, SIGNAL(sig_AllChecked(bool)), this, SLOT(slotCheckBoxStateChanged(bool)));
	m_pViewModelinout = new QStandardItemModel();
	ui->material_in_out_detail_tableview->setModel(m_pViewModelinout);
	m_pViewModelinout->setColumnCount(9);
	m_pViewModelinout->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit(""));
	m_pViewModelinout->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("时间"));
	m_pViewModelinout->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("物品名称"));
	m_pViewModelinout->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("数量"));
	m_pViewModelinout->setHeaderData(4, Qt::Horizontal, QString::fromLocal8Bit("单价"));
	m_pViewModelinout->setHeaderData(5, Qt::Horizontal, QString::fromLocal8Bit("运费"));
	m_pViewModelinout->setHeaderData(6, Qt::Horizontal, QString::fromLocal8Bit("剩余数量"));
	m_pViewModelinout->setHeaderData(7, Qt::Horizontal, QString::fromLocal8Bit("剩余总额"));
	m_pViewModelinout->setHeaderData(8, Qt::Horizontal, QString::fromLocal8Bit("出库区域"));

	onSetTableAttribute(ui->material_in_out_detail_tableview, 9, false);
	ui->material_in_out_detail_tableview->setColumnWidth(0, 30);
	ui->material_in_out_detail_tableview->setColumnWidth(1, 100);
	ui->material_in_out_detail_tableview->setColumnWidth(2, 180);



	m_pViewHeadDeleagteFix = new CCheckBoxHeaderView(0, Qt::Horizontal, ui->fix_material_tableView);
	ui->fix_material_tableView->setHorizontalHeader(m_pViewHeadDeleagteFix);
	connect(m_pViewHeadDeleagteFix, SIGNAL(sig_AllChecked(bool)), this, SLOT(slotCheckBoxStateChanged(bool)));
	m_pViewModelFix = new QStandardItemModel();
	ui->fix_material_tableView->setModel(m_pViewModelFix);
	m_pViewModelFix->setColumnCount(10);
	m_pViewModelFix->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit(""));
	m_pViewModelFix->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("设备名称"));
	m_pViewModelFix->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("入库时间"));
	m_pViewModelFix->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("出库时间"));
	m_pViewModelFix->setHeaderData(4, Qt::Horizontal, QString::fromLocal8Bit("单位"));
	m_pViewModelFix->setHeaderData(5, Qt::Horizontal, QString::fromLocal8Bit("单价"));
	m_pViewModelFix->setHeaderData(6, Qt::Horizontal, QString::fromLocal8Bit("总金额"));
	m_pViewModelFix->setHeaderData(7, Qt::Horizontal, QString::fromLocal8Bit("待摊金额"));
	m_pViewModelFix->setHeaderData(8, Qt::Horizontal, QString::fromLocal8Bit("本期分摊金额"));
	m_pViewModelFix->setHeaderData(9, Qt::Horizontal, QString::fromLocal8Bit("分摊期数"));

	
	onSetTableAttribute(ui->fix_material_tableView, 10, false);
	ui->fix_material_tableView->setColumnWidth(0, 30);
	ui->fix_material_tableView->setColumnWidth(1, 100);
	ui->fix_material_tableView->setColumnWidth(2, 180);

}

void MaterialManagerWidget::ChangeDetailTableView()
{
	if (ui->comboBox->currentText() == QString::fromLocal8Bit("入库"))
	{
		ui->material_in_out_detail_tableview->setColumnHidden(5, false);
		ui->material_in_out_detail_tableview->setColumnHidden(6, true);
		ui->material_in_out_detail_tableview->setColumnHidden(7, true);
		ui->material_in_out_detail_tableview->setColumnHidden(8, true);
		
		ui->area_comboBox->setVisible(false);
	}
	else {
		ui->material_in_out_detail_tableview->setColumnHidden(5, true);
		ui->material_in_out_detail_tableview->setColumnHidden(6, false);
		ui->material_in_out_detail_tableview->setColumnHidden(7, false);
		ui->material_in_out_detail_tableview->setColumnHidden(8, false);
		ui->area_comboBox->setVisible(true);
	}
}

void MaterialManagerWidget::AddInMaterial(InMaterialStruct&item)
{
	int nCount = m_pViewModelinout->rowCount();
	m_pViewModelinout->setItem(nCount, 0, new QStandardItem("id"));
	m_pViewModelinout->item(nCount, 0)->setCheckable(true);
	m_pViewModelinout->item(nCount, 0)->setData(QString::number(item.id));
	m_pViewModelinout->setItem(nCount, 1, new QStandardItem(item.time.mid(0, 10)));
	m_pViewModelinout->setItem(nCount, 2, new QStandardItem(item.subject));
	m_pViewModelinout->setItem(nCount, 3, new QStandardItem(QString::number(item.number)));
	m_pViewModelinout->setItem(nCount, 4, new QStandardItem(item.price));
	m_pViewModelinout->setItem(nCount, 5, new QStandardItem(item.fare));
	
	//ChangeDetailTableView();
	ui->material_in_out_detail_tableview->setColumnWidth(0, 30);
}

void MaterialManagerWidget::comboBoxValueChanged()
{
	ChangeDetailTableView();
}

void MaterialManagerWidget::SlotAddMaterialDetail(QString&time, QString&use, QString&subject_name, QString&category, QString&price, QString&unit, QString&specs, QString&fare, QString&number)
{
	ui->comboBox->setCurrentIndex(0);
	 m_addTime = time;
	 m_addUse = use;
	 m_addSubject_name = subject_name;
	 m_addCategory = category;
	 m_addPrice = price;
	 m_addUnit = unit;
	 m_addSpecs =specs;
	 m_addFare = fare;
	 m_addNumber = number;
	 QThread *m_pThread = new QThread;
	 connect(m_pThread, SIGNAL(started()), this, SLOT(SlotThreadAddMaterialDetail()));
	 connect(m_pThread, SIGNAL(finished()), m_pThread, SLOT(deleteLater()));
	 m_pThread->start();
}

void MaterialManagerWidget::SlotThreadAddMaterialDetail()
{

	QString strParam = QString("operat_time=%1&use=%2&subject_name=%3&category=%4&price=%5&unit=%6&specs=%7&number=%8&fare=%9")
		.arg(m_addTime).arg(m_addUse).arg(m_addSubject_name).arg(m_addCategory).arg(m_addPrice).arg(m_addUnit).
		arg(m_addSpecs).arg(m_addNumber).arg(m_addFare);
	QByteArray responseData;
	SingletonHttpRequest::getInstance()->RequestPost("http://127.0.0.1:80/zerg/public/index.php/InsertMaterial"
		, TempToken, strParam, responseData);
	QJsonParseError json_error;
	QJsonDocument parse_doucment = QJsonDocument::fromJson(responseData, &json_error);
	if (json_error.error == QJsonParseError::NoError)
	{
		if (parse_doucment.isArray())
		{
			QJsonArray array = parse_doucment.array();
			for (int i = 0; i < array.size(); i++)
			{
				InMaterialStruct item;
				QJsonValue materialArray = array.at(i);
				QJsonObject materialObject = materialArray.toObject();
				item.id = materialObject["id"].toInt();
				item.time = materialObject["operat_time"].toString();
				item.subject = materialObject["subject_name"].toString();
				item.fare = materialObject["fare"].toString();
				item.number = materialObject["number"].toInt();
				item.price = materialObject["price"].toString();
				AddInMaterial(item);
			}
			emit sig_NotifyMsg(QString::fromLocal8Bit("添加成功！"), 0);
		}
		else
		{
			QJsonObject rootObject = parse_doucment.object();
			if (!rootObject["error_code"].isNull())//
			{
				int errorcode = rootObject["error_code"].toInt();
				QString strMsg = rootObject["msg"].toString();
				emit sig_NotifyMsg(strMsg, errorcode);
			}
		}
	}
	else {
		int errorcode = 404;
		emit sig_NotifyMsg(QString::fromLocal8Bit("网络请求异常！"), errorcode);
	}
}

void MaterialManagerWidget::SlotPopMsg(QString msg, int errorCode)
{
	MsgPopWidget*pQtWidget = new MsgPopWidget(msg, errorCode);
	pQtWidget->setAttribute(Qt::WA_DeleteOnClose);
	pQtWidget->setWindowModality(Qt::ApplicationModal);
	pQtWidget->show();
}

