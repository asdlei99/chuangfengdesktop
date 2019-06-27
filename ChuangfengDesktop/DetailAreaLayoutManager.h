#pragma once
#include "BaseLayoutManager.h"
#include "AreaLayoutManager.h"
#include <memory>
using namespace std;
class DetailAreaLayoutManager :
	public BaseLayoutManager
{
	Q_OBJECT
public:
	DetailAreaLayoutManager(Ui::ChuangfengDesktopClass*ui, shared_ptr<AreaLayoutManager> ptrAreaLayoutManager);
	~DetailAreaLayoutManager();
public:
	void threadAreaInfoCallBack();
private:
	virtual void InitLayout();
	void AddTableViewItem(int id, QString AreaDetailName, QString AreaName);
public slots:
	void SlotAddDetailArea(QString &tagName, QString&fromName);
	void SlotThreadAddDetailArea();
signals:
	void sig_NotifyMsg(QString msg, int errorCode);
private:
	shared_ptr<AreaLayoutManager> m_ptrAreaLayoutManager;
private:
	QString m_addItemName;
	QString m_addParentName;
};

