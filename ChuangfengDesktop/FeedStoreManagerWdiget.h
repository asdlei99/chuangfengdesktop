#pragma once
#include "QtCustomBaseWnd.h"
#include "ui_FeedStoreQwidget.h"
#include "QNavButton.h"
#include "CCheckBoxHeaderView.h"
#include "commomdef.h"

class FeedStoreManagerWdiget :
	public MoveableFramelessWindow
{
	Q_OBJECT
public:
	FeedStoreManagerWdiget(QWidget *parent = Q_NULLPTR);
	~FeedStoreManagerWdiget();
public slots:
	void updateMaximize();
	void SlotOptionClick();
	void comboBoxValueChanged();
	void SlotDescFeedStore();
	void SlotBackFeedStore();
	void SlotSearchFeedStoreDetail_in_out_return_back();
	void SlotAddFeedStore(QString&time, QString&suplier, QString&subject_name, QString&price, QString&unit, QString&specs, QString&number);
	void SlotThreadAddFeedStore();
	void SlotPopMsg(QString msg, int errorCode);
	void SlotSearchFeedStore();
	void SlotSearchAreaFeedStore();
	void SlotSearchAreaOutFeedStore();
	void SlotThreadSearchFeedStore();
	void SlotOutFeedStorel(FeedTypeEnum &_type, int&number, QString&time, QString&area);
	void SlotThreadDescFeedStore();
	void SlotThreadSearchFeedStore_in_out_return_back();
	void SlotThreadSearchAreaFeedStore();
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
	void HideDetailTableView(FeedTypeEnum _type);
signals:
	void sig_NotifyMsg(QString msg, int errorCode);
public:
	Ui::FeedStore*ui;
	QList< NavButton*> m_NavButtonList;
	QStandardItemModel *m_pViewModelFeedTotalDetail;
	QStandardItemModel *m_pViewModelTotalDetail_in_out_return;
	QStandardItemModel *m_pViewModelTotalArea;
	QString m_time ;
	QString m_suplier;
	QString m_subject_name;
	QString m_price;
	QString m_unit;
	QString m_specs;
	QString m_number;
	int m_id = 0;
	QString m_area;
	FeedTypeEnum m_type;
};

