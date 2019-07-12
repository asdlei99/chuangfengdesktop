#pragma once
#include "QtCustomBaseWnd.h"
#include "ui_ShareDetailManagerQWidget.h"
#include "CCheckBoxHeaderView.h"
#include "singleAreaShare.h"

class DetailShareReportManager :public MoveableFramelessWindow
{
	Q_OBJECT
public:
	DetailShareReportManager(QWidget *parent = Q_NULLPTR);
	~DetailShareReportManager();
private slots:
	void updateMaximize();
	void slotCheckBoxStateChanged(bool status);
	void SlotThreadSearchShare();
	void finishedThreadBtnSlot();
private:
	virtual void mouseDoubleClickEvent(QMouseEvent *event);
	void paintEvent(QPaintEvent *event);
	virtual QWidget*getDragnWidget();
	void AddTableView();


private:
	virtual void InitLayout();
	Ui::detailsharereport* ui;
	QStandardItemModel *m_pViewModel;
	map<QString, singleShareStruct> m_list;
};




