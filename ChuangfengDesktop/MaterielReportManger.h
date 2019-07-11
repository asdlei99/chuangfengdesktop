#pragma once
#include "QtCustomBaseWnd.h"
#include "ui_MaterielReportManagerQWidget.h"
#include "CCheckBoxHeaderView.h"
#include "MatterObject.h"
class MaterielReportManger :public MoveableFramelessWindow
{
	Q_OBJECT
public:
	MaterielReportManger(QWidget *parent = Q_NULLPTR);
	~MaterielReportManger();
	const int mouthMax[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
private slots:
	void updateMaximize();
	void slotCheckBoxStateChanged(bool status);
	void SlotThreadGetMaterialInfo();
private:
	virtual void mouseDoubleClickEvent(QMouseEvent *event);
	void paintEvent(QPaintEvent *event);
	virtual QWidget*getDragnWidget();
	void  getMaterialTotalPrice(double&all);
	void  getInComeMaterialSearchTime();
	void  getInComeMaterialCurrentTime(double&add);
	void  getFixedUseCurrentTime(double&value);
	void  getOutMaterialCurrentTime(double&value);
	void  getOutMaterialUse();
	void  getFixedUse();
	void  getFixedAsset();
	void AddTableView();
private:
	virtual void InitLayout();
	Ui::materielreport* ui;
	QStandardItemModel *m_pViewModel;
	double m_initAmount = 0;
	double m_currentAmout = 0;
	double m_FixedUse = 0;
	map<QString, double> m_materialUseList;
	map<QString, tuple<double, double>> m_fixedList;
};
