#pragma once
#include "QtCustomBaseWnd.h"
#include "ui_NopayManagerQWidget.h"
#include "CCheckBoxHeaderView.h"
#include "commomdef.h"


class NoPayLayoutManager :public MoveableFramelessWindow
{
	Q_OBJECT
public:
	NoPayLayoutManager(QWidget *parent = Q_NULLPTR);
	~NoPayLayoutManager();
private slots:
	void updateMaximize();
	void slotCheckBoxStateChanged(bool status);
	void SlotMsgPop(QString msg, int errorcode);
	void SlotAddNopayDetail(QString&time,QString&suplier,QString&adjust,QString&newAdd,QString&returnValue,QString&pay,QString&remake);
	void SlothreadAddnopay();
	void SlotSearchThread();
	void SlotThreadRemoveItem();
private:
	virtual void mouseDoubleClickEvent(QMouseEvent *event);
	void paintEvent(QPaintEvent *event);
	virtual QWidget*getDragnWidget();
	void AddTableViewItem(noPayDetailItem&item);
	
signals:
	void sig_NotifyMsg(QString msg, int errorCode);
private:
	virtual void InitLayout();
	Ui::nopayManager* ui;
	CCheckBoxHeaderView * m_pViewHeadDeleagte;
	QStandardItemModel *m_pViewModel;
private:
	QString m_strTime;
	QString m_strSuplier;
	QString  m_remake;
	QString m_adjust;
	QString m_newadd;
	QString m_returnValue;
	QString m_pay;
};

