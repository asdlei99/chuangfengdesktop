#include "NoPayLayoutManager.h"



NoPayLayoutManager::NoPayLayoutManager(Ui::ChuangfengDesktopClass*ui)
	:BaseLayoutManager(ui)
{
}


NoPayLayoutManager::~NoPayLayoutManager()
{
}

void NoPayLayoutManager::InitLayout()
{
	m_pViewHeadDeleagte = new CCheckBoxHeaderView(0, Qt::Horizontal, m_pUi->nopay_tableView);
	m_pUi->nopay_tableView->setHorizontalHeader(m_pViewHeadDeleagte);
	connect(m_pViewHeadDeleagte, SIGNAL(sig_AllChecked(bool)), this, SLOT(slotCheckBoxStateChanged(bool)));
	m_pViewModel = new QStandardItemModel();
	m_pUi->nopay_tableView->setModel(m_pViewModel);
	m_pViewModel->setColumnCount(11);
	m_pViewModel->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit(""));
	m_pViewModel->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("日期"));
	m_pViewModel->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("供应商"));
	m_pViewModel->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("摘要"));
	m_pViewModel->setHeaderData(4, Qt::Horizontal, QString::fromLocal8Bit("初期金额"));
	m_pViewModel->setHeaderData(5, Qt::Horizontal, QString::fromLocal8Bit("调账或扣款"));
	m_pViewModel->setHeaderData(6, Qt::Horizontal, QString::fromLocal8Bit("新增应付款"));
	m_pViewModel->setHeaderData(7, Qt::Horizontal, QString::fromLocal8Bit("退货"));
	m_pViewModel->setHeaderData(8, Qt::Horizontal, QString::fromLocal8Bit("已付款"));
	m_pViewModel->setHeaderData(9, Qt::Horizontal, QString::fromLocal8Bit("期末余额"));
	m_pViewModel->setHeaderData(10, Qt::Horizontal, QString::fromLocal8Bit("备注"));
	onSetTableAttribute(m_pUi->nopay_tableView, 11);

	int nCount = 0;
	for (auto i = 0; i < 10; i++)
	{
		m_pViewModel->setItem(i, 0, new QStandardItem(""));
		m_pViewModel->item(i, 0)->setCheckable(true);
		m_pViewModel->setItem(i, 1, new QStandardItem("2019-05-06"));
		m_pViewModel->setItem(i, 2, new QStandardItem(QString::fromLocal8Bit("宋荣生")));
		m_pViewModel->setItem(i, 3, new QStandardItem(QString::fromLocal8Bit("淡水井款")));
		m_pViewModel->setItem(i, 4, new QStandardItem(QString::number(2000)));
		m_pViewModel->setItem(i, 5, new QStandardItem(QString::number(0)));
		m_pViewModel->setItem(i, 6, new QStandardItem(QString::number(0)));
		m_pViewModel->setItem(i, 7, new QStandardItem(QString::number(0)));
		m_pViewModel->setItem(i, 8, new QStandardItem(QString::number(0)));
		m_pViewModel->setItem(i, 9, new QStandardItem(QString::number(2000)));
		nCount++;
	}

	m_pUi->nopay_tableView->setColumnWidth(0, 30);
	m_pUi->nopay_tableView->setColumnWidth(1, 100);
	m_pUi->nopay_tableView->setColumnWidth(2, 180);
	
}
