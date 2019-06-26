#include "AreaLayoutManager.h"
#include "Common2ParamWidget.h"
#include <thread>
#include "SingletonHttpRequest.h"
#include "globalVariable.h"



AreaLayoutManager::AreaLayoutManager(Ui::ChuangfengDesktopClass*ui)
	:BaseLayoutManager(ui)
{
	InitLayout();
	connect(m_pUi->area_add_btn, &QPushButton::clicked, this, [this]()->void {
		Common2ParamWidget*pQtWidget = new Common2ParamWidget(PopWidgetEnum::enAreaLayout);
		connect(pQtWidget, SIGNAL(sig_comit(QString&, QString&)), this, SLOT(SlotAddArea(QString&, QString&)));
		pQtWidget->setAttribute(Qt::WA_DeleteOnClose);
		pQtWidget->setWindowModality(Qt::ApplicationModal);
		pQtWidget->show();
	});
}


AreaLayoutManager::~AreaLayoutManager()
{
}

void AreaLayoutManager::InitLayout()
{
	m_pViewHeadDeleagte = new CCheckBoxHeaderView(0, Qt::Horizontal, m_pUi->area_tableView);
	m_pUi->area_tableView->setHorizontalHeader(m_pViewHeadDeleagte);
	connect(m_pViewHeadDeleagte, SIGNAL(sig_AllChecked(bool)), this, SLOT(slotCheckBoxStateChanged(bool)));
	m_pViewModel = new QStandardItemModel();
	m_pUi->area_tableView->setModel(m_pViewModel);
	m_pViewModel->setColumnCount(4);
	m_pViewModel->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit(""));
	m_pViewModel->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("ID"));
	m_pViewModel->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("区域名称"));
	m_pViewModel->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("备注"));
	onSetTableAttribute(m_pUi->area_tableView, 4);

	
}

void AreaLayoutManager::SlotAddArea(QString& name, QString&remake)
{
	std::thread t([this](QString&Name)->void {
		QString strParam = QString("name=%1").arg(Name);
		QByteArray responseData;
		SingletonHttpRequest::getInstance()->RequestPost("http://127.0.0.1:80/zerg/public/index.php/addAquaculture"
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
				AddTableViewItem(id.toInt(), Name);
				AreaDetailStruct&item = g_areaList[id.toInt()];
				item.areaName = Name;
			}
			else {//失败

			}
		}
		else {

		}
	}, name);
	t.detach();
}

void AreaLayoutManager::AddTableViewItem(int id, QString AreaName)
{
	int nCount = m_pViewModel->rowCount();
	
	m_pViewModel->setItem(nCount, 0, new QStandardItem(""));
	m_pViewModel->item(nCount, 0)->setCheckable(true);

	m_pViewModel->setItem(nCount, 1, new QStandardItem(QString::number(id)));
	m_pViewModel->setItem(nCount, 2, new QStandardItem(AreaName));

	m_pUi->area_tableView->setColumnWidth(0, 30);
	m_pUi->area_tableView->setColumnWidth(1, 50);
	m_pUi->area_tableView->setColumnWidth(2, 180);
}
