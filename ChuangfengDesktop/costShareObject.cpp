#include "costShareObject.h"
#include "QExcel.h"
#include <windows.h>



costShareObject::costShareObject(map<QString, ShareInfoStruct>& _list, QString _strTablePath)
	:m_strTablePath(_strTablePath)
	,m_list(_list)
{
}


costShareObject::~costShareObject()
{
}

void costShareObject::run()
{
	CoInitializeEx(NULL, COINIT_MULTITHREADED);
	QExcel::copyFileToPath("sharereport.xlsx", m_strTablePath, true);
	QExcel object(m_strTablePath);
	object.selectSheet(1);
// 	object.mergeCells("A1:E1");
// 	object.mergeCells("A2:E2");
// 	object.setCellString("A1", QString::fromLocal8Bit("创丰X月份区域分摊表"), EnumTextAliPos::Center, 18, true);
// 	object.setCellString("A2", QString::fromLocal8Bit("单位：元"), EnumTextAliPos::Right, 14, false);
// 	object.setCellString("A3", QString::fromLocal8Bit("区域\\项目"), EnumTextAliPos::Center, 14, true);
// 	object.setCellString("B3", QString::fromLocal8Bit("费用"), EnumTextAliPos::Center, 14, true);
// 	object.setCellString("C3", QString::fromLocal8Bit("饲料药品"), EnumTextAliPos::Center, 14, true);
// 	object.setCellString("D3", QString::fromLocal8Bit("物料"), EnumTextAliPos::Center, 14, true);
// 	object.setCellString("E3", QString::fromLocal8Bit("固定资产"), EnumTextAliPos::Center, 14, true);
// 	object.setColumnWidth(1, 16);
// 	object.setColumnWidth(3, 14);
// 	object.setColumnWidth(4, 14);
// 	object.setColumnWidth(2, 14);
// 	object.setColumnWidth(5, 24);
	int iInsertRaw = m_iDataStartRaw;
	for (auto&kvp : m_list)
	{
		object.setCellString(iInsertRaw, 1, kvp.first);
		object.setCellString(iInsertRaw, 2, QString::number(kvp.second.LogisticsCosts));
		object.setCellString(iInsertRaw, 3, QString::number(kvp.second.FeedCosts));
		object.setCellString(iInsertRaw, 4, QString::number(kvp.second.MaterialCosts));
		object.setCellString(iInsertRaw, 5, QString::number(kvp.second.FixedAssetCosts));
		iInsertRaw++;
	}
	object.setBorder(m_iDataStartRaw - 1, iInsertRaw, 1, 5);
	object.save();
}


