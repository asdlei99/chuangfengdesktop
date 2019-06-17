#include "costShareObject.h"
#include "QExcel.h"



costShareObject::costShareObject(QString _strTablePath)
	:m_strTablePath(_strTablePath)
{
}


costShareObject::~costShareObject()
{
}

bool costShareObject::FillTableData(map<QString, shareStruct>_areaShare)
{
	InitTableForm();
	QExcel object(m_strTablePath);
	object.selectSheet("Sheet1");
	int iInsertRaw = m_iDataStartRaw;
	for (auto&kvp : _areaShare)
	{
		object.setCellString(iInsertRaw, 1, kvp.first);
		object.setCellString(iInsertRaw, 2, QString::number(kvp.second.dbCost));
		object.setCellString(iInsertRaw, 3, QString::number(kvp.second.dbFeedMedicine));
		object.setCellString(iInsertRaw, 4, QString::number(kvp.second.dbMatter));
		object.setCellString(iInsertRaw, 5, QString::number(kvp.second.dbFixedAssets));
		iInsertRaw++;
	}

	object.setBorder(m_iDataStartRaw - 1, iInsertRaw, 1, 8);

	object.save();
	return true;
}

bool costShareObject::InitTableForm()
{
	QExcel object(m_strTablePath);
	object.selectSheet("Sheet1");
	object.mergeCells("A1:E1");
	object.mergeCells("A2:E2");
	object.setCellString("A1", QString::fromLocal8Bit("创丰五月份区域分摊表"), EnumTextAliPos::Center, 18, true);
	object.setCellString("A2", QString::fromLocal8Bit("单位：元"), EnumTextAliPos::Right, 14, false);
	object.setCellString("A3", QString::fromLocal8Bit("区域\\项目"), EnumTextAliPos::Center, 14, true);
	object.setCellString("B3", QString::fromLocal8Bit("费用"), EnumTextAliPos::Center, 14, true);
	object.setCellString("C3", QString::fromLocal8Bit("饲料药品"), EnumTextAliPos::Center, 14, true);
	object.setCellString("D3", QString::fromLocal8Bit("物料"), EnumTextAliPos::Center, 14, true);
	object.setCellString("E3", QString::fromLocal8Bit("固定资产"), EnumTextAliPos::Center, 14, true);
	object.setColumnWidth(1, 16);
	object.setColumnWidth(3, 14);
	object.setColumnWidth(4, 14);
	object.setColumnWidth(2, 14);
	object.setColumnWidth(5, 24);
	object.save();
	return true;
}
