#include "FeedingManagerWidget.h"
#include <QKeyEvent>
#include <QMouseEvent>
#include <QRect>
#include <QPoint>
#include <QGridLayout>
#include <QPainter>
#include <QPen>
#include <QtMath>
#include "iconhelper.h"

#include "globalVariable.h"
#include "SingletonHttpRequest.h"

#include "AddFeedingWidget.h"

FeedingManagerWidget::FeedingManagerWidget(QWidget *parent )
	:MoveableFramelessWindow(parent)
	, ui(new Ui::FeedingWidget)
{
	ui->setupUi(this);
	connect(ui->feedstore_cose_btn, &QPushButton::clicked, this, &QWidget::close);
	connect(ui->feedstore_max_restore_btn, &QPushButton::clicked, this, &FeedingManagerWidget::updateMaximize);
	connect(ui->feedstore_min_btn, &QPushButton::clicked, this, &QWidget::showMinimized);
	ui->feedstore_max_restore_btn->setToolTip(QString::fromLocal8Bit("最大化"));
	//设置按钮的属性名为"maximizeProperty"
	ui->feedstore_max_restore_btn->setProperty("maximizeProperty", "maximize");
	ui->feedstore_max_restore_btn->setStyle(QApplication::style());
	InitOption();
	initTableView();
	for (auto&kvp:g_areaList)
	{
		ui->area3_combox->addItem(kvp.second.areaName);
	}
	connect(ui->area_feed_search_btn, &QPushButton::clicked, this, &FeedingManagerWidget::SlotSearchAreaFeedStore);
	QDateTime current_date_time = QDateTime::currentDateTime();
	ui->startdateEdit->setCalendarPopup(true);
	ui->startdateEdit->setDateTime(current_date_time);
	ui->enddateEdit->setCalendarPopup(true);
	ui->enddateEdit->setDateTime(current_date_time);

	for (auto&kvp : g_areaList)
	{
		ui->area_combox->addItem(kvp.second.areaName);
	}
	ui->area_combox->setCurrentIndex(0);
	for (auto&kvp : g_areaList)
	{
		if (kvp.second.areaName == ui->area_combox->currentText())
		{
			for (auto&kvpi: kvp.second.areaDetailList)
			{
				ui->area_item_combox->addItem(kvpi.second);
			}	
		}
	}

	connect(ui->area_combox, SIGNAL(currentIndexChanged(int)), this, SLOT(comboBoxValueChanged()));
	connect(ui->feeding_btn, &QPushButton::clicked, this, [this]()->void {
	
		int nCount = 0;
		int m_maxNumber = 0;
		for (int i = 0; i < m_pViewModelTotalArea->rowCount(); ++i)
		{
			if (Qt::Checked == m_pViewModelTotalArea->item(i, 0)->checkState())
			{
				m_id = m_pViewModelTotalArea->item(i, 0)->text().toInt();
				m_subject_name = m_pViewModelTotalArea->item(i, 2)->text();
				m_price = m_pViewModelTotalArea->item(i, 5)->text();
				m_maxNumber = m_pViewModelTotalArea->item(i, 6)->text().toInt();
				m_area = m_pViewModelTotalArea->item(i, 1)->text();
				m_unit = m_pViewModelTotalArea->item(i, 3)->text();
				m_specs = m_pViewModelTotalArea->item(i, 4)->text();
				nCount++;
			}
		}
		if (nCount > 1 || nCount == 0)
		{
			emit sig_NotifyMsg(QString::fromLocal8Bit("请选择节点且只能一个节点！"), 10086);
			return;
		}

		AddFeedingWidget*pQtWidget = new AddFeedingWidget(m_subject_name,m_price,m_maxNumber, m_area);
		connect(pQtWidget, SIGNAL(sig_commit(QString&, QString&, QString&, QString&)), this, SLOT(SlotAddFeeding(QString&, QString&, QString&, QString&)));
		pQtWidget->setAttribute(Qt::WA_DeleteOnClose);
		pQtWidget->setWindowModality(Qt::ApplicationModal);
		pQtWidget->show();
	});

	connect(ui->detail_search_btn, &QPushButton::clicked, this, [this]()->void {
		m_pViewModelFeedingDetail->removeRows(0, m_pViewModelFeedingDetail->rowCount());
		QThread *m_pThread = new QThread;
		connect(m_pThread, SIGNAL(started()), this, SLOT(SlotThreadSearchFeeding()));
		connect(m_pThread, SIGNAL(finished()), m_pThread, SLOT(deleteLater()));
		m_pThread->start();
	});
}


FeedingManagerWidget::~FeedingManagerWidget()
{
}

void FeedingManagerWidget::updateMaximize()
{
	QWidget *pWindow = this->window(); //获得标题栏所在的窗口
	pWindow->isMaximized() ? pWindow->showNormal() : pWindow->showMaximized();  //窗口最大化/还原显示
	if (pWindow->isTopLevel())
	{
		bool bMaximize = pWindow->isMaximized(); //判断窗口是不是最大化状态，是则返回true，否则返回false
		if (bMaximize)
		{
			//目前窗口是最大化状态，则最大化/还原的toolTip设置为"Restore"
			ui->feedstore_max_restore_btn->setToolTip(QString::fromLocal8Bit("还原"));
			//设置按钮的属性名为"maximizeProperty"
			ui->feedstore_max_restore_btn->setProperty("maximizeProperty", "restore");
		}
		else
		{
			//目前窗口是还原状态，则最大化/还原的toolTip设置为"Maximize"
			ui->feedstore_max_restore_btn->setToolTip(QString::fromLocal8Bit("最大化"));
			//设置按钮的属性名为"maximizeProperty"
			ui->feedstore_max_restore_btn->setProperty("maximizeProperty", "maximize");
		}

		ui->feedstore_max_restore_btn->setStyle(QApplication::style());
	}
}

void FeedingManagerWidget::SlotOptionClick()
{
	NavButton *btn = (NavButton *)sender();
	for (int i = 0; i < m_NavButtonList.count(); i++) {
		if (m_NavButtonList.at(i) == btn)
		{
			ui->feeding_stackedWidget->setCurrentIndex(i);
			m_NavButtonList.at(i)->setChecked(true);
		}
		else {
			m_NavButtonList.at(i)->setChecked(false);
		}
	}
}



void FeedingManagerWidget::SlotSearchAreaFeedStore()
{
	m_pViewModelTotalArea->removeRows(0, m_pViewModelTotalArea->rowCount());
	QThread *m_pThread = new QThread;
	connect(m_pThread, SIGNAL(started()), this, SLOT(SlotThreadSearchAreaFeedStore()));
	connect(m_pThread, SIGNAL(finished()), m_pThread, SLOT(deleteLater()));
	m_pThread->start();
}

void FeedingManagerWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
	Q_UNUSED(event); //没有实质性的作用，只是用来允许event可以不使用，用来避免编译器警告
	emit ui->feedstore_max_restore_btn->clicked();
}

void FeedingManagerWidget::paintEvent(QPaintEvent *event)
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

QWidget* FeedingManagerWidget::getDragnWidget()
{
	return ui->child_widget_title;
}

void FeedingManagerWidget::InitOption()
{
	m_NavButtonList << ui->feeding_opt << ui->feeding_detail_opt ;
	QList<QChar> pixChar;
	pixChar << 0xf509 << 0xf571 ;
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

		connect(m_NavButtonList.at(i), &QPushButton::clicked, this, &FeedingManagerWidget::SlotOptionClick);
	}
	m_NavButtonList.at(0)->setChecked(true);
}

void FeedingManagerWidget::initTableView()
{
	m_pViewModelTotalArea = new QStandardItemModel();
	ui->area_feedstore_tableView->setModel(m_pViewModelTotalArea);
	m_pViewModelTotalArea->setColumnCount(8);
	m_pViewModelTotalArea->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("ID"));
	m_pViewModelTotalArea->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("区域"));
	m_pViewModelTotalArea->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("物品名称"));
	m_pViewModelTotalArea->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("单位"));
	m_pViewModelTotalArea->setHeaderData(4, Qt::Horizontal, QString::fromLocal8Bit("规格"));
	m_pViewModelTotalArea->setHeaderData(5, Qt::Horizontal, QString::fromLocal8Bit("成本单价"));
	m_pViewModelTotalArea->setHeaderData(6, Qt::Horizontal, QString::fromLocal8Bit("数量"));
	m_pViewModelTotalArea->setHeaderData(7, Qt::Horizontal, QString::fromLocal8Bit("总价值"));
	onSetTableAttribute(ui->area_feedstore_tableView, 8, false);

	m_pViewModelFeedingDetail = new QStandardItemModel();

	ui->feeding_detail_tableView->setModel(m_pViewModelFeedingDetail);
	m_pViewModelFeedingDetail->setColumnCount(11);
	m_pViewModelFeedingDetail->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("ID"));
	m_pViewModelFeedingDetail->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("时间"));
	m_pViewModelFeedingDetail->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("区域"));
	m_pViewModelFeedingDetail->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("塘号"));
	m_pViewModelFeedingDetail->setHeaderData(4, Qt::Horizontal, QString::fromLocal8Bit("物品名称"));
	m_pViewModelFeedingDetail->setHeaderData(5, Qt::Horizontal, QString::fromLocal8Bit("规格"));
	m_pViewModelFeedingDetail->setHeaderData(6, Qt::Horizontal, QString::fromLocal8Bit("单位"));
	m_pViewModelFeedingDetail->setHeaderData(7, Qt::Horizontal, QString::fromLocal8Bit("数量"));
	m_pViewModelFeedingDetail->setHeaderData(8, Qt::Horizontal, QString::fromLocal8Bit("成本单价"));
	m_pViewModelFeedingDetail->setHeaderData(9, Qt::Horizontal, QString::fromLocal8Bit("成本总额"));
	m_pViewModelFeedingDetail->setHeaderData(10, Qt::Horizontal, QString::fromLocal8Bit("物品类别"));
	onSetTableAttribute(ui->feeding_detail_tableView, 11, false);
}

void FeedingManagerWidget::AddAreaFeedStoreTableView(AreaFeedStoreStruct&item)
{
	int nCount = m_pViewModelTotalArea->rowCount();
	m_pViewModelTotalArea->setItem(nCount, 0, new QStandardItem(QString::number(item.id)));
	m_pViewModelTotalArea->item(nCount, 0)->setCheckable(true);
	m_pViewModelTotalArea->setItem(nCount, 1, new QStandardItem(item.area));
	m_pViewModelTotalArea->setItem(nCount, 2, new QStandardItem(item.subject_name));
	m_pViewModelTotalArea->setItem(nCount, 3, new QStandardItem(item.unit));
	m_pViewModelTotalArea->setItem(nCount, 4, new QStandardItem(item.specs));
	m_pViewModelTotalArea->setItem(nCount, 5, new QStandardItem(item.price));
	m_pViewModelTotalArea->setItem(nCount, 6, new QStandardItem(QString::number(item.number)));
	m_pViewModelTotalArea->setItem(nCount, 7, new QStandardItem(QString::number(item.price.toDouble()*item.number)));
	ui->area_feedstore_tableView->setColumnWidth(0, 60);
	
}

void FeedingManagerWidget::AddAreaFeedingDetailTableViEW(AreaFeedFeedingDetailStruct&item)
{
	int nCount = m_pViewModelFeedingDetail->rowCount();
	m_pViewModelFeedingDetail->setItem(nCount, 0, new QStandardItem(QString::number(item.id)));
	m_pViewModelFeedingDetail->item(nCount, 0)->setCheckable(true);
	m_pViewModelFeedingDetail->setItem(nCount, 1, new QStandardItem(item.time.mid(0,10)));
	m_pViewModelFeedingDetail->setItem(nCount, 2, new QStandardItem(item.area));
	m_pViewModelFeedingDetail->setItem(nCount, 3, new QStandardItem(item.areaitem));
	m_pViewModelFeedingDetail->setItem(nCount, 4, new QStandardItem(item.subject_name));
	m_pViewModelFeedingDetail->setItem(nCount, 5, new QStandardItem(item.specs));
	m_pViewModelFeedingDetail->setItem(nCount, 6, new QStandardItem(item.unit));
	m_pViewModelFeedingDetail->setItem(nCount, 7, new QStandardItem(item.price));
	m_pViewModelFeedingDetail->setItem(nCount, 8, new QStandardItem(QString::number(item.number)));
	m_pViewModelFeedingDetail->setItem(nCount, 9, new QStandardItem(QString::number(item.price.toDouble()*item.number)));
	m_pViewModelFeedingDetail->setItem(nCount, 10, new QStandardItem(item.type));
	ui->feeding_detail_tableView->setColumnWidth(0, 60);
}

void FeedingManagerWidget::SlotThreadAddFeeding()
{
	QString strParam = QString("id=%1&operat_time=%2&subject_name=%3&price=%4&number=%5&area=%6&areaitem=%7&specs=%8&unit=%9&type=%10")
		.arg(QString::number(m_id)).arg(m_time).arg(m_subject_name).arg(m_price).arg(m_number).arg(m_area)
		.arg(m_areaItem).arg(m_specs).arg(m_unit).arg(m_feedingType);
	QByteArray responseData;
	SingletonHttpRequest::getInstance()->RequestPost("http://127.0.0.1:80/zerg/public/index.php/addFeeding"
		, g_token, strParam, responseData);
	QJsonParseError json_error;
	QJsonDocument parse_doucment = QJsonDocument::fromJson(responseData, &json_error);
	if (json_error.error == QJsonParseError::NoError)
	{
		if (parse_doucment.isArray())
		{
			QJsonArray array = parse_doucment.array();
			for (int i = 0; i < array.size(); i++)
			{
				QJsonValue materialArray = array.at(i);
				QJsonObject materialObject = materialArray.toObject();
				AreaFeedStoreStruct item;
				item.id = materialObject["id"].toInt();
				item.supplier = materialObject["supplier"].toString();
				item.number = materialObject["number"].toInt();
				item.subject_name = materialObject["subject_name"].toString();
				item.area = materialObject["area"].toString();
				item.specs = materialObject["specs"].toString();
				item.unit = materialObject["unit"].toString();
				item.price = materialObject["price"].toString();
				AddAreaFeedStoreTableView(item);
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

void FeedingManagerWidget::SlotThreadSearchFeeding()
{
	QString strParam = QString("starttime=%1&endtime=%2&area=%3&areaitem=%4")
		.arg(ui->startdateEdit->text()).arg(ui->enddateEdit->text()).arg(ui->area_combox->currentText()).arg(ui->area_item_combox->currentText());
	QByteArray responseData;
	SingletonHttpRequest::getInstance()->RequestPost("http://127.0.0.1:80/zerg/public/index.php/SerachFeeding"
		, g_token, strParam, responseData);
	QJsonParseError json_error;
	QJsonDocument parse_doucment = QJsonDocument::fromJson(responseData, &json_error);
	if (json_error.error == QJsonParseError::NoError)
	{
		if (parse_doucment.isArray())
		{
			QJsonArray array = parse_doucment.array();
			for (int i = 0; i < array.size(); i++)
			{
				QJsonValue materialArray = array.at(i);
				QJsonObject materialObject = materialArray.toObject();
				AreaFeedFeedingDetailStruct item;
				item.id = materialObject["id"].toInt();
				item.time = materialObject["operat_time"].toString();
				item.supplier = materialObject["supplier"].toString();
				item.number = materialObject["number"].toInt();
				item.subject_name = materialObject["subject_name"].toString();
				item.area = materialObject["area"].toString();
				item.specs = materialObject["specs"].toString();
				item.unit = materialObject["unit"].toString();
				item.price = materialObject["price"].toString();
				item.areaitem = materialObject["areaitem"].toString();
				item.type = materialObject["type"].toString();
				AddAreaFeedingDetailTableViEW(item);
			}
			
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

void FeedingManagerWidget::comboBoxValueChanged()
{
	ui->area_item_combox->clear();
	for (auto&kvp : g_areaList)
	{
		if (kvp.second.areaName == ui->area_combox->currentText())
		{
			for (auto&kvpi : kvp.second.areaDetailList)
			{
				ui->area_item_combox->addItem(kvpi.second);
			}

		}
	}

}

void FeedingManagerWidget::SlotAddFeeding(QString&time, QString&number, QString&areaItem, QString&type)
{
	m_time = time;
	m_number = number;
	m_areaItem = areaItem;
	m_feedingType = type;
	m_pViewModelTotalArea->removeRows(0, m_pViewModelTotalArea->rowCount());

	QThread *m_pThread = new QThread;
	connect(m_pThread, SIGNAL(started()), this, SLOT(SlotThreadAddFeeding()));
	connect(m_pThread, SIGNAL(finished()), m_pThread, SLOT(deleteLater()));
	m_pThread->start();
}

void FeedingManagerWidget::SlotThreadSearchAreaFeedStore()
{
	QString strParam = QString("subject_name=%1&area=%2")
		.arg(ui->area_feed_edit->text()).arg(ui->area3_combox->currentText());
	QByteArray responseData;
	SingletonHttpRequest::getInstance()->RequestPost("http://127.0.0.1:80/zerg/public/index.php/SearchAreaFeedStore"
		, g_token, strParam, responseData);
	QJsonParseError json_error;
	QJsonDocument parse_doucment = QJsonDocument::fromJson(responseData, &json_error);
	if (json_error.error == QJsonParseError::NoError)
	{
		if (parse_doucment.isArray())
		{
			QJsonArray array = parse_doucment.array();
			for (int i = 0; i < array.size(); i++)
			{
				QJsonValue materialArray = array.at(i);
				QJsonObject materialObject = materialArray.toObject();
				AreaFeedStoreStruct item;
				item.id = materialObject["id"].toInt();
				item.supplier = materialObject["supplier"].toString();
				item.number = materialObject["number"].toInt();
				item.subject_name = materialObject["subject_name"].toString();
				item.area = materialObject["area"].toString();
				item.specs = materialObject["specs"].toString();
				item.unit = materialObject["unit"].toString();
				item.price = materialObject["price"].toString();
				AddAreaFeedStoreTableView(item);
			}
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
