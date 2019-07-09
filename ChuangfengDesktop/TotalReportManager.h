#pragma once
#include "QtCustomBaseWnd.h"
#include "ui_TotalReportManagerQWidget.h"
#include "CCheckBoxHeaderView.h"
#include <map>
#include "StatementObject.h"
using namespace  std;




class TotalReportManager :public MoveableFramelessWindow
{
	Q_OBJECT
public:
	TotalReportManager(QWidget *parent = Q_NULLPTR);
	~TotalReportManager();
private slots:
	void updateMaximize();
	void slotCheckBoxStateChanged(bool status);
	void SlotSearchBtnAction();
	void SlotThreadSearchGeneral();
	void FormatTableView();
	void AddGeneralTableview();
	void SlotThreadExportReport();
	void finishedThreadBtnSlot();

private:
	virtual void mouseDoubleClickEvent(QMouseEvent *event);
	void paintEvent(QPaintEvent *event);
	virtual QWidget*getDragnWidget();
private:
	virtual void InitLayout();
	Ui::totalreportmanager* ui;
	QStandardItemModel *m_pViewModel;
	map<QString, tableViewItemStruct> m_tableViewMap;

	double m_initGeneral = 0;
	double m_initBak = 0;
	QString m_ExcelPath = "";
};

