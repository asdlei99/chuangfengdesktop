#include "DetailAreaLayoutManager.h"
#include "CommonDependenceWidget.h"
#include <thread>
#include "SingletonHttpRequest.h"
#include "globalVariable.h"
#include "commomdef.h"


DetailAreaLayoutManager::DetailAreaLayoutManager(Ui::ChuangfengDesktopClass*ui,shared_ptr<AreaLayoutManager> ptrAreaLayoutManager)
	:BaseLayoutManager(ui)
	, m_ptrAreaLayoutManager(ptrAreaLayoutManager)
{
	InitLayout();
	connect(m_pUi->detailarea_add_btn, &QPushButton::clicked, this, [this]()->void {
		CommonDependenceWidget*pQtWidget = new CommonDependenceWidget(PopDependenceWidgetEnum::enDetailAreaLayout);
		connect(pQtWidget, SIGNAL(sig_comit(QString&, QString&)), this, SLOT(SlotAddDetailArea(QString&, QString&)));
		pQtWidget->setAttribute(Qt::WA_DeleteOnClose);
		pQtWidget->setWindowModality(Qt::ApplicationModal);
		pQtWidget->show();
	});

	std::thread t([this]()->void {
		this->threadAreaInfoCallBack();
	});
	t.detach();
}


DetailAreaLayoutManager::~DetailAreaLayoutManager()
{
}

void DetailAreaLayoutManager::threadAreaInfoCallBack()
{
	QString Url = QString(getAquaculturearea).arg(g_strIpAddr).arg(g_strIpPort);
	QByteArray responseData;
	SingletonHttpRequest::getInstance()->RequestGet(Url, g_token, responseData);

	QJsonParseError json_error;
	QJsonDocument parse_doucment = QJsonDocument::fromJson(responseData, &json_error);
	if (json_error.error == QJsonParseError::NoError)
	{
		if (parse_doucment.isArray())
		{
			QJsonArray rootarray = parse_doucment.array();
			for (int i = 0; i < rootarray.size(); i++)
			{
				QJsonValue areaArray = rootarray.at(i);
				QJsonObject areaObject = areaArray.toObject();
				int id = areaObject["id"].toInt();
				QString areaName = areaObject["name"].toString();
				QJsonArray itemarray= areaObject["items"].toArray();
				AreaDetailStruct&item = g_areaList[areaName];
				item.areaName = areaName;
				for (int j = 0; j < itemarray.size(); j++)
				{
				
					QJsonValue areaDetailArray = itemarray.at(j);
					QJsonObject areaDetailObject = areaDetailArray.toObject();
					int itemId = areaDetailObject["id"].toInt();
					QString areaDetailName = areaDetailObject["name"].toString();
					AddTableViewItem(itemId, areaDetailName, areaName);
					QString &detailArea = item.areaDetailList[itemId];
					detailArea = areaDetailName;
				}
				m_ptrAreaLayoutManager->AddTableViewItem(id, areaName);
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

	
}

void DetailAreaLayoutManager::AddTableViewItem(int id, QString AreaDetailName, QString AreaName)
{
	int nCount = m_pViewModel->rowCount();

	m_pViewModel->setItem(nCount, 0, new QStandardItem(""));
	m_pViewModel->item(nCount, 0)->setCheckable(true);

	m_pViewModel->setItem(nCount, 1, new QStandardItem(QString::number(id)));
	m_pViewModel->setItem(nCount, 2, new QStandardItem(AreaDetailName));
	m_pViewModel->setItem(nCount, 3, new QStandardItem(AreaName));

	
	m_pUi->detailarea_tableView->setColumnWidth(0, 30);
	m_pUi->detailarea_tableView->setColumnWidth(1, 50);
	m_pUi->detailarea_tableView->setColumnWidth(2, 180);
}

void DetailAreaLayoutManager::SlotAddDetailArea(QString &tagName, QString&fromName)
{
	m_addParentName = fromName;
	m_addItemName = tagName;
	QThread *m_pThread = new QThread;
	connect(m_pThread, SIGNAL(started()), this, SLOT(SlotThreadAddDetailArea()));
	connect(m_pThread, SIGNAL(finished()), m_pThread, SLOT(deleteLater()));
	m_pThread->start();
}

void DetailAreaLayoutManager::SlotThreadAddDetailArea()
{
	QString Url = QString(addAquacultureareaDetail).arg(g_strIpAddr).arg(g_strIpPort);
	QString strParam = QString("name=%1&itemname=%2").arg(m_addParentName).arg(m_addItemName);
	QByteArray responseData;
	SingletonHttpRequest::getInstance()->RequestPost(Url, g_token, strParam, responseData);

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
			AddTableViewItem(id.toInt(), m_addItemName, m_addParentName);
			if (g_areaList.find(m_addParentName) != g_areaList.end())
			{
				auto itor = g_areaList.find(m_addParentName);
				itor->second.areaDetailList[id.toInt()] = m_addItemName;
			}
			else {
				AreaDetailStruct& item = g_areaList[m_addParentName];
				item.areaName = m_addParentName;
				item.areaDetailList[id.toInt()] = m_addItemName;
				m_ptrAreaLayoutManager->AddTableViewItem(pid, m_addParentName);
			}
			emit sig_NotifyMsg(QString::fromLocal8Bit("添加数据成功！"), 0);
		}
		else {//失败
			emit sig_NotifyMsg(strMsg, errorcode);
		}
	}
	else {
		emit sig_NotifyMsg(QString::fromLocal8Bit("添加数据失败！"), 404);
	}
}
