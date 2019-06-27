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
	void SlotThreadRemoveItem();
	void SlotThreadAddItem();
signals:
	void sig_NotifyMsg(QString msg, int errorCode);
private:
	virtual void InitLayout();
	void threadGetSupplierInfoCallBack();
	void AddTableViewItem(int id, QString supplierName, QString remake);
private:
	QString m_addName;
	QString m_addRemake;
};

