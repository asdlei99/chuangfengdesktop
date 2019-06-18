#include "UserLayoutManger.h"



UserLayoutManger::UserLayoutManger(Ui::ChuangfengDesktopClass*ui)
	:BaseLayoutManager(ui)
{
}


UserLayoutManger::~UserLayoutManger()
{
}

void UserLayoutManger::InitLayout()
{
	m_pUserMangerViewHeadDeleagte = new CCheckBoxHeaderView(0, Qt::Horizontal, m_pUi->user_table_view);
	m_pUi->user_table_view->setHorizontalHeader(m_pUserMangerViewHeadDeleagte);
	connect(m_pUserMangerViewHeadDeleagte, SIGNAL(sig_AllChecked(bool)), this, SLOT(slotChannelCheckBoxStateChanged(bool)));
	m_pUserMangerViewModel = new QStandardItemModel();
	m_pUi->user_table_view->setModel(m_pUserMangerViewModel);
	m_pUserMangerViewModel->setColumnCount(4);
	m_pUserMangerViewModel->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit(""));
	m_pUserMangerViewModel->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("ID"));
	m_pUserMangerViewModel->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("用户名"));
	m_pUserMangerViewModel->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("备注"));
	onSetTableAttribute(m_pUi->user_table_view, 4);

	int nCount = 0;
	for (auto i =0;i<100;i++)
	{
		m_pUserMangerViewModel->setItem(i, 0, new QStandardItem(""));
		m_pUserMangerViewModel->item(i, 0)->setCheckable(true);
	
		m_pUserMangerViewModel->setItem(i, 1, new QStandardItem(QString::number(1)));
		m_pUserMangerViewModel->setItem(i, 2, new QStandardItem("admin"));

	nCount++;
	}

	m_pUi->user_table_view->setColumnWidth(0, 30);
	m_pUi->user_table_view->setColumnWidth(1, 50);
	m_pUi->user_table_view->setColumnWidth(2, 180);
	
}

void UserLayoutManger::slotChannelCheckBoxStateChanged(bool status)
{
	if (status) {
		for (int i = 0; i < m_pUserMangerViewModel->rowCount(); ++i)
			m_pUserMangerViewModel->item(i, 0)->setCheckState(Qt::Checked);
	}
	else {
		for (int i = 0; i < m_pUserMangerViewModel->rowCount(); ++i)
			m_pUserMangerViewModel->item(i, 0)->setCheckState(Qt::Unchecked);
	}
}
