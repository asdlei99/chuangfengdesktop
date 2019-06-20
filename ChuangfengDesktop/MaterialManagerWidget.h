#pragma once
#include "QtCustomBaseWnd.h"
#include "ui_MaterialQWidget.h"
#include "QNavButton.h"
class MaterialManagerWidget :
	public MoveableFramelessWindow
{
	Q_OBJECT
public:
	MaterialManagerWidget(QWidget *parent = Q_NULLPTR);
	~MaterialManagerWidget();
	//双击标题栏进行界面的最大化/还原
private slots:
	void updateMaximize();
	void SlotOptionClick();
private:
	virtual void mouseDoubleClickEvent(QMouseEvent *event);
	void paintEvent(QPaintEvent *event);
	virtual QWidget*getDragnWidget();
private:
	Ui::Material*ui;
	QList< NavButton*> m_NavButtonList;
};

