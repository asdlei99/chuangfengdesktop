#include "singleAreaShare.h"
#include "QExcel.h"
#include <windows.h>



singleAreaShare::singleAreaShare(QString _strTablePath, map<QString, singleShareStruct>&_list)
	:m_strTablePath(_strTablePath)
	,m_list(_list)
{
}


singleAreaShare::~singleAreaShare()
{
}

void singleAreaShare::run()
{
	CoInitializeEx(NULL, COINIT_MULTITHREADED);
	QExcel::copyFileToPath("singleareashare.xlsx", m_strTablePath, true);
	QExcel object(m_strTablePath);
	object.selectSheet(1);
// 	object.mergeCells("A1:D1");
// 	object.mergeCells("A2:D2");
// 	object.setCellString("A1", QString::fromLocal8Bit("X区X月份单塘分摊表"), EnumTextAliPos::Center, 18, true);
// 	object.setCellString("A2", QString::fromLocal8Bit("单位：元"), EnumTextAliPos::Right, 14, false);
// 	object.setCellString("A3", QString::fromLocal8Bit("塘号"), EnumTextAliPos::Center, 14, true);
// 	object.setCellString("B3", QString::fromLocal8Bit("饲料"), EnumTextAliPos::Center, 14, true);
// 	object.setCellString("C3", QString::fromLocal8Bit("药品"), EnumTextAliPos::Center, 14, true);
// 	object.setCellString("D3", QString::fromLocal8Bit("消毒"), EnumTextAliPos::Center, 14, true);
// 	object.setCellString("E3", QString::fromLocal8Bit("合计"), EnumTextAliPos::Center, 14, true);

// 	object.setColumnWidth(1, 16);
// 	object.setColumnWidth(3, 14);
// 	object.setColumnWidth(4, 14);
// 	object.setColumnWidth(2, 14);
	int iInsertRaw = m_iDataStartRaw;
	double a = 0, b = 0, c = 0;
	for (auto&kvp : m_list)
	{
		object.setCellString(iInsertRaw, 1, kvp.first);
		object.setCellString(iInsertRaw, 2, QString::number(kvp.second.dbFeed));
		a += kvp.second.dbFeed;
		b += kvp.second.dbDrug;
		object.setCellString(iInsertRaw, 3, QString::number(kvp.second.dbDrug));
		object.setCellString(iInsertRaw, 4, QString::number(kvp.second.dbDisinfect));
		c += kvp.second.dbDisinfect;
		object.setCellString(iInsertRaw, 5, QString::number(kvp.second.dbFeed + kvp.second.dbDrug +kvp.second.dbDisinfect));
		iInsertRaw++;
	}
	object.setCellString(iInsertRaw, 1,QString::fromLocal8Bit("合计"));
	object.setCellString(iInsertRaw, 2, QString::number(a));
	object.setCellString(iInsertRaw, 3, QString::number(b));
	object.setCellString(iInsertRaw, 4, QString::number(c));
	object.setCellString(iInsertRaw, 5, QString::number(a+b+c));
	object.setBorder(m_iDataStartRaw - 1, iInsertRaw, 1,5);

	object.save();
	return ;
}


