#pragma once
#include "BaseLayoutManager.h"
class BakLayoutManager :
	public BaseLayoutManager
{
public:
	BakLayoutManager(Ui::ChuangfengDesktopClass*ui);
	~BakLayoutManager();
public:
	virtual void InitLayout();
};

