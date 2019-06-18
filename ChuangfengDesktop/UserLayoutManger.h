#pragma once
#include "BaseLayoutManager.h"
#include "CCheckBoxHeaderView.h"
class UserLayoutManger :
	public BaseLayoutManager
{
	Q_OBJECT
public:
	UserLayoutManger(Ui::ChuangfengDesktopClass*ui);
	~UserLayoutManger();
	virtual void InitLayout();
public slots:
	
	void slotChannelCheckBoxStateChanged(bool status);
private:
	CCheckBoxHeaderView * m_pUserMangerViewHeadDeleagte;
	QStandardItemModel *m_pUserMangerViewModel;
};

