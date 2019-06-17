#pragma once

#include <QObject>
#include <map>
using namespace std;
struct singleShareStruct
{
	singleShareStruct() {

		areaName = "";
		dbFeed = 0;
		dbMedicine = 0;
	}
	QString areaName;
	double dbFeed;
	double dbMedicine;

};

class singleAreaShare :public QObject
{
	Q_OBJECT
public:
	singleAreaShare(QString _strTablePath);
	~singleAreaShare();
public:
	bool FillTableData(map<QString, singleShareStruct>_areaShare);
private:
	bool InitTableForm();
private:
	QString m_strTablePath;
	const int m_iDataStartRaw = 3;
};