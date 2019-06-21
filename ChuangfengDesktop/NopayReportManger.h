#pragma once
#include "QtCustomBaseWnd.h"
#include "ui_NoPayReportManagerQWidget.h"
#include "CCheckBoxHeaderView.h"
class NopayReportManger :public MoveableFramelessWindow
{
	Q_OBJECT
public:
	NopayReportManger(QWidget *parent = Q_NULLPTR);
	~NopayReportManger();
private slots:
	void updateMaximize();
	void slotCheckBoxStateChanged(bool status);
private:
	virtual void mouseDoubleClickEvent(QMouseEvent *event);
	void paintEvent(QPaintEvent *event);
	virtual QWidget*getDragnWidget();
private:
	virtual void InitLayout();
	Ui::noPayReportMannger* ui;
	QStandardItemModel *m_pViewModel;
};


