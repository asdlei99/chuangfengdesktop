#pragma once
#include "BaseLayoutManager.h"
class MaterielReportManger :
	public BaseLayoutManager
{
public:
	MaterielReportManger(Ui::ChuangfengDesktopClass*ui);
	~MaterielReportManger();
private:
	virtual void InitLayout();
};

