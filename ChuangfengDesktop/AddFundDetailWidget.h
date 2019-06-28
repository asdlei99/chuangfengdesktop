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
	Q_OBJECT
public:
	AddFundDetailWidget(PopFundDetailEnum type, QWidget *parent = Q_NULLPTR);
	~AddFundDetailWidget();
private:
	virtual QWidget*getDragnWidget();
private:
	Ui::addFundDetailWidget *ui;
	PopFundDetailEnum m_enWidgetType;
private slots:
	void SubjectcomboBoxValueChanged();
	void SharecomboBoxValueChanged();
	void SlotCommitAction();
signals:
	void sig_comit(QString&time, QString &incom, QString&pay, QString&taskName, QString&shareName, QString&remake);
};

