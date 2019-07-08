#include "FeedStoreManagerWdiget.h"
#include <QKeyEvent>
#include <QMouseEvent>
#include <QRect>
#include <QPoint>
#include <QGridLayout>
#include <QPainter>
#include <QPen>
#include <QtMath>
#include "iconhelper.h"
#include "globalVariable.h"
#include "AddFeedStoreWidget.h"
#include "DescFeedStoreWidget.h"
#include "SingletonHttpRequest.h"
#include "MsgPopWidget.h"

FeedStoreManagerWdiget::FeedStoreManagerWdiget(QWidget *parent)
	:MoveableFramelessWindow(parent)
	, ui(new Ui::FeedStore)
{
	ui->setupUi(this);
	connect(ui->feedstore_cose_btn, &QPushButton::clicked, this, &QWidget::close);
	connect(ui->feedstore_max_restore_btn, &QPushButton::clicked, this, &FeedStoreManagerWdiget::updateMaximize);
	connect(ui->feedstore_min_btn, &QPushButton::clicked, this, &QWidget::showMinimized);
	ui->feedstore_max_restore_btn->setToolTip(QString::fromLocal8Bit("最大化"));
	//设置按钮的属性名为"maximizeProperty"
	ui->feedstore_max_restore_btn->setProperty("maximizeProperty", "maximize");
	ui->feedstore_max_restore_btn->setStyle(QApplication::style());
	InitOption();
	initTableView();
 	QDateTime current_date_time = QDateTime::currentDateTime();
 	ui->startdateEdit->setCalendarPopup(true);
 	ui->startdateEdit->setDateTime(current_date_time);
 	ui->enddateEdit->setCalendarPopup(true);
 	ui->enddateEdit->setDateTime(current_date_time);
 	
	ui->feed_name_edit->setPlaceholderText(QStringLiteral("为空检索全部"));
	ui->storge_type_combox->addItem(QString::fromLocal8Bit("入库"));
	ui->storge_type_combox->addItem(QString::fromLocal8Bit("出库"));
	ui->storge_type_combox->addItem(QString::fromLocal8Bit("退货"));
	ui->storge_type_combox->addItem(QString::fromLocal8Bit("退库"));
	ui->storge_type_combox->setCurrentText(0);
	for (auto&kvp:g_areaList)
	{
		ui->area_combox->addItem(kvp.second.areaName);
		ui->area3_combox->addItem(kvp.second.areaName);
	}
	ui->area_combox->setCurrentText(0);
	connect(ui->storge_type_combox, SIGNAL(currentIndexChanged(int)), this, SLOT(comboBoxValueChanged()));
	ui->area_combox->setVisible(false);
	

	connect(ui->feed_income_btn, &QPushButton::clicked, this, [this]()->void {
		AddFeedStoreWidget*pQtWidget = new AddFeedStoreWidget();
		connect(pQtWidget, SIGNAL(sig_commit(QString&, QString&, QString&, QString&, QString&, QString&, QString&)), this, SLOT(SlotAddFeedStore(QString&, QString&, QString&, QString&, QString&, QString&, QString&)));
		pQtWidget->setAttribute(Qt::WA_DeleteOnClose);
		pQtWidget->setWindowModality(Qt::ApplicationModal);
		pQtWidget->show();
	});

	connect(ui->feed_out_btn, &QPushButton::clicked, this, &FeedStoreManagerWdiget::SlotDescFeedStore);
	connect(ui->feed_return_btn, &QPushButton::clicked, this, &FeedStoreManagerWdiget::SlotBackFeedStore);
	connect(ui->feedstore_in_out_search_btn, &QPushButton::clicked, this, &FeedStoreManagerWdiget::SlotSearchFeedStoreDetail_in_out_return_back);
	connect(this, SIGNAL(sig_NotifyMsg(QString, int)), this, SLOT(SlotPopMsg(QString, int)));
	connect(ui->feed_search_btn, &QPushButton::clicked, this, &FeedStoreManagerWdiget::SlotSearchFeedStore);
	connect(ui->area_feed_search_btn, &QPushButton::clicked, this, &FeedStoreManagerWdiget::SlotSearchAreaFeedStore);
	connect(ui->area_feed_return_btn, &QPushButton::clicked, this, &FeedStoreManagerWdiget::SlotSearchAreaOutFeedStore);
	HideDetailTableView(_enIncomStore);
}


FeedStoreManagerWdiget::~FeedStoreManagerWdiget()
{
}

void FeedStoreManagerWdiget::updateMaximize()
{
	QWidget *pWindow = this->window(); //获得标题栏所在的窗口
	pWindow->isMaximized() ? pWindow->showNormal() : pWindow->showMaximized();  //窗口最大化/还原显示
	if (pWindow->isTopLevel())
	{
		bool bMaximize = pWindow->isMaximized(); //判断窗口是不是最大化状态，是则返回true，否则返回false
		if (bMaximize)
		{
			//目前窗口是最大化状态，则最大化/还原的toolTip设置为"Restore"
			ui->feedstore_max_restore_btn->setToolTip(QString::fromLocal8Bit("还原"));
			//设置按钮的属性名为"maximizeProperty"
			ui->feedstore_max_restore_btn->setProperty("maximizeProperty", "restore");
		}
		else
		{
			//目前窗口是还原状态，则最大化/还原的toolTip设置为"Maximize"
			ui->feedstore_max_restore_btn->setToolTip(QString::fromLocal8Bit("最大化"));
			//设置按钮的属性名为"maximizeProperty"
			ui->feedstore_max_restore_btn->setProperty("maximizeProperty", "maximize");
		}

		ui->feedstore_max_restore_btn->setStyle(QApplication::style());
	}
}

void FeedStoreManagerWdiget::SlotOptionClick()
{
	NavButton *btn = (NavButton *)sender();
	for (int i = 0; i < m_NavButtonList.count(); i++) {
		if (m_NavButtonList.at(i) == btn)
		{
			ui->feedstore_stackedWidget->setCurrentIndex(i);
			m_NavButtonList.at(i)->setChecked(true);
		}
		else {
			m_NavButtonList.at(i)->setChecked(false);
		}
	}
}

void FeedStoreManagerWdiget::comboBoxValueChanged()
{
	ChangeDetailTableView();
}

void FeedStoreManagerWdiget::SlotDescFeedStore()
{
	int nCount = 0;
	int m_maxNumber = 0;
	
	for (int i = 0; i < m_pViewModelFeedTotalDetail->rowCount(); ++i)
	{
		if (Qt::Checked == m_pViewModelFeedTotalDetail->item(i, 0)->checkState())
		{
			m_id = m_pViewModelFeedTotalDetail->item(i, 0)->text().toInt();
			m_subject_name = m_pViewModelFeedTotalDetail->item(i, 2)->text();
			m_price = m_pViewModelFeedTotalDetail->item(i, 5)->text();
			m_maxNumber = m_pViewModelFeedTotalDetail->item(i, 6)->text().toInt();
			nCount++;
		}
	}
	if (nCount > 1||nCount == 0)
	{
		return;
	}

	DescFeedStoreWidget*pQtWidget = new DescFeedStoreWidget(_enOutStore, m_subject_name, m_price, m_maxNumber, m_area);
	connect(pQtWidget, SIGNAL(sig_commit(FeedTypeEnum &, int&, QString&, QString&)), this, SLOT(SlotOutFeedStorel(FeedTypeEnum &, int&, QString&, QString&)));
	pQtWidget->setAttribute(Qt::WA_DeleteOnClose);
	pQtWidget->setWindowModality(Qt::ApplicationModal);
	pQtWidget->show();
}

void FeedStoreManagerWdiget::SlotBackFeedStore()
{
	int nCount = 0;
	int m_maxNumber = 0;

	for (int i = 0; i < m_pViewModelFeedTotalDetail->rowCount(); ++i)
	{
		if (Qt::Checked == m_pViewModelFeedTotalDetail->item(i, 0)->checkState())
		{
			m_id = m_pViewModelFeedTotalDetail->item(i, 0)->text().toInt();
			m_subject_name = m_pViewModelFeedTotalDetail->item(i, 2)->text();
			m_price = m_pViewModelFeedTotalDetail->item(i, 5)->text();
			m_maxNumber = m_pViewModelFeedTotalDetail->item(i, 6)->text().toInt();
			m_specs = m_pViewModelFeedTotalDetail->item(i, 3)->text();
			m_suplier  = m_pViewModelFeedTotalDetail->item(i, 1)->text();
			m_unit = m_pViewModelFeedTotalDetail->item(i, 4)->text();
			nCount++;
		}
	}
	if (nCount > 1 || nCount == 0)
	{
		return;
	}

	DescFeedStoreWidget*pQtWidget = new DescFeedStoreWidget(_enBack, m_subject_name, m_price, m_maxNumber, m_area);
	connect(pQtWidget, SIGNAL(sig_commit(FeedTypeEnum &, int&, QString&, QString&)), this, SLOT(SlotOutFeedStorel(FeedTypeEnum &, int&, QString&, QString&)));
	pQtWidget->setAttribute(Qt::WA_DeleteOnClose);
	pQtWidget->setWindowModality(Qt::ApplicationModal);
	pQtWidget->show();
}

void FeedStoreManagerWdiget::SlotSearchFeedStoreDetail_in_out_return_back()
{
	m_pViewModelTotalDetail_in_out_return->removeRows(0, m_pViewModelTotalDetail_in_out_return->rowCount());
	QThread *m_pThread = new QThread;
	connect(m_pThread, SIGNAL(started()), this, SLOT(SlotThreadSearchFeedStore_in_out_return_back()));
	connect(m_pThread, SIGNAL(finished()), m_pThread, SLOT(deleteLater()));
	m_pThread->start();
}

void FeedStoreManagerWdiget::SlotAddFeedStore(QString&time, QString&suplier, QString&subject_name, QString&price, QString&unit, QString&specs, QString&number)
{
	 m_pViewModelFeedTotalDetail->removeRows(0, m_pViewModelFeedTotalDetail->rowCount());
	 m_time = time;
	 m_suplier = suplier;
	 m_subject_name = subject_name;
	 m_price = price;
	 m_unit = unit;
	 m_specs = specs;
	 m_number = number;
	 QThread *m_pThread = new QThread;
	 connect(m_pThread, SIGNAL(started()), this, SLOT(SlotThreadAddFeedStore()));
	 connect(m_pThread, SIGNAL(finished()), m_pThread, SLOT(deleteLater()));
	 m_pThread->start();

}

void FeedStoreManagerWdiget::ChangeDetailTableView()
{
	if (ui->storge_type_combox->currentText() == QString::fromLocal8Bit("入库")|| ui->storge_type_combox->currentText() == QString::fromLocal8Bit("退货"))
	{
		ui->area_combox->setVisible(false);
		HideDetailTableView(_enIncomStore);
	}
	else if (ui->storge_type_combox->currentText() == QString::fromLocal8Bit("退库"))
	{
		ui->area_combox->setVisible(true);
		HideDetailTableView(_enRenturnStore);
	}
	else {
		ui->area_combox->setVisible(true);
		HideDetailTableView(_enOutStore);
	}
}

void FeedStoreManagerWdiget::AddFeedStoreTableView(FeedStoreStruct&item)
{
	int nCount = m_pViewModelFeedTotalDetail->rowCount();
	m_pViewModelFeedTotalDetail->setItem(nCount, 0, new QStandardItem(QString::number(item.id)));
	m_pViewModelFeedTotalDetail->item(nCount, 0)->setCheckable(true);
	m_pViewModelFeedTotalDetail->setItem(nCount, 1, new QStandardItem(item.supplier));
	m_pViewModelFeedTotalDetail->setItem(nCount, 2, new QStandardItem(item.subject_name));
	m_pViewModelFeedTotalDetail->setItem(nCount, 3, new QStandardItem(item.specs));
	m_pViewModelFeedTotalDetail->setItem(nCount, 4, new QStandardItem(item.unit));
	m_pViewModelFeedTotalDetail->setItem(nCount, 5, new QStandardItem(item.price));
	m_pViewModelFeedTotalDetail->setItem(nCount, 6, new QStandardItem(QString::number(item.number)));
	m_pViewModelFeedTotalDetail->setItem(nCount, 7, new QStandardItem(QString::number(item.price.toDouble()*item.number)));
	ui->total_feed_store_tableView->setColumnWidth(0, 60);
}

void FeedStoreManagerWdiget::AddFeedStoreIn_out_return_TableView(FeedStoreIn_out_return_Struct&item)
{
	int nCount = m_pViewModelTotalDetail_in_out_return->rowCount();
 	m_pViewModelTotalDetail_in_out_return->setItem(nCount, 0, new QStandardItem(QString::number(item.id)));
	m_pViewModelTotalDetail_in_out_return->item(nCount, 0)->setCheckable(true);
	m_pViewModelTotalDetail_in_out_return->setItem(nCount, 1, new QStandardItem(item.time.mid(0,10)));
	m_pViewModelTotalDetail_in_out_return->setItem(nCount, 2, new QStandardItem(item.subject_name));
	m_pViewModelTotalDetail_in_out_return->setItem(nCount, 3, new QStandardItem(QString::number(item.number)));
	m_pViewModelTotalDetail_in_out_return->setItem(nCount, 4, new QStandardItem(item.price));
	m_pViewModelTotalDetail_in_out_return->setItem(nCount, 5, new QStandardItem(QString::number(item.surplus)));
	m_pViewModelTotalDetail_in_out_return->setItem(nCount, 6, new QStandardItem(item.total));
	m_pViewModelTotalDetail_in_out_return->setItem(nCount, 7, new QStandardItem(item.area));
	ui->feedstore_in_out_tableView->setColumnWidth(0, 60);
}

void FeedStoreManagerWdiget::AddAreaFeedStoreTableView(AreaFeedStoreStruct&item)
{
	int nCount = m_pViewModelTotalArea->rowCount();
	m_pViewModelTotalArea->setItem(nCount, 0, new QStandardItem(QString::number(item.id)));
	m_pViewModelTotalArea->item(nCount, 0)->setCheckable(true);
	m_pViewModelTotalArea->setItem(nCount, 1, new QStandardItem(item.area));
	m_pViewModelTotalArea->setItem(nCount, 2, new QStandardItem(item.subject_name));
	m_pViewModelTotalArea->setItem(nCount, 3, new QStandardItem(item.price));
	m_pViewModelTotalArea->setItem(nCount, 4, new QStandardItem(QString::number(item.number)));
	m_pViewModelTotalArea->setItem(nCount, 5, new QStandardItem(QString::number(item.price.toDouble()*item.number)));
	ui->area_feed_detail_tableView->setColumnWidth(0, 60);
}

void FeedStoreManagerWdiget::HideDetailTableView(FeedTypeEnum _type)
{
	switch (_type)
	{
	case _enIncomStore:
		ui->feedstore_in_out_tableView->setColumnHidden(5, true);
		ui->feedstore_in_out_tableView->setColumnHidden(6, true);
		ui->feedstore_in_out_tableView->setColumnHidden(7, true);
		
		break;
	case _enOutStore:
		ui->feedstore_in_out_tableView->setColumnHidden(5, false);
		ui->feedstore_in_out_tableView->setColumnHidden(6, false);
		ui->feedstore_in_out_tableView->setColumnHidden(7, false);
		break;
	case _enRenturnStore:
		ui->feedstore_in_out_tableView->setColumnHidden(5, true);
		ui->feedstore_in_out_tableView->setColumnHidden(6, true);
		ui->feedstore_in_out_tableView->setColumnHidden(7, false);
		break;
	case _enBack:
		ui->feedstore_in_out_tableView->setColumnHidden(5, true);
		ui->feedstore_in_out_tableView->setColumnHidden(6, true);
		ui->feedstore_in_out_tableView->setColumnHidden(7, true);
		break;
	default:
		break;
	}
}

void FeedStoreManagerWdiget::SlotThreadSearchAreaFeedStore()
{
	QString strParam = QString("subject_name=%1&area=%2")
		.arg(ui->feed_name_edit->text()).arg(ui->area3_combox->currentText());
	QByteArray responseData;
	SingletonHttpRequest::getInstance()->RequestPost("http://127.0.0.1:80/zerg/public/index.php/SearchAreaFeedStore"
		, TempToken, strParam, responseData);
	QJsonParseError json_error;
	QJsonDocument parse_doucment = QJsonDocument::fromJson(responseData, &json_error);
	if (json_error.error == QJsonParseError::NoError)
	{
		if (parse_doucment.isArray())
		{
			QJsonArray array = parse_doucment.array();
			for (int i = 0; i < array.size(); i++)
			{
				QJsonValue materialArray = array.at(i);
				QJsonObject materialObject = materialArray.toObject();
				AreaFeedStoreStruct item;
				item.id = materialObject["id"].toInt();
				item.supplier = materialObject["supplier"].toString();
				item.number = materialObject["number"].toInt();
				item.subject_name = materialObject["subject_name"].toString();
				item.area = materialObject["area"].toString();
				item.price = materialObject["price"].toString();
				AddAreaFeedStoreTableView(item);
			}
		}
		else
		{
			QJsonObject rootObject = parse_doucment.object();
			if (!rootObject["error_code"].isNull())//
			{
				int errorcode = rootObject["error_code"].toInt();
				QString strMsg = rootObject["msg"].toString();
				emit sig_NotifyMsg(strMsg, errorcode);
			}
		}
	}
	else {
		int errorcode = 404;
		emit sig_NotifyMsg(QString::fromLocal8Bit("网络请求异常！"), errorcode);
	}
}

void FeedStoreManagerWdiget::SlotThreadDescFeedStore()
{
	QString strParam = "";
	QByteArray responseData;
	if (m_type == _enOutStore)
	{
		QString strParam = QString("id=%1&operat_time=%2&subject_name=%3&price=%4&number=%5&outarea=%6")
			.arg(m_id).arg(m_time).arg(m_subject_name).arg(m_price).arg(m_number).arg(m_area);
		SingletonHttpRequest::getInstance()->RequestPost("http://127.0.0.1:80/zerg/public/index.php/OutComFeedStore"
			, TempToken, strParam, responseData);
	}
	else if (m_type == _enBack)
	{
		QString strParam = QString("id=%1&operat_time=%2&subject_name=%3&price=%4&number=%5&supplier=%6&unit=%7&specs=%8")
			.arg(m_id).arg(m_time).arg(m_subject_name).arg(m_price).arg(m_number).arg(m_suplier).arg(m_unit).arg(m_specs);
		SingletonHttpRequest::getInstance()->RequestPost("http://127.0.0.1:80/zerg/public/index.php/BackFeedStore"
			, TempToken, strParam, responseData);
	}
	else if (m_type == _enRenturnStore) {
		QString strParam = QString("id=%1&operat_time=%2&subject_name=%3&price=%4&number=%5&area=%6")
			.arg(m_id).arg(m_time).arg(m_subject_name).arg(m_price).arg(m_number).arg(m_area);
		SingletonHttpRequest::getInstance()->RequestPost("http://127.0.0.1:80/zerg/public/index.php/ReturnFeedStore"
			, TempToken, strParam, responseData);
	}

	
	QJsonParseError json_error;
	QJsonDocument parse_doucment = QJsonDocument::fromJson(responseData, &json_error);
	if (json_error.error == QJsonParseError::NoError)
	{
		if (parse_doucment.isArray())
		{
			QJsonArray array = parse_doucment.array();
			for (int i = 0; i < array.size(); i++)
			{
				QJsonValue materialArray = array.at(i);
				QJsonObject materialObject = materialArray.toObject();
				if (m_type == _enRenturnStore)
				{
					AreaFeedStoreStruct item;
					item.id = materialObject["id"].toInt();
					item.supplier = materialObject["supplier"].toString();
					item.number = materialObject["number"].toInt();
					item.subject_name = materialObject["subject_name"].toString();
					item.area = materialObject["area"].toString();
					item.price = materialObject["price"].toString();
					AddAreaFeedStoreTableView(item);
				}
				else {
					FeedStoreStruct item;
					item.id = materialObject["id"].toInt();
					item.supplier = materialObject["supplier"].toString();
					item.number = materialObject["number"].toInt();
					item.subject_name = materialObject["subject_name"].toString();
					item.specs = materialObject["specs"].toString();
					item.unit = materialObject["unit"].toString();
					item.price = materialObject["price"].toString();
					AddFeedStoreTableView(item);
				}			
			}
			if (m_type == _enOutStore)
			{
				emit sig_NotifyMsg(QString::fromLocal8Bit("出库成功！"), 0);
			}
			else if (m_type == _enBack)
			{
				emit sig_NotifyMsg(QString::fromLocal8Bit("退货成功！"), 0);
			}
			else if (m_type == _enRenturnStore)
			{
				emit sig_NotifyMsg(QString::fromLocal8Bit("退库成功！"), 0);
			}
		}
		else
		{
			QJsonObject rootObject = parse_doucment.object();
			if (!rootObject["error_code"].isNull())//
			{
				int errorcode = rootObject["error_code"].toInt();
				QString strMsg = rootObject["msg"].toString();
				emit sig_NotifyMsg(strMsg, errorcode);
			}
		}
	}
	else {
		int errorcode = 404;
		emit sig_NotifyMsg(QString::fromLocal8Bit("网络请求异常！"), errorcode);
	}
}

void FeedStoreManagerWdiget::SlotThreadSearchFeedStore_in_out_return_back()
{
	QString strParam;
	QByteArray responseData;
	if (ui->storge_type_combox->currentText() == QString::fromLocal8Bit("入库"))
	{
		strParam = QString("starttime=%1&endtime=%2").arg(ui->startdateEdit->text()).arg(ui->enddateEdit->text());
		SingletonHttpRequest::getInstance()->RequestPost("http://127.0.0.1:80/zerg/public/index.php/SearchInComSearchFeedStore"
			, TempToken, strParam, responseData);
	}
	else if (ui->storge_type_combox->currentText() == QString::fromLocal8Bit("出库"))
	{
		strParam = QString("starttime=%1&endtime=%2&area=%3").arg(ui->startdateEdit->text()).arg(ui->enddateEdit->text()).arg(ui->area_combox->currentText());
		SingletonHttpRequest::getInstance()->RequestPost("http://127.0.0.1:80/zerg/public/index.php/SearchOutFeedStore"
			, TempToken, strParam, responseData);
	}
	else if (ui->storge_type_combox->currentText() == QString::fromLocal8Bit("退货"))
	{
		strParam = QString("starttime=%1&endtime=%2").arg(ui->startdateEdit->text()).arg(ui->enddateEdit->text());
		SingletonHttpRequest::getInstance()->RequestPost("http://127.0.0.1:80/zerg/public/index.php/SearchBackFeedStore"
			, TempToken, strParam, responseData);
	}
	else
	{
		strParam = QString("starttime=%1&endtime=%2&area=%3").arg(ui->startdateEdit->text()).arg(ui->enddateEdit->text()).arg(ui->area_combox->currentText());
		SingletonHttpRequest::getInstance()->RequestPost("http://127.0.0.1:80/zerg/public/index.php/SearchReturnFeedStore"
			, TempToken, strParam, responseData);
	}
	 
	QJsonParseError json_error;
	QJsonDocument parse_doucment = QJsonDocument::fromJson(responseData, &json_error);
	if (json_error.error == QJsonParseError::NoError)
	{
		if (parse_doucment.isArray())
		{
			QJsonArray array = parse_doucment.array();
			for (int i = 0; i < array.size(); i++)
			{
				QJsonValue materialArray = array.at(i);
				QJsonObject materialObject = materialArray.toObject();
				FeedStoreIn_out_return_Struct item;
				item.id = materialObject["id"].toInt();
				
				item.number = materialObject["number"].toInt();
				item.subject_name = materialObject["subject_name"].toString();
				item.surplus = materialObject["surplus"].toInt();
				item.time = materialObject["operat_time"].toString();
				item.area = materialObject["outarea"].toString();
				item.total = materialObject["totalprice"].toString();
				item.price = materialObject["price"].toString();
				AddFeedStoreIn_out_return_TableView(item);
			}
		}
		else
		{
			QJsonObject rootObject = parse_doucment.object();
			if (!rootObject["error_code"].isNull())//
			{
				int errorcode = rootObject["error_code"].toInt();
				QString strMsg = rootObject["msg"].toString();
				emit sig_NotifyMsg(strMsg, errorcode);
			}
		}
	}
	else {
		int errorcode = 404;
		emit sig_NotifyMsg(QString::fromLocal8Bit("网络请求异常！"), errorcode);
	}
}

void FeedStoreManagerWdiget::SlotThreadSearchFeedStore()
{
	QString strParam = QString("subject_name=%1")
		.arg(ui->feed_name_edit->text());
	QByteArray responseData;
	SingletonHttpRequest::getInstance()->RequestPost("http://127.0.0.1:80/zerg/public/index.php/SearchFeedStore"
		, TempToken, strParam, responseData);
	QJsonParseError json_error;
	QJsonDocument parse_doucment = QJsonDocument::fromJson(responseData, &json_error);
	if (json_error.error == QJsonParseError::NoError)
	{
		if (parse_doucment.isArray())
		{
			QJsonArray array = parse_doucment.array();
			for (int i = 0; i < array.size(); i++)
			{
				QJsonValue materialArray = array.at(i);
				QJsonObject materialObject = materialArray.toObject();
				FeedStoreStruct item;
				item.id = materialObject["id"].toInt();
				item.supplier = materialObject["supplier"].toString();
				item.number = materialObject["number"].toInt();
				item.subject_name = materialObject["subject_name"].toString();
				item.specs = materialObject["specs"].toString();
				item.unit = materialObject["unit"].toString();
				item.price = materialObject["price"].toString();
				AddFeedStoreTableView(item);
			}
		}
		else
		{
			QJsonObject rootObject = parse_doucment.object();
			if (!rootObject["error_code"].isNull())//
			{
				int errorcode = rootObject["error_code"].toInt();
				QString strMsg = rootObject["msg"].toString();
				emit sig_NotifyMsg(strMsg, errorcode);
			}
		}
	}
	else {
		int errorcode = 404;
		emit sig_NotifyMsg(QString::fromLocal8Bit("网络请求异常！"), errorcode);
	}
}

void FeedStoreManagerWdiget::SlotOutFeedStorel(FeedTypeEnum &_type, int&number, QString&time, QString&area)
{
	m_pViewModelFeedTotalDetail->removeRows(0, m_pViewModelFeedTotalDetail->rowCount());
	m_pViewModelTotalArea->removeRows(0, m_pViewModelTotalArea->rowCount());
	m_type = _type;
	m_number = QString::number(number);
	m_time = time;
	if (m_type != _enRenturnStore)
	{	
		m_area = area;
	}
	QThread *m_pThread = new QThread;
	connect(m_pThread, SIGNAL(started()), this, SLOT(SlotThreadDescFeedStore()));
	connect(m_pThread, SIGNAL(finished()), m_pThread, SLOT(deleteLater()));
	m_pThread->start();
}

void FeedStoreManagerWdiget::SlotThreadAddFeedStore()
{
	QString strParam = QString("operat_time=%1&supplier=%2&subject_name=%3&specs=%4&price=%5&unit=%6&number=%7")
		.arg(m_time).arg(m_suplier).arg(m_subject_name).arg(m_specs).arg(m_price).arg(m_unit).
		arg(m_number);
	QByteArray responseData;
	SingletonHttpRequest::getInstance()->RequestPost("http://127.0.0.1:80/zerg/public/index.php/InComFeedStore"
		, TempToken, strParam, responseData);
	QJsonParseError json_error;
	QJsonDocument parse_doucment = QJsonDocument::fromJson(responseData, &json_error);
	if (json_error.error == QJsonParseError::NoError)
	{
		if (parse_doucment.isArray())
		{
			QJsonArray array = parse_doucment.array();
			for (int i = 0; i < array.size(); i++)
			{		
				QJsonValue materialArray = array.at(i);
				QJsonObject materialObject = materialArray.toObject();
				FeedStoreStruct item;	
				item.id = materialObject["id"].toInt();
				item.supplier = materialObject["supplier"].toString();
				item.number = materialObject["number"].toInt();
				item.subject_name = materialObject["subject_name"].toString();
				item.specs = materialObject["specs"].toString();
				item.unit = materialObject["unit"].toString();
				item.price = materialObject["price"].toString();
				AddFeedStoreTableView(item);
			}	
			emit sig_NotifyMsg(QString::fromLocal8Bit("添加成功！"), 0);	
		}
		else
		{
			QJsonObject rootObject = parse_doucment.object();
			if (!rootObject["error_code"].isNull())//
			{
				int errorcode = rootObject["error_code"].toInt();
				QString strMsg = rootObject["msg"].toString();
				emit sig_NotifyMsg(strMsg, errorcode);
			}
		}
	}
	else {
		int errorcode = 404;
		emit sig_NotifyMsg(QString::fromLocal8Bit("网络请求异常！"), errorcode);
	}
}

void FeedStoreManagerWdiget::SlotPopMsg(QString msg, int errorCode)
{
	MsgPopWidget*pQtWidget = new MsgPopWidget(msg, errorCode);
	pQtWidget->setAttribute(Qt::WA_DeleteOnClose);
	pQtWidget->setWindowModality(Qt::ApplicationModal);
	pQtWidget->show();
}


void FeedStoreManagerWdiget::SlotSearchFeedStore()
{
	m_pViewModelFeedTotalDetail->removeRows(0, m_pViewModelFeedTotalDetail->rowCount());
	QThread *m_pThread = new QThread;
	connect(m_pThread, SIGNAL(started()), this, SLOT(SlotThreadSearchFeedStore()));
	connect(m_pThread, SIGNAL(finished()), m_pThread, SLOT(deleteLater()));
	m_pThread->start();
}

void FeedStoreManagerWdiget::SlotSearchAreaFeedStore()
{
	m_pViewModelTotalArea->removeRows(0, m_pViewModelTotalArea->rowCount());
	QThread *m_pThread = new QThread;
	connect(m_pThread, SIGNAL(started()), this, SLOT(SlotThreadSearchAreaFeedStore()));
	connect(m_pThread, SIGNAL(finished()), m_pThread, SLOT(deleteLater()));
	m_pThread->start();
}

void FeedStoreManagerWdiget::SlotSearchAreaOutFeedStore()
{
	int nCount = 0;
	int m_maxNumber = 0;
	for (int i = 0; i < m_pViewModelTotalArea->rowCount(); ++i)
	{
		if (Qt::Checked == m_pViewModelTotalArea->item(i, 0)->checkState())
		{
			m_id = m_pViewModelTotalArea->item(i, 0)->text().toInt();
			m_subject_name = m_pViewModelTotalArea->item(i, 2)->text();
			m_price = m_pViewModelTotalArea->item(i, 3)->text();
			m_maxNumber = m_pViewModelTotalArea->item(i, 4)->text().toInt();
			m_area = m_pViewModelTotalArea->item(i, 1)->text();
			nCount++;
		}
	}
	if (nCount > 1 || nCount == 0)
	{
		return;
	}

	DescFeedStoreWidget*pQtWidget = new DescFeedStoreWidget(_enRenturnStore, m_subject_name, m_price, m_maxNumber, m_area);
	connect(pQtWidget, SIGNAL(sig_commit(FeedTypeEnum &, int&, QString&, QString&)), this, SLOT(SlotOutFeedStorel(FeedTypeEnum &, int&, QString&, QString&)));
	pQtWidget->setAttribute(Qt::WA_DeleteOnClose);
	pQtWidget->setWindowModality(Qt::ApplicationModal);
	pQtWidget->show();
}

void FeedStoreManagerWdiget::mouseDoubleClickEvent(QMouseEvent *event)
{
	Q_UNUSED(event); //没有实质性的作用，只是用来允许event可以不使用，用来避免编译器警告
	emit ui->feedstore_max_restore_btn->clicked();
}

void FeedStoreManagerWdiget::paintEvent(QPaintEvent *event)
{
	QPainterPath path;
	path.setFillRule(Qt::WindingFill);
	path.addRect(0, 0, this->width(), 40);
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing, true);
	painter.fillPath(path, QBrush(QColor(41, 57, 85)));
	{
		QPainterPath path;
		path.setFillRule(Qt::WindingFill);
		path.addRect(0, 40, this->width(), this->height());
		QPainter painter(this);
		painter.setRenderHint(QPainter::Antialiasing, true);
		//painter.fillPath(path, QBrush(QColor(68, 71, 77)));
		painter.fillPath(path, QBrush(QColor(54, 78, 111)));
	}
}

QWidget* FeedStoreManagerWdiget::getDragnWidget()
{
	return ui->child_widget_title;
}

void FeedStoreManagerWdiget::InitOption()
{
	m_NavButtonList << ui->feedstore_detail_opt << ui->feedstore_in_out_opt
		<< ui->area_detail_opt;
	QList<QChar> pixChar;
	pixChar << 0xf509 << 0xf1fe << 0xf2a3;
	QColor normalBgColor = QColor("#364E6F");
	QColor hoverBgColor = QColor("#478CB6");
	QColor checkBgColor = QColor("#478CB6");
	QColor normalTextColor = QColor("#FFFFFF");
	QColor hoverTextColor = QColor("#FFFFFF");
	QColor checkTextColor = QColor("#FFFFFF");
	for (int i = 0; i < m_NavButtonList.count(); i++) {

		m_NavButtonList.at(i)->setLineColor(QColor("#029FEA"));
		///mNavButtonList.at(i)->setShowLine(true);
		m_NavButtonList.at(i)->setTextAlign(NavButton::TextAlign_Left);
		m_NavButtonList.at(i)->setTrianglePosition(NavButton::TrianglePosition_Right);
		//mNavButtonList.at(i)->setLinePosition(NavButton::LinePosition_Top);

		m_NavButtonList.at(i)->setPaddingLeft(5);
		m_NavButtonList.at(i)->setLineSpace(1);
		m_NavButtonList.at(i)->setLineWidth(5);
		m_NavButtonList.at(i)->setLineColor(QColor(255, 107, 107));
		m_NavButtonList.at(i)->setShowTriangle(true);

		m_NavButtonList.at(i)->setShowIcon(true);
		m_NavButtonList.at(i)->setIconSpace(ICOSPACE);
		m_NavButtonList.at(i)->setIconSize(QSize(ICONSIZE, ICONSIZE));

		//分开设置图标
		QChar icon = pixChar.at(i);
		QPixmap iconNormal = IconHelper::Instance()->getPixmap(normalTextColor.name(), icon, ICONFONTSIZE, PIXMAPSIZE, PIXMAPSIZE);
		QPixmap iconHover = IconHelper::Instance()->getPixmap(hoverTextColor.name(), icon, ICONFONTSIZE, PIXMAPSIZE, PIXMAPSIZE);
		QPixmap iconCheck = IconHelper::Instance()->getPixmap(checkTextColor.name(), icon, ICONFONTSIZE, PIXMAPSIZE, PIXMAPSIZE);

		m_NavButtonList.at(i)->setIconNormal(iconNormal);
		m_NavButtonList.at(i)->setIconHover(iconHover);
		m_NavButtonList.at(i)->setIconCheck(iconCheck);

		m_NavButtonList.at(i)->setNormalBgColor(normalBgColor);
		m_NavButtonList.at(i)->setHoverBgColor(hoverBgColor);
		m_NavButtonList.at(i)->setCheckBgColor(checkBgColor);
		m_NavButtonList.at(i)->setNormalTextColor(normalTextColor);
		m_NavButtonList.at(i)->setHoverTextColor(hoverTextColor);
		m_NavButtonList.at(i)->setCheckTextColor(checkTextColor);

		connect(m_NavButtonList.at(i), &QPushButton::clicked, this, &FeedStoreManagerWdiget::SlotOptionClick);
	}
	m_NavButtonList.at(0)->setChecked(true);
}

void FeedStoreManagerWdiget::initTableView()
{
	m_pViewModelFeedTotalDetail = new QStandardItemModel();
	ui->total_feed_store_tableView->setModel(m_pViewModelFeedTotalDetail);
	m_pViewModelFeedTotalDetail->setColumnCount(8);
	m_pViewModelFeedTotalDetail->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("ID"));
	m_pViewModelFeedTotalDetail->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("供应商"));
	m_pViewModelFeedTotalDetail->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("物品名称"));
	m_pViewModelFeedTotalDetail->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("物品规格"));
	m_pViewModelFeedTotalDetail->setHeaderData(4, Qt::Horizontal, QString::fromLocal8Bit("单位"));
	m_pViewModelFeedTotalDetail->setHeaderData(5, Qt::Horizontal, QString::fromLocal8Bit("成本单价"));
	m_pViewModelFeedTotalDetail->setHeaderData(6, Qt::Horizontal, QString::fromLocal8Bit("数量"));
	m_pViewModelFeedTotalDetail->setHeaderData(7, Qt::Horizontal, QString::fromLocal8Bit("总价值"));
	onSetTableAttribute(ui->total_feed_store_tableView, 8, false);
	m_pViewModelTotalDetail_in_out_return = new QStandardItemModel();
	ui->feedstore_in_out_tableView->setModel(m_pViewModelTotalDetail_in_out_return);
	m_pViewModelTotalDetail_in_out_return->setColumnCount(8);
	m_pViewModelTotalDetail_in_out_return->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("ID"));
	m_pViewModelTotalDetail_in_out_return->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("时间"));
	m_pViewModelTotalDetail_in_out_return->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("物品名称"));
	m_pViewModelTotalDetail_in_out_return->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("数量"));
	m_pViewModelTotalDetail_in_out_return->setHeaderData(4, Qt::Horizontal, QString::fromLocal8Bit("成本单价"));
	m_pViewModelTotalDetail_in_out_return->setHeaderData(5, Qt::Horizontal, QString::fromLocal8Bit("剩余数量"));
	m_pViewModelTotalDetail_in_out_return->setHeaderData(6, Qt::Horizontal, QString::fromLocal8Bit("剩余总额"));
	m_pViewModelTotalDetail_in_out_return->setHeaderData(7, Qt::Horizontal, QString::fromLocal8Bit("区域"));
	onSetTableAttribute(ui->feedstore_in_out_tableView, 8, false);	
	m_pViewModelTotalArea = new QStandardItemModel();
	ui->area_feed_detail_tableView->setModel(m_pViewModelTotalArea);
	m_pViewModelTotalArea->setColumnCount(6);
	m_pViewModelTotalArea->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("ID"));
	m_pViewModelTotalArea->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("区域"));
	m_pViewModelTotalArea->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("物品名称"));
	m_pViewModelTotalArea->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("成本单价"));
	m_pViewModelTotalArea->setHeaderData(4, Qt::Horizontal, QString::fromLocal8Bit("数量"));
	m_pViewModelTotalArea->setHeaderData(5, Qt::Horizontal, QString::fromLocal8Bit("总价值"));
	onSetTableAttribute(ui->area_feed_detail_tableView, 6, false);
}
