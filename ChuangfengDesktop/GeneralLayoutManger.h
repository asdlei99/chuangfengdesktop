#pragma once
#include "QtCustomBaseWnd.h"
#include "ui_GeneralManagerQWidget.h"
#include "CCheckBoxHeaderView.h"

class GeneralLayoutManger:public MoveableFramelessWindow
{
	Q_OBJECT
public:
	GeneralLayoutManger(QWidget *parent = Q_NULLPTR);
	~GeneralLayoutManger();
private slots:
	void updateMaximize();
	void slotCheckBoxStateChanged(bool status);
private:
	virtual void mouseDoubleClickEvent(QMouseEvent *event);
	void paintEvent(QPaintEvent *event);
	virtual QWidget*getDragnWidget();
private:
	virtual void InitLayout();
	Ui::generalManager* ui;
	CCheckBoxHeaderView * m_pViewHeadDeleagte;
	QStandardItemModel *m_pViewModel;
};

