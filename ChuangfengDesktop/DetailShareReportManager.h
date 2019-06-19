#pragma once
#include "BaseLayoutManager.h"
class DetailShareReportManager :
	public BaseLayoutManager
{
public:
	DetailShareReportManager(Ui::ChuangfengDesktopClass*ui);
	~DetailShareReportManager();
private:
	virtual void InitLayout();
};

