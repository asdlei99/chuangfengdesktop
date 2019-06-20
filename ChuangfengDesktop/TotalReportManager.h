#pragma once
#include "QtCustomBaseWnd.h"
#include "ui_TotalReportManagerQWidget.h"
#include "CCheckBoxHeaderView.h"


class TotalReportManager :public MoveableFramelessWindow
{
	Q_OBJECT
public:
	TotalReportManager(QWidget *parent = Q_NULLPTR);
	~TotalReportManager();
private slots:
	void updateMaximize();
	void slotCheckBoxStateChanged(bool status);
private:
	virtual void mouseDoubleClickEvent(QMouseEvent *event);
	void paintEvent(QPaintEvent *event);
	virtual QWidget*getDragnWidget();
private:
	virtual void InitLayout();
	Ui::totalreportmanager* ui;
	QStandardItemModel *m_pViewModel;
};

