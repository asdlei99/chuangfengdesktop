#pragma once

#include <QObject>
#include <map>
#include <tuple>
using namespace std;
class MatterObject :public QObject
{
	Q_OBJECT

public:
	MatterObject(QString _strTablePath);
	~MatterObject();
public:
	bool FillTableData(map<QString, tuple<double, double> >_MatterdataMap, map<QString, tuple<double, double> >_sharedataMap);
private:
	bool InitTableForm();
private:
	QString m_strTablePath;
	const int m_iDataStartRaw = 4;
};



