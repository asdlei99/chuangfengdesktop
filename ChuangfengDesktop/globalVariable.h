#pragma once
#include <map>
#include <QString>
using namespace  std;

#define  TempToken "de3da0bee486fdc0449608074bfdcb73"
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
extern map<int, AreaDetailStruct> g_areaList;
extern map<int, CostAreaStruct> g_CostAreaList;


