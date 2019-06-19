#pragma once
#include "BaseLayoutManager.h"
class AreaLayoutManager :
	public BaseLayoutManager
{
public:
	AreaLayoutManager(Ui::ChuangfengDesktopClass*ui);
	~AreaLayoutManager();
private:
	virtual void InitLayout();
};

