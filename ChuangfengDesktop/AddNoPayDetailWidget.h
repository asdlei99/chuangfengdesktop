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
	void SlotCommitAction();
signals:
	void sig_commit(QString&time, QString&suplier, QString&adjust, QString&newAdd, QString&returnValue, QString&pay, QString&remake);
private:
	Ui::addNoPayDetailWidget*ui;

};

