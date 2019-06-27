#pragma once
#include "BaseLayoutManager.h"
class CategoryLayoutManager :
	public BaseLayoutManager
{
	Q_OBJECT
public:
	CategoryLayoutManager(Ui::ChuangfengDesktopClass*ui);
	~CategoryLayoutManager();
public slots:
	void SlotAddCategory(QString&itemName, QString &remake);
	void SlotRemoveCategoryItem();
	void SlotThreadRemoveItem();
	void SlotThreadAddItem();
signals:
	void sig_NotifyMsg(QString msg, int errorCode);
public:
	void threadGetCategoryInfoCallBack();
private:
	virtual void InitLayout();
	void AddTableViewItem(int id, QString Category);
private:
	QString m_addName;
};

