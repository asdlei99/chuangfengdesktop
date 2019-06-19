#pragma once
#include "BaseLayoutManager.h"
class DetailAreaLayoutManager :
	public BaseLayoutManager
{
public:
	DetailAreaLayoutManager(Ui::ChuangfengDesktopClass*ui);
	~DetailAreaLayoutManager();
private:
	virtual void InitLayout();
};

