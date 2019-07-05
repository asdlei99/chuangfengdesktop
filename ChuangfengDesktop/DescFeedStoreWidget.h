#pragma once

#include "QtCustomBaseWnd.h"
#include "ui_DescFeedStoreWidget.h"
#include "globalVariable.h"
#include "commomdef.h"

class DescFeedStoreWidget :
	public MoveableFramelessWindow
{
	Q_OBJECT
public:
	DescFeedStoreWidget(FeedTypeEnum _type,QString&subject, QString&price, int&number, QString&area, QWidget *parent = Q_NULLPTR);
	~DescFeedStoreWidget();
private:
	virtual QWidget*getDragnWidget();
signals:
	void sig_commit(FeedTypeEnum &_type,int&number, QString&time, QString&area);
private:
	Ui::DescFeedStoreWidget*ui;
	QString m_subject;
	QString m_price;
	int m_maxNumber;
	FeedTypeEnum m_type;
};


