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

struct MaterialStruct
{
	int id = 0;
	QString use = "";
	QString subject_name = "";
	QString category = "";
	QString price = "";
	QString unit = "";
	QString specs = "";
	int number = 0;
};
struct OutMaterialStruct
{
	int id = 0;
	QString strTime = "";
	QString strSubject = "";
	int number = 0;
	QString strPrice = "";
	int Surplus = 0;
	QString strTotal = "";
	QString strArea = "";

};
struct FixedAssetStruct {
	int id = 0;
	QString	subject_name = "";
		QString instorge_time = "";
		QString outstorge_time = "";
		QString number = "";
		QString price = "";
		QString unit = "";
		QString total = "";
		QString outarea = "";
			int periods = 0;
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
	void SlotThreadSearchItem();
	void SlotOutMaterial(int&number,QString&time,QString&area);
	void SlotThreadOutMaterialDetail();
	void SlotThreadSearchInoutItem();
	void SlotThreadSearchFixedAsset();
private:
	virtual void mouseDoubleClickEvent(QMouseEvent *event);
	void paintEvent(QPaintEvent *event);
	virtual QWidget*getDragnWidget();
	void initOption();
	void initTableView();
	void ChangeDetailTableView();
	void AddInMaterial(InMaterialStruct&item);
	void AddMaterialTableView(MaterialStruct&item);
	void AddOutMaterialTableView(OutMaterialStruct&item);
	void AddFixAsset(FixedAssetStruct&item);
	void SearchInMaterial();
	void SearchOutMaterial();
	
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

	QString m_outId;
	QString m_outSubject;
	QString m_outPrice;
	QString m_outNumber;
	QString m_outTime;
	QString m_outArea;
	
	

};

