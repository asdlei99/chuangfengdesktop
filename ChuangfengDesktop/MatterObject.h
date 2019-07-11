#pragma once

#include <QThread>
#include <map>
#include <tuple>
using namespace std;


class MatterObject :public QThread
{
	Q_OBJECT
public:
	MatterObject(QString& _strTablePath, const double &_initAmount,const double& _currentAmout, double _FixedUse, map<QString, double>& _materialUseList, map<QString, tuple<double, double>> & _fixedList);
	~MatterObject();
private:
	virtual void run();
private:
	QString m_strTablePath;
	const int m_iDataStartRaw = 4;
	double m_initAmount = 0;
	double m_currentAmout = 0;
	double m_FixedUse = 0;
	map<QString, double> m_materialUseList;
	map<QString, tuple<double, double>> m_fixedList;
};



