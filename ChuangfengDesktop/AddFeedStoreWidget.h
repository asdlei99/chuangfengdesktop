#pragma once
 #include "QtCustomBaseWnd.h"
#include "ui_AddFeedStoreWidget.h"

class AddFeedStoreWidget :
	public MoveableFramelessWindow
{
	Q_OBJECT
public:
	AddFeedStoreWidget(QWidget *parent = Q_NULLPTR);
	~AddFeedStoreWidget();
signals:
	void sig_commit(QString&time,  QString&subject_name, QString&price, QString&unit, QString&specs,  QString&number);
private:
	virtual QWidget*getDragnWidget();
private slots:
	void SlotCommit();
private:
	Ui::AddFeedStoreWidget*ui;
};

