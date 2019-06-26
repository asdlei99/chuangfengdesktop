#include "ShareItemLayoutManager.h"
#include "CommonDependenceWidget.h"
#include <thread>
#include "SingletonHttpRequest.h"
#include "globalVariable.h"
ShareItemLayoutManager::ShareItemLayoutManager(Ui::ChuangfengDesktopClass*ui)
	:BaseLayoutManager(ui)
{
	InitLayout();
	connect(m_pUi->shareitem_add_btn, &QPushButton::clicked, this, [this]()->void {
		CommonDependenceWidget*pQtWidget = new CommonDependenceWidget(PopDependenceWidgetEnum::enShareItemLayout);
		connect(pQtWidget, SIGNAL(sig_comit(QString&, QString&)), this, SLOT(SlotAddShareItem(QString&, QString&)));
		pQtWidget->setAttribute(Qt::WA_DeleteOnClose);
		pQtWidget->setWindowModality(Qt::ApplicationModal);
		pQtWidget->show();
	});

	std::thread t([this]()->void {
		this->threadCostAreaInfoCallBack();
	});
	t.detach();
}

ShareItemLayoutManager::~ShareItemLayoutManager()
{
}

void ShareItemLayoutManager::InitLayout()
{
	m_pViewHeadDeleagte = new CCheckBoxHeaderView(0, Qt::Horizontal, m_pUi->shareitem_tableView);
	m_pUi->shareitem_tableView->setHorizontalHeader(m_pViewHeadDeleagte);
	connect(m_pViewHeadDeleagte, SIGNAL(sig_AllChecked(bool)), this, SLOT(slotCheckBoxStateChanged(bool)));
	m_pViewModel = new QStandardItemModel();
	m_pUi->shareitem_tableView->setModel(m_pViewModel);
	m_pViewModel->setColumnCount(4);
	m_pViewModel->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit(""));
	m_pViewModel->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("ID"));
	m_pViewModel->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("费用名称"));
	m_pViewModel->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("所属区域"));
	onSetTableAttribute(m_pUi->shareitem_tableView, 4);

	int nCount = 0;
	for (auto i = 0; i < 1; i++)
	{
		m_pViewModel->setItem(i, 0, new QStandardItem(""));
		m_pViewModel->item(i, 0)->setCheckable(true);

		m_pViewModel->setItem(i, 1, new QStandardItem(QString::number(1)));
		m_pViewModel->setItem(i, 2, new QStandardItem(QString::fromLocal8Bit("A区费用")));
		m_pViewModel->setItem(i, 3, new QStandardItem(QString::fromLocal8Bit("A区")));

		nCount++;
	}
	m_pUi->shareitem_tableView->setColumnWidth(0, 30);
	m_pUi->shareitem_tableView->setColumnWidth(1, 50);
	m_pUi->shareitem_tableView->setColumnWidth(2, 180);
}

void ShareItemLayoutManager::SlotAddShareItem(QString &tagName, QString&fromName)
{
	std::thread t([this](QString&Name, QString&itemName)->void {
		QString strParam = QString("name=%1&itemname=%2").arg(Name).arg(itemName);
		QByteArray responseData;
		SingletonHttpRequest::getInstance()->RequestPost("http://127.0.0.1:80/zerg/public/index.php/addCostareas"
			, TempToken, strParam, responseData);

		QJsonParseError json_error;
		QJsonDocument parse_doucment = QJsonDocument::fromJson(responseData, &json_error);
		if (json_error.error == QJsonParseError::NoError)
		{
			QJsonObject rootObject = parse_doucment.object();
			int errorcode = rootObject["error_code"].toInt();
			QString strMsg = rootObject["msg"].toString();
			if (errorcode == 0)//成功
			{
				QString id = rootObject["id"].toString();
				int pid = rootObject["pid"].toInt();
				AddTableViewItem(id.toInt(), itemName, Name);
				CostAreaStruct&item = g_CostAreaList[id.toInt()];
				item.areaId = pid;
				item.areaName = Name;
				item.costAreaName = itemName;
			}
			else {//失败

			}
		}
		else {

		}
	}, fromName, tagName);
	t.detach();
}

void ShareItemLayoutManager::AddTableViewItem(int id, QString shareItem, QString AreaName)
{
	int nCount = m_pViewModel->rowCount();

	m_pViewModel->setItem(nCount, 0, new QStandardItem(""));
	m_pViewModel->item(nCount, 0)->setCheckable(true);

	m_pViewModel->setItem(nCount, 1, new QStandardItem(QString::number(id)));
	m_pViewModel->setItem(nCount, 2, new QStandardItem(shareItem));
	m_pViewModel->setItem(nCount, 3, new QStandardItem(AreaName));


	m_pUi->shareitem_tableView->setColumnWidth(0, 30);
	m_pUi->shareitem_tableView->setColumnWidth(1, 50);
	m_pUi->shareitem_tableView->setColumnWidth(2, 180);
}

void ShareItemLayoutManager::threadCostAreaInfoCallBack()
{
	QByteArray responseData;
	SingletonHttpRequest::getInstance()->RequestGet("http://127.0.0.1:80/zerg/public/index.php/getCostareas"
		, TempToken, responseData);

	QJsonParseError json_error;
	QJsonDocument parse_doucment = QJsonDocument::fromJson(responseData, &json_error);
	if (json_error.error == QJsonParseError::NoError)
	{
		if (parse_doucment.isArray())
		{
			QJsonArray rootarray = parse_doucment.array();
			for (int i = 0; i < rootarray.size(); i++)
			{
				QJsonValue costareaArray = rootarray.at(i);
				QJsonObject costareaObject = costareaArray.toObject();
				int id = costareaObject["id"].toInt();
				QString costareaName = costareaObject["name"].toString();
				QJsonObject areaobject = costareaObject["aquaculture"].toObject();
				QString areaName = areaobject["name"].toString();
				int pid = areaobject["id"].toInt();
				AddTableViewItem(id, costareaName, areaName);
				CostAreaStruct&item = g_CostAreaList[id];
				item.areaId = pid;
				item.areaName = areaName;
				item.costAreaName = costareaName;
			}
		}
		else
		{
			QJsonObject rootObject = parse_doucment.object();
			if (!rootObject["error_code"].isNull())//
			{
				int errorcode = rootObject["error_code"].toInt();
				QString strMsg = rootObject["msg"].toString();
			}
		}
	}
	else {

	}

}
