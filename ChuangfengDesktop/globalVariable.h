#pragma once
#include <map>
#include <QString>
using namespace  std;

#define  TempToken "3caa763e27ab73863580f25e00ce5117"
struct AreaDetailStruct
{
	AreaDetailStruct() {
		areaName = "";
	}
	QString areaName;
	map<int, QString> areaDetailList;
};

struct CostAreaStruct
{
	CostAreaStruct() {
		costAreaName = "";
		areaName = "";
		areaId = 0;
	}
	QString costAreaName;
	QString  areaName;
	int areaId;
};

extern map<int, QString> g_CategoryList;
extern map<int, QString> g_SupplierList;
extern map<QString, AreaDetailStruct> g_areaList;
extern map<QString, CostAreaStruct> g_CostAreaList;




