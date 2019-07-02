#pragma once
#include "QtCustomBaseWnd.h"
#include "ui_DescMaterialWidget.h"
#include "globalVariable.h"
class DescMaterialWidget :
	public MoveableFramelessWindow
{
public:
	DescMaterialWidget(QWidget *parent = Q_NULLPTR);
	~DescMaterialWidget();
private:
	virtual QWidget*getDragnWidget();
private:
	Ui::DescMaterialWidget*ui;
};

