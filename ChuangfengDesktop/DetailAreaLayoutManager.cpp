#include "DetailAreaLayoutManager.h"



DetailAreaLayoutManager::DetailAreaLayoutManager(Ui::ChuangfengDesktopClass*ui)
	:BaseLayoutManager(ui)
{
	InitLayout();
}


DetailAreaLayoutManager::~DetailAreaLayoutManager()
{
}

void DetailAreaLayoutManager::InitLayout()
{
	m_pViewHeadDeleagte = new CCheckBoxHeaderView(0, Qt::Horizontal, m_pUi->detailarea_tableView);
	m_pUi->detailarea_tableView->setHorizontalHeader(m_pViewHeadDeleagte);
	connect(m_pViewHeadDeleagte, SIGNAL(sig_AllChecked(bool)), this, SLOT(slotCheckBoxStateChanged(bool)));
	m_pViewModel = new QStandardItemModel();
	m_pUi->detailarea_tableView->setModel(m_pViewModel);
	m_pViewModel->setColumnCount(4);
	m_pViewModel->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit(""));
	m_pViewModel->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("ID"));
	m_pViewModel->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("塘口名称"));
	m_pViewModel->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("所属区域"));
	onSetTableAttribute(m_pUi->detailarea_tableView, 4);

	int nCount = 0;
	for (auto i = 0; i < 1; i++)
	{
		m_pViewModel->setItem(i, 0, new QStandardItem(""));
		m_pViewModel->item(i, 0)->setCheckable(true);

		m_pViewModel->setItem(i, 1, new QStandardItem(QString::number(1)));
		m_pViewModel->setItem(i, 2, new QStandardItem(QString::fromLocal8Bit("A1")));
		m_pViewModel->setItem(i, 3, new QStandardItem(QString::fromLocal8Bit("A区")));

		nCount++;
	}
	m_pUi->detailarea_tableView->setColumnWidth(0, 30);
	m_pUi->detailarea_tableView->setColumnWidth(1, 50);
	m_pUi->detailarea_tableView->setColumnWidth(2, 180);
}
