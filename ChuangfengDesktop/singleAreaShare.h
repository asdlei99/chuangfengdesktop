#pragma once
#include <QThread>
#include <map>
using namespace std;
struct singleShareStruct
{
	double dbFeed = 0;
	double dbDrug = 0;
	double dbDisinfect = 0;
// 	double dbMateriel = 0;
// 	double dbFixed = 0;
};

class singleAreaShare :public QThread
{
	Q_OBJECT
public:
	singleAreaShare(QString _strTablePath, map<QString, singleShareStruct>&_list);
	~singleAreaShare();
private:
	virtual void run();
private:
	QString m_strTablePath;
	const int m_iDataStartRaw = 4;
	map<QString, singleShareStruct> m_list;
};