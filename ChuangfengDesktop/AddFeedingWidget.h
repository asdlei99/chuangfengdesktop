#pragma once

#include "QtCustomBaseWnd.h"
#include "ui_AddFeedingWidget.h"

class AddFeedingWidget :
	public MoveableFramelessWindow
{
	Q_OBJECT
public:
	AddFeedingWidget(QString&subject_name,QString&price,int maxNumber,QString&areaName, QWidget *parent = Q_NULLPTR);
	~AddFeedingWidget();
signals:
	void sig_commit(QString&time,QString&number,QString&areaItem);
private:
	virtual QWidget*getDragnWidget();
private slots:
	void SlotCommit();
private:
	Ui::AddFeedingWidget*ui;
private:
	QString m_subject_name;
	QString m_price;
	int maxNumber;
	QString m_areaName;

};
