#pragma once
#include "BaseLayoutManager.h"
class CategoryLayoutManager :
	public BaseLayoutManager
{
public:
	CategoryLayoutManager(Ui::ChuangfengDesktopClass*ui);
	~CategoryLayoutManager();
private:
	virtual void InitLayout();
};

