#pragma once
#include "QtCustomBaseWnd.h"
#include "ui_NoPayReportManagerQWidget.h"
#include "CCheckBoxHeaderView.h"
#include <map>
using namespace std;

struct DuesStruct
{
	QString supplier = "";
	QString abstract = "";
	double  surplus = 0;
	double initDues = 0;
	double adjustment = 0;
	double added = 0;
	double pay = 0;
	double back = 0;
};

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
private:
	virtual void mouseDoubleClickEvent(QMouseEvent *event);
	void paintEvent(QPaintEvent *event);
	virtual QWidget*getDragnWidget();
private:
	virtual void InitLayout();
	Ui::noPayReportMannger* ui;
	QStandardItemModel *m_pViewModel;
	map<QString, DuesStruct> m_DuesInfoMap;

};


