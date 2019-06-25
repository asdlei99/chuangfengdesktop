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
	void SlotAddUser(QString&userName, QString &password, QString &role);
	void SlotRemoveUserItem(); 
private:
	virtual void InitLayout();
	void threadGetUserInfoCallBack();
	void threadAddUserInfoCallBack(QString&userName, QString &password, QString &role);
	void AddTableViewItem(int id, QString nickName, QString roleName);
};

