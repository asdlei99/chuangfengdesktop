#pragma once
#include <map>
#include <tuple>
#include <QObject>
using namespace std;


struct  tableViewItemStruct
{
	unsigned short bType = 0; //змеЫ 0x01,0x10
	double generalIncome = 0;
	double  generalPay = 0;
	double bakIncome = 0;
	double  bakPay = 0;
};

class StatementObject :public QObject
{
	Q_OBJECT

public:
	StatementObject(QString _strTablePath);
	~StatementObject();
public:
	bool FillTableData(double initGeneral,double initBak, map<QString, tableViewItemStruct> _dataMap);
private:
	bool InitTableForm();
private:
	QString m_strTablePath;
	const int m_iDataStartRaw = 5;
};

