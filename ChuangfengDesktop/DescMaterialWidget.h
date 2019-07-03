#pragma once
#include "QtCustomBaseWnd.h"
#include "ui_DescMaterialWidget.h"
#include "globalVariable.h"
class DescMaterialWidget :
	public MoveableFramelessWindow
{
	Q_OBJECT
public:
	DescMaterialWidget(QString&subject,QString&price,int&number,QWidget *parent = Q_NULLPTR);
	~DescMaterialWidget();
private:
	virtual QWidget*getDragnWidget();
signals:
	void sig_commit(int&number, QString&time, QString&area);
private:
	Ui::DescMaterialWidget*ui;
	QString m_subject;
	QString m_price;
	int m_maxNumber;
};

