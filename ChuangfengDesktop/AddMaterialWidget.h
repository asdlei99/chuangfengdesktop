#pragma once
#include "QtCustomBaseWnd.h"
#include "ui_materialStorgeWidget.h"

class AddMaterialWidget :
	public MoveableFramelessWindow
{
	Q_OBJECT
public:
	AddMaterialWidget(QWidget *parent = Q_NULLPTR);
	~AddMaterialWidget();
signals:
	void sig_commit(QString&time, QString&use, QString&subject_name, QString&category, QString&price, QString&unit, QString&specs,QString&fare,QString&number);
private:
	virtual QWidget*getDragnWidget();
private slots:
	void SlotCommit();
private:
	Ui::materialStorgeWidget*ui;
};

