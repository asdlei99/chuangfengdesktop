#pragma once
#include "BaseLayoutManager.h"
class ShareReportManager :
	public BaseLayoutManager
{
public:
	ShareReportManager(Ui::ChuangfengDesktopClass*ui);
	~ShareReportManager();
private:
	virtual void InitLayout();
};

