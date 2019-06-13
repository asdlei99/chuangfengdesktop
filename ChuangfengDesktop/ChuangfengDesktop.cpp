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

ChuangfengDesktop::ChuangfengDesktop(QWidget *parent)
	:
	MoveableFramelessWindow(parent),
	ui(new Ui::ChuangfengDesktopClass)
{
	ui->setupUi(this);
	connect(ui->close_btn, &QPushButton::clicked, this, &ChuangfengDesktop::close);
	connect(ui->max_restore_btn, &QPushButton::clicked, this, &ChuangfengDesktop::updateMaximize);
	connect(ui->min_btn, &QPushButton::clicked, this, &QWidget::showMinimized);
	showMaximized();
	m_nBorderWidth = 5;
	ui->max_restore_btn->setToolTip(QString::fromLocal8Bit("还原"));
	//设置按钮的属性名为"maximizeProperty"
	ui->max_restore_btn->setProperty("maximizeProperty", "restore");
	ui->max_restore_btn->setStyle(QApplication::style());
// 	setStyleSheet(QString("#min_btn {border-image:url(%1)0 0 31 0}")
// 		.append("#min_btn:pressed {border-image:url(%1)44 0 88 0}")
// 		.append("#min_btn:hover {border-image:url(%1)88 0 44 0}")
// 		.append("#min_btn:disabled {border-image:url(%1)132 0 0 0}")
// 		.arg(":/images/install.png")
// 	);
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
		painter.fillPath(path, QBrush(QColor(68, 71, 77)));
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
