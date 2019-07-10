#pragma once
#include "QtCustomBaseWnd.h"
#include "ui_NoPayReportManagerQWidget.h"
#include "CCheckBoxHeaderView.h"
#include <map>
#include "non_paymentObject.h"
using namespace std;



class NopayReportManger :public MoveableFramelessWindow
{
	Q_OBJECT
public:
	NopayReportManger(QWidget *parent = Q_NULLPTR);
	~NopayReportManger();
private slots:
	void updateMaximize();
	void slotCheckBoxStateChanged(bool status);
	void SlotThreadSearchBakInfo();
	void finishedThreadBtnSlot();
private:
	virtual void mouseDoubleClickEvent(QMouseEvent *event);
	void paintEvent(QPaintEvent *event);
	virtual QWidget*getDragnWidget();
	
private:
	virtual void InitLayout();
	Ui::noPayReportMannger* ui;
	QStandardItemModel *m_pViewModel;
	map<QString, DuesStruct> m_DuesInfoMap;
	QString m_ExcelPath ="";
};


