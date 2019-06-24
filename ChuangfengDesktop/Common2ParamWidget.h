#pragma once
#include "QtCustomBaseWnd.h"
#include "ui_common2ParamWidget.h"

enum PopWidgetEnum
{
	enCategoryLayout = 1,
	enAreaLayout,
	enSupplierLayout,

};


class Common2ParamWidget :
	public MoveableFramelessWindow
{
public:
	Common2ParamWidget(PopWidgetEnum type,QWidget *parent = Q_NULLPTR);
	~Common2ParamWidget();
private:
	virtual QWidget*getDragnWidget();
private:
	Ui::Common2ParamWidget *ui;
	PopWidgetEnum m_enWidgetType;
};

