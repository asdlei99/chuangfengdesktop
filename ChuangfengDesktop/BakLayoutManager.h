#pragma once
#include "BaseLayoutManager.h"
class BakLayoutManager :
	public BaseLayoutManager
{
public:
	BakLayoutManager(Ui::ChuangfengDesktopClass*ui);
	~BakLayoutManager();
private:
	virtual void InitLayout();
};

