#pragma once
#include "BaseLayoutManager.h"
class AreaLayoutManager :
	public BaseLayoutManager
{
	Q_OBJECT
public:
	AreaLayoutManager(Ui::ChuangfengDesktopClass*ui);
	~AreaLayoutManager();
	void AddTableViewItem(int id, QString AreaName);
private:
	virtual void InitLayout();
signals:
	void sig_NotifyMsg(QString msg, int errorCode);
public slots:
	void SlotAddArea(QString& name, QString&remake);
	void SlotThreadAddArea();
private:
	QString m_addName;
};

