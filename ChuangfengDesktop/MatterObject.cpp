#include "MatterObject.h"
#include "QExcel.h"


MatterObject::MatterObject(QString& _strTablePath, const double &_initAmount, const double& _currentAmout, double _FixedUse, map<QString, double>& _materialUseList, map<QString, tuple<double, double>> & _fixedList)
	:m_strTablePath(_strTablePath)
	,m_initAmount(_initAmount)
	,m_currentAmout(_currentAmout)
	,m_FixedUse(m_FixedUse)
	,m_fixedList(_fixedList)
	, m_materialUseList(_materialUseList)
{
}


MatterObject::~MatterObject()
{
}

void MatterObject::run()
{
	QExcel object(m_strTablePath);
	object.selectSheet("Sheet1");
	object.mergeCells("A1:D1");
	object.mergeCells("A2:D2");

	object.mergeCells("F1:I1");
	object.mergeCells("F2:I2");

	object.setCellString("A1", QString::fromLocal8Bit("X月份物料领用汇总表"), EnumTextAliPos::Center, 14, true);
	object.setCellString("A2", QString::fromLocal8Bit("单位：元"), EnumTextAliPos::Right, 12, false);

	object.setCellString("F1", QString::fromLocal8Bit("X月份固资分摊情况表"), EnumTextAliPos::Center, 14, true);
	object.setCellString("F2", QString::fromLocal8Bit("单位：元"), EnumTextAliPos::Right, 12, false);

	object.setColumnWidth(1, 16);
	object.setColumnWidth(3, 16);
	object.setColumnWidth(4, 16);
	object.setColumnWidth(2, 16);

	object.setColumnWidth(6, 16);
	object.setColumnWidth(7, 16);
	object.setColumnWidth(8, 16);
	object.setColumnWidth(9, 16);

	object.setCellString("A3", QString::fromLocal8Bit("项目"));
	object.setCellString("B3", QString::fromLocal8Bit("库存"));
	object.setCellString("C4", QString::fromLocal8Bit("领用"));
	object.setCellString("D4", QString::fromLocal8Bit("结余"));

	object.setCellString("F3", QString::fromLocal8Bit("区域"));
	object.setCellString("G3", QString::fromLocal8Bit("待摊"));
	object.setCellString("H4", QString::fromLocal8Bit("本期分摊"));
	int iInsertRaw = m_iDataStartRaw;
	int iSubInsertRaw = m_iDataStartRaw;
	double inData = 0, outData = 0, subinData = 0, subOutData = 0;
	object.setCellString(iInsertRaw, 1, QString::fromLocal8Bit("期初余额"));
	object.setCellString(iInsertRaw, 3, QString::number(m_initAmount));
	iInsertRaw++;
	inData += m_initAmount;

	object.setCellString(iInsertRaw, 1, QString::fromLocal8Bit("本月购入"));
	object.setCellString(iInsertRaw, 3, QString::number(m_currentAmout));
	iInsertRaw++;
	inData += m_currentAmout;

	object.setCellString(iInsertRaw, 1, QString::fromLocal8Bit("固资领用"));
	object.setCellString(iInsertRaw, 3, QString::number(m_FixedUse));
	iInsertRaw++;
	outData += m_FixedUse;
	for (auto&kvp : m_materialUseList)
	{
		object.setCellString(iInsertRaw, 1, kvp.first);
		object.setCellString(iInsertRaw, 3, QString::number(kvp.second));
		outData += kvp.second;
		iInsertRaw++;
	}
	object.setCellString(iInsertRaw, 1, QString::fromLocal8Bit("合计："));
	object.setCellString(iInsertRaw, 2, QString::number(inData));
	object.setCellString(iInsertRaw, 3, QString::number(outData));
	object.setCellString(iInsertRaw, 3, QString::number(inData - outData));
	object.setBorder(m_iDataStartRaw - 1, iInsertRaw, 1, 4);

	for (auto&kvp : m_fixedList)
	{
		object.setCellString(iSubInsertRaw, 7, kvp.first);
		object.setCellString(iSubInsertRaw, 8, QString::number(get<0>(kvp.second)));
		subinData += get<0>(kvp.second);
		object.setCellString(iSubInsertRaw, 9, QString::number(get<1>(kvp.second)));
		subOutData += get<1>(kvp.second);
		iSubInsertRaw++;
	}

	object.setCellString(iSubInsertRaw, 7, QString::fromLocal8Bit("合计："));
	object.setCellString(iSubInsertRaw, 8, QString::number(subinData));
	object.setCellString(iSubInsertRaw, 9, QString::number(subOutData));

	object.setBorder(m_iDataStartRaw - 1, iSubInsertRaw, 7, 10);
	object.save();
}



