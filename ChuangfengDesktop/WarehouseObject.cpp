#include "WarehouseObject.h"
#include "QExcel.h"
#include <windows.h>



WarehouseObject::WarehouseObject(QString _strTablePath, double &_initAmount, map<QString, double> &_backList
	, map<QString, double> &_incomeList, map<QString, double> &_returnList, map<QString, double> &_useList,
	map<QString, tuple<double, double>> &_areaUseList)
	:m_strTablePath(_strTablePath)
	,m_initAmount(_initAmount)
	,m_backList(_backList)
	,m_areaUseList(_areaUseList)
	,m_incomeList(_incomeList)
	,m_returnList(_returnList)
	,m_useList(_useList)
{
}


WarehouseObject::~WarehouseObject()
{
}

void WarehouseObject::run()
{
	CoInitializeEx(NULL, COINIT_MULTITHREADED);
	QExcel::copyFileToPath("Warehouse.xlsx", m_strTablePath, true);
	QExcel object(m_strTablePath);
	object.selectSheet(1);
// 	object.mergeCells("A1:D1");
// 	object.mergeCells("A2:D2");
// 
// 	object.mergeCells("F1:I1");
// 	object.mergeCells("F2:I2");
// 
// 	object.setCellString("A1", QString::fromLocal8Bit("总库饲料药品出入库汇总"), EnumTextAliPos::Center, 14, true);
// 	object.setCellString("A2", QString::fromLocal8Bit("单位：元"), EnumTextAliPos::Right, 12, false);
// 
// 	object.setCellString("F1", QString::fromLocal8Bit("X月分库饲料药品用料汇总"), EnumTextAliPos::Center, 14, true);
// 	object.setCellString("F2", QString::fromLocal8Bit("单位：元"), EnumTextAliPos::Right, 12, false);
// 
// 	object.setColumnWidth(1, 16);
// 	object.setColumnWidth(3, 16);
// 	object.setColumnWidth(4, 16);
// 	object.setColumnWidth(2, 16);
// 
// 	object.setColumnWidth(6, 16);
// 	object.setColumnWidth(7, 16);
// 	object.setColumnWidth(8, 16);
// 	object.setColumnWidth(9, 16);
// 
// 	object.setCellString("A3", QString::fromLocal8Bit("项目"));
// 	object.setCellString("B3", QString::fromLocal8Bit("入库"));
// 	object.setCellString("C3", QString::fromLocal8Bit("出库"));
// 	object.setCellString("D3", QString::fromLocal8Bit("结余"));
// 
// 	object.setCellString("F3", QString::fromLocal8Bit("项目"));
// 	object.setCellString("G3", QString::fromLocal8Bit("入库"));
// 	object.setCellString("H3", QString::fromLocal8Bit("用料"));
// 	object.setCellString("I3", QString::fromLocal8Bit("结余"));

	int nCount = m_iDataStartRaw;
	double inCome = 0, out = 0;
	
/*	object.setCellString(m_iDataStartRaw, 1, QString::fromLocal8Bit("总仓期初总额"));*/
	object.setCellString(nCount, 2, QString::number(m_initAmount));
	
	inCome += m_initAmount;
	nCount++;
	for (auto kvp : m_backList)
	{
		object.setCellString(nCount, 1, kvp.first);

		
		object.setCellString(nCount, 3,QString::number(kvp.second));
		
		out += kvp.second;
		nCount++;
	}
	for (auto kvp : m_incomeList)
	{
		object.setCellString(nCount, 1, kvp.first);

		object.setCellString(nCount, 2, QString::number(kvp.second));
		inCome += kvp.second;
		nCount++;
	}
	for (auto kvp : m_returnList)
	{
		object.setCellString(nCount, 1, kvp.first);

		object.setCellString(nCount, 2, QString::number(kvp.second));
		inCome += kvp.second;
		nCount++;
	}
	for (auto kvp : m_useList)
	{
		object.setCellString(nCount, 1, kvp.first);

	
		object.setCellString(nCount, 3, QString::number(kvp.second));
	
		out += kvp.second;
		nCount++;
	}
	object.setCellString(nCount, 1, QString::fromLocal8Bit("合计"));
	object.setCellString(nCount, 2, QString::number(inCome));
	object.setCellString(nCount, 3,QString::number(out));
	object.setCellString(nCount, 4, QString::number(inCome - out));
	object.setBorder(m_iDataStartRaw - 1, nCount, 1, 4);
	inCome = 0; out = 0;
	nCount = m_iDataStartRaw;
	for (auto&kvp : m_areaUseList)
	{
		object.setCellString(nCount, 6, kvp.first);
		object.setCellString(nCount, 7, QString::number(get<0>(kvp.second)));
		inCome += get<0>(kvp.second);
		object.setCellString(nCount, 8, QString::number(get<1>(kvp.second)));
		out += get<1>(kvp.second);
		object.setCellString(nCount, 9, QString::number(get<0>(kvp.second) - get<1>(kvp.second)));
		nCount++;
	}
	object.setCellString(nCount, 6, QString::fromLocal8Bit("合计"));
	object.setCellString(nCount, 7, QString::number(inCome));
	object.setCellString(nCount, 8, QString::number(out));
	object.setCellString(nCount, 9, QString::number(inCome - out));
	object.setBorder(m_iDataStartRaw - 1, nCount, 6, 9);
	object.save();
}

