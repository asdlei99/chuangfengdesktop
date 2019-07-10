#include "StatementObject.h"
#include "QExcel.h"
#include <QFileDialog>
#include <QAxObject>
#include <QAxWidget>
#include <windows.h>

StatementObject::StatementObject(QString&path,double initGeneral, double initBak, map<QString, tableViewItemStruct> &list)
	:m_list(list)
	,m_initGeneral(initGeneral)
	,m_initBak(initBak)
	, m_strTablePath(path)
{
}

StatementObject::~StatementObject()
{
}

bool copyFileToPath(QString sourceDir, QString toDir, bool coverFileIfExist)
{
	toDir.replace("\\", "/");
	if (sourceDir == toDir) {
		return true;
	}
	if (!QFile::exists(sourceDir)) {
		return false;
	}
	QDir *createfile = new QDir;
	bool exist = createfile->exists(toDir);
	if (exist) {
		if (coverFileIfExist) {
			createfile->remove(toDir);
		}
	}//end if

	if (!QFile::copy(sourceDir, toDir))
	{
		return false;
	}
	return true;
}


void StatementObject::run()
{
	CoInitializeEx(NULL, COINIT_MULTITHREADED);
	copyFileToPath("general.xlsx", m_strTablePath, true);
	QExcel object(m_strTablePath);
	//object.selectSheet("Sheet1");
	object.selectSheet(1);

	object.setCellString("A1", QString::fromLocal8Bit("创丰五月份总收支表"), EnumTextAliPos::Center, 18, true);
	object.setCellString("A2", QString::fromLocal8Bit("单位：元"), EnumTextAliPos::Right, 14, false);

	object.setCellString("B3", QString::fromLocal8Bit("总账收支"), EnumTextAliPos::Center, 14, true);
	object.setCellString("F3", QString::fromLocal8Bit("备用金收支"), EnumTextAliPos::Center, 14, true);
	object.setCellString("A4", QString::fromLocal8Bit("项目"));
	object.setCellString("B4", QString::fromLocal8Bit("借方"));
	object.setCellString("C4", QString::fromLocal8Bit("贷方"));
	object.setCellString("D4", QString::fromLocal8Bit("结余"));
	object.setCellString("F4", QString::fromLocal8Bit("借方"));
	object.setCellString("G4", QString::fromLocal8Bit("贷方"));
	object.setCellString("H4", QString::fromLocal8Bit("结余"));


	int iInsertRaw = m_iDataStartRaw;
	double iTotalIncom = 0, iTotalPay = 0, iBakIncom = 0, iBakPay = 0;
	iTotalIncom += m_initGeneral;
	iBakIncom += m_initBak;
	object.setCellString(iInsertRaw, 1, QString::fromLocal8Bit("总账号期初余额"));
	object.setCellString(iInsertRaw, 2, QString::number(m_initGeneral));
	iInsertRaw++;
	object.setCellString(iInsertRaw, 1, QString::fromLocal8Bit("备用金期初余额"));
	object.setCellString(iInsertRaw, 6, QString::number(m_initBak));
	iInsertRaw++;
	for (auto&kvp : m_list)
	{
		object.setCellString(iInsertRaw, 1, kvp.first);

		if (kvp.second.bType & 0x01)
		{
			object.setCellString(iInsertRaw, 2, QString::number(kvp.second.generalIncome) == "0" ? "" : QString::number(kvp.second.generalIncome));
			iTotalIncom += kvp.second.generalIncome;
			object.setCellString(iInsertRaw, 3, QString::number(kvp.second.generalPay) == "0" ? "" : QString::number(kvp.second.generalPay));
			iTotalPay += kvp.second.generalPay;
		}
		if (kvp.second.bType & 0x10)
		{
			object.setCellString(iInsertRaw, 6, QString::number(kvp.second.bakIncome) == "0" ? "" : QString::number(kvp.second.bakIncome));
			iBakIncom += kvp.second.bakIncome;
			object.setCellString(iInsertRaw, 7, QString::number(kvp.second.bakPay) == "0" ? "" : QString::number(kvp.second.bakPay));
			iBakPay += kvp.second.bakPay;
		}

		iInsertRaw++;
	}
	object.setCellString(iInsertRaw, 2, QString::number(iTotalIncom));
	object.setCellString(iInsertRaw, 3, QString::number(iTotalPay));
	object.setCellString(iInsertRaw, 4, QString::number(iTotalIncom - iTotalPay));

	object.setCellString(iInsertRaw, 6, QString::number(iBakIncom));
	object.setCellString(iInsertRaw, 7, QString::number(iBakPay));
	object.setCellString(iInsertRaw, 8, QString::number(iBakIncom - iBakPay));
	object.setBorder(m_iDataStartRaw - 1, iInsertRaw, 1, 8);
	object.save();
}
