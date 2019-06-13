#pragma once
#include "QtCustomBaseWnd.h"
#include "ui_ChuangfengDesktop.h"

class ChuangfengDesktop :  public MoveableFramelessWindow
{
	Q_OBJECT

public:
	ChuangfengDesktop(QWidget *parent = Q_NULLPTR);
	void close();
	//双击标题栏进行界面的最大化/还原
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
	int m_nBorderWidth; //m_nBorder表示鼠标位于边框缩放范围的宽度
};
