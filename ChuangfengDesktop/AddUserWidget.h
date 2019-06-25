#pragma once
#include "QtCustomBaseWnd.h"
#include "ui_addUserWidget.h"
class AddUserWidget :
	public MoveableFramelessWindow
{
	Q_OBJECT
public:
	AddUserWidget(QWidget *parent = Q_NULLPTR);
	~AddUserWidget();
signals:
	void RequestAddUser(QString&userName ,QString &password, QString &role);
public:
	void DoCommit();
private:
	virtual QWidget*getDragnWidget();
private:
	Ui::adduserWidget *ui;
};

