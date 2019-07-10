#include "non_paymentObject.h"
#include "QExcel.h"
#include <windows.h>


non_paymentObject::non_paymentObject(map<QString, DuesStruct> &_DuesInfoMap, QString _strTablePath)
	:m_strTablePath(_strTablePath)
	,m_DuesInfoMap(_DuesInfoMap)
{
}


non_paymentObject::~non_paymentObject()
{
}


void non_paymentObject::run()
{
	CoInitializeEx(NULL, COINIT_MULTITHREADED);
	QExcel::copyFileToPath("nopay.xlsx", m_strTablePath, true);
	QExcel object(m_strTablePath);
	

	object.selectSheet(1);

// 	object.setCellString("A1", QString::fromLocal8Bit("创丰X月份应付款及未付款"), EnumTextAliPos::Center, 18, true);
// 	object.setCellString("A2", QString::fromLocal8Bit("单位：元"), EnumTextAliPos::Right, 14, false);
// 	object.setCellString("A3", QString::fromLocal8Bit("供应商"), EnumTextAliPos::Center, 14, true);
// 	object.setCellString("B3", QString::fromLocal8Bit("摘要"), EnumTextAliPos::Center, 14, true);
// 	object.setCellString("C3", QString::fromLocal8Bit("期初金额"), EnumTextAliPos::Center, 14, true);
// 	object.setCellString("D3", QString::fromLocal8Bit("调账或扣款"), EnumTextAliPos::Center, 14, true);
// 	object.setCellString("E3", QString::fromLocal8Bit("5月份新增应付款"), EnumTextAliPos::Center, 14, true);
// 	object.setCellString("F3", QString::fromLocal8Bit("5月份退货"), EnumTextAliPos::Center, 14, true);
// 	object.setCellString("G3", QString::fromLocal8Bit("5月份已付款"), EnumTextAliPos::Center, 14, true);
// 	object.setCellString("H3", QString::fromLocal8Bit("期末余额"), EnumTextAliPos::Center, 14, true);

	int iInsertRaw = m_iDataStartRaw;
	double dbTotalOpeningBalance = 0, dbTotalDeductio = 0,
		dbTotalAdd = 0, dbTotalReturn = 0, dbTotalPay = 0, dbTotalRemainingSum = 0;
	for (auto&kvp:m_DuesInfoMap)
	{
		
		object.setCellString(iInsertRaw, 1, kvp.first);
		object.setCellString(iInsertRaw, 2, kvp.second.abstract);
		object.setCellString(iInsertRaw, 3, QString::number(kvp.second.initDues));
		dbTotalOpeningBalance += kvp.second.initDues;
		object.setCellString(iInsertRaw, 4, QString::number(kvp.second.adjustment));
		dbTotalDeductio += kvp.second.adjustment;
		object.setCellString(iInsertRaw, 5, QString::number(kvp.second.added));
		dbTotalAdd += kvp.second.added;
		object.setCellString(iInsertRaw, 6, QString::number(kvp.second.back));
		dbTotalReturn += kvp.second.back;
		object.setCellString(iInsertRaw, 7, QString::number(kvp.second.pay));
		dbTotalPay += kvp.second.pay;
		object.setCellString(iInsertRaw, 8, QString::number(kvp.second.surplus));
		dbTotalRemainingSum += kvp.second.surplus;
		iInsertRaw++;
	}

	object.mergeCells(iInsertRaw, 1, iInsertRaw, 2);
	QString strCell = "A" + QString::number(iInsertRaw);
	object.setCellString(strCell, QString::fromLocal8Bit("小计"), EnumTextAliPos::Center, 14, false);

	object.setCellString(iInsertRaw, 3, QString::number(dbTotalOpeningBalance));
	object.setCellString(iInsertRaw, 4, QString::number(dbTotalDeductio));
	object.setCellString(iInsertRaw, 5, QString::number(dbTotalAdd));
	object.setCellString(iInsertRaw, 6, QString::number(dbTotalReturn));
	object.setCellString(iInsertRaw, 7, QString::number(dbTotalPay));
	object.setCellString(iInsertRaw, 8, QString::number(dbTotalRemainingSum));
	object.setBorder(m_iDataStartRaw - 1, iInsertRaw, 1, 8);
	object.save();

}
