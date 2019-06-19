#include "BaseLayoutManager.h"

#include "NoFocusDelegate.h"

BaseLayoutManager::BaseLayoutManager(Ui::ChuangfengDesktopClass*ui)
	:m_pUi(ui)
{
	
}


BaseLayoutManager::~BaseLayoutManager()
{
}



void BaseLayoutManager::onSetTableAttribute(QTableView *pTableView, const int cloum)
{
	pTableView->setItemDelegate(new NoFocusDelegate());
	for (auto i = 0; i < cloum - 1; i++)
	{
		pTableView->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Interactive);
	}
	pTableView->horizontalHeader()->setStretchLastSection(true);

	pTableView->verticalHeader()->setDefaultSectionSize(30); //设置行高
	pTableView->setFrameShape(QFrame::Box); //设置无边框
	pTableView->setShowGrid(false); //设置不显示格子线
	pTableView->verticalHeader()->setVisible(false); //设置垂直头不可见
	pTableView->setSelectionBehavior(QAbstractItemView::SelectRows);  //设置选择行为时每次选择一行
	pTableView->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置不可编辑
	pTableView->verticalHeader()->setHidden(true);
	//点击表时不对表头行光亮（获取焦点） 
	pTableView->horizontalHeader()->setHighlightSections(false);	
}

void BaseLayoutManager::slotCheckBoxStateChanged(bool status)
{
	if (status) {
		for (int i = 0; i < m_pViewModel->rowCount(); ++i)
			m_pViewModel->item(i, 0)->setCheckState(Qt::Checked);
	}
	else {
		for (int i = 0; i < m_pViewModel->rowCount(); ++i)
			m_pViewModel->item(i, 0)->setCheckState(Qt::Unchecked);
	}
}
