#pragma once
#include "QtCustomBaseWnd.h"
#include "ui_FeedingWidget.h"
#include "QNavButton.h"
#include "CCheckBoxHeaderView.h"
#include "commomdef.h"
class FeedingManagerWidget :
	public MoveableFramelessWindow
{
	Q_OBJECT
public:
	FeedingManagerWidget(QWidget *parent = Q_NULLPTR);
	~FeedingManagerWidget();
public slots:
	void updateMaximize();
	void SlotOptionClick();
	void SlotPopMsg(QString msg, int errorCode);
	void SlotSearchAreaFeedStore();
	void SlotThreadSearchAreaFeedStore();
	void comboBoxValueChanged();
	void SlotAddFeeding(QString&time, QString&number, QString&areaItem);
	void SlotThreadAddFeeding();
	void SlotThreadSearchFeeding();
signals:
	void sig_NotifyMsg(QString msg, int errorCode);
private:
	virtual void mouseDoubleClickEvent(QMouseEvent *event);
	void paintEvent(QPaintEvent *event);
	virtual QWidget*getDragnWidget();
	void InitOption();
	void initTableView();
	void AddAreaFeedStoreTableView(AreaFeedStoreStruct&item);
	void AddAreaFeedingDetailTableViEW(AreaFeedFeedingDetailStruct&item);
private:
	Ui::FeedingWidget*ui;
	QList< NavButton*> m_NavButtonList;
	QStandardItemModel *m_pViewModelTotalArea;
	QStandardItemModel *m_pViewModelFeedingDetail;
	QString m_time;
	QString m_suplier;
	QString m_subject_name;
	QString m_price;
	QString m_unit;
	QString m_specs;
	QString m_number;
	int m_id = 0;
	QString m_area;
	QString m_areaItem;
};

