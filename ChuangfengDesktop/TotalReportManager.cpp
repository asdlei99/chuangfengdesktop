#include "TotalReportManager.h"
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
#include "SingletonHttpRequest.h"
#include "globalVariable.h"


void TotalReportManager::InitLayout()
{
 	m_pViewModel = new QStandardItemModel();
 	ui->total_reporttableView->setModel(m_pViewModel);
 	m_pViewModel->setColumnCount(8);
 	m_pViewModel->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("项目"));
 	m_pViewModel->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("借方"));
 	m_pViewModel->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("贷方"));
 	m_pViewModel->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("结余"));
 	m_pViewModel->setHeaderData(4, Qt::Horizontal, QString::fromLocal8Bit(""));
 	m_pViewModel->setHeaderData(5, Qt::Horizontal, QString::fromLocal8Bit("借方"));
 	m_pViewModel->setHeaderData(6, Qt::Horizontal, QString::fromLocal8Bit("贷方"));
 	m_pViewModel->setHeaderData(7, Qt::Horizontal, QString::fromLocal8Bit("结余"));
 	onSetTableAttribute(ui->total_reporttableView, 8);
 	ui->total_reporttableView->horizontalHeader()->setStretchLastSection(false);
	
}


TotalReportManager::TotalReportManager(QWidget *parent)
	:MoveableFramelessWindow(parent)
	, ui(new Ui::totalreportmanager)
{
	ui->setupUi(this);
	connect(ui->close_btn, &QPushButton::clicked, this, &QWidget::close);
	connect(ui->max_restore_btn, &QPushButton::clicked, this, &TotalReportManager::updateMaximize);
	connect(ui->min_btn, &QPushButton::clicked, this, &QWidget::showMinimized);
	ui->max_restore_btn->setToolTip(QString::fromLocal8Bit("最大化"));
	//设置按钮的属性名为"maximizeProperty"
	ui->max_restore_btn->setProperty("maximizeProperty", "maximize");
	ui->max_restore_btn->setStyle(QApplication::style());
	InitLayout();
	
	QDateTime current_date_time = QDateTime::currentDateTime();
	ui->total_report_enddateEdit->setCalendarPopup(true);
	ui->total_report_enddateEdit->setDateTime(current_date_time);
	ui->totalreport_startdateEdit->setCalendarPopup(true);
	ui->totalreport_startdateEdit->setDateTime(current_date_time);
	connect(ui->totalreport_search_btn, &QPushButton::clicked, this, &TotalReportManager::SlotSearchBtnAction);
	connect(ui->totalreport_export_btn, &QPushButton::clicked, this, [this]()->void {
		QThread *m_pThread = new QThread;
		this->moveToThread(m_pThread);
		connect(m_pThread, SIGNAL(started()), this, SLOT(SlotThreadExportReport()));
		connect(m_pThread, SIGNAL(finished()), m_pThread, SLOT(deleteLater()));
		m_pThread->start();
		
	});
	m_tableViewMap.clear();
}


TotalReportManager::~TotalReportManager()
{
}

void TotalReportManager::updateMaximize()
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

void TotalReportManager::slotCheckBoxStateChanged(bool status)
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

void TotalReportManager::SlotSearchBtnAction()
{
	m_tableViewMap.clear();
	m_pViewModel->removeRows(0, m_pViewModel->rowCount());
	QThread *m_pThread = new QThread;
	connect(m_pThread, SIGNAL(started()), this, SLOT(SlotThreadSearchGeneral()));
	connect(m_pThread, SIGNAL(finished()), m_pThread, SLOT(deleteLater()));
	m_pThread->start();
}

void TotalReportManager::SlotThreadSearchGeneral()
{

	QString strParam = QString("starttime=%1&endtime=%2").arg(ui->totalreport_startdateEdit->text()).arg(ui->total_report_enddateEdit->text());
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
			for (int i = array.size()-1; i >=0; i--)
			{
				QJsonValue userArray = array.at(i);
				QJsonObject userObject = userArray.toObject();
				if (i == array.size() - 1)
				{
					m_initGeneral = userObject["surplus"].toString().toDouble() + userObject["pay"].toString().toDouble() 
						- userObject["income"].toString().toDouble();
				}
				tableViewItemStruct&item = m_tableViewMap[userObject["task_name"].toString()];
				item.generalIncome += userObject["income"].toString().toDouble();
				item.generalPay += userObject["pay"].toString().toDouble();
				item.bType |= 0x01;
				
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

	SingletonHttpRequest::getInstance()->RequestPost("http://127.0.0.1:80/zerg/public/index.php/getBakDetail"
		, TempToken, strParam, responseData);


	 parse_doucment = QJsonDocument::fromJson(responseData, &json_error);
	if (json_error.error == QJsonParseError::NoError)
	{
		if (parse_doucment.isArray())
		{
			QJsonArray array = parse_doucment.array();
			for (int i = array.size()-1; i >=0; i--)
			{
				QJsonValue userArray = array.at(i);
				QJsonObject userObject = userArray.toObject();
				if (i == array.size() - 1)
				{
					m_initBak = userObject["surplus"].toString().toDouble() + userObject["pay"].toString().toDouble()
						- userObject["income"].toString().toDouble();
				}
				
				tableViewItemStruct&item = m_tableViewMap[userObject["task_name"].toString()];
				item.bakIncome += userObject["income"].toString().toDouble();
				item.bakPay += userObject["pay"].toString().toDouble();
				item.bType |= 0x10;
				
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
	AddGeneralTableview();
}

void TotalReportManager::FormatTableView()
{
	ui->total_reporttableView->setColumnWidth(0, 160);
	ui->total_reporttableView->setColumnWidth(1, 80);
	ui->total_reporttableView->setColumnWidth(2, 80);
	ui->total_reporttableView->setColumnWidth(3, 80);

	ui->total_reporttableView->setColumnWidth(5, 80);
	ui->total_reporttableView->setColumnWidth(6, 80);
	ui->total_reporttableView->setColumnWidth(7, 80);
}

void TotalReportManager::AddGeneralTableview()
{
	double totalGeneralIncome = 0;
	double totalGeneralOut = 0;
	double totalBakIncome = 0;
	double totalBakOut = 0;
	m_pViewModel->setItem(0, 0, new QStandardItem(QString::fromLocal8Bit("总账号期初余额")));
	m_pViewModel->setItem(0, 1, new QStandardItem(QString::number(m_initGeneral)));
	m_pViewModel->setItem(0, 2, new QStandardItem(QString::fromLocal8Bit("")));
	m_pViewModel->setItem(0, 3, new QStandardItem(QString::fromLocal8Bit("")));
	m_pViewModel->setItem(1, 0, new QStandardItem(QString::fromLocal8Bit("备用金初期余额")));
	m_pViewModel->setItem(1, 5, new QStandardItem(QString::number(m_initBak)));
	m_pViewModel->setItem(1, 6, new QStandardItem(QString::fromLocal8Bit("")));
	m_pViewModel->setItem(1, 7, new QStandardItem(QString::fromLocal8Bit("")));
	totalGeneralIncome += m_initGeneral;
	totalBakIncome += m_initBak;
	int nCount = 2;
	for (auto&kvp:m_tableViewMap)
	{
		m_pViewModel->setItem(nCount, 0, new QStandardItem(kvp.first));
		if (kvp.second.bType&0x01)
		{
			totalGeneralIncome += kvp.second.generalIncome;
			totalGeneralOut += kvp.second.generalPay;
			m_pViewModel->setItem(nCount, 1, new QStandardItem(QString::number(kvp.second.generalIncome) == "0" ? "" : QString::number(kvp.second.generalIncome)));
			m_pViewModel->setItem(nCount, 2, new QStandardItem(QString::number(kvp.second.generalPay)=="0"?"": QString::number(kvp.second.generalPay)));
			m_pViewModel->setItem(nCount, 3, new QStandardItem(QString::fromLocal8Bit("")));
		}
		if (kvp.second.bType & 0x10)
		{
			totalBakIncome += kvp.second.bakIncome;
			totalBakOut += kvp.second.bakPay;
			m_pViewModel->setItem(nCount, 5, new QStandardItem(QString::number(kvp.second.bakIncome) == "0" ? "" : QString::number(kvp.second.bakIncome)));
			m_pViewModel->setItem(nCount, 6, new QStandardItem(QString::number(kvp.second.bakPay) == "0" ? "" : QString::number(kvp.second.bakPay)));
			m_pViewModel->setItem(nCount, 7, new QStandardItem(QString::fromLocal8Bit("")));
		}
		nCount++;
	}

	m_pViewModel->setItem(nCount, 0, new QStandardItem(QString::fromLocal8Bit("结算")));
	m_pViewModel->setItem(nCount, 1, new QStandardItem(QString::number(totalGeneralIncome)));
	m_pViewModel->setItem(nCount, 2, new QStandardItem(QString::number(totalGeneralOut)));
	m_pViewModel->setItem(nCount, 3, new QStandardItem(QString::number(totalGeneralIncome- totalGeneralOut)));

	m_pViewModel->setItem(nCount, 5, new QStandardItem(QString::number(totalBakIncome)));
	m_pViewModel->setItem(nCount, 6, new QStandardItem(QString::number(totalBakOut)));
	m_pViewModel->setItem(nCount, 7, new QStandardItem(QString::number(totalBakIncome- totalBakOut)));
	FormatTableView();
}

void TotalReportManager::SlotThreadExportReport()
{
	//多线程必须初始化
	CoInitializeEx(NULL, COINIT_MULTITHREADED);
	m_ExcelPath = "";
	exportToExcel(m_ExcelPath);
	if (m_ExcelPath != "")
	{
		StatementObject test(m_ExcelPath);
		test.FillTableData(m_initGeneral, m_initBak, m_tableViewMap);
		emit sig_NotifyMsg(QString::fromLocal8Bit("导出成功！"), 0);
	}
	
}



void TotalReportManager::mouseDoubleClickEvent(QMouseEvent *event)
{
	Q_UNUSED(event); //没有实质性的作用，只是用来允许event可以不使用，用来避免编译器警告
	emit ui->max_restore_btn->clicked();
}

void TotalReportManager::paintEvent(QPaintEvent *event)
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

QWidget* TotalReportManager::getDragnWidget()
{
	return ui->child_widget_title;
}

