#pragma once
#include "BaseLayoutManager.h"

class UserLayoutManger :
	public BaseLayoutManager
{
	Q_OBJECT
public:
	UserLayoutManger(Ui::ChuangfengDesktopClass*ui);
	~UserLayoutManger();
private:
	virtual void InitLayout();
};

