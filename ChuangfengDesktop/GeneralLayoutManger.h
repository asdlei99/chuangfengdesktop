#pragma once
#include "QtCustomBaseWnd.h"
#include "ui_GeneralManagerQWidget.h"
#include "CCheckBoxHeaderView.h"
#include "commomdef.h"

class GeneralLayoutManger:public MoveableFramelessWindow
{
	Q_OBJECT
public:
	GeneralLayoutManger(QWidget *parent = Q_NULLPTR);
	~GeneralLayoutManger();
private slots:
	void updateMaximize();
	void slotCheckBoxStateChanged(bool status);
	void SlotSearchBtnAction();
	void SlotThreadSearchGeneral();
	void SlotAddGeneral(QString&time, QString &incom, QString&pay, QString&taskName, QString&shareName, QString&remake);
	void SlotThreadAddGeneral();
	void SlotThreadRemoveItem();
private:
	virtual void mouseDoubleClickEvent(QMouseEvent *event);
	void paintEvent(QPaintEvent *event);
	virtual QWidget*getDragnWidget();
	void addTableView(DetailItemStruct&item);

private:
	virtual void InitLayout();
	Ui::generalManager* ui;
	CCheckBoxHeaderView * m_pViewHeadDeleagte;
	QStandardItemModel *m_pViewModel;
	QString m_addTime;
	QString m_addIncom;
	QString m_addPay;
	QString m_addTaskName;
	QString m_addShare;
	QString m_addRemake;
};

