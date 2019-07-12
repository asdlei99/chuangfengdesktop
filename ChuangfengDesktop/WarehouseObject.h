#pragma once
#include <QThread>
#include <map>
#include <tuple>
using namespace std;
class WarehouseObject :public QThread
{
	Q_OBJECT

public:
	WarehouseObject(QString _strTablePath, double &_initAmount, map<QString, double> &_backList
		,map<QString, double> &_incomeList, map<QString, double> &_returnList, map<QString, double> &_useList,
		map<QString, tuple<double, double>> &_areaUseList);
	~WarehouseObject();
private:
	virtual void run();
private:
	QString m_strTablePath;
	const int m_iDataStartRaw = 4;
	double m_initAmount;
	map<QString, double> m_backList;
	map<QString, double> m_incomeList;
	map<QString, double> m_returnList;
	map<QString, double> m_useList;
	map<QString, tuple<double, double>> m_areaUseList;
};

