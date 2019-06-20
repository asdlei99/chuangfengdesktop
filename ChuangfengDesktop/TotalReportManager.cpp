#include "TotalReportManager.h"



TotalReportManager::TotalReportManager(Ui::ChuangfengDesktopClass*ui)
	:BaseLayoutManager(ui)
{
	InitLayout();
}


TotalReportManager::~TotalReportManager()
{
}

void TotalReportManager::InitLayout()
{
	//m_pViewHeadDeleagte = new CCheckBoxHeaderView(0, Qt::Horizontal, m_pUi->detailarea_tableView);
	//m_pUi->detailarea_tableView->setHorizontalHeader(m_pViewHeadDeleagte);
	//connect(m_pViewHeadDeleagte, SIGNAL(sig_AllChecked(bool)), this, SLOT(slotCheckBoxStateChanged(bool)));
// 	m_pViewModel = new QStandardItemModel();
// 	m_pUi->total_reporttableView->setModel(m_pViewModel);
// 	m_pViewModel->setColumnCount(8);
// 	m_pViewModel->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("项目"));
// 	m_pViewModel->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("借方"));
// 	m_pViewModel->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("贷方"));
// 	m_pViewModel->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("结余"));
// 	m_pViewModel->setHeaderData(4, Qt::Horizontal, QString::fromLocal8Bit(""));
// 	m_pViewModel->setHeaderData(5, Qt::Horizontal, QString::fromLocal8Bit("借方"));
// 	m_pViewModel->setHeaderData(6, Qt::Horizontal, QString::fromLocal8Bit("贷方"));
// 	m_pViewModel->setHeaderData(7, Qt::Horizontal, QString::fromLocal8Bit("结余"));
// 	onSetTableAttribute(m_pUi->total_reporttableView, 8);
// 	m_pUi->total_reporttableView->horizontalHeader()->setStretchLastSection(false);
// 	int nCount = 0;
// 	for (auto i = 0; i < 10; i++)
// 	{
// 		m_pViewModel->setItem(i, 0, new QStandardItem(QString::fromLocal8Bit("总账号期初余额")));
// 		/*m_pViewModel->item(i, 0)->setCheckable(tru)));
// 		m_pViewModel->setItem(i, 2, new QStandardItem()));
// 		m_pViewModel->setItem(i, 2, new QStandardItem(e);*/
// 
// 		m_pViewModel->setItem(i, 1, new QStandardItem(QString::number(209637.89)));
// 		m_pViewModel->setItem(i, 2, new QStandardItem(QString::fromLocal8Bit("0")));
// 		m_pViewModel->setItem(i, 3, new QStandardItem(QString::fromLocal8Bit("0")));
// 
// 		
// 
// 		nCount++;
// 	}
// 	for (auto i = 0; i < 10; i++)
// 	{
// 		m_pViewModel->setItem(i, 5, new QStandardItem(QString::number(209637.89)));
// 		m_pViewModel->setItem(i, 6, new QStandardItem(QString::fromLocal8Bit("0")));
// 		m_pViewModel->setItem(i, 7, new QStandardItem(QString::fromLocal8Bit("0")));
// 	}
// 	m_pUi->total_reporttableView->setColumnWidth(0, 160);
// 	m_pUi->total_reporttableView->setColumnWidth(1, 80);
// 	m_pUi->total_reporttableView->setColumnWidth(2, 80);
// 	m_pUi->total_reporttableView->setColumnWidth(3, 80);
// 
// 	m_pUi->total_reporttableView->setColumnWidth(5, 80);
// 	m_pUi->total_reporttableView->setColumnWidth(6, 80);
// 	m_pUi->total_reporttableView->setColumnWidth(7, 80);
}
