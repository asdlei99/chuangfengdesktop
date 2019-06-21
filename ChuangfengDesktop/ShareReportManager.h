#pragma once
#include "QtCustomBaseWnd.h"
#include "ui_ShareReportManagerQWidget.h"
#include "CCheckBoxHeaderView.h"
class ShareReportManager :public MoveableFramelessWindow
{
	Q_OBJECT
public:
	ShareReportManager(QWidget *parent = Q_NULLPTR);
	~ShareReportManager();
private slots:
	void updateMaximize();
	void slotCheckBoxStateChanged(bool status);
private:
	virtual void mouseDoubleClickEvent(QMouseEvent *event);
	void paintEvent(QPaintEvent *event);
	virtual QWidget*getDragnWidget();
private:
	virtual void InitLayout();
	Ui::shareReport* ui;
	QStandardItemModel *m_pViewModel;
};




