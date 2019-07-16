
#include "CategoryLayoutManager.h"
#include "Common2ParamWidget.h"
#include "globalVariable.h"
#include "SingletonHttpRequest.h"
#include <thread>
#include "commomdef.h"

using namespace std;


CategoryLayoutManager::CategoryLayoutManager(Ui::ChuangfengDesktopClass*ui) 
	:BaseLayoutManager(ui)
{
	InitLayout();
	connect(m_pUi->category_add_btn, &QPushButton::clicked, this, [this]()->void {
		Common2ParamWidget*pQtWidget = new Common2ParamWidget(PopWidgetEnum::enCategoryLayout);
		connect(pQtWidget, SIGNAL(sig_comit(QString&, QString&)), this, SLOT(SlotAddCategory(QString&, QString&)));
		pQtWidget->setAttribute(Qt::WA_DeleteOnClose);
		pQtWidget->setWindowModality(Qt::ApplicationModal);
		pQtWidget->show();
	});

	connect(ui->category_remove_btn, &QPushButton::clicked, this, &CategoryLayoutManager::SlotRemoveCategoryItem);

	std::thread t([this]()->void {
		this->threadGetCategoryInfoCallBack();
	});
	t.detach();
}


CategoryLayoutManager::~CategoryLayoutManager()
{
}

void CategoryLayoutManager::SlotAddCategory(QString&itemName, QString &remake)
{
	m_addName = itemName;
	QThread *pThread = new QThread;
	connect(pThread, SIGNAL(started()), this, SLOT(SlotThreadAddItem()));
	connect(pThread, SIGNAL(finished()), pThread, SLOT(deleteLater()));
	pThread->start();
}

void CategoryLayoutManager::SlotRemoveCategoryItem()
{
	QThread *m_pThread = new QThread;
	connect(m_pThread, SIGNAL(started()), this, SLOT(SlotThreadRemoveItem()));
	connect(m_pThread, SIGNAL(finished()), m_pThread, SLOT(deleteLater()));
	m_pThread->start();
}

void CategoryLayoutManager::SlotThreadRemoveItem()
{
	QMap<int, int> qMapSelect;
	bool isFirst = true;
	QString itemList = "";
	for (int i = 0; i < m_pViewModel->rowCount(); ++i)
	{
		if (Qt::Checked == m_pViewModel->item(i, 0)->checkState())
		{
			if (isFirst)
			{
				itemList = m_pViewModel->item(i, 1)->text();
			}
			else {
				itemList += "," + m_pViewModel->item(i, 1)->text();
			}
			isFirst = false;
			qMapSelect.insert(i, m_pViewModel->item(i, 1)->text().toInt());
		}
	}
	if (qMapSelect.count() == 0)
	{
		return;
	}
	QString Url = QString(removeTaskItem).arg(g_strIpAddr).arg(g_strIpPort);
	QString strParam = "ids=" + itemList;
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
			QMapIterator<int, int> Iterator(qMapSelect);
			Iterator.toBack();
			while (Iterator.hasPrevious())//利用qmap排序 从大的节点 往小的进行删除。
			{
				Iterator.previous();
				int rowm = Iterator.key();
				m_pViewModel->removeRow(rowm);
				auto iter = g_CategoryList.find(Iterator.value());
				if (iter != g_CategoryList.end())
				{
					g_CategoryList.erase(iter);
				}
			}
			emit sig_NotifyMsg(QString::fromLocal8Bit("删除成功！"), errorcode);
		}
		else {//失败
			emit sig_NotifyMsg(strMsg, errorcode);
		}
	}
	else {
		int errorcode = 404;
		emit sig_NotifyMsg(QString::fromLocal8Bit("网络请求异常！"), errorcode);
	}
}

void CategoryLayoutManager::SlotThreadAddItem()
{
	QString Url = QString(insertTaskItem).arg(g_strIpAddr).arg(g_strIpPort);
	QString strParam = QString("name=%1").arg(m_addName);
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
			AddTableViewItem(id.toInt(), m_addName);
			g_CategoryList[id.toInt()] = m_addName;
			emit sig_NotifyMsg(QString::fromLocal8Bit("添加成功！"), errorcode);
		}
		else {//失败
			emit sig_NotifyMsg(strMsg, errorcode);
		}
	}
	else {
		int errorcode = 404;
		emit sig_NotifyMsg(QString::fromLocal8Bit("网络请求异常！"), errorcode);
	}
}

void CategoryLayoutManager::threadGetCategoryInfoCallBack()
{
	QString Url = QString(getTaskItem).arg(g_strIpAddr).arg(g_strIpPort);
	QByteArray responseData;
	SingletonHttpRequest::getInstance()->RequestGet(Url	, g_token, responseData);
	
	QJsonParseError json_error;
	QJsonDocument parse_doucment = QJsonDocument::fromJson(responseData, &json_error);
	if (json_error.error == QJsonParseError::NoError)
	{
		if (parse_doucment.isArray())
		{
			QJsonArray array = parse_doucment.array();
			for (int i = 0; i < array.size(); i++)
			{
				QJsonValue userArray = array.at(i);
				QJsonObject userObject = userArray.toObject();
				int id = userObject["id"].toInt();
				QString CategoryName = userObject["name"].toString();
				AddTableViewItem(id, CategoryName);
				g_CategoryList[id] = CategoryName;
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

void CategoryLayoutManager::InitLayout()
{
	m_pViewHeadDeleagte = new CCheckBoxHeaderView(0, Qt::Horizontal, m_pUi->category_tableView);
	m_pUi->category_tableView->setHorizontalHeader(m_pViewHeadDeleagte);
	connect(m_pViewHeadDeleagte, SIGNAL(sig_AllChecked(bool)), this, SLOT(slotCheckBoxStateChanged(bool)));
	m_pViewModel = new QStandardItemModel();
	m_pUi->category_tableView->setModel(m_pViewModel);
	m_pViewModel->setColumnCount(4);
	m_pViewModel->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit(""));
	m_pViewModel->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("ID"));
	m_pViewModel->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("账目名称"));
	m_pViewModel->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("备注"));
	onSetTableAttribute(m_pUi->category_tableView, 4);

}

void CategoryLayoutManager::AddTableViewItem(int id, QString  Category)
{
	int nCount = m_pViewModel->rowCount();
	m_pViewModel->setItem(nCount, 0, new QStandardItem(""));
	m_pViewModel->item(nCount, 0)->setCheckable(true);
	m_pViewModel->setItem(nCount, 0, new QStandardItem(""));
	m_pViewModel->item(nCount, 0)->setCheckable(true);

	m_pViewModel->setItem(nCount, 1, new QStandardItem(QString::number(id)));
	m_pViewModel->setItem(nCount, 2, new QStandardItem(Category));
	
	m_pUi->category_tableView->setColumnWidth(0, 30);
	m_pUi->category_tableView->setColumnWidth(1, 50);
	m_pUi->category_tableView->setColumnWidth(2, 180);
}
