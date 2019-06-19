#pragma once
#include "BaseLayoutManager.h"
#include "CCheckBoxHeaderView.h"
class GeneralLayoutManger
	:public BaseLayoutManager
{
	Q_OBJECT
public:
	GeneralLayoutManger(Ui::ChuangfengDesktopClass*ui);
	~GeneralLayoutManger();
private:
	virtual void InitLayout();
};

