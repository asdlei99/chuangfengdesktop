#pragma once
#include "BaseLayoutManager.h"
class TotalReportManager :
	public BaseLayoutManager
{
public:
	TotalReportManager(Ui::ChuangfengDesktopClass*ui);
	~TotalReportManager();
private:
	virtual void InitLayout();
};

