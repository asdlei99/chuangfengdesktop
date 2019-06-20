#pragma once
#include "QtCustomBaseWnd.h"
#include "ui_FeedStoreQwidget.h"
class FeedStoreManagerWdiget :
	public MoveableFramelessWindow
{
	Q_OBJECT
public:
	FeedStoreManagerWdiget(QWidget *parent = Q_NULLPTR);
	~FeedStoreManagerWdiget();
private slots:
	void updateMaximize();
	void SlotOptionClick();
private:
	virtual void mouseDoubleClickEvent(QMouseEvent *event);
	void paintEvent(QPaintEvent *event);
	virtual QWidget*getDragnWidget();
private:
	Ui::FeedStore*ui;
	QList< NavButton*> m_NavButtonList;
};

