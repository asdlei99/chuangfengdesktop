#pragma once
#include "BaseLayoutManager.h"
class CategoryLayoutManager :
	public BaseLayoutManager
{
public:
	CategoryLayoutManager(Ui::ChuangfengDesktopClass*ui);
	~CategoryLayoutManager();
public:
	virtual void InitLayout();
};

