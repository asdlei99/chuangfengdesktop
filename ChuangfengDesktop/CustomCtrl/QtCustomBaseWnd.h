#pragma once
#include <QObject>
#include <QWidget>
#include <QPoint>
#include <QTableView>
/**
* @brief 无边框窗体
*/
class MoveableFramelessWindow : public QWidget
{
	Q_OBJECT
public:
	explicit MoveableFramelessWindow(QWidget *parent);


protected:
	void paintEvent(QPaintEvent *event);
	/**
	* @brief 鼠标按下，准备拖动窗体
	* @param event
	*/
	void mousePressEvent(QMouseEvent *event);

	/**
	* @brief 鼠标移动，处理窗体拖动
	* @param event
	*/
	void mouseMoveEvent(QMouseEvent *event);

	/**
	* @brief 释放鼠标
	* @param event
	*/
	void mouseReleaseEvent(QMouseEvent *event);


	/**
	* @brief 获取可拖动控件，必须由子类指定
	* @return
	*/
	virtual QWidget*getDragnWidget() = 0;

	/**
	* @brief 判断鼠标点击的位置是否进入可拖动区域
	* @param widget 可拖动控件位置
	* @param point  鼠标点击位置
	* @return
	*/
	bool isPointInDragnWidget(const QWidget*widget, const QPoint &point);

	/**
	* @brief 标志是否移动窗体
	*/
	bool isMove;

	/**
	* @brief 鼠标按下去的点
	*/
	bool nativeEvent(const QByteArray &eventType, void *message, long *result);
	QPoint pressedPoint;
protected slots:
	//主题改变
	virtual void onThemeColorChange(QString colorStr) {}
	virtual void onSetTableAttribute(QTableView *pTableView,const int cloum,bool bStretchLast = true);
	void SlotMsgPop(QString msg, int errorcode);
protected:
	bool exportToExcel( QString&excelPath);

signals:
	void sig_NotifyMsg(QString msg, int errorCode);

protected:
	int m_nBorderWidth; //m_nBorder表示鼠标位于边框缩放范围的宽度
};
