#include "FeedStoreManagerWdiget.h"

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
#include "globalVariable.h"


FeedStoreManagerWdiget::FeedStoreManagerWdiget(QWidget *parent)
	:MoveableFramelessWindow(parent)
	, ui(new Ui::FeedStore)
{
	ui->setupUi(this);
	connect(ui->feedstore_cose_btn, &QPushButton::clicked, this, &QWidget::close);
	connect(ui->feedstore_max_restore_btn, &QPushButton::clicked, this, &FeedStoreManagerWdiget::updateMaximize);
	connect(ui->feedstore_min_btn, &QPushButton::clicked, this, &QWidget::showMinimized);
	ui->feedstore_max_restore_btn->setToolTip(QString::fromLocal8Bit("���"));
	//���ð�ť��������Ϊ"maximizeProperty"
	ui->feedstore_max_restore_btn->setProperty("maximizeProperty", "maximize");
	ui->feedstore_max_restore_btn->setStyle(QApplication::style());
	InitOption();
 	QDateTime current_date_time = QDateTime::currentDateTime();
 	ui->startdateEdit->setCalendarPopup(true);
 	ui->startdateEdit->setDateTime(current_date_time);
 	ui->enddateEdit->setCalendarPopup(true);
 	ui->enddateEdit->setDateTime(current_date_time);
 	
	
	ui->storge_type_combox->addItem(QString::fromLocal8Bit("���"));
	ui->storge_type_combox->addItem(QString::fromLocal8Bit("����"));
	ui->storge_type_combox->addItem(QString::fromLocal8Bit("�˻�"));
	ui->storge_type_combox->addItem(QString::fromLocal8Bit("�˿�"));
	ui->storge_type_combox->setCurrentText(0);
	for (auto&kvp:g_areaList)
	{
		ui->area_combox->addItem(kvp.second.areaName);
		ui->area3_combox->addItem(kvp.second.areaName);
	}
	ui->area_combox->setCurrentText(0);
	connect(ui->storge_type_combox, SIGNAL(currentIndexChanged(int)), this, SLOT(comboBoxValueChanged()));
	ui->area_combox->setVisible(false);
	initTableView();
}


FeedStoreManagerWdiget::~FeedStoreManagerWdiget()
{
}

void FeedStoreManagerWdiget::updateMaximize()
{
	QWidget *pWindow = this->window(); //��ñ��������ڵĴ���
	pWindow->isMaximized() ? pWindow->showNormal() : pWindow->showMaximized();  //�������/��ԭ��ʾ
	if (pWindow->isTopLevel())
	{
		bool bMaximize = pWindow->isMaximized(); //�жϴ����ǲ������״̬�����򷵻�true�����򷵻�false
		if (bMaximize)
		{
			//Ŀǰ���������״̬�������/��ԭ��toolTip����Ϊ"Restore"
			ui->feedstore_max_restore_btn->setToolTip(QString::fromLocal8Bit("��ԭ"));
			//���ð�ť��������Ϊ"maximizeProperty"
			ui->feedstore_max_restore_btn->setProperty("maximizeProperty", "restore");
		}
		else
		{
			//Ŀǰ�����ǻ�ԭ״̬�������/��ԭ��toolTip����Ϊ"Maximize"
			ui->feedstore_max_restore_btn->setToolTip(QString::fromLocal8Bit("���"));
			//���ð�ť��������Ϊ"maximizeProperty"
			ui->feedstore_max_restore_btn->setProperty("maximizeProperty", "maximize");
		}

		ui->feedstore_max_restore_btn->setStyle(QApplication::style());
	}
}

void FeedStoreManagerWdiget::SlotOptionClick()
{
	NavButton *btn = (NavButton *)sender();
	for (int i = 0; i < m_NavButtonList.count(); i++) {
		if (m_NavButtonList.at(i) == btn)
		{
			ui->feedstore_stackedWidget->setCurrentIndex(i);
			m_NavButtonList.at(i)->setChecked(true);
		}
		else {
			m_NavButtonList.at(i)->setChecked(false);
		}
	}
}

void FeedStoreManagerWdiget::comboBoxValueChanged()
{
	ChangeDetailTableView();
}
void FeedStoreManagerWdiget::ChangeDetailTableView()
{
	if (ui->storge_type_combox->currentText() == QString::fromLocal8Bit("���")|| ui->storge_type_combox->currentText() == QString::fromLocal8Bit("�˻�"))
	{
		ui->area_combox->setVisible(false);
	}
	else {
		
		ui->area_combox->setVisible(true);
	}
}
void FeedStoreManagerWdiget::mouseDoubleClickEvent(QMouseEvent *event)
{
	Q_UNUSED(event); //û��ʵ���Ե����ã�ֻ����������event���Բ�ʹ�ã������������������
	emit ui->feedstore_max_restore_btn->clicked();
}

void FeedStoreManagerWdiget::paintEvent(QPaintEvent *event)
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

QWidget* FeedStoreManagerWdiget::getDragnWidget()
{
	return ui->child_widget_title;
}

void FeedStoreManagerWdiget::InitOption()
{
	m_NavButtonList << ui->feedstore_detail_opt << ui->feedstore_in_out_opt
		<< ui->area_detail_opt;
	QList<QChar> pixChar;
	pixChar << 0xf509 << 0xf1fe << 0xf2a3;
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

		connect(m_NavButtonList.at(i), &QPushButton::clicked, this, &FeedStoreManagerWdiget::SlotOptionClick);
	}
	m_NavButtonList.at(0)->setChecked(true);
}

void FeedStoreManagerWdiget::initTableView()
{
	m_pViewHeadDeleagteTotalDetail = new CCheckBoxHeaderView(0, Qt::Horizontal, ui->total_feed_store_tableView);
	ui->total_feed_store_tableView->setHorizontalHeader(m_pViewHeadDeleagteTotalDetail);
	m_pViewModelTotalDetail = new QStandardItemModel();
	ui->total_feed_store_tableView->setModel(m_pViewModelTotalDetail);
	m_pViewModelTotalDetail->setColumnCount(8);
	m_pViewModelTotalDetail->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit(""));
	m_pViewModelTotalDetail->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("��Ӧ��"));
	m_pViewModelTotalDetail->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("��Ʒ����"));
	m_pViewModelTotalDetail->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("��Ʒ���"));
	m_pViewModelTotalDetail->setHeaderData(4, Qt::Horizontal, QString::fromLocal8Bit("��λ"));
	m_pViewModelTotalDetail->setHeaderData(5, Qt::Horizontal, QString::fromLocal8Bit("�ɱ�����"));
	m_pViewModelTotalDetail->setHeaderData(6, Qt::Horizontal, QString::fromLocal8Bit("����"));
	m_pViewModelTotalDetail->setHeaderData(7, Qt::Horizontal, QString::fromLocal8Bit("�ܼ�ֵ"));
	onSetTableAttribute(ui->total_feed_store_tableView, 8, false);
	ui->total_feed_store_tableView->setColumnWidth(0, 30);
	ui->total_feed_store_tableView->setColumnWidth(1, 100);
	ui->total_feed_store_tableView->setColumnWidth(2, 180);

	m_pViewHeadDeleagteTotal_in_out_return = new CCheckBoxHeaderView(0, Qt::Horizontal, ui->feedstore_in_out_tableView);
	ui->feedstore_in_out_tableView->setHorizontalHeader(m_pViewHeadDeleagteTotal_in_out_return);
	m_pViewModelTotalDetail_in_out_return = new QStandardItemModel();
	ui->feedstore_in_out_tableView->setModel(m_pViewModelTotalDetail_in_out_return);
	m_pViewModelTotalDetail_in_out_return->setColumnCount(8);
	m_pViewModelTotalDetail_in_out_return->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit(""));
	m_pViewModelTotalDetail_in_out_return->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("ʱ��"));
	m_pViewModelTotalDetail_in_out_return->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("��Ʒ����"));
	m_pViewModelTotalDetail_in_out_return->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("����"));
	m_pViewModelTotalDetail_in_out_return->setHeaderData(4, Qt::Horizontal, QString::fromLocal8Bit("�ɱ�����"));
	m_pViewModelTotalDetail_in_out_return->setHeaderData(5, Qt::Horizontal, QString::fromLocal8Bit("ʣ������"));
	m_pViewModelTotalDetail_in_out_return->setHeaderData(6, Qt::Horizontal, QString::fromLocal8Bit("ʣ���ܶ�"));
	m_pViewModelTotalDetail_in_out_return->setHeaderData(7, Qt::Horizontal, QString::fromLocal8Bit("����"));
	onSetTableAttribute(ui->feedstore_in_out_tableView, 8, false);
	ui->feedstore_in_out_tableView->setColumnWidth(0, 30);
	ui->feedstore_in_out_tableView->setColumnWidth(1, 100);
	ui->feedstore_in_out_tableView->setColumnWidth(2, 180);


	m_pViewHeadDeleagteTotalArea= new CCheckBoxHeaderView(0, Qt::Horizontal, ui->area_feed_detail_tableView);
	ui->area_feed_detail_tableView->setHorizontalHeader(m_pViewHeadDeleagteTotalArea);
	m_pViewModelTotalArea = new QStandardItemModel();
	ui->area_feed_detail_tableView->setModel(m_pViewModelTotalArea);
	m_pViewModelTotalArea->setColumnCount(8);
	m_pViewModelTotalArea->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit(""));
	m_pViewModelTotalArea->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("����"));
	m_pViewModelTotalArea->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("��Ʒ����"));
	m_pViewModelTotalArea->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("��Ʒ���"));
	m_pViewModelTotalArea->setHeaderData(4, Qt::Horizontal, QString::fromLocal8Bit("��λ"));
	m_pViewModelTotalArea->setHeaderData(5, Qt::Horizontal, QString::fromLocal8Bit("�ɱ�����"));
	m_pViewModelTotalArea->setHeaderData(6, Qt::Horizontal, QString::fromLocal8Bit("����"));
	m_pViewModelTotalArea->setHeaderData(7, Qt::Horizontal, QString::fromLocal8Bit("�ܼ�ֵ"));
	onSetTableAttribute(ui->area_feed_detail_tableView, 8, false);
	ui->area_feed_detail_tableView->setColumnWidth(0, 30);
	ui->area_feed_detail_tableView->setColumnWidth(1, 100);
	ui->area_feed_detail_tableView->setColumnWidth(2, 180);
}
