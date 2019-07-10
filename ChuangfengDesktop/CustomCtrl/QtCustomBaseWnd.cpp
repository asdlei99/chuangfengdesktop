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
#include "MsgPopWidget.h"
#ifdef Q_OS_WIN
#include <qt_windows.h>
#include <Windowsx.h>
#endif

MoveableFramelessWindow::MoveableFramelessWindow(QWidget *parent) :
	QWidget(parent),
	isMove(false)
	, m_nBorderWidth(5)
{
	//���ô���Ϊ�ޱ߿�
	this->setWindowFlags(Qt::FramelessWindowHint);
	//���õײ㱳��͸��
	setAttribute(Qt::WA_TranslucentBackground);
	connect(this, SIGNAL(sig_NotifyMsg(QString, int)), this, SLOT(SlotMsgPop(QString, int)));
}

void MoveableFramelessWindow::SlotMsgPop(QString msg, int errorcode)
{
	MsgPopWidget*pQtWidget = new MsgPopWidget(msg, errorcode);
	pQtWidget->setAttribute(Qt::WA_DeleteOnClose);
	pQtWidget->setWindowModality(Qt::ApplicationModal);
	pQtWidget->show();
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
	//�ж�λ��
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
	//�ж�λ��
	QRect rect = widget->rect();

	bool isIn = point.x() >= rect.left() && point.x() <= rect.right() && point.y() >= rect.top() && point.y() <= rect.bottom();

	return isIn;
}

bool MoveableFramelessWindow::nativeEvent(const QByteArray &eventType, void *message, long *result)
{
	Q_UNUSED(eventType)
		MSG *param = static_cast<MSG *>(message);

	switch (param->message)
	{
	case WM_NCHITTEST:
	{
		int nX = GET_X_LPARAM(param->lParam) - this->geometry().x();
		int nY = GET_Y_LPARAM(param->lParam) - this->geometry().y();

		// ������λ���ӿؼ��ϣ��򲻽��д���
		if (childAt(nX, nY) != nullptr)
			return QWidget::nativeEvent(eventType, message, result);

		*result = HTCAPTION;

		// �������λ�ڴ���߿򣬽�������
		if ((nX >= 0) && (nX <= m_nBorderWidth))
			*result = HTLEFT;

		if ((nX >= this->width() - m_nBorderWidth) && (nX <= this->width()))
			*result = HTRIGHT;

		if ((nY >= 0) && (nY <= m_nBorderWidth))
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

	return QWidget::nativeEvent(eventType, message, result);
}

void MoveableFramelessWindow::onSetTableAttribute(QTableView *pTableView, const int cloum,bool bStretchLast)
{
	pTableView->setItemDelegate(new NoFocusDelegate());
	for (auto i =0;i< cloum-1;i++)
	{
		pTableView->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Interactive);
	}
	pTableView ->horizontalHeader()->setStretchLastSection(bStretchLast);

	pTableView->verticalHeader()->setDefaultSectionSize(30); //�����и�
	pTableView->setFrameShape(QFrame::Box); //�����ޱ߿�
	pTableView->setShowGrid(false); //���ò���ʾ������
	pTableView->verticalHeader()->setVisible(false); //���ô�ֱͷ���ɼ�
	pTableView->setSelectionBehavior(QAbstractItemView::SelectRows);  //����ѡ����Ϊʱÿ��ѡ��һ��
	pTableView->setEditTriggers(QAbstractItemView::NoEditTriggers); //���ò��ɱ༭
	pTableView->verticalHeader()->setHidden(true);
	//�����ʱ���Ա�ͷ�й�������ȡ���㣩 
	pTableView->horizontalHeader()->setHighlightSections(false);
}
