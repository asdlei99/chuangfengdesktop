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
private:
	shared_ptr<AreaLayoutManager> m_ptrAreaLayoutManager;
};

