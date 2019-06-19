#include "GeneralLayoutManger.h"

GeneralLayoutManger::GeneralLayoutManger(Ui::ChuangfengDesktopClass*ui) 
	:BaseLayoutManager(ui)
{
}


GeneralLayoutManger::~GeneralLayoutManger()
{
}

void GeneralLayoutManger::InitLayout()
{
	m_pViewHeadDeleagte = new CCheckBoxHeaderView(0, Qt::Horizontal, m_pUi->general_table_view);
	m_pUi->general_table_view->setHorizontalHeader(m_pViewHeadDeleagte);
	connect(m_pViewHeadDeleagte, SIGNAL(sig_AllChecked(bool)), this, SLOT(slotCheckBoxStateChanged(bool)));
	m_pViewModel = new QStandardItemModel();
	m_pUi->general_table_view->setModel(m_pViewModel);
	m_pViewModel->setColumnCount(8);
	m_pViewModel->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit(""));
	m_pViewModel->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("日期"));
	m_pViewModel->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("摘要"));
	m_pViewModel->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("借方"));
	m_pViewModel->setHeaderData(4, Qt::Horizontal, QString::fromLocal8Bit("贷方"));
	m_pViewModel->setHeaderData(5, Qt::Horizontal, QString::fromLocal8Bit("结余"));
	m_pViewModel->setHeaderData(6, Qt::Horizontal, QString::fromLocal8Bit("项目"));
	m_pViewModel->setHeaderData(7, Qt::Horizontal, QString::fromLocal8Bit("费用分摊"));
	onSetTableAttribute(m_pUi->general_table_view, 8);

	int nCount = 0;
	for (auto i = 0; i < 10; i++)
	{
		m_pViewModel->setItem(i, 0, new QStandardItem(""));
		m_pViewModel->item(i, 0)->setCheckable(true);
		m_pViewModel->setItem(i, 1, new QStandardItem("2019-05-06"));
		m_pViewModel->setItem(i, 2, new QStandardItem(QString::fromLocal8Bit("虾收入")));
		m_pViewModel->setItem(i, 3, new QStandardItem(QString::number(3000)));
		m_pViewModel->setItem(i, 4, new QStandardItem(QString::number(2000)));
		m_pViewModel->setItem(i, 5, new QStandardItem(QString::number(1000)));
		m_pViewModel->setItem(i, 6, new QStandardItem(QString::fromLocal8Bit("虾收入")));
		nCount++;
	}

	m_pUi->general_table_view->setColumnWidth(0, 30);
	m_pUi->general_table_view->setColumnWidth(1, 100);
	m_pUi->general_table_view->setColumnWidth(2, 180);
	
}

