#pragma once
#include "BaseLayoutManager.h"
class SupplierLayoutManager :
	public BaseLayoutManager
{
	Q_OBJECT
public:
	SupplierLayoutManager(Ui::ChuangfengDesktopClass*ui);
	~SupplierLayoutManager();
public slots :
	void SlotAddSupplier(QString&itemName, QString &remake);
	void SlotRemoveSupplierItem();
private:
	virtual void InitLayout();
	void threadGetSupplierInfoCallBack();
	void AddTableViewItem(int id, QString supplierName, QString remake);
};

