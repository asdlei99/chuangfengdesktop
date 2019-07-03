#pragma once
#include "QtCustomBaseWnd.h"
#include "ui_MaterialQWidget.h"
#include "QNavButton.h"
#include "CCheckBoxHeaderView.h"
struct InMaterialStruct
{
	
	int id = 0;
	QString time = "";
	QString subject = "";
	QString fare = "";
	QString price = "";
	int number = 0;

};
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
	void comboBoxValueChanged();
	void SlotAddMaterialDetail(QString&time, QString&use, QString&subject_name, QString&category, QString&price, QString&unit, QString&specs, QString&fare, QString&number);
	void SlotThreadAddMaterialDetail();
	void SlotPopMsg(QString msg, int errorCode);
private:
	virtual void mouseDoubleClickEvent(QMouseEvent *event);
	void paintEvent(QPaintEvent *event);
	virtual QWidget*getDragnWidget();
	void initOption();
	void initTableView();
	void ChangeDetailTableView();
	void AddInMaterial(InMaterialStruct&item);
signals:
	void sig_NotifyMsg(QString msg, int errorCode);
private:
	Ui::Material*ui;
	QList< NavButton*> m_NavButtonList;
	CCheckBoxHeaderView * m_pViewHeadDeleagteDetail;
	QStandardItemModel *m_pViewModelDetail;
	CCheckBoxHeaderView * m_pViewHeadDeleagteinout;
	QStandardItemModel *m_pViewModelinout;
	CCheckBoxHeaderView * m_pViewHeadDeleagteFix;
	QStandardItemModel *m_pViewModelFix;
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
	
};

