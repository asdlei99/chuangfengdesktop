
#include "UserLayoutManger.h"
#include "AddUserWidget.h"
#include <thread>
#include "SingletonHttpRequest.h"
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QByteArray>
#include "globalVariable.h"
#include "commomdef.h"


using namespace  std;

UserLayoutManger::UserLayoutManger(Ui::ChuangfengDesktopClass*ui)
	:BaseLayoutManager(ui)
{
	InitLayout();
	connect(ui->user_add_btn, &QPushButton::clicked, this, [this]()->void {
		AddUserWidget*pQtWidget = new AddUserWidget();
		connect(pQtWidget, SIGNAL(RequestAddUser(QString&,QString&, QString&)), this, SLOT(SlotAddUser(QString&, QString&, QString&)));
		pQtWidget->setAttribute(Qt::WA_DeleteOnClose);
		pQtWidget->setWindowModality(Qt::ApplicationModal);
		pQtWidget->show();
	});
	
	connect(ui->user_remove_btn, &QPushButton::clicked, this, &UserLayoutManger::SlotRemoveUserItem);
	std::thread t([this]()->void {
		this->threadGetUserInfoCallBack();
	});
	t.detach();
}

UserLayoutManger::~UserLayoutManger()
{
}

void UserLayoutManger::SlotAddUser(QString&userName, QString &password, QString &role)
{
	 m_addPsd = password;
	 m_addUserName = userName;
	 m_addrole =role; 
	QThread *m_pThread  =  new QThread;
	connect(m_pThread, SIGNAL(started()), this, SLOT(threadAddUserInfoCallBack()));
	connect(m_pThread, SIGNAL(finished()), m_pThread, SLOT(deleteLater()));
	m_pThread->start();
}

void UserLayoutManger::SlotRemoveUserItem()
{
	QThread *m_pThread = new QThread;
	connect(m_pThread, SIGNAL(started()), this, SLOT(SlotThreadRemove()));
	connect(m_pThread, SIGNAL(finished()), m_pThread, SLOT(deleteLater()));
	m_pThread->start();
}


void UserLayoutManger::SlotThreadRemove()
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
	QString strParam = "ids=" + itemList;
	QByteArray responseData;
	QString Url = QString(deleteuser).arg(g_strIpAddr).arg(g_strIpPort);
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
			}
			emit sig_NotifyMsg(QString::fromLocal8Bit("删除成功！"), errorcode);
		}
		else {//失败
			emit sig_NotifyMsg(strMsg, errorcode);
		}
	}
	else {
		int errorcode = 404;
		emit sig_NotifyMsg(QString::fromLocal8Bit("删除失败！"), errorcode);
	}
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
	m_pViewModel->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("权限"));
	onSetTableAttribute(m_pUi->user_table_view, 4);
	m_pUi->user_table_view->horizontalHeader()->setStretchLastSection(false);
}

void UserLayoutManger::threadGetUserInfoCallBack()
{
	QString Url = QString(GETUSERLIST).arg(g_strIpAddr).arg(g_strIpPort);
	QByteArray responseData;
	SingletonHttpRequest::getInstance()->RequestGet(Url, g_token, responseData);
	
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
				QString nickName = userObject["nickname"].toString();
				QJsonObject RoleObject = userObject["role"].toObject();
				QString roleName = RoleObject["name"].toString();
				AddTableViewItem(id, nickName, roleName);
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

void UserLayoutManger::threadAddUserInfoCallBack()
{
	QString Url = QString(adduser).arg(g_strIpAddr).arg(g_strIpPort);
	QString md5;
	QByteArray bb;
	bb = QCryptographicHash::hash(m_addPsd.toLocal8Bit(), QCryptographicHash::Md5);
	md5.append(bb.toHex());
	QString strParam = QString("username=%1&password=%2&role=%3").arg(m_addUserName).arg(md5).arg(m_addrole);
	QByteArray responseData;
	SingletonHttpRequest::getInstance()->RequestPost(Url, g_token, strParam,responseData);
	
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
			AddTableViewItem(id.toInt(), m_addUserName, m_addrole);
			emit sig_NotifyMsg(QString::fromLocal8Bit("添加用户成功！"), errorcode);
		}
		else {//失败
			emit sig_NotifyMsg(strMsg, errorcode);
		}
	}
	else {
		int errorcode = 404;
		emit sig_NotifyMsg(QString::fromLocal8Bit("增加失败！"), errorcode);
	}
}

void UserLayoutManger::AddTableViewItem(int id, QString nickName, QString roleName)
{
	int nCount = m_pViewModel->rowCount();
	m_pViewModel->setItem(nCount, 0, new QStandardItem(""));
	m_pViewModel->item(nCount, 0)->setCheckable(true);
	m_pViewModel->setItem(nCount, 1, new QStandardItem(QString::number(id)));
	m_pViewModel->setItem(nCount, 2, new QStandardItem(nickName));
	m_pViewModel->setItem(nCount, 3, new QStandardItem(roleName));
	m_pUi->user_table_view->setColumnWidth(0, 30);
	m_pUi->user_table_view->setColumnWidth(1, 50);
	m_pUi->user_table_view->setColumnWidth(2, 180);
	m_pUi->user_table_view->setColumnWidth(3, 180);
}

