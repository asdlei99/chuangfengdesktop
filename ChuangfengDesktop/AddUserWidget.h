#pragma once
#include "QtCustomBaseWnd.h"
#include "ui_addUserWidget.h"
class AddUserWidget :
	public MoveableFramelessWindow
{
public:
	AddUserWidget(QWidget *parent = Q_NULLPTR);
	~AddUserWidget();
private:
	virtual QWidget*getDragnWidget();
private:
	Ui::adduserWidget *ui;
};

