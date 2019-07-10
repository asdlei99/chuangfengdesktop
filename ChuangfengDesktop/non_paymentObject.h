#pragma once
#include <QThread>
#include <map>

using namespace  std;

struct DuesStruct
{
	QString supplier = "";
	QString abstract = "";
	double  surplus = 0;
	double initDues = 0;
	double adjustment = 0;
	double added = 0;
	double pay = 0;
	double back = 0;
};

class non_paymentObject :public QThread
{
	Q_OBJECT
public:
	non_paymentObject(map<QString, DuesStruct> &_DuesInfoMap,QString _strTablePath);
	~non_paymentObject();
private:
	virtual void run();
private:
	QString m_strTablePath;
	const int m_iDataStartRaw = 4;
	map<QString, DuesStruct> m_DuesInfoMap;
};
