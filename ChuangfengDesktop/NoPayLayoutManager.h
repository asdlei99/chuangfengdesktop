#pragma once
#include "BaseLayoutManager.h"
class NoPayLayoutManager :
	public BaseLayoutManager
{
public:
	NoPayLayoutManager(Ui::ChuangfengDesktopClass*ui);
	~NoPayLayoutManager();
public:
	virtual void InitLayout();
};

