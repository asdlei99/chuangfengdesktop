#pragma once
#include "BaseLayoutManager.h"

class UserLayoutManger :
	public BaseLayoutManager
{
	Q_OBJECT
public:
	UserLayoutManger(Ui::ChuangfengDesktopClass*ui);
	~UserLayoutManger();
public slots:
	void ActionClickAddBtnSlot();
private:
	virtual void InitLayout();
};

