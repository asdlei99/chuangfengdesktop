#pragma once
#include "QtCustomBaseWnd.h"
#include "ui_commonDependenceAreaWidget.h"

enum PopDependenceWidgetEnum
{
	enShareItemLayout = 1,
	enDetailAreaLayout
};
class CommonDependenceWidget :
	public MoveableFramelessWindow
{
public:
	CommonDependenceWidget(PopDependenceWidgetEnum type, QWidget *parent = Q_NULLPTR);
	~CommonDependenceWidget();
private:
	virtual QWidget*getDragnWidget();
private:
	Ui::CommondenpendenceWidget *ui;
	PopDependenceWidgetEnum m_enWidgetType;
};

