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
	void SlotAddMaterialDetail(QString&time, QString&use, QString&subject_name, QString&category, QString&price, QString&unit, QString&specs, QString&fare, QString&number);
	void SlotThreadAddMaterialDetail();
	void SlotAddFeedStore(QString&time, QString&suplier, QString&subject_name, QString&price, QString&unit, QString&specs, QString&number);
	void SlotThreadAddFeedStore();
signals:
	void sig_comit(QString&time, QString &incom, QString&pay, QString&taskName, QString&shareName, QString&remake);
private:
	QString m_addTime;
	QString m_addUse;
	QString m_addSubject_name;
	QString m_addCategory;
	QString m_addPrice;
	QString m_addUnit;
	QString m_addSpecs;
	QString m_addFare;
	QString m_addNumber;

	QString m_time;
	QString m_suplier;
	QString m_subject_name;
	QString m_price;
	QString m_unit;
	QString m_specs;
	QString m_number;
};

