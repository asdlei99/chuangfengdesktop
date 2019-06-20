#pragma once
#include "QtCustomBaseWnd.h"
#include "ui_NopayManagerQWidget.h"
#include "CCheckBoxHeaderView.h"

class NoPayLayoutManager :public MoveableFramelessWindow
{
	Q_OBJECT
public:
	NoPayLayoutManager(QWidget *parent = Q_NULLPTR);
	~NoPayLayoutManager();
private slots:
	void updateMaximize();
	void slotCheckBoxStateChanged(bool status);
private:
	virtual void mouseDoubleClickEvent(QMouseEvent *event);
	void paintEvent(QPaintEvent *event);
	virtual QWidget*getDragnWidget();
private:
	virtual void InitLayout();
	Ui::nopayManager* ui;
	CCheckBoxHeaderView * m_pViewHeadDeleagte;
	QStandardItemModel *m_pViewModel;
};

