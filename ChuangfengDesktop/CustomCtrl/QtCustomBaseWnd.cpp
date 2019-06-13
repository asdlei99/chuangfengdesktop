#include "QtCustomBaseWnd.h"
#include <QKeyEvent>
#include <QMouseEvent>
#include <QRect>
#include <QPoint>
#include <QGridLayout>
#include <QPainter>
#include <QPen>
#include <QtMath>
#include <QHeaderView>
#include "NoFocusDelegate.h"

MoveableFramelessWindow::MoveableFramelessWindow(QWidget *parent) :
	QWidget(parent),
	isMove(false)
{
	//设置窗体为无边框
	this->setWindowFlags(Qt::FramelessWindowHint);
	//设置底层背景透明
	setAttribute(Qt::WA_TranslucentBackground);
}

void MoveableFramelessWindow::paintEvent(QPaintEvent *event)
{
	QPainterPath path;
	path.setFillRule(Qt::WindingFill);
	path.addRect(10, 10, this->width() - 20, this->height() - 20);
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing, true);
	painter.fillPath(path, QBrush(Qt::white));

	QColor color(0, 0, 0, 50);
	for (int i = 0; i < 10; i++)
	{
		QPainterPath path;
		path.setFillRule(Qt::WindingFill);
		path.addRect(10 - i, 10 - i, this->width() - (10 - i) * 2, this->height() - (10 - i) * 2);
		color.setAlpha(150 - qSqrt(i) * 50);
		painter.setPen(color);
		painter.drawPath(path);
	}
}

void MoveableFramelessWindow::mousePressEvent(QMouseEvent *event)
{
	//判断位置
	bool shouldMove = isPointInDragnWidget(getDragnWidget(), event->pos());

	if (shouldMove) {
		pressedPoint = event->pos();
		isMove = true;
	}

	event->ignore();

}

void MoveableFramelessWindow::mouseMoveEvent(QMouseEvent *event)
{
	if ((event->buttons() == Qt::LeftButton) && isMove == true) {

		QPoint currPoint = this->pos();
		currPoint.setX(currPoint.x() + event->x() - pressedPoint.x());
		currPoint.setY(currPoint.y() + event->y() - pressedPoint.y());
		this->move(currPoint);
	}
}

void MoveableFramelessWindow::mouseReleaseEvent(QMouseEvent *event)
{
	isMove = false;

}

bool MoveableFramelessWindow::isPointInDragnWidget(const QWidget *widget, const QPoint &point)
{
	//判断位置
	QRect rect = widget->rect();

	bool isIn = point.x() >= rect.left() && point.x() <= rect.right() && point.y() >= rect.top() && point.y() <= rect.bottom();

	return isIn;
}

void MoveableFramelessWindow::onSetTableAttribute(QTableView *pTableView, const int cloum)
{
	
	pTableView->setItemDelegate(new NoFocusDelegate());
	for (auto i =0;i< cloum-1;i++)
	{
		pTableView->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Interactive);
	}
	pTableView ->horizontalHeader()->setStretchLastSection(true);

	pTableView->verticalHeader()->setDefaultSectionSize(30); //设置行高
	pTableView->setFrameShape(QFrame::Box); //设置无边框
	pTableView->setShowGrid(false); //设置不显示格子线
	pTableView->verticalHeader()->setVisible(false); //设置垂直头不可见
	pTableView->setSelectionBehavior(QAbstractItemView::SelectRows);  //设置选择行为时每次选择一行
	pTableView->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置不可编辑
	pTableView->verticalHeader()->setHidden(true);
	//点击表时不对表头行光亮（获取焦点） 
	pTableView->horizontalHeader()->setHighlightSections(false);
}
