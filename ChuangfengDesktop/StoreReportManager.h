#pragma once
#include "QtCustomBaseWnd.h"
#include "ui_StoreReportManagerQWidget.h"
#include "CCheckBoxHeaderView.h"
#include "WarehouseObject.h"
class StoreReportManager :public MoveableFramelessWindow
{
	Q_OBJECT
public:
	StoreReportManager(QWidget *parent = Q_NULLPTR);
	~StoreReportManager();
private slots:
	void updateMaximize();
	void slotCheckBoxStateChanged(bool status);
	void SlotThreadSearchShare();
	void finishedThreadBtnSlot();
private:
	virtual void mouseDoubleClickEvent(QMouseEvent *event);
	void paintEvent(QPaintEvent *event);
	virtual QWidget*getDragnWidget();
	void getCurrentStore(double&value);
	void getCurrentBackStore(double&value);
	void getCurrentUse(double&value);
	void getCurrentInCome(double&value);
	void getCurrentReturn(double&value);

	void getBackInfo();
	void getIncome();
	void getReturn();
	void getUse();

	void getAreaUse();
	void AddTableView();


private:
	virtual void InitLayout();
	Ui::storereport* ui;
	QStandardItemModel *m_pViewModel;
	double m_initAmount;
	map<QString, double> m_backList;
	map<QString, double> m_incomeList;
	map<QString, double> m_returnList;
	map<QString, double> m_useList;
	map<QString, tuple<double, double>> m_areaUseList;
};

