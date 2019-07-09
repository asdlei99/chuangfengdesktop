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

bool StatementObject::FillTableData(double initGeneral, double initBak,  map<QString, tableViewItemStruct> _dataMap)
{
	QExcel object(m_strTablePath);
	object.selectSheet("Sheet1");
	object.mergeCells("A1:H1");
	object.mergeCells("A2:H2");
	object.mergeCells("B3:D3");
	object.mergeCells("F3:H3");
	object.setCellString("A1", QString::fromLocal8Bit("创丰五月份总收支表"), EnumTextAliPos::Center, 18, true);
	object.setCellString("A2", QString::fromLocal8Bit("单位：元"), EnumTextAliPos::Right, 14, false);

	object.setCellString("B3", QString::fromLocal8Bit("总账收支"), EnumTextAliPos::Center, 14, true);
	object.setCellString("F3", QString::fromLocal8Bit("备用金收支"), EnumTextAliPos::Center, 14, true);

	object.setColumnWidth(1, 16);
	object.setColumnWidth(3, 16);
	object.setColumnWidth(4, 16);
	object.setColumnWidth(2, 16);
	object.setColumnWidth(5, 2);
	object.setColumnWidth(6, 16);
	object.setColumnWidth(7, 16);
	object.setColumnWidth(8, 16);
	object.setCellString("A4", QString::fromLocal8Bit("项目"));
	object.setCellString("B4", QString::fromLocal8Bit("借方"));
	object.setCellString("C4", QString::fromLocal8Bit("贷方"));
	object.setCellString("D4", QString::fromLocal8Bit("结余"));
	object.setCellString("F4", QString::fromLocal8Bit("借方"));
	object.setCellString("G4", QString::fromLocal8Bit("贷方"));
	object.setCellString("H4", QString::fromLocal8Bit("结余"));

	
	int iInsertRaw = m_iDataStartRaw;
	double iTotalIncom = 0, iTotalPay = 0, iBakIncom = 0, iBakPay = 0;
	iTotalIncom += initGeneral;
	iBakIncom += initBak;
	object.setCellString(iInsertRaw, 1, QString::fromLocal8Bit("总账号期初余额"));
	object.setCellString(iInsertRaw, 2, QString::number(initGeneral) );
	iInsertRaw++;
	object.setCellString(iInsertRaw, 1, QString::fromLocal8Bit("备用金期初余额"));
	object.setCellString(iInsertRaw, 6, QString::number(initBak));
	iInsertRaw++;
	for (auto&kvp : _dataMap)
	{
		object.setCellString(iInsertRaw, 1, kvp.first);
		
			if (kvp.second.bType &0x01)
			{
				object.setCellString(iInsertRaw, 2, QString::number(kvp.second.generalIncome)=="0"?"": QString::number(kvp.second.generalPay));
				iTotalIncom += kvp.second.generalIncome;
				object.setCellString(iInsertRaw, 3, QString::number(kvp.second.generalPay) == "0" ? "" : QString::number(kvp.second.generalPay));
				iTotalPay += kvp.second.generalPay;
			}
			if(kvp.second.bType & 0x10)
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
	return true;
}

bool StatementObject::InitTableForm()
{
	QExcel object(m_strTablePath);
	object.selectSheet("Sheet1");
	object.mergeCells("A1:H1");
	object.mergeCells("A2:H2");
	object.mergeCells("B3:D3");
	object.mergeCells("F3:H3");
	object.setCellString("A1", QString::fromLocal8Bit("创丰五月份总收支表"), EnumTextAliPos::Center, 18, true);
	object.setCellString("A2", QString::fromLocal8Bit("单位：元"), EnumTextAliPos::Right, 14, false);

	object.setCellString("B3", QString::fromLocal8Bit("总账收支"), EnumTextAliPos::Center, 14, true);
	object.setCellString("F3", QString::fromLocal8Bit("备用金收支"), EnumTextAliPos::Center, 14, true);

	object.setColumnWidth(1, 16);
	object.setColumnWidth(3, 16);
	object.setColumnWidth(4, 16);
	object.setColumnWidth(2, 16);
	object.setColumnWidth(5, 2);
	object.setColumnWidth(6, 16);
	object.setColumnWidth(7, 16);
	object.setColumnWidth(8, 16);
	object.setCellString("A4", QString::fromLocal8Bit("项目"));
	object.setCellString("B4", QString::fromLocal8Bit("借方"));
	object.setCellString("C4", QString::fromLocal8Bit("贷方"));
	object.setCellString("D4", QString::fromLocal8Bit("结余"));
	object.setCellString("F4", QString::fromLocal8Bit("借方"));
	object.setCellString("G4", QString::fromLocal8Bit("贷方"));
	object.setCellString("H4", QString::fromLocal8Bit("结余"));
	object.save();
	return true;
}

void StatementObject::run()
{
	CoInitializeEx(NULL, COINIT_MULTITHREADED);
	
		QAxObject *excel = new QAxObject((QObject*)nullptr);
		excel->setControl("Excel.Application");//连接Excel控件
		excel->dynamicCall("SetVisible (bool Visible)", "false");//不显示窗体
		excel->setProperty("DisplayAlerts", false);//不显示任何警告信息。如果为true那么在关闭是会出现类似“文件已修改，是否保存”的提示

		QAxObject *workbooks = excel->querySubObject("WorkBooks");//获取工作簿集合
		workbooks->dynamicCall("Add");//新建一个工作簿
		QAxObject *workbook = excel->querySubObject("ActiveWorkBook");//获取当前工作簿
		QAxObject *worksheets = workbook->querySubObject("Sheets");//获取工作表集合
		QAxObject *worksheet = worksheets->querySubObject("Item(int)", 1);//获取工作表集合的工作表1，即sheet1
		workbook->dynamicCall("SaveAs(const QString&)", QDir::toNativeSeparators(m_strTablePath));//保存至filepath，注意一定要用QDir::toNativeSeparators将路径中的"/"转换为"\"，不然一定保存不了。
		workbook->dynamicCall("Close()");//关闭工作簿
		excel->dynamicCall("Quit()");//关闭excel
		delete excel;
		excel = NULL;


	QExcel object(m_strTablePath);
	object.selectSheet("Sheet1");
	object.mergeCells("A1:H1");
	object.mergeCells("A2:H2");
	object.mergeCells("B3:D3");
	object.mergeCells("F3:H3");
	object.setCellString("A1", QString::fromLocal8Bit("创丰五月份总收支表"), EnumTextAliPos::Center, 18, true);
	object.setCellString("A2", QString::fromLocal8Bit("单位：元"), EnumTextAliPos::Right, 14, false);

	object.setCellString("B3", QString::fromLocal8Bit("总账收支"), EnumTextAliPos::Center, 14, true);
	object.setCellString("F3", QString::fromLocal8Bit("备用金收支"), EnumTextAliPos::Center, 14, true);

	object.setColumnWidth(1, 16);
	object.setColumnWidth(3, 16);
	object.setColumnWidth(4, 16);
	object.setColumnWidth(2, 16);
	object.setColumnWidth(5, 2);
	object.setColumnWidth(6, 16);
	object.setColumnWidth(7, 16);
	object.setColumnWidth(8, 16);
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
			object.setCellString(iInsertRaw, 2, QString::number(kvp.second.generalIncome) == "0" ? "" : QString::number(kvp.second.generalPay));
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
