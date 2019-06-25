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
public:
	void threadGetCategoryInfoCallBack();
private:
	virtual void InitLayout();
	void AddTableViewItem(int id, QString Category);
};

