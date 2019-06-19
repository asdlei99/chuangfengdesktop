#pragma once
#include "BaseLayoutManager.h"
class SupplierLayoutManager :
	public BaseLayoutManager
{
public:
	SupplierLayoutManager(Ui::ChuangfengDesktopClass*ui);
	~SupplierLayoutManager();
public:
	virtual void InitLayout();
};

