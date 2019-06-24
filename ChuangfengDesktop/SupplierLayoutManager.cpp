#include "SupplierLayoutManager.h"
#include "Common2ParamWidget.h"



SupplierLayoutManager::SupplierLayoutManager(Ui::ChuangfengDesktopClass*ui)
	:BaseLayoutManager(ui)
{
	InitLayout();
	connect(m_pUi->supplier_add_btn, &QPushButton::clicked, this, [this]()->void {
		Common2ParamWidget*pQtWidget = new Common2ParamWidget(PopWidgetEnum::enSupplierLayout);
		pQtWidget->setAttribute(Qt::WA_DeleteOnClose);
		pQtWidget->setWindowModality(Qt::ApplicationModal);
		pQtWidget->show();
	});
}


SupplierLayoutManager::~SupplierLayoutManager()
{
}

void SupplierLayoutManager::InitLayout()
{
	m_pViewHeadDeleagte = new CCheckBoxHeaderView(0, Qt::Horizontal, m_pUi->supplier_tableView);
	m_pUi->supplier_tableView->setHorizontalHeader(m_pViewHeadDeleagte);
	connect(m_pViewHeadDeleagte, SIGNAL(sig_AllChecked(bool)), this, SLOT(slotCheckBoxStateChanged(bool)));
	m_pViewModel = new QStandardItemModel();
	m_pUi->supplier_tableView->setModel(m_pViewModel);
	m_pViewModel->setColumnCount(4);
	m_pViewModel->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit(""));
	m_pViewModel->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("ID"));
	m_pViewModel->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("供应商名称"));
	m_pViewModel->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("备注"));
	onSetTableAttribute(m_pUi->supplier_tableView, 4);

	int nCount = 0;
	for (auto i = 0; i < 1; i++)
	{
		m_pViewModel->setItem(i, 0, new QStandardItem(""));
		m_pViewModel->item(i, 0)->setCheckable(true);

		m_pViewModel->setItem(i, 1, new QStandardItem(QString::number(1)));
		m_pViewModel->setItem(i, 2, new QStandardItem(QString::fromLocal8Bit("宋荣生")));

		nCount++;
	}
	m_pUi->supplier_tableView->setColumnWidth(0, 30);
	m_pUi->supplier_tableView->setColumnWidth(1, 50);
	m_pUi->supplier_tableView->setColumnWidth(2, 180);

}
