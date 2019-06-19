#pragma once
#include "BaseLayoutManager.h"
class NopayReportManger :
	public BaseLayoutManager
{
public:
	NopayReportManger(Ui::ChuangfengDesktopClass*ui);
	~NopayReportManger();
private:
	virtual void InitLayout();
};

