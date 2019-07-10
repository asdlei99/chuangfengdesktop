#pragma once
#include <map>
#include <tuple>
#include <QThread>
using namespace std;


struct  tableViewItemStruct
{
	unsigned short bType = 0; //змеЫ 0x01,0x10
	double generalIncome = 0;
	double  generalPay = 0;
	double bakIncome = 0;
	double  bakPay = 0;
};

class StatementObject :public QThread
{
	Q_OBJECT

public:
	StatementObject(QString&path, double initGeneral, double initBak, map<QString, tableViewItemStruct> &list);
	~StatementObject();
private:
	virtual void run();
private:
	QString m_strTablePath;
	const int m_iDataStartRaw = 5;
	map<QString, tableViewItemStruct> m_list;
	double m_initGeneral;
	double m_initBak;
};

