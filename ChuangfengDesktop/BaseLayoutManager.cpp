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

	pTableView->verticalHeader()->setDefaultSectionSize(30); //�����и�
	pTableView->setFrameShape(QFrame::Box); //�����ޱ߿�
	pTableView->setShowGrid(false); //���ò���ʾ������
	pTableView->verticalHeader()->setVisible(false); //���ô�ֱͷ���ɼ�
	pTableView->setSelectionBehavior(QAbstractItemView::SelectRows);  //����ѡ����Ϊʱÿ��ѡ��һ��
	pTableView->setEditTriggers(QAbstractItemView::NoEditTriggers); //���ò��ɱ༭
	pTableView->verticalHeader()->setHidden(true);
	//�����ʱ���Ա�ͷ�й�������ȡ���㣩 
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
