#pragma once
#include "QtCustomBaseWnd.h"
#include "ui_materialStorgeWidget.h"

class AddMaterialWidget :
	public MoveableFramelessWindow
{
public:
	AddMaterialWidget(QWidget *parent = Q_NULLPTR);
	~AddMaterialWidget();
private:
	virtual QWidget*getDragnWidget();
private:
	Ui::materialStorgeWidget*ui;
};

