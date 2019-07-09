#pragma once
#include <QObject>
#include <QWidget>
#include <QPoint>
#include <QTableView>
/**
* @brief �ޱ߿���
*/
class MoveableFramelessWindow : public QWidget
{
	Q_OBJECT
public:
	explicit MoveableFramelessWindow(QWidget *parent);


protected:
	void paintEvent(QPaintEvent *event);
	/**
	* @brief ��갴�£�׼���϶�����
	* @param event
	*/
	void mousePressEvent(QMouseEvent *event);

	/**
	* @brief ����ƶ����������϶�
	* @param event
	*/
	void mouseMoveEvent(QMouseEvent *event);

	/**
	* @brief �ͷ����
	* @param event
	*/
	void mouseReleaseEvent(QMouseEvent *event);


	/**
	* @brief ��ȡ���϶��ؼ�������������ָ��
	* @return
	*/
	virtual QWidget*getDragnWidget() = 0;

	/**
	* @brief �ж��������λ���Ƿ������϶�����
	* @param widget ���϶��ؼ�λ��
	* @param point  �����λ��
	* @return
	*/
	bool isPointInDragnWidget(const QWidget*widget, const QPoint &point);

	/**
	* @brief ��־�Ƿ��ƶ�����
	*/
	bool isMove;

	/**
	* @brief ��갴��ȥ�ĵ�
	*/
	bool nativeEvent(const QByteArray &eventType, void *message, long *result);
	QPoint pressedPoint;
protected slots:
	//����ı�
	virtual void onThemeColorChange(QString colorStr) {}
	virtual void onSetTableAttribute(QTableView *pTableView,const int cloum,bool bStretchLast = true);
	void SlotMsgPop(QString msg, int errorcode);
protected:
	bool exportToExcel( QString&excelPath);

signals:
	void sig_NotifyMsg(QString msg, int errorCode);

protected:
	int m_nBorderWidth; //m_nBorder��ʾ���λ�ڱ߿����ŷ�Χ�Ŀ��
};
