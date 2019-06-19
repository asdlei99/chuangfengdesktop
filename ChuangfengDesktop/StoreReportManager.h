#pragma once
#include "BaseLayoutManager.h"
class StoreReportManager :
	public BaseLayoutManager
{
public:
	StoreReportManager(Ui::ChuangfengDesktopClass*ui);
	~StoreReportManager();
private:
	virtual void InitLayout();
};

