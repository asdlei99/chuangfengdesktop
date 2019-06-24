#pragma once
#include "QtCustomBaseWnd.h"
#include "ui_addNopayDetailWidget.h"
class AddNoPayDetailWidget :
	public MoveableFramelessWindow
{
public:
	AddNoPayDetailWidget( QWidget *parent = Q_NULLPTR);
	~AddNoPayDetailWidget();
private:
	virtual QWidget*getDragnWidget();
private:
	Ui::addNoPayDetailWidget*ui;
};

