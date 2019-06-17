#include "singleAreaShare.h"
#include "QExcel.h"



singleAreaShare::singleAreaShare(QString _strTablePath)
	:m_strTablePath(_strTablePath)
{
}


singleAreaShare::~singleAreaShare()
{
}

bool singleAreaShare::FillTableData(map<QString, singleShareStruct>_areaShare)
{
	InitTableForm();
	QExcel object(m_strTablePath);
	object.selectSheet("Sheet1");
	int iInsertRaw = m_iDataStartRaw;
	for (auto&kvp : _areaShare)
	{
		object.setCellString(iInsertRaw, 1, kvp.first);
		object.setCellString(iInsertRaw, 2, kvp.second.areaName);
		object.setCellString(iInsertRaw, 3, QString::number(kvp.second.dbFeed));
		object.setCellString(iInsertRaw, 4, QString::number(kvp.second.dbMedicine));
		iInsertRaw++;
	}
	object.setBorder(m_iDataStartRaw - 1, iInsertRaw, 1, 8);

	object.save();
	return true;
}

bool singleAreaShare::InitTableForm()
{
	QExcel object(m_strTablePath);
	object.selectSheet("Sheet1");
	object.mergeCells("A1:D1");
	object.mergeCells("A2:D2");
	object.setCellString("A1", QString::fromLocal8Bit("C区五月份单塘分摊表"), EnumTextAliPos::Center, 18, true);
	object.setCellString("A2", QString::fromLocal8Bit("单位：元"), EnumTextAliPos::Right, 14, false);
	object.setCellString("A3", QString::fromLocal8Bit("塘号"), EnumTextAliPos::Center, 14, true);
	object.setCellString("B3", QString::fromLocal8Bit("饲料药品"), EnumTextAliPos::Center, 14, true);
	object.setCellString("C3", QString::fromLocal8Bit("消毒"), EnumTextAliPos::Center, 14, true);
	object.setCellString("D3", QString::fromLocal8Bit("合计"), EnumTextAliPos::Center, 14, true);

	object.setColumnWidth(1, 16);
	object.setColumnWidth(3, 14);
	object.setColumnWidth(4, 14);
	object.setColumnWidth(2, 14);

	object.save();
	return true;

}
