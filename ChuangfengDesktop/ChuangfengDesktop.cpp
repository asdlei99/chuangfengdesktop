#include "ChuangfengDesktop.h"
//调用WIN API需要用到的头文件与库 [实现缩放]

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
#include "MaterialManagerWidget.h"
#include "FeedStoreManagerWdiget.h"
#include "GeneralLayoutManger.h"
#include "BakLayoutManager.h"
#include "NoPayLayoutManager.h"
#include "TotalReportManager.h"
#include "NopayReportManger.h"
#include "ShareReportManager.h"
#include "DetailShareReportManager.h"
#include "MaterielReportManger.h"
#include "StoreReportManager.h"

#include "FeedingManagerWidget.h"

ChuangfengDesktop::ChuangfengDesktop(QWidget *parent)
	:MoveableFramelessWindow(parent)
	,ui(new Ui::ChuangfengDesktopClass)
	
{
	ui->setupUi(this);
	myEvent1 = static_cast<QEvent::Type>(QEvent::registerEventType(-1));
	connect(ui->close_btn, &QPushButton::clicked, this, &ChuangfengDesktop::close);
	connect(ui->max_restore_btn, &QPushButton::clicked, this, &ChuangfengDesktop::updateMaximize);
	connect(ui->min_btn, &QPushButton::clicked, this, &QWidget::showMinimized);
	connect(ui->store_material_mgr_btn, &QPushButton::clicked, this, [this]()->void {
		MaterialManagerWidget*pQtWidget = new MaterialManagerWidget();
		pQtWidget->setAttribute(Qt::WA_DeleteOnClose);
		pQtWidget->setWindowModality(Qt::ApplicationModal);
		pQtWidget->show();
	});

	connect(ui->store_feed_mgr_btn, &QPushButton::clicked, this, [this]()->void {
		FeedStoreManagerWdiget*pQtWidget = new FeedStoreManagerWdiget();
		pQtWidget->setAttribute(Qt::WA_DeleteOnClose);
		pQtWidget->setWindowModality(Qt::ApplicationModal);
		pQtWidget->show();
	});
	connect(ui->general_btn, &QPushButton::clicked, this, [this]()->void {
		GeneralLayoutManger*pQtWidget = new GeneralLayoutManger();
		pQtWidget->setAttribute(Qt::WA_DeleteOnClose);
		pQtWidget->setWindowModality(Qt::ApplicationModal);
		pQtWidget->show();
	});

	connect(ui->bak_btn, &QPushButton::clicked, this, [this]()->void {
		BakLayoutManager*pQtWidget = new BakLayoutManager();
		pQtWidget->setAttribute(Qt::WA_DeleteOnClose);
		pQtWidget->setWindowModality(Qt::ApplicationModal);
		pQtWidget->show();
	});

	connect(ui->nopay_btn, &QPushButton::clicked, this, [this]()->void {
		NoPayLayoutManager*pQtWidget = new NoPayLayoutManager();
		pQtWidget->setAttribute(Qt::WA_DeleteOnClose);
		pQtWidget->setWindowModality(Qt::ApplicationModal);
		pQtWidget->show();
	});
	connect(ui->TotalReport_btn, &QPushButton::clicked, this, [this]()->void {
		TotalReportManager*pQtWidget = new TotalReportManager();
		pQtWidget->setAttribute(Qt::WA_DeleteOnClose);
		pQtWidget->setWindowModality(Qt::ApplicationModal);
		pQtWidget->show();
	});
	connect(ui->NoPayReport_btn, &QPushButton::clicked, this, [this]()->void {
		NopayReportManger*pQtWidget = new NopayReportManger();
		pQtWidget->setAttribute(Qt::WA_DeleteOnClose);
		pQtWidget->setWindowModality(Qt::ApplicationModal);
		pQtWidget->show();
	});
	connect(ui->ShareReport_btn, &QPushButton::clicked, this, [this]()->void {
		ShareReportManager*pQtWidget = new ShareReportManager();
		pQtWidget->setAttribute(Qt::WA_DeleteOnClose);
		pQtWidget->setWindowModality(Qt::ApplicationModal);
		pQtWidget->show();
	});
	connect(ui->ShareDetail_btn, &QPushButton::clicked, this, [this]()->void {
		DetailShareReportManager*pQtWidget = new DetailShareReportManager();
		pQtWidget->setAttribute(Qt::WA_DeleteOnClose);
		pQtWidget->setWindowModality(Qt::ApplicationModal);
		pQtWidget->show();
	});
	connect(ui->MaterielReport_btn, &QPushButton::clicked, this, [this]()->void {
		MaterielReportManger*pQtWidget = new MaterielReportManger();
		pQtWidget->setAttribute(Qt::WA_DeleteOnClose);
		pQtWidget->setWindowModality(Qt::ApplicationModal);
		pQtWidget->show();
	});
	connect(ui->feed_btn, &QPushButton::clicked, this, [this]()->void {
		FeedingManagerWidget*pQtWidget = new FeedingManagerWidget();
		pQtWidget->setAttribute(Qt::WA_DeleteOnClose);
		pQtWidget->setWindowModality(Qt::ApplicationModal);
		pQtWidget->show();
	});
	connect(ui->StoreReport_btn, &QPushButton::clicked, this, [this]()->void {
		StoreReportManager*pQtWidget = new StoreReportManager();
		pQtWidget->setAttribute(Qt::WA_DeleteOnClose);
		pQtWidget->setWindowModality(Qt::ApplicationModal);
		pQtWidget->show();
	});
	ui->max_restore_btn->setToolTip(QString::fromLocal8Bit("最大化"));
	//设置按钮的属性名为"maximizeProperty"
	ui->max_restore_btn->setProperty("maximizeProperty", "maximize");
	ui->max_restore_btn->setStyle(QApplication::style());
	initMainOption();
	initSysLayoutOption();//初始化系统设置导航栏
	m_ptrUserLayoutManger = make_shared<UserLayoutManger>(ui);
	connect(m_ptrUserLayoutManger.get(), SIGNAL(sig_NotifyMsg(QString, int)), this, SLOT(SlotMsgPop(QString,int)));
	m_ptrCategoryLayoutManager = make_shared<CategoryLayoutManager>(ui);
	connect(m_ptrCategoryLayoutManager.get(), SIGNAL(sig_NotifyMsg(QString, int)), this, SLOT(SlotMsgPop(QString, int)));
	m_ptrAreaLayoutManager = make_shared<AreaLayoutManager>(ui);
	connect(m_ptrAreaLayoutManager.get(), SIGNAL(sig_NotifyMsg(QString, int)), this, SLOT(SlotMsgPop(QString, int)));
	m_ptrSupplierLayoutManager = make_shared<SupplierLayoutManager>(ui);
	connect(m_ptrSupplierLayoutManager.get(), SIGNAL(sig_NotifyMsg(QString, int)), this, SLOT(SlotMsgPop(QString, int)));
	m_ptrShareItemLayoutManager = make_shared<ShareItemLayoutManager>(ui);
	connect(m_ptrShareItemLayoutManager.get(), SIGNAL(sig_NotifyMsg(QString, int)), this, SLOT(SlotMsgPop(QString, int)));
	m_ptrDetailAreaLayoutManager = make_shared<DetailAreaLayoutManager>(ui, m_ptrAreaLayoutManager);
	connect(m_ptrDetailAreaLayoutManager.get(), SIGNAL(sig_NotifyMsg(QString, int)), this, SLOT(SlotMsgPop(QString, int)));
}

void ChuangfengDesktop::close()
{
	emit	CloseMainWidgetSingnal();
	__super::close();
}

void ChuangfengDesktop::mouseDoubleClickEvent(QMouseEvent *event)
{
	Q_UNUSED(event); //没有实质性的作用，只是用来允许event可以不使用，用来避免编译器警告
	emit ui->max_restore_btn->clicked();
}

void ChuangfengDesktop::paintEvent(QPaintEvent *event)
{
	QPainterPath path;
	path.setFillRule(Qt::WindingFill);
	path.addRect(0, 0, this->width(), 86);
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing, true);
	painter.fillPath(path, QBrush(QColor(56, 59, 67)));
	{
		QPainterPath path;
		path.setFillRule(Qt::WindingFill);
		path.addRect(0, 86, this->width(), this->height());
		QPainter painter(this);
		painter.setRenderHint(QPainter::Antialiasing, true);
		//painter.fillPath(path, QBrush(QColor(68, 71, 77)));
		painter.fillPath(path, QBrush(QColor(56, 59, 67)));
	}
}

QWidget* ChuangfengDesktop::getDragnWidget()
{
	return  ui->main_title_widget;
}



void ChuangfengDesktop::initMainOption()
{
	mNavButtonList << ui->opt_finance_mgr << ui->opt_store << ui->opt_feed_mgr << ui->opt_report << ui->opt_sysset;
	QList<QChar> pixChar;
	pixChar << 0xf653 << 0xf54e << 0xf48e << 0xf1c3 << 0xf085;
	QColor normalBgColor = QColor("#383B43");
	QColor hoverBgColor = QColor("#478CB6");
	QColor checkBgColor = QColor("#478CB6");
	QColor normalTextColor = QColor("#FFFFFF");
	QColor hoverTextColor = QColor("#FFFFFF");
	QColor checkTextColor = QColor("#FFFFFF");

	for (int i = 0; i < mNavButtonList.count(); i++) {

		mNavButtonList.at(i)->setLineColor(QColor("#029FEA"));
		///mNavButtonList.at(i)->setShowLine(true);
		mNavButtonList.at(i)->setTextAlign(NavButton::TextAlign_Left);
		mNavButtonList.at(i)->setTrianglePosition(NavButton::TrianglePosition_Bottom);
		//mNavButtonList.at(i)->setLinePosition(NavButton::LinePosition_Top);

		mNavButtonList.at(i)->setPaddingLeft(5);
		mNavButtonList.at(i)->setLineSpace(1);
		mNavButtonList.at(i)->setLineWidth(5);
		mNavButtonList.at(i)->setLineColor(QColor(255, 107, 107));
		mNavButtonList.at(i)->setShowTriangle(true);

		mNavButtonList.at(i)->setShowIcon(true);
		mNavButtonList.at(i)->setIconSpace(ICOSPACE);
		mNavButtonList.at(i)->setIconSize(QSize(ICONSIZE, ICONSIZE));

		//分开设置图标
		QChar icon = pixChar.at(i);
		QPixmap iconNormal = IconHelper::Instance()->getPixmap(normalTextColor.name(), icon, ICONFONTSIZE, PIXMAPSIZE, PIXMAPSIZE);
		QPixmap iconHover = IconHelper::Instance()->getPixmap(hoverTextColor.name(), icon, ICONFONTSIZE, PIXMAPSIZE, PIXMAPSIZE);
		QPixmap iconCheck = IconHelper::Instance()->getPixmap(checkTextColor.name(), icon, ICONFONTSIZE, PIXMAPSIZE, PIXMAPSIZE);

		mNavButtonList.at(i)->setIconNormal(iconNormal);
		mNavButtonList.at(i)->setIconHover(iconHover);
		mNavButtonList.at(i)->setIconCheck(iconCheck);

		mNavButtonList.at(i)->setNormalBgColor(normalBgColor);
		mNavButtonList.at(i)->setHoverBgColor(hoverBgColor);
		mNavButtonList.at(i)->setCheckBgColor(checkBgColor);
		mNavButtonList.at(i)->setNormalTextColor(normalTextColor);
		mNavButtonList.at(i)->setHoverTextColor(hoverTextColor);
		mNavButtonList.at(i)->setCheckTextColor(checkTextColor);

		connect(mNavButtonList.at(i), &QPushButton::clicked, this, &ChuangfengDesktop::SlotOptionClick);
	}
	mNavButtonList.at(0)->setChecked(true);
}

void ChuangfengDesktop::initSysLayoutOption()
{
	m_SysLayoutNavButtonList << ui->set_opt_person << ui->set_opt_account << ui->set_opt_area << ui->set_opt_supplier << ui->set_opt_task << ui->set_opt_detail_area;
	QList<QChar> pixChar;
	pixChar << 0xf509 << 0xf571 << 0xf1fe << 0xf2a3 << 0xf0ae << 0xf1fe;
	QColor normalBgColor = QColor("#44474D");
	QColor hoverBgColor = QColor("#478CB6");
	QColor checkBgColor = QColor("#478CB6");
	QColor normalTextColor = QColor("#FFFFFF");
	QColor hoverTextColor = QColor("#FFFFFF");
	QColor checkTextColor = QColor("#FFFFFF");

	for (int i = 0; i < m_SysLayoutNavButtonList.count(); i++) {

		m_SysLayoutNavButtonList.at(i)->setLineColor(QColor("#029FEA"));
		///mNavButtonList.at(i)->setShowLine(true);
		m_SysLayoutNavButtonList.at(i)->setTextAlign(NavButton::TextAlign_Left);
		m_SysLayoutNavButtonList.at(i)->setTrianglePosition(NavButton::TrianglePosition_Right);
		//mNavButtonList.at(i)->setLinePosition(NavButton::LinePosition_Top);

		m_SysLayoutNavButtonList.at(i)->setPaddingLeft(5);
		m_SysLayoutNavButtonList.at(i)->setLineSpace(1);
		m_SysLayoutNavButtonList.at(i)->setLineWidth(5);
		m_SysLayoutNavButtonList.at(i)->setLineColor(QColor(255, 107, 107));
		m_SysLayoutNavButtonList.at(i)->setShowTriangle(true);

		m_SysLayoutNavButtonList.at(i)->setShowIcon(true);
		m_SysLayoutNavButtonList.at(i)->setIconSpace(ICOSPACE);
		m_SysLayoutNavButtonList.at(i)->setIconSize(QSize(ICONSIZE, ICONSIZE));

		//分开设置图标
		QChar icon = pixChar.at(i);
		QPixmap iconNormal = IconHelper::Instance()->getPixmap(normalTextColor.name(), icon, ICONFONTSIZE, PIXMAPSIZE, PIXMAPSIZE);
		QPixmap iconHover = IconHelper::Instance()->getPixmap(hoverTextColor.name(), icon, ICONFONTSIZE, PIXMAPSIZE, PIXMAPSIZE);
		QPixmap iconCheck = IconHelper::Instance()->getPixmap(checkTextColor.name(), icon, ICONFONTSIZE, PIXMAPSIZE, PIXMAPSIZE);

		m_SysLayoutNavButtonList.at(i)->setIconNormal(iconNormal);
		m_SysLayoutNavButtonList.at(i)->setIconHover(iconHover);
		m_SysLayoutNavButtonList.at(i)->setIconCheck(iconCheck);

		m_SysLayoutNavButtonList.at(i)->setNormalBgColor(normalBgColor);
		m_SysLayoutNavButtonList.at(i)->setHoverBgColor(hoverBgColor);
		m_SysLayoutNavButtonList.at(i)->setCheckBgColor(checkBgColor);
		m_SysLayoutNavButtonList.at(i)->setNormalTextColor(normalTextColor);
		m_SysLayoutNavButtonList.at(i)->setHoverTextColor(hoverTextColor);
		m_SysLayoutNavButtonList.at(i)->setCheckTextColor(checkTextColor);

		connect(m_SysLayoutNavButtonList.at(i), &QPushButton::clicked, this, &ChuangfengDesktop::SlotSysLayoutOptionClick);
	}
	m_SysLayoutNavButtonList.at(0)->setChecked(true);
}




void ChuangfengDesktop::updateMaximize()
{
	QWidget *pWindow = this->window(); //获得标题栏所在的窗口
	pWindow->isMaximized() ? pWindow->showNormal() : pWindow->showMaximized();  //窗口最大化/还原显示
	if (pWindow->isTopLevel())
	{
		bool bMaximize = pWindow->isMaximized(); //判断窗口是不是最大化状态，是则返回true，否则返回false
		if (bMaximize)
		{
			//目前窗口是最大化状态，则最大化/还原的toolTip设置为"Restore"
			ui->max_restore_btn->setToolTip(QString::fromLocal8Bit("还原"));
			//设置按钮的属性名为"maximizeProperty"
			ui->max_restore_btn->setProperty("maximizeProperty", "restore");
		}
		else
		{
			//目前窗口是还原状态，则最大化/还原的toolTip设置为"Maximize"
			ui->max_restore_btn->setToolTip(QString::fromLocal8Bit("最大化"));
			//设置按钮的属性名为"maximizeProperty"
			ui->max_restore_btn->setProperty("maximizeProperty", "maximize");
		}

		ui->max_restore_btn->setStyle(QApplication::style());
	}
}

void ChuangfengDesktop::SlotOptionClick()
{
	NavButton *btn = (NavButton *)sender();
	for (int i = 0; i < mNavButtonList.count(); i++) {
		if (mNavButtonList.at(i) == btn)
		{
			ui->main_stackedWidget->setCurrentIndex(i);
			mNavButtonList.at(i)->setChecked(true);
		}
		else {
			mNavButtonList.at(i)->setChecked(false);
		}
	}
}

void ChuangfengDesktop::SlotSysLayoutOptionClick()
{
	NavButton *btn = (NavButton *)sender();
	for (int i = 0; i < m_SysLayoutNavButtonList.count(); i++) {
		if (m_SysLayoutNavButtonList.at(i) == btn)
		{
			ui->sysLayout_StackedWidget->setCurrentIndex(i);
			m_SysLayoutNavButtonList.at(i)->setChecked(true);
		}
		else {
			m_SysLayoutNavButtonList.at(i)->setChecked(false);
		}
	}
}



