#include "DetailShareReportManager.h"



DetailShareReportManager::DetailShareReportManager(Ui::ChuangfengDesktopClass*ui)
	:BaseLayoutManager(ui)
{
	InitLayout();
}


DetailShareReportManager::~DetailShareReportManager()
{
}

void DetailShareReportManager::InitLayout()
{
	m_pViewModel = new QStandardItemModel();
	m_pUi->detailshare_report_tableview->setModel(m_pViewModel);
	m_pViewModel->setColumnCount(5);
	m_pViewModel->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("����"));
	m_pViewModel->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("����ҩƷ"));
	m_pViewModel->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("����"));
	m_pViewModel->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("����"));
	m_pViewModel->setHeaderData(4, Qt::Horizontal, QString::fromLocal8Bit("���ʷ�̯"));

	onSetTableAttribute(m_pUi->detailshare_report_tableview, 5);
	m_pUi->detailshare_report_tableview->horizontalHeader()->setStretchLastSection(false);
	int nCount = 0;
	for (auto i = 0; i < 10; i++)
	{
		m_pViewModel->setItem(i, 0, new QStandardItem(QString::fromLocal8Bit("���˺��ڳ����")));

		m_pViewModel->setItem(i, 1, new QStandardItem(QString::number(209637.89)));
		m_pViewModel->setItem(i, 2, new QStandardItem(QString::fromLocal8Bit("0")));
		m_pViewModel->setItem(i, 3, new QStandardItem(QString::fromLocal8Bit("0")));
		nCount++;
	}

	m_pUi->detailshare_report_tableview->setColumnWidth(0, 160);
	m_pUi->detailshare_report_tableview->setColumnWidth(1, 80);
	m_pUi->detailshare_report_tableview->setColumnWidth(2, 80);
	m_pUi->detailshare_report_tableview->setColumnWidth(3, 80);
}
