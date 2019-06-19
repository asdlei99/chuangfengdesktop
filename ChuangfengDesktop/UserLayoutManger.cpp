#include "UserLayoutManger.h"

UserLayoutManger::UserLayoutManger(Ui::ChuangfengDesktopClass*ui)
	:BaseLayoutManager(ui)
{
	InitLayout();
}

UserLayoutManger::~UserLayoutManger()
{
}

void UserLayoutManger::InitLayout()
{
	m_pViewHeadDeleagte = new CCheckBoxHeaderView(0, Qt::Horizontal, m_pUi->user_table_view);
	m_pUi->user_table_view->setHorizontalHeader(m_pViewHeadDeleagte);
	connect(m_pViewHeadDeleagte, SIGNAL(sig_AllChecked(bool)), this, SLOT(slotCheckBoxStateChanged(bool)));
	m_pViewModel = new QStandardItemModel();
	m_pUi->user_table_view->setModel(m_pViewModel);
	m_pViewModel->setColumnCount(4);
	m_pViewModel->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit(""));
	m_pViewModel->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("ID"));
	m_pViewModel->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("用户名"));
	m_pViewModel->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("备注"));
	onSetTableAttribute(m_pUi->user_table_view, 4);

	int nCount = 0;
	for (auto i =0;i<10;i++)
	{
		m_pViewModel->setItem(i, 0, new QStandardItem(""));
		m_pViewModel->item(i, 0)->setCheckable(true);
	
		m_pViewModel->setItem(i, 1, new QStandardItem(QString::number(1)));
		m_pViewModel->setItem(i, 2, new QStandardItem("admin"));

	nCount++;
	}
	m_pUi->user_table_view->setColumnWidth(0, 30);
	m_pUi->user_table_view->setColumnWidth(1, 50);
	m_pUi->user_table_view->setColumnWidth(2, 180);
}

