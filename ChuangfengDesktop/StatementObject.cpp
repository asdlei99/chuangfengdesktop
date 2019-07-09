#include "StatementObject.h"
#include "QExcel.h"

StatementObject::StatementObject(QString _strTablePath)
	:m_strTablePath(_strTablePath)
{
	InitTableForm();
}


StatementObject::~StatementObject()
{
}

bool StatementObject::FillTableData(double initGeneral, double initBak,  map<QString, tableViewItemStruct> _dataMap)
{
	QExcel object(m_strTablePath);
	object.selectSheet("Sheet1");
	int iInsertRaw = m_iDataStartRaw;
	double iTotalIncom = 0, iTotalPay = 0, iBakIncom = 0, iBakPay = 0;
	iTotalIncom += initGeneral;
	iBakIncom += initBak;
	object.setCellString(iInsertRaw, 1, QString::fromLocal8Bit("���˺��ڳ����"));
	object.setCellString(iInsertRaw, 2, QString::number(initGeneral) );
	iInsertRaw++;
	object.setCellString(iInsertRaw, 1, QString::fromLocal8Bit("���ý��ڳ����"));
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
	object.setCellString("A1", QString::fromLocal8Bit("�������·�����֧��"), EnumTextAliPos::Center, 18, true);
	object.setCellString("A2", QString::fromLocal8Bit("��λ��Ԫ"), EnumTextAliPos::Right, 14, false);

	object.setCellString("B3", QString::fromLocal8Bit("������֧"), EnumTextAliPos::Center, 14, true);
	object.setCellString("F3", QString::fromLocal8Bit("���ý���֧"), EnumTextAliPos::Center, 14, true);

	object.setColumnWidth(1, 16);
	object.setColumnWidth(3, 16);
	object.setColumnWidth(4, 16);
	object.setColumnWidth(2, 16);
	object.setColumnWidth(5, 2);
	object.setColumnWidth(6, 16);
	object.setColumnWidth(7, 16);
	object.setColumnWidth(8, 16);
	object.setCellString("A4", QString::fromLocal8Bit("��Ŀ"));
	object.setCellString("B4", QString::fromLocal8Bit("�跽"));
	object.setCellString("C4", QString::fromLocal8Bit("����"));
	object.setCellString("D4", QString::fromLocal8Bit("����"));
	object.setCellString("F4", QString::fromLocal8Bit("�跽"));
	object.setCellString("G4", QString::fromLocal8Bit("����"));
	object.setCellString("H4", QString::fromLocal8Bit("����"));
	object.save();
	return true;
}
