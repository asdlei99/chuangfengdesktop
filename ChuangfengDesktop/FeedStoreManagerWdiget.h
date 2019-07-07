#pragma once
#include "QtCustomBaseWnd.h"
#include "ui_FeedStoreQwidget.h"
#include "CCheckBoxHeaderView.h"
#include "commomdef.h"

class FeedStoreManagerWdiget :
	public MoveableFramelessWindow
{
	Q_OBJECT
public:
	FeedStoreManagerWdiget(QWidget *parent = Q_NULLPTR);
	~FeedStoreManagerWdiget();
private slots:
	void updateMaximize();
	void SlotOptionClick();
	void comboBoxValueChanged();
	void SlotDescFeedStore();
	void SlotAddFeedStore(QString&time, QString&suplier, QString&subject_name, QString&price, QString&unit, QString&specs, QString&number);
	void SlotThreadAddFeedStore();
	void SlotPopMsg(QString msg, int errorCode);
private:
	virtual void mouseDoubleClickEvent(QMouseEvent *event);
	void paintEvent(QPaintEvent *event);
	virtual QWidget*getDragnWidget();
	void InitOption();
	void initTableView();
	void ChangeDetailTableView();
	void AddFeedStoreTableView(FeedStoreStruct&item);
	void AddFeedStoreIn_out_return_TableView(FeedStoreIn_out_return_Struct&item);
	void AddAreaFeedStoreTableView(AreaFeedStoreStruct&item);
signals:
	void sig_NotifyMsg(QString msg, int errorCode);
private:
	Ui::FeedStore*ui;
	QList< NavButton*> m_NavButtonList;
	CCheckBoxHeaderView * m_pViewHeadDeleagteTotalDetail;
	QStandardItemModel *m_pViewModelTotalDetail;
	CCheckBoxHeaderView * m_pViewHeadDeleagteTotal_in_out_return;
	QStandardItemModel *m_pViewModelTotalDetail_in_out_return;
	CCheckBoxHeaderView * m_pViewHeadDeleagteTotalArea;
	QStandardItemModel *m_pViewModelTotalArea;
	QString m_time ;
	QString m_suplier;
	QString m_subject_name;
	QString m_price;
	QString m_unit;
	QString m_specs;
	QString m_number;
	
};

