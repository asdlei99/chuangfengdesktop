#pragma once
#include "QtCustomBaseWnd.h"
#include "ui_addFundDetailWidget.h"
enum PopFundDetailEnum
{
	enGeneralLayout = 1,
	enBakLayout
};

class AddFundDetailWidget :
	public MoveableFramelessWindow
{
public:
	AddFundDetailWidget(PopFundDetailEnum type, QWidget *parent = Q_NULLPTR);
	~AddFundDetailWidget();
private:
	virtual QWidget*getDragnWidget();
private:
	Ui::addFundDetailWidget *ui;
	PopFundDetailEnum m_enWidgetType;
};

