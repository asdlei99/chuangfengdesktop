#pragma once
#include <QObject>
#include <map>
using namespace std;
struct shareStruct
{
	shareStruct() {
		dbCost = 0;
		dbFeedMedicine = 0;
		dbMatter = 0;
		dbFixedAssets = 0;
	}
	double dbCost;
	double dbFeedMedicine;
	double dbMatter;
	double dbFixedAssets;
};

class costShareObject :public QObject
{
	Q_OBJECT
public:
	costShareObject(QString _strTablePath);
	~costShareObject();
public:
	bool FillTableData(map<QString, shareStruct>_areaShare);
private:
	bool InitTableForm();
private:
	QString m_strTablePath;
	const int m_iDataStartRaw = 3;
};