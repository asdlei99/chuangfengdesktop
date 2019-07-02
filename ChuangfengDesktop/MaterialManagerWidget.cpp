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
MaterialManagerWidget::MaterialManagerWidget(QWidget *parent)
	:MoveableFramelessWindow(parent)
, ui(new Ui::Material)

{
	ui->setupUi(this);
	connect(ui->material_cose_btn, &QPushButton::clicked, this, &QWidget::close);
	connect(ui->material_max_restore_btn, &QPushButton::clicked, this, &MaterialManagerWidget::updateMaximize);
	connect(ui->material_min_btn, &QPushButton::clicked, this, &QWidget::showMinimized);
	ui->material_max_restore_btn->setToolTip(QString::fromLocal8Bit("���"));
	//���ð�ť��������Ϊ"maximizeProperty"
	ui->material_max_restore_btn->setProperty("maximizeProperty", "maximize");
	ui->material_max_restore_btn->setStyle(QApplication::style());
	initOption();
	initTableView();
	connect(ui->material_income_btn, &QPushButton::clicked, this, [this]()->void {
		AddMaterialWidget*pQtWidget = new AddMaterialWidget();
		/*connect(pQtWidget, SIGNAL(sig_commit(QString&, QString&, QString&, QString&, QString&, QString&, QString&)), this, SLOT(SlotAddNopayDetail(QString&, QString&, QString&, QString&, QString&, QString&, QString&)));*/
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
}


MaterialManagerWidget::~MaterialManagerWidget()
{
}

void MaterialManagerWidget::updateMaximize()
{
	QWidget *pWindow = this->window(); //��ñ��������ڵĴ���
	pWindow->isMaximized() ? pWindow->showNormal() : pWindow->showMaximized();  //�������/��ԭ��ʾ
	if (pWindow->isTopLevel())
	{
		bool bMaximize = pWindow->isMaximized(); //�жϴ����ǲ������״̬�����򷵻�true�����򷵻�false
		if (bMaximize)
		{
			//Ŀǰ���������״̬�������/��ԭ��toolTip����Ϊ"Restore"
			ui->material_max_restore_btn->setToolTip(QString::fromLocal8Bit("��ԭ"));
			//���ð�ť��������Ϊ"maximizeProperty"
			ui->material_max_restore_btn->setProperty("maximizeProperty", "restore");
		}
		else
		{
			//Ŀǰ�����ǻ�ԭ״̬�������/��ԭ��toolTip����Ϊ"Maximize"
			ui->material_max_restore_btn->setToolTip(QString::fromLocal8Bit("���"));
			//���ð�ť��������Ϊ"maximizeProperty"
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
	Q_UNUSED(event); //û��ʵ���Ե����ã�ֻ����������event���Բ�ʹ�ã������������������
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

		//�ֿ�����ͼ��
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
	m_pViewModelDetail->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("��;"));
	m_pViewModelDetail->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("���"));
	m_pViewModelDetail->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("��Ʒ����"));
	m_pViewModelDetail->setHeaderData(4, Qt::Horizontal, QString::fromLocal8Bit("��Ʒ���"));
	m_pViewModelDetail->setHeaderData(5, Qt::Horizontal, QString::fromLocal8Bit("��λ"));
	m_pViewModelDetail->setHeaderData(6, Qt::Horizontal, QString::fromLocal8Bit("�ɱ�����"));
	m_pViewModelDetail->setHeaderData(7, Qt::Horizontal, QString::fromLocal8Bit("����"));
	m_pViewModelDetail->setHeaderData(8, Qt::Horizontal, QString::fromLocal8Bit("�ܼ�ֵ"));
	onSetTableAttribute(ui->material_detail_tableView, 9,false);
	ui->material_detail_tableView->setColumnWidth(0, 30);
	ui->material_detail_tableView->setColumnWidth(1, 100);
	ui->material_detail_tableView->setColumnWidth(2, 180);

	m_pViewHeadDeleagteinout = new CCheckBoxHeaderView(0, Qt::Horizontal, ui->material_in_out_detail_tableview);
	ui->material_in_out_detail_tableview->setHorizontalHeader(m_pViewHeadDeleagteinout);
	connect(m_pViewHeadDeleagteinout, SIGNAL(sig_AllChecked(bool)), this, SLOT(slotCheckBoxStateChanged(bool)));
	m_pViewModelinout = new QStandardItemModel();
	ui->material_in_out_detail_tableview->setModel(m_pViewModelinout);
	m_pViewModelinout->setColumnCount(8);
	m_pViewModelinout->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit(""));
	m_pViewModelinout->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("ʱ��"));
	m_pViewModelinout->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("��ʽ"));
	m_pViewModelinout->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("����"));
	m_pViewModelinout->setHeaderData(4, Qt::Horizontal, QString::fromLocal8Bit("����"));
	m_pViewModelinout->setHeaderData(5, Qt::Horizontal, QString::fromLocal8Bit("�˷�"));
	m_pViewModelinout->setHeaderData(6, Qt::Horizontal, QString::fromLocal8Bit("ʣ������"));
	m_pViewModelinout->setHeaderData(7, Qt::Horizontal, QString::fromLocal8Bit("ʣ���ܶ�"));

	onSetTableAttribute(ui->material_in_out_detail_tableview, 8, false);
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
	m_pViewModelFix->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("�豸����"));
	m_pViewModelFix->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("���ʱ��"));
	m_pViewModelFix->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("����ʱ��"));
	m_pViewModelFix->setHeaderData(4, Qt::Horizontal, QString::fromLocal8Bit("��λ"));
	m_pViewModelFix->setHeaderData(5, Qt::Horizontal, QString::fromLocal8Bit("����"));
	m_pViewModelFix->setHeaderData(6, Qt::Horizontal, QString::fromLocal8Bit("�ܽ��"));
	m_pViewModelFix->setHeaderData(7, Qt::Horizontal, QString::fromLocal8Bit("��̯���"));
	m_pViewModelFix->setHeaderData(8, Qt::Horizontal, QString::fromLocal8Bit("���ڷ�̯���"));
	m_pViewModelFix->setHeaderData(9, Qt::Horizontal, QString::fromLocal8Bit("��̯����"));


	onSetTableAttribute(ui->fix_material_tableView, 10, false);
	ui->fix_material_tableView->setColumnWidth(0, 30);
	ui->fix_material_tableView->setColumnWidth(1, 100);
	ui->fix_material_tableView->setColumnWidth(2, 180);

}

