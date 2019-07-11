#pragma once
#include <QThread>
#include <map>
using namespace std;

struct  ShareInfoStruct
{
	QString costName = "";
	double LogisticsCosts = 0.0;
	double FeedCosts = 0.0;
	double MaterialCosts = 0.0;
	double FixedAssetCosts = 0.0;

};

class costShareObject :public QThread
{
	Q_OBJECT
public:
	costShareObject(map<QString, ShareInfoStruct>& _list,QString _strTablePath);
	~costShareObject();
private:
	virtual void run();
private:
	QString m_strTablePath;
	const int m_iDataStartRaw = 4;
	map<QString, ShareInfoStruct> m_list;
};