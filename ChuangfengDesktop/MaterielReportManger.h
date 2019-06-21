#pragma once
#include "QtCustomBaseWnd.h"
#include "ui_MaterielReportManagerQWidget.h"
#include "CCheckBoxHeaderView.h"
class MaterielReportManger :public MoveableFramelessWindow
{
	Q_OBJECT
public:
	MaterielReportManger(QWidget *parent = Q_NULLPTR);
	~MaterielReportManger();
private slots:
	void updateMaximize();
	void slotCheckBoxStateChanged(bool status);
private:
	virtual void mouseDoubleClickEvent(QMouseEvent *event);
	void paintEvent(QPaintEvent *event);
	virtual QWidget*getDragnWidget();
private:
	virtual void InitLayout();
	Ui::materielreport* ui;
	QStandardItemModel *m_pViewModel;
};
