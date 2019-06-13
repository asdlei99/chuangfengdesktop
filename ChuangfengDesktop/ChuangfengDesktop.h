#pragma once
#include "QtCustomBaseWnd.h"
#include "ui_ChuangfengDesktop.h"

class ChuangfengDesktop :  public MoveableFramelessWindow
{
	Q_OBJECT

public:
	ChuangfengDesktop(QWidget *parent = Q_NULLPTR);
	void close();
	//˫�����������н�������/��ԭ
	virtual void mouseDoubleClickEvent(QMouseEvent *event);
	void paintEvent(QPaintEvent *event);
private:
	QWidget*getDragnWidget();
	bool nativeEvent(const QByteArray &eventType, void *message, long *result);
signals:
	void CloseMainWidgetSingnal();
public slots:
	void updateMaximize();
private:
	Ui::ChuangfengDesktopClass*ui;
	int m_nBorderWidth; //m_nBorder��ʾ���λ�ڱ߿����ŷ�Χ�Ŀ��
};
