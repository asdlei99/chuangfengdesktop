#pragma once
#include "QtCustomBaseWnd.h"
#include "ui_BakManagerQWidget.h"
#include "CCheckBoxHeaderView.h"

class BakLayoutManager :public MoveableFramelessWindow
{
	Q_OBJECT
public:
	BakLayoutManager(QWidget *parent = Q_NULLPTR);
	~BakLayoutManager();
private slots:
	void updateMaximize();
	void slotCheckBoxStateChanged(bool status);
private:
	virtual void mouseDoubleClickEvent(QMouseEvent *event);
	void paintEvent(QPaintEvent *event);
	virtual QWidget*getDragnWidget();
private:
	virtual void InitLayout();
	Ui::BakManager* ui;
	CCheckBoxHeaderView * m_pViewHeadDeleagte;
	QStandardItemModel *m_pViewModel;
};


