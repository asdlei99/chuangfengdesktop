#pragma once
#include "BaseLayoutManager.h"
class ShareItemLayoutManager :
	public BaseLayoutManager
{
	Q_OBJECT
public:
	ShareItemLayoutManager(Ui::ChuangfengDesktopClass*ui);
	~ShareItemLayoutManager();
private:
	virtual void InitLayout();
	void AddTableViewItem(int id, QString shareItem, QString AreaName);
	void threadCostAreaInfoCallBack();
public slots:
	void SlotAddShareItem(QString &tagName, QString&fromName);
	void SlotThreadAddShareItem();
signals:
	void sig_NotifyMsg(QString msg, int errorCode);
private:
	QString m_addName;
	QString m_addfromName;
	
};

