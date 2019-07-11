#include "ShareReportManager.h"
#include <QKeyEvent>
#include <QMouseEvent>
#include <QRect>
#include <QPoint>
#include <QGridLayout>
#include <QPainter>
#include <QPen>
#include <QtMath>
#include "iconhelper.h"
#include "commomdef.h"
#include "globalVariable.h"
#include "SingletonHttpRequest.h"

void ShareReportManager::finishedThreadBtnSlot()
{
	ui->sharereport_export_btn->setEnabled(true);
	emit sig_NotifyMsg(QString::fromLocal8Bit("导出成功！"), 0);
}

void ShareReportManager::InitLayout()
{
	m_pViewModel = new QStandardItemModel();
 	ui->share_report_tableview->setModel(m_pViewModel);
 	m_pViewModel->setColumnCount(6);
 	m_pViewModel->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("项目"));
 	m_pViewModel->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("费用"));
 	m_pViewModel->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("饲料药品"));
 	m_pViewModel->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("物料"));
 	m_pViewModel->setHeaderData(4, Qt::Horizontal, QString::fromLocal8Bit("固资分摊"));
	m_pViewModel->setHeaderData(5, Qt::Horizontal, QString::fromLocal8Bit("总金额"));
 	onSetTableAttribute(ui->share_report_tableview, 6);
	ui->share_report_tableview->horizontalHeader()->setStretchLastSection(false);
 	
}


ShareReportManager::ShareReportManager(QWidget *parent)
	:MoveableFramelessWindow(parent)
	, ui(new Ui::shareReport)
{
	ui->setupUi(this);
	connect(ui->close_btn, &QPushButton::clicked, this, &QWidget::close);
	connect(ui->max_restore_btn, &QPushButton::clicked, this, &ShareReportManager::updateMaximize);
	connect(ui->min_btn, &QPushButton::clicked, this, &QWidget::showMinimized);
	ui->max_restore_btn->setToolTip(QString::fromLocal8Bit("最大化"));
	//设置按钮的属性名为"maximizeProperty"
	ui->max_restore_btn->setProperty("maximizeProperty", "maximize");
	ui->max_restore_btn->setStyle(QApplication::style());
	InitLayout();
	QDateTime current_date_time = QDateTime::currentDateTime();
	ui->share_report_enddateEdit->setCalendarPopup(true);
	ui->share_report_enddateEdit->setDateTime(current_date_time);
	ui->share_report_startdateEdit->setCalendarPopup(true);
	ui->share_report_startdateEdit->setDateTime(current_date_time);
	
	connect(ui->share_report_search_btn, &QPushButton::clicked, this, [this]()->void {
		m_list.clear();
		for (auto&kvp : g_CostAreaList)
		{
			ShareInfoStruct&item = m_list[kvp.second.areaName];
			item.costName = kvp.second.costAreaName;
		}
		
		m_pViewModel->removeRows(0, m_pViewModel->rowCount());
		QThread *m_pThread = new QThread;
		connect(m_pThread, SIGNAL(started()), this, SLOT(SlotThreadGetCostsShare()));
		connect(m_pThread, SIGNAL(finished()), m_pThread, SLOT(deleteLater()));
		m_pThread->start();
	});

	connect(ui->sharereport_export_btn, &QPushButton::clicked, this, [this]()->void {
		m_ExcelPath = QFileDialog::getSaveFileName(0, QString::fromLocal8Bit("导出表格"), ".", "Microsoft Office(*.xlsx)");//获取保存路径
		if (!m_ExcelPath.isEmpty()) {
			ui->sharereport_export_btn->setEnabled(false);
			costShareObject* pthread = new costShareObject( m_list,m_ExcelPath);
			connect(pthread, SIGNAL(finished()), this, SLOT(finishedThreadBtnSlot()));
			pthread->start();
		}

	});

}


ShareReportManager::~ShareReportManager()
{
}

void ShareReportManager::updateMaximize()
{
	QWidget *pWindow = this->window(); //获得标题栏所在的窗口
	pWindow->isMaximized() ? pWindow->showNormal() : pWindow->showMaximized();  //窗口最大化/还原显示
	if (pWindow->isTopLevel())
	{
		bool bMaximize = pWindow->isMaximized(); //判断窗口是不是最大化状态，是则返回true，否则返回false
		if (bMaximize)
		{
			//目前窗口是最大化状态，则最大化/还原的toolTip设置为"Restore"
			ui->max_restore_btn->setToolTip(QString::fromLocal8Bit("还原"));
			//设置按钮的属性名为"maximizeProperty"
			ui->max_restore_btn->setProperty("maximizeProperty", "restore");
		}
		else
		{
			//目前窗口是还原状态，则最大化/还原的toolTip设置为"Maximize"
			ui->max_restore_btn->setToolTip(QString::fromLocal8Bit("最大化"));
			//设置按钮的属性名为"maximizeProperty"
			ui->max_restore_btn->setProperty("maximizeProperty", "maximize");
		}

		ui->max_restore_btn->setStyle(QApplication::style());
	}
}

void ShareReportManager::slotCheckBoxStateChanged(bool status)
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

void ShareReportManager::SlotThreadGetCostsShare()
{
	GetGeneralCostsShare();
	GetBakCostsShare();
	GetFeedingCostsShare();
	GetMaterialCostsShare();
	GetFixedAssetCostsShare();
	addTableView();

}

void ShareReportManager::mouseDoubleClickEvent(QMouseEvent *event)
{
	Q_UNUSED(event); //没有实质性的作用，只是用来允许event可以不使用，用来避免编译器警告
	emit ui->max_restore_btn->clicked();
}

void ShareReportManager::paintEvent(QPaintEvent *event)
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

QWidget* ShareReportManager::getDragnWidget()
{
	return ui->child_widget_title;
}

void ShareReportManager::GetGeneralCostsShare()
{

	QString strParam = QString("starttime=%1&endtime=%2").arg(ui->share_report_startdateEdit->text()).arg(ui->share_report_enddateEdit->text());
	QByteArray responseData;
	SingletonHttpRequest::getInstance()->RequestPost("http://127.0.0.1:80/zerg/public/index.php/getGeneralDetail"
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
				QJsonValue userArray = array.at(i);
				QJsonObject userObject = userArray.toObject();
				auto itor = g_CostAreaList.find(userObject["costarea_name"].toString());
				if (itor != g_CostAreaList.end())
				{
					auto &iter = m_list.find(itor->second.areaName);
					if (iter != m_list.end())
					{
						iter->second.LogisticsCosts += userObject["pay"].toString().toDouble();
					}
				}	
			}
		}
		else
		{
			QJsonObject rootObject = parse_doucment.object();
			if (!rootObject["error_code"].isNull())//
			{
				int errorcode = rootObject["error_code"].toInt();
				QString strMsg = rootObject["msg"].toString();
			//	emit sig_NotifyMsg(strMsg, errorcode);
			}
		}
	}
	else {
		int errorcode = 404;
		//emit sig_NotifyMsg(QString::fromLocal8Bit("网络请求异常！"), errorcode);
	}

	 strParam = QString("starttime=%1&endtime=%2").arg(ui->share_report_startdateEdit->dateTime().toString("yyyy-MM-dd")).arg(ui->share_report_enddateEdit->dateTime().toString("yyyy-MM-dd"));

	SingletonHttpRequest::getInstance()->RequestPost("http://127.0.0.1:80/zerg/public/index.php/getBakDetail"
		, TempToken, strParam, responseData);


	 parse_doucment = QJsonDocument::fromJson(responseData, &json_error);
	if (json_error.error == QJsonParseError::NoError)
	{
		if (parse_doucment.isArray())
		{
			QJsonArray array = parse_doucment.array();
			for (int i = 0; i < array.size(); i++)
			{
				QJsonValue userArray = array.at(i);
				QJsonObject userObject = userArray.toObject();
				auto itor = g_CostAreaList.find(userObject["costarea_name"].toString());
				if (itor != g_CostAreaList.end())
				{
					auto &iter = m_list.find(itor->second.areaName);
					if (iter != m_list.end())
					{
						iter->second.LogisticsCosts += userObject["pay"].toString().toDouble();
					}
				}
				
			}
		}
		else
		{
			QJsonObject rootObject = parse_doucment.object();
			if (!rootObject["error_code"].isNull())//
			{
				int errorcode = rootObject["error_code"].toInt();
				QString strMsg = rootObject["msg"].toString();
				//emit sig_NotifyMsg(strMsg, errorcode);
			}
		}
	}
	else {
		int errorcode = 404;
		//emit sig_NotifyMsg(QString::fromLocal8Bit("网络请求异常！"), errorcode);
	}
}

void ShareReportManager::GetBakCostsShare()
{

}

void ShareReportManager::GetMaterialCostsShare()
{
	QString strParam = QString("starttime=%1&endtime=%2")
		.arg(ui->share_report_startdateEdit->text()).arg(ui->share_report_enddateEdit->text());
	QByteArray responseData;
	SingletonHttpRequest::getInstance()->RequestPost("http://127.0.0.1:80/zerg/public/index.php/SearchOutMaterialByReport"
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
				auto&itor = m_list.find(materialObject["outarea"].toString());
				if (itor != m_list.end())
				{
					itor->second.MaterialCosts += materialObject["totalprice"].toString().toDouble();
				}
			}
		}
		else
		{
			QJsonObject rootObject = parse_doucment.object();
			if (!rootObject["error_code"].isNull())//
			{
				int errorcode = rootObject["error_code"].toInt();
				QString strMsg = rootObject["msg"].toString();
				//emit sig_NotifyMsg(strMsg, errorcode);
			}
		}
	}
	else {
		int errorcode = 404;
		//emit sig_NotifyMsg(QString::fromLocal8Bit("网络请求异常！"), errorcode);
	}
}

void ShareReportManager::GetFeedingCostsShare()
{
	QString strParam;
	QByteArray responseData;
	
		strParam = QString("starttime=%1&endtime=%2").arg(ui->share_report_startdateEdit->text()).arg(ui->share_report_enddateEdit->text());
		SingletonHttpRequest::getInstance()->RequestPost("http://127.0.0.1:80/zerg/public/index.php/SearchOutFeedStoreByReport"
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
				auto&itor = m_list.find(materialObject["outarea"].toString());
				if (itor != m_list.end())
				{
					itor->second.FeedCosts += materialObject["totalprice"].toString().toDouble();
				}
				
			}
		}
		else
		{
			QJsonObject rootObject = parse_doucment.object();
			if (!rootObject["error_code"].isNull())//
			{
				int errorcode = rootObject["error_code"].toInt();
				QString strMsg = rootObject["msg"].toString();
				//emit sig_NotifyMsg(strMsg, errorcode);
			}
		}
	}
	else {
		int errorcode = 404;
		//emit sig_NotifyMsg(QString::fromLocal8Bit("网络请求异常！"), errorcode);
	}
}

void ShareReportManager::GetFixedAssetCostsShare()
{
	int year = ui->share_report_enddateEdit->date().year();
	int mouth = ui->share_report_enddateEdit->date().month();
	QString maxtime = QString("%1-%2-%3").arg(QString::number(year)).arg(QString::number(mouth)).arg(QString::number(mouthMax[mouth-1]));

	QString strParam = QString("over_time=%1").arg(maxtime);
	QByteArray responseData;
	SingletonHttpRequest::getInstance()->RequestPost("http://127.0.0.1:80/zerg/public/index.php/SearchFixedAsset"
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
				 auto&itor = m_list.find(materialObject["outarea"].toString());
				 if (itor != m_list.end())
				 {
					 itor->second.FixedAssetCosts += materialObject["total"].toString().toDouble() / materialObject["periods"].toInt();
				 }	
			}
		}
	}
	
}

void ShareReportManager::addTableView()
{
	int nCount = 0;
	double a=0, b=0, c=0, d=0,e=0;
	for (auto&kvp:m_list)
	{
		m_pViewModel->setItem(nCount, 0, new QStandardItem(kvp.first));
		m_pViewModel->setItem(nCount, 1, new QStandardItem(QString::number(kvp.second.LogisticsCosts)));
		a += kvp.second.LogisticsCosts;
		m_pViewModel->setItem(nCount, 2, new QStandardItem(QString::number(kvp.second.FeedCosts)));
		b += kvp.second.FeedCosts;
		m_pViewModel->setItem(nCount, 3, new QStandardItem(QString::number(kvp.second.MaterialCosts)));
		c += kvp.second.MaterialCosts;
		m_pViewModel->setItem(nCount, 4, new QStandardItem(QString::number(kvp.second.FixedAssetCosts)));
		d += kvp.second.FixedAssetCosts;
		nCount++;
	}
	m_pViewModel->setItem(nCount, 0, new QStandardItem(QString::fromLocal8Bit("总计")));
	m_pViewModel->setItem(nCount, 1, new QStandardItem(QString::number(a)));

	m_pViewModel->setItem(nCount, 2, new QStandardItem(QString::number(b)));

	m_pViewModel->setItem(nCount, 3, new QStandardItem(QString::number(c)));

	m_pViewModel->setItem(nCount, 4, new QStandardItem(QString::number(d)));
	m_pViewModel->setItem(nCount, 5, new QStandardItem(QString::number(d+c+b+a)));

	ui->share_report_tableview->setColumnWidth(0, 160);
	ui->share_report_tableview->setColumnWidth(1, 80);
	ui->share_report_tableview->setColumnWidth(2, 80);
	ui->share_report_tableview->setColumnWidth(3, 80);
}

