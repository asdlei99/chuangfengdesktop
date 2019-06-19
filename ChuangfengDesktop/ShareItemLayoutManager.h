#pragma once
#include "BaseLayoutManager.h"
class ShareItemLayoutManager :
	public BaseLayoutManager
{
public:
	ShareItemLayoutManager(Ui::ChuangfengDesktopClass*ui);
	~ShareItemLayoutManager();
private:
	virtual void InitLayout();
};

