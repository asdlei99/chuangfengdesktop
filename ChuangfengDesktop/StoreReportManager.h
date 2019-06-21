#pragma once
#include "QtCustomBaseWnd.h"
#include "ui_StoreReportManagerQWidget.h"
#include "CCheckBoxHeaderView.h"
class StoreReportManager :public MoveableFramelessWindow
{
	Q_OBJECT
public:
	StoreReportManager(QWidget *parent = Q_NULLPTR);
	~StoreReportManager();
private slots:
	void updateMaximize();
	void slotCheckBoxStateChanged(bool status);
private:
	virtual void mouseDoubleClickEvent(QMouseEvent *event);
	void paintEvent(QPaintEvent *event);
	virtual QWidget*getDragnWidget();
private:
	virtual void InitLayout();
	Ui::storereport* ui;
	QStandardItemModel *m_pViewModel;
};

