#pragma once
#include <QObject>
#include <map>
using namespace  std;

struct non_paymentStruct //应付款总表数据结构
{
	non_paymentStruct() {
		dbOpeningBalance = 0;
		dbDeductio = 0;
		dbAdd = 0;
		dbReturn = 0;
		dbPay = 0;
		strMark = "";
		dbRemainingSum = 0;
	}
	QString strMark;
	double dbOpeningBalance;
	double dbDeductio;
	double dbAdd;
	double dbReturn;
	double dbPay;
	double dbRemainingSum;

};

class non_paymentObject :public QObject
{
	Q_OBJECT
public:
	non_paymentObject(QString _strTablePath);
	~non_paymentObject();
public:
	bool FillTableData(map<QString, non_paymentStruct> _dataMap);
private:
	bool InitTableForm();
private:
	QString m_strTablePath;
	const int m_iDataStartRaw = 4;
};
