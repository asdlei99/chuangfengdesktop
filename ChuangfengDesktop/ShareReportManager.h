#pragma once
#include "QtCustomBaseWnd.h"
#include "ui_ShareReportManagerQWidget.h"
#include "CCheckBoxHeaderView.h"
#include "costShareObject.h"

class ShareReportManager 
	:public MoveableFramelessWindow
{
	Q_OBJECT
public:
	ShareReportManager(QWidget *parent = Q_NULLPTR);
	~ShareReportManager();
	const int mouthMax[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
private slots:
	void updateMaximize();
	void slotCheckBoxStateChanged(bool status);
	void SlotThreadGetCostsShare();
	void finishedThreadBtnSlot();
private:
	virtual void mouseDoubleClickEvent(QMouseEvent *event);
	void paintEvent(QPaintEvent *event);
	virtual QWidget*getDragnWidget();
	void GetGeneralCostsShare();
	
	void GetMaterialCostsShare();
	void GetFeedingCostsShare();
	void GetFixedAssetCostsShare();
	void addTableView();
	QString m_ExcelPath;

private:
	virtual void InitLayout();
	Ui::shareReport* ui;
	QStandardItemModel *m_pViewModel;
	map<QString, ShareInfoStruct> m_list;
};




