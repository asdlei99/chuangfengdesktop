#pragma once
#include "QtCustomBaseWnd.h"
#include "ui_ShareDetailManagerQWidget.h"
#include "CCheckBoxHeaderView.h"
class DetailShareReportManager :public MoveableFramelessWindow
{
	Q_OBJECT
public:
	DetailShareReportManager(QWidget *parent = Q_NULLPTR);
	~DetailShareReportManager();
private slots:
	void updateMaximize();
	void slotCheckBoxStateChanged(bool status);
private:
	virtual void mouseDoubleClickEvent(QMouseEvent *event);
	void paintEvent(QPaintEvent *event);
	virtual QWidget*getDragnWidget();
private:
	virtual void InitLayout();
	Ui::detailsharereport* ui;
	QStandardItemModel *m_pViewModel;
};




