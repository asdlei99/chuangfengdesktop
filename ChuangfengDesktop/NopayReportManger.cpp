#include "NopayReportManger.h"



NopayReportManger::NopayReportManger(Ui::ChuangfengDesktopClass*ui)
	:BaseLayoutManager(ui)
{
	InitLayout();
}


NopayReportManger::~NopayReportManger()
{
}

void NopayReportManger::InitLayout()
{
	m_pViewModel = new QStandardItemModel();
	m_pUi->nopayreport_tableView->setModel(m_pViewModel);
	m_pViewModel->setColumnCount(8);
	m_pViewModel->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("��Ӧ��"));
	m_pViewModel->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("ժҪ"));
	m_pViewModel->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("�ڳ����"));
	m_pViewModel->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("���˻�ۿ�"));
	m_pViewModel->setHeaderData(4, Qt::Horizontal, QString::fromLocal8Bit("����Ӧ����"));
	m_pViewModel->setHeaderData(5, Qt::Horizontal, QString::fromLocal8Bit("�˻�"));
	m_pViewModel->setHeaderData(6, Qt::Horizontal, QString::fromLocal8Bit("�Ѹ���"));
	m_pViewModel->setHeaderData(7, Qt::Horizontal, QString::fromLocal8Bit("��ĩ���"));
	onSetTableAttribute(m_pUi->nopayreport_tableView, 8);
	m_pUi->nopayreport_tableView->horizontalHeader()->setStretchLastSection(false);
	int nCount = 0;
	for (auto i = 0; i < 10; i++)
	{
		m_pViewModel->setItem(i, 0, new QStandardItem(QString::fromLocal8Bit("���˺��ڳ����")));
		/*m_pViewModel->item(i, 0)->setCheckable(tru)));
		m_pViewModel->setItem(i, 2, new QStandardItem()));
		m_pViewModel->setItem(i, 2, new QStandardItem(e);*/

		m_pViewModel->setItem(i, 1, new QStandardItem(QString::number(209637.89)));
		m_pViewModel->setItem(i, 2, new QStandardItem(QString::fromLocal8Bit("0")));
		m_pViewModel->setItem(i, 3, new QStandardItem(QString::fromLocal8Bit("0")));



		nCount++;
	}
	for (auto i = 0; i < 10; i++)
	{
		m_pViewModel->setItem(i, 5, new QStandardItem(QString::number(209637.89)));
		m_pViewModel->setItem(i, 6, new QStandardItem(QString::fromLocal8Bit("0")));
		m_pViewModel->setItem(i, 7, new QStandardItem(QString::fromLocal8Bit("0")));
	}
	m_pUi->nopayreport_tableView->setColumnWidth(0, 160);
	m_pUi->nopayreport_tableView->setColumnWidth(1, 80);
	m_pUi->nopayreport_tableView->setColumnWidth(2, 80);
	m_pUi->nopayreport_tableView->setColumnWidth(3, 80);

	m_pUi->nopayreport_tableView->setColumnWidth(5, 80);
	m_pUi->nopayreport_tableView->setColumnWidth(6, 80);
	m_pUi->nopayreport_tableView->setColumnWidth(7, 80);
}
