#pragma once
#include <QObject>
#include <map>
#include <tuple>
using namespace std;
class WarehouseObject :public QObject
{
	Q_OBJECT

public:
	WarehouseObject(QString _strTablePath);
	~WarehouseObject();
public:
	bool FillTableData(map<QString,  tuple<double, double> >_TotaldataMap, map<QString, tuple<double, double> >_subdataMap);
private:
	bool InitTableForm();
private:
	QString m_strTablePath;
	const int m_iDataStartRaw = 4;
};

