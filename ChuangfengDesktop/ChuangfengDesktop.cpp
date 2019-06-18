#include "ChuangfengDesktop.h"
//调用WIN API需要用到的头文件与库 [实现缩放]
#ifdef Q_OS_WIN
#include <qt_windows.h>
#include <Windowsx.h>
#endif
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
ChuangfengDesktop::ChuangfengDesktop(QWidget *parent)
	:MoveableFramelessWindow(parent)
	,ui(new Ui::ChuangfengDesktopClass)
	, m_nBorderWidth(5)
{
	ui->setupUi(this);
	connect(ui->close_btn, &QPushButton::clicked, this, &ChuangfengDesktop::close);
	connect(ui->max_restore_btn, &QPushButton::clicked, this, &ChuangfengDesktop::updateMaximize);
	connect(ui->min_btn, &QPushButton::clicked, this, &QWidget::showMinimized);

	ui->max_restore_btn->setToolTip(QString::fromLocal8Bit("最大化"));
	//设置按钮的属性名为"maximizeProperty"
	ui->max_restore_btn->setProperty("maximizeProperty", "maximize");
	ui->max_restore_btn->setStyle(QApplication::style());
	initMainOption();
	initSysLayoutOption();//初始化系统设置导航栏
	initFinancialLayoutOption();
	initReportLayoutOption();
	m_ptrUserLayoutManger = make_shared<UserLayoutManger>(ui);
	m_ptrUserLayoutManger->InitLayout();
	m_ptrGeneralLayoutManger = make_shared<GeneralLayoutManger>(ui);
	m_ptrGeneralLayoutManger->InitLayout();
	m_ptrBakLayoutManager = make_shared<BakLayoutManager>(ui);
	m_ptrBakLayoutManager->InitLayout();
	m_ptrNoPayLayoutManager = make_shared<NoPayLayoutManager>(ui);
	m_ptrNoPayLayoutManager->InitLayout();
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

bool ChuangfengDesktop::nativeEvent(const QByteArray &eventType, void *message, long *result)
{
	Q_UNUSED(eventType)
	MSG *param = static_cast<MSG *>(message);

	switch (param->message)
	{
		case WM_NCHITTEST:
		{
			int nX = GET_X_LPARAM(param->lParam) - this->geometry().x();
			int nY = GET_Y_LPARAM(param->lParam) - this->geometry().y();

			// 如果鼠标位于子控件上，则不进行处理
			if (childAt(nX, nY) != nullptr)
				return QWidget::nativeEvent(eventType, message, result);

			*result = HTCAPTION;

			// 鼠标区域位于窗体边框，进行缩放
			if ((nX >= 0) && (nX <= m_nBorderWidth))
				*result = HTLEFT;

			if ((nX >= this->width() - m_nBorderWidth) && (nX <= this->width()))
				*result = HTRIGHT;

			if ((nY >= 0) && (nY <=m_nBorderWidth))
				*result = HTTOP;

			if ((nY >= this->height() - m_nBorderWidth) && (nY <= this->height()))
				*result = HTBOTTOM;

			if ((nX >= 0) && (nX <= m_nBorderWidth) && (nY >= 0)
				&& (nY < m_nBorderWidth))
				*result = HTTOPLEFT;

			if ((nX >= this->width() - m_nBorderWidth) && (nX <= this->width())
				&& (nY >= 0) && (nY <= m_nBorderWidth))
				*result = HTTOPRIGHT;

			if ((nX >= 0) && (nX <= m_nBorderWidth)
				&& (nY >= this->height() - m_nBorderWidth) && (nY <= this->height()))
				*result = HTBOTTOMLEFT;

			if ((nX >= this->width() - m_nBorderWidth) && (nX < this->width())
				&& (nY >= this->height() - m_nBorderWidth) && (nY <= this->height()))
				*result = HTBOTTOMRIGHT;

			return true;
		}
	}

	return MoveableFramelessWindow::nativeEvent(eventType, message, result);
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
	m_SysLayoutNavButtonList << ui->set_opt_person << ui->set_opt_account << ui->set_opt_area << ui->set_opt_supplier << ui->set_opt_task;
	QList<QChar> pixChar;
	pixChar << 0xf509 << 0xf571 << 0xf1fe << 0xf2a3 << 0xf0ae;
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

void ChuangfengDesktop::initFinancialLayoutOption()
{
	m_FinancialLayoutNavButtonList << ui->financial_opt_totalpay << ui->financial_opt_imprest << ui->financial_opt_payable ;
	QList<QChar> pixChar;
	pixChar << 0xf53d << 0xf157 << 0xf571;
	QColor normalBgColor = QColor("#44474D");
	QColor hoverBgColor = QColor("#478CB6");
	QColor checkBgColor = QColor("#478CB6");
	QColor normalTextColor = QColor("#FFFFFF");
	QColor hoverTextColor = QColor("#FFFFFF");
	QColor checkTextColor = QColor("#FFFFFF");

	for (int i = 0; i < m_FinancialLayoutNavButtonList.count(); i++) {

		m_FinancialLayoutNavButtonList.at(i)->setLineColor(QColor("#029FEA"));
		m_FinancialLayoutNavButtonList.at(i)->setTextAlign(NavButton::TextAlign_Left);
		m_FinancialLayoutNavButtonList.at(i)->setTrianglePosition(NavButton::TrianglePosition_Right);

		m_FinancialLayoutNavButtonList.at(i)->setPaddingLeft(5);
		m_FinancialLayoutNavButtonList.at(i)->setLineSpace(1);
		m_FinancialLayoutNavButtonList.at(i)->setLineWidth(5);
		m_FinancialLayoutNavButtonList.at(i)->setLineColor(QColor(255, 107, 107));
		m_FinancialLayoutNavButtonList.at(i)->setShowTriangle(true);

		m_FinancialLayoutNavButtonList.at(i)->setShowIcon(true);
		m_FinancialLayoutNavButtonList.at(i)->setIconSpace(ICOSPACE);
		m_FinancialLayoutNavButtonList.at(i)->setIconSize(QSize(ICONSIZE, ICONSIZE));

		//分开设置图标
		QChar icon = pixChar.at(i);
		QPixmap iconNormal = IconHelper::Instance()->getPixmap(normalTextColor.name(), icon, ICONFONTSIZE, PIXMAPSIZE, PIXMAPSIZE);
		QPixmap iconHover = IconHelper::Instance()->getPixmap(hoverTextColor.name(), icon, ICONFONTSIZE, PIXMAPSIZE, PIXMAPSIZE);
		QPixmap iconCheck = IconHelper::Instance()->getPixmap(checkTextColor.name(), icon, ICONFONTSIZE, PIXMAPSIZE, PIXMAPSIZE);

		m_FinancialLayoutNavButtonList.at(i)->setIconNormal(iconNormal);
		m_FinancialLayoutNavButtonList.at(i)->setIconHover(iconHover);
		m_FinancialLayoutNavButtonList.at(i)->setIconCheck(iconCheck);

		m_FinancialLayoutNavButtonList.at(i)->setNormalBgColor(normalBgColor);
		m_FinancialLayoutNavButtonList.at(i)->setHoverBgColor(hoverBgColor);
		m_FinancialLayoutNavButtonList.at(i)->setCheckBgColor(checkBgColor);
		m_FinancialLayoutNavButtonList.at(i)->setNormalTextColor(normalTextColor);
		m_FinancialLayoutNavButtonList.at(i)->setHoverTextColor(hoverTextColor);
		m_FinancialLayoutNavButtonList.at(i)->setCheckTextColor(checkTextColor);

		connect(m_FinancialLayoutNavButtonList.at(i), &QPushButton::clicked, this, &ChuangfengDesktop::SlotFinancialLayoutOptionClick);
	}
	m_FinancialLayoutNavButtonList.at(0)->setChecked(true);
}

void ChuangfengDesktop::initReportLayoutOption()
{
	m_ReportLayoutNavButtonList << ui->report_opt_totaltask << ui->report_opt_payable << 
		ui->report_opt_share << ui->report_opt_signal << ui->report_opt_materiel <<
		 ui->report_opt_totalfeed ;
	QList<QChar> pixChar;
	pixChar << 0xf570 << 0xf3d1 << 0xf0b2 << 0xf1e1 << 0xf55f << 0xf54f ;
	QColor normalBgColor = QColor("#44474D");
	QColor hoverBgColor = QColor("#478CB6");
	QColor checkBgColor = QColor("#478CB6");
	QColor normalTextColor = QColor("#FFFFFF");
	QColor hoverTextColor = QColor("#FFFFFF");
	QColor checkTextColor = QColor("#FFFFFF");

	for (int i = 0; i < m_ReportLayoutNavButtonList.count(); i++) {

		m_ReportLayoutNavButtonList.at(i)->setLineColor(QColor("#029FEA"));
		m_ReportLayoutNavButtonList.at(i)->setTextAlign(NavButton::TextAlign_Left);
		m_ReportLayoutNavButtonList.at(i)->setTrianglePosition(NavButton::TrianglePosition_Right);

		m_ReportLayoutNavButtonList.at(i)->setPaddingLeft(5);
		m_ReportLayoutNavButtonList.at(i)->setLineSpace(1);
		m_ReportLayoutNavButtonList.at(i)->setLineWidth(5);
		m_ReportLayoutNavButtonList.at(i)->setLineColor(QColor(255, 107, 107));
		m_ReportLayoutNavButtonList.at(i)->setShowTriangle(true);

		m_ReportLayoutNavButtonList.at(i)->setShowIcon(true);
		m_ReportLayoutNavButtonList.at(i)->setIconSpace(ICOSPACE);
		m_ReportLayoutNavButtonList.at(i)->setIconSize(QSize(ICONSIZE, ICONSIZE));

		//分开设置图标
		QChar icon = pixChar.at(i);
		QPixmap iconNormal = IconHelper::Instance()->getPixmap(normalTextColor.name(), icon, ICONFONTSIZE, PIXMAPSIZE, PIXMAPSIZE);
		QPixmap iconHover = IconHelper::Instance()->getPixmap(hoverTextColor.name(), icon, ICONFONTSIZE, PIXMAPSIZE, PIXMAPSIZE);
		QPixmap iconCheck = IconHelper::Instance()->getPixmap(checkTextColor.name(), icon, ICONFONTSIZE, PIXMAPSIZE, PIXMAPSIZE);

		m_ReportLayoutNavButtonList.at(i)->setIconNormal(iconNormal);
		m_ReportLayoutNavButtonList.at(i)->setIconHover(iconHover);
		m_ReportLayoutNavButtonList.at(i)->setIconCheck(iconCheck);

		m_ReportLayoutNavButtonList.at(i)->setNormalBgColor(normalBgColor);
		m_ReportLayoutNavButtonList.at(i)->setHoverBgColor(hoverBgColor);
		m_ReportLayoutNavButtonList.at(i)->setCheckBgColor(checkBgColor);
		m_ReportLayoutNavButtonList.at(i)->setNormalTextColor(normalTextColor);
		m_ReportLayoutNavButtonList.at(i)->setHoverTextColor(hoverTextColor);
		m_ReportLayoutNavButtonList.at(i)->setCheckTextColor(checkTextColor);

		connect(m_ReportLayoutNavButtonList.at(i), &QPushButton::clicked, this, &ChuangfengDesktop::SlotReportLayoutOptionClick);
	}
	m_ReportLayoutNavButtonList.at(0)->setChecked(true);
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

void ChuangfengDesktop::SlotFinancialLayoutOptionClick()
{
	NavButton *btn = (NavButton *)sender();
	for (int i = 0; i < m_FinancialLayoutNavButtonList.count(); i++) {
		if (m_FinancialLayoutNavButtonList.at(i) == btn)
		{
			ui->financial_StackedWidget->setCurrentIndex(i);
			m_FinancialLayoutNavButtonList.at(i)->setChecked(true);
		}
		else {
			m_FinancialLayoutNavButtonList.at(i)->setChecked(false);
		}
	}
}

void ChuangfengDesktop::SlotReportLayoutOptionClick()
{
	NavButton *btn = (NavButton *)sender();
	for (int i = 0; i < m_ReportLayoutNavButtonList.count(); i++) {
		if (m_ReportLayoutNavButtonList.at(i) == btn)
		{
			ui->Report_StackedWidget->setCurrentIndex(i);
			m_ReportLayoutNavButtonList.at(i)->setChecked(true);
		}
		else {
			m_ReportLayoutNavButtonList.at(i)->setChecked(false);
		}
	}
}
