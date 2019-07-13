#include "MaterielReportManger.h"
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

void MaterielReportManger::InitLayout()
{
	m_pViewModel = new QStandardItemModel();
	ui->materiel_report_tableView->setModel(m_pViewModel);
	m_pViewModel->setColumnCount(8);
	m_pViewModel->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("项目"));
	m_pViewModel->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("库存"));
	m_pViewModel->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("领用"));
	m_pViewModel->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("结余"));
	m_pViewModel->setHeaderData(4, Qt::Horizontal, QString::fromLocal8Bit(" "));
	m_pViewModel->setHeaderData(5, Qt::Horizontal, QString::fromLocal8Bit("区域"));
	m_pViewModel->setHeaderData(6, Qt::Horizontal, QString::fromLocal8Bit("待摊"));
	m_pViewModel->setHeaderData(7, Qt::Horizontal, QString::fromLocal8Bit("本期分摊"));
	onSetTableAttribute(ui->materiel_report_tableView, 8);
	ui->materiel_report_tableView->horizontalHeader()->setStretchLastSection(false);
}


MaterielReportManger::MaterielReportManger(QWidget *parent)
	:MoveableFramelessWindow(parent)
	, ui(new Ui::materielreport)
{
	ui->setupUi(this);
	connect(ui->close_btn, &QPushButton::clicked, this, &QWidget::close);
	connect(ui->max_restore_btn, &QPushButton::clicked, this, &MaterielReportManger::updateMaximize);
	connect(ui->min_btn, &QPushButton::clicked, this, &QWidget::showMinimized);
	ui->max_restore_btn->setToolTip(QString::fromLocal8Bit("最大化"));
	//设置按钮的属性名为"maximizeProperty"
	ui->max_restore_btn->setProperty("maximizeProperty", "maximize");
	ui->max_restore_btn->setStyle(QApplication::style());
	InitLayout();
	QDateTime current_date_time = QDateTime::currentDateTime();
	ui->materielreport_startdateEdit->setCalendarPopup(true);
	ui->materielreport_startdateEdit->setDateTime(current_date_time);
	ui->materiel_report_enddateEdit->setCalendarPopup(true);
	ui->materiel_report_enddateEdit->setDateTime(current_date_time);
	connect(ui->materielreport_search_btn, &QPushButton::clicked, this, [this]()->void {
		m_pViewModel->removeRows(0, m_pViewModel->rowCount());
		 m_initAmount = 0;
		 m_currentAmout = 0;
		 m_FixedUse = 0;
		 m_materialUseList.clear();
		 m_fixedList.clear();
		QThread *m_pThread = new QThread;
		connect(m_pThread, SIGNAL(started()), this, SLOT(SlotThreadGetMaterialInfo()));
		connect(m_pThread, SIGNAL(finished()), m_pThread, SLOT(deleteLater()));
		m_pThread->start();
	});

	connect(ui->materielreport_export_btn, &QPushButton::clicked, this, [this]()->void {
		QString m_ExcelPath = QFileDialog::getSaveFileName(0, QString::fromLocal8Bit("导出表格"), ".", "Microsoft Office(*.xlsx)");//获取保存路径
		if (!m_ExcelPath.isEmpty()) {
			ui->materielreport_export_btn->setEnabled(false);
			MatterObject* pthread = new MatterObject(m_ExcelPath, m_initAmount, m_currentAmout, m_FixedUse, m_materialUseList,m_fixedList);
			connect(pthread, SIGNAL(finished()), this, SLOT(finishedThreadBtnSlot()));
			pthread->start();
		}

	});
}


MaterielReportManger::~MaterielReportManger()
{
}

void MaterielReportManger::updateMaximize()
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

void MaterielReportManger::slotCheckBoxStateChanged(bool status)
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

void MaterielReportManger::mouseDoubleClickEvent(QMouseEvent *event)
{
	Q_UNUSED(event); //没有实质性的作用，只是用来允许event可以不使用，用来避免编译器警告
	emit ui->max_restore_btn->clicked();
}

void MaterielReportManger::paintEvent(QPaintEvent *event)
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

QWidget* MaterielReportManger::getDragnWidget()
{
	return ui->child_widget_title;
}

void MaterielReportManger::getMaterialTotalPrice(double&all)
{
	QString Url = QString(SerachMaterial).arg(g_strIpAddr).arg(g_strIpPort);
	QString strParam = QString("subject_name=%1").arg("");
	QByteArray responseData;
	SingletonHttpRequest::getInstance()->RequestPost(Url
		, g_token, strParam, responseData);
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
				
				all += materialObject["totalprice"].toString().toDouble();
				
			}
		}
	}
}

void MaterielReportManger::getInComeMaterialSearchTime()
{
	QString Url = QString(SearchInMaterialDetail).arg(g_strIpAddr).arg(g_strIpPort);
	QDateTime current_date_time = QDateTime::currentDateTime();
	QString strParam = QString("starttime=%1&endtime=%2")
		.arg(ui->materielreport_startdateEdit->text()).arg(ui->materiel_report_enddateEdit->text());
	QByteArray responseData;
	SingletonHttpRequest::getInstance()->RequestPost(Url
		, g_token, strParam, responseData);
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
				m_currentAmout += materialObject["price"].toString().toDouble()*materialObject["number"].toInt();
			}
		}
	}
}

void MaterielReportManger::getInComeMaterialCurrentTime(double&add)
{
	QString Url = QString(SearchInMaterialDetail).arg(g_strIpAddr).arg(g_strIpPort);
	QDateTime current_date_time = QDateTime::currentDateTime();
	QString strParam = QString("starttime=%1&endtime=%2")
		.arg(ui->materielreport_startdateEdit->text()).arg(current_date_time.toString("yyyy-MM-dd hh:mm:ss"));
	QByteArray responseData;
	SingletonHttpRequest::getInstance()->RequestPost(Url, g_token, strParam, responseData);
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
				add += materialObject["price"].toString().toDouble()*materialObject["number"].toInt();
			}
		}
	}	
}

void MaterielReportManger::getFixedUseCurrentTime(double&value)
{
	QDateTime current_date_time = QDateTime::currentDateTime();
	QString strParam = QString("starttime=%1&endtime=%2")
		.arg(ui->materielreport_startdateEdit->text()).arg(current_date_time.toString("yyyy-MM-dd hh:mm:ss"));
	QByteArray responseData;
	SingletonHttpRequest::getInstance()->RequestPost("http://127.0.0.1:80/zerg/public/index.php/getFixedUsetoReport"
		, g_token, strParam, responseData);
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
				value += materialObject["total"].toDouble();
			}
		}
	}
}

void MaterielReportManger::getOutMaterialCurrentTime(double&value)
{
	QDateTime current_date_time = QDateTime::currentDateTime();
	QString strParam = QString("starttime=%1&endtime=%2")
		.arg(ui->materielreport_startdateEdit->text()).arg(current_date_time.toString("yyyy-MM-dd hh:mm:ss"));
	QByteArray responseData;
	SingletonHttpRequest::getInstance()->RequestPost("http://127.0.0.1:80/zerg/public/index.php/SearchOutMaterialByReport"
		, g_token, strParam, responseData);
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
				value += materialObject["total"].toString().toDouble();
			}
		}
	}
}

void MaterielReportManger::getOutMaterialUse()
{
	
	QString strParam = QString("starttime=%1&endtime=%2")
		.arg(ui->materielreport_startdateEdit->text()).arg(ui->materiel_report_enddateEdit->text());
	QByteArray responseData;
	SingletonHttpRequest::getInstance()->RequestPost("http://127.0.0.1:80/zerg/public/index.php/SearchOutMaterialByReport"
		, g_token, strParam, responseData);
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
				double&value = m_materialUseList[materialObject["outarea"].toString()];
				value += materialObject["price"].toString().toDouble()*materialObject["number"].toInt();
			}
		}
	}
}

void MaterielReportManger::getFixedUse()
{

	QString strParam = QString("starttime=%1&endtime=%2")
		.arg(ui->materielreport_startdateEdit->text()).arg(ui->materiel_report_enddateEdit->text());
	QByteArray responseData;
	SingletonHttpRequest::getInstance()->RequestPost("http://127.0.0.1:80/zerg/public/index.php/getFixedUsetoReport"
		, g_token, strParam, responseData);
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
				m_FixedUse += materialObject["total"].toString().toDouble();
			}
		}
	}
}
int month_numbers(QString overtime, QString currenttime)
{
	QDateTime overdata;
	overdata = QDateTime::fromString(overtime, "yyyy-MM-dd hh:mm:ss");
	QDateTime currentdata;
	currentdata = QDateTime::fromString(currenttime, "yyyy-MM-dd hh:mm:ss");
	int month_number = 0;
	int overdataYear = overdata.date().year();
	int currentdataYear = currentdata.date().year();
	int overdataMouth = overdata.date().month();
	int  currentdataMouth = currentdata.date().month();
	if (overdataYear < currentdataYear) { //判断月份大小，进行相应加或减
		month_number = abs(overdataYear - currentdataYear) * 12 + abs(overdataMouth - currentdataMouth);
	}
	else {
		month_number = abs(overdataYear - currentdataYear) * 12 - abs(overdataMouth - currentdataMouth);
	}
	return month_number - 1;
}

void MaterielReportManger::getFixedAsset()
{
	int year = ui->materiel_report_enddateEdit->date().year();
	int mouth = ui->materiel_report_enddateEdit->date().month();
	QString maxtime = QString("%1-%2-%3").arg(QString::number(year)).arg(QString::number(mouth)).arg(QString::number(mouthMax[mouth - 1]));

	QString strParam = QString("over_time=%1").arg(maxtime);
	QByteArray responseData;
	SingletonHttpRequest::getInstance()->RequestPost("http://127.0.0.1:80/zerg/public/index.php/SearchFixedAsset"
		, g_token, strParam, responseData);
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
				tuple<double, double>& item = m_fixedList[materialObject["outarea"].toString()];
				get<1>(item) += materialObject["total"].toString().toDouble() / materialObject["periods"].toInt();
				QString test = maxtime + (" 00:00:00");
				int suplis = month_numbers(materialObject["over_time"].toString(), test);
				get<0>(item) += (materialObject["total"].toString().toDouble() / materialObject["periods"].toInt())*suplis;
			}
		}
	}
}

void MaterielReportManger::AddTableView()
{
	int nCount = 0;
	double inCome = 0;
	double out = 0;
	m_pViewModel->setItem(nCount, 0, new QStandardItem(QString::fromLocal8Bit("期初余额")));
	m_pViewModel->setItem(nCount, 1, new QStandardItem(QString::number(m_initAmount)));
	inCome += m_initAmount;
	nCount++;
	m_pViewModel->setItem(nCount, 0, new QStandardItem(QString::fromLocal8Bit("本月购入")));
	m_pViewModel->setItem(nCount, 1, new QStandardItem(QString::number(m_currentAmout)));
	nCount++;
	inCome += m_currentAmout;
	m_pViewModel->setItem(nCount, 0, new QStandardItem(QString::fromLocal8Bit("固资领用")));
	m_pViewModel->setItem(nCount, 2, new QStandardItem(QString::number(m_FixedUse)));
	out += m_FixedUse;
	nCount++;

	for (auto&kvp:m_materialUseList)
	{
		m_pViewModel->setItem(nCount, 0, new QStandardItem(kvp.first));
		m_pViewModel->setItem(nCount, 2, new QStandardItem(QString::number(kvp.second)));
		out += kvp.second;
		nCount++;
	}
	m_pViewModel->setItem(nCount, 0, new QStandardItem(QString::fromLocal8Bit("合计：")));
	m_pViewModel->setItem(nCount, 1, new QStandardItem(QString::number(inCome)));
	m_pViewModel->setItem(nCount, 2, new QStandardItem(QString::number(out)));
	m_pViewModel->setItem(nCount, 3, new QStandardItem(QString::number(inCome- out)));
	
	nCount = 0;
	double a = 0, b = 0;
	for (auto&kvp : m_fixedList)
	{
		m_pViewModel->setItem(nCount, 5, new QStandardItem(kvp.first));
		m_pViewModel->setItem(nCount, 6, new QStandardItem(QString::number(get<0>(kvp.second))));
		a += get<0>(kvp.second);
		m_pViewModel->setItem(nCount, 7, new QStandardItem(QString::number(get<1>(kvp.second))));
		b += get<1>(kvp.second);
		nCount++;
	}
	m_pViewModel->setItem(nCount, 5, new QStandardItem(QString::fromLocal8Bit("合计：")));
	m_pViewModel->setItem(nCount, 6, new QStandardItem(QString::number(a)));
	m_pViewModel->setItem(nCount, 7, new QStandardItem(QString::number(b)));

	ui->materiel_report_tableView->setColumnWidth(0, 160);
	ui->materiel_report_tableView->setColumnWidth(1, 80);
	ui->materiel_report_tableView->setColumnWidth(2, 80);
	ui->materiel_report_tableView->setColumnWidth(3, 80);
}

void MaterielReportManger::finishedThreadBtnSlot()
{
	ui->materielreport_export_btn->setEnabled(true);
	emit sig_NotifyMsg(QString::fromLocal8Bit("导出成功！"), 0);
}

void MaterielReportManger::SlotThreadGetMaterialInfo()
{
	  double dbTotal = 0;
	  getMaterialTotalPrice(dbTotal);
	  double add = 0;
	  getInComeMaterialCurrentTime(add);
	  double outMaterial = 0;
	  getOutMaterialCurrentTime(outMaterial);
		  double fix = 0;
	  getFixedUseCurrentTime(fix);
	  m_initAmount = dbTotal - add+ outMaterial+ fix;
	  getInComeMaterialSearchTime();
	  getFixedUse();
	 
	 getFixedAsset();
	 getOutMaterialUse();
	 AddTableView();
	 
}
