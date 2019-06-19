#include "MaterielReportManger.h"



MaterielReportManger::MaterielReportManger(Ui::ChuangfengDesktopClass*ui)
	:BaseLayoutManager(ui)
{
	InitLayout();
}


MaterielReportManger::~MaterielReportManger()
{
}

void MaterielReportManger::InitLayout()
{
	m_pViewModel = new QStandardItemModel();
	m_pUi->materiel_report_tableView->setModel(m_pViewModel);
	m_pViewModel->setColumnCount(8);
	m_pViewModel->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("项目"));
	m_pViewModel->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("库存"));
	m_pViewModel->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("领用"));
	m_pViewModel->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("结余"));
	m_pViewModel->setHeaderData(4, Qt::Horizontal, QString::fromLocal8Bit(" "));
	m_pViewModel->setHeaderData(5, Qt::Horizontal, QString::fromLocal8Bit("区域"));
	m_pViewModel->setHeaderData(6, Qt::Horizontal, QString::fromLocal8Bit("待摊"));
	m_pViewModel->setHeaderData(7, Qt::Horizontal, QString::fromLocal8Bit("本期分摊"));
	onSetTableAttribute(m_pUi->materiel_report_tableView,8);
	m_pUi->materiel_report_tableView->horizontalHeader()->setStretchLastSection(false);
	int nCount = 0;
	for (auto i = 0; i < 10; i++)
	{
		m_pViewModel->setItem(i, 0, new QStandardItem(QString::fromLocal8Bit("总账号期初余额")));

		m_pViewModel->setItem(i, 1, new QStandardItem(QString::number(209637.89)));
		m_pViewModel->setItem(i, 2, new QStandardItem(QString::fromLocal8Bit("0")));
		m_pViewModel->setItem(i, 3, new QStandardItem(QString::fromLocal8Bit("0")));
		nCount++;
	}

	m_pUi->materiel_report_tableView->setColumnWidth(0, 160);
	m_pUi->materiel_report_tableView->setColumnWidth(1, 80);
	m_pUi->materiel_report_tableView->setColumnWidth(2, 80);
	m_pUi->materiel_report_tableView->setColumnWidth(3, 80);
}
