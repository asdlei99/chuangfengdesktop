#pragma once
#include <map>
#include <tuple>
#include <QObject>
using namespace std;



enum accountType {
	EN_Total = 1,
	EN_Bak
};

class StatementObject :public QObject
{
	Q_OBJECT

public:
	StatementObject(QString _strTablePath);
	~StatementObject();
public:
	bool FillTableData(map<QString, map<accountType, tuple<double, double>>> _dataMap);
private:
	bool InitTableForm();
private:
	QString m_strTablePath;
	const int m_iDataStartRaw = 5;
};

