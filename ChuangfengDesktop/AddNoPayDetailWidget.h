#pragma once
#include "QtCustomBaseWnd.h"
#include "ui_addNopayDetailWidget.h"
class AddNoPayDetailWidget :
	public MoveableFramelessWindow
{
	Q_OBJECT
public:
	AddNoPayDetailWidget( QWidget *parent = Q_NULLPTR);
	~AddNoPayDetailWidget();
private:
	virtual QWidget*getDragnWidget();
private slots:
	void comboBoxValueChanged();
private:
	Ui::addNoPayDetailWidget*ui;
};

