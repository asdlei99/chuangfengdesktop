#include "NopayReportManger.h"
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

void NopayReportManger::InitLayout()
{
	  	m_pViewModel = new QStandardItemModel();
  	ui->nopayreport_tableView->setModel(m_pViewModel);
  	m_pViewModel->setColumnCount(8);
  	m_pViewModel->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("供应商"));
  	m_pViewModel->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("摘要"));
  	m_pViewModel->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("期初金额"));
  	m_pViewModel->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("调账或扣款"));
  	m_pViewModel->setHeaderData(4, Qt::Horizontal, QString::fromLocal8Bit("新增应付款"));
  	m_pViewModel->setHeaderData(5, Qt::Horizontal, QString::fromLocal8Bit("退货"));
  	m_pViewModel->setHeaderData(6, Qt::Horizontal, QString::fromLocal8Bit("已付款"));
  	m_pViewModel->setHeaderData(7, Qt::Horizontal, QString::fromLocal8Bit("期末余额"));
  	onSetTableAttribute(ui->nopayreport_tableView, 8);
	ui->nopayreport_tableView->horizontalHeader()->setStretchLastSection(false);
  	
}


void NopayReportManger::SlotThreadSearchBakInfo()
{
	map<QString, vector<DuesStruct>> tempList;
	QString strParam = QString("");
	QByteArray responseData;
	SingletonHttpRequest::getInstance()->RequestPost("http://127.0.0.1:80/zerg/public/index.php/getDuesList"
		, TempToken, strParam, responseData);

	QJsonParseError json_error;
	QJsonDocument parse_doucment = QJsonDocument::fromJson(responseData, &json_error);
	if (json_error.error == QJsonParseError::NoError)
	{
		if (parse_doucment.isArray())
		{
			QJsonArray array = parse_doucment.array();
			for (int i = array.size() - 1; i >= 0; i--)
			{
				QJsonValue userArray = array.at(i);
				QJsonObject userObject = userArray.toObject();
				DuesStruct&item = m_DuesInfoMap[userObject["supplier"].toString()];
				item.abstract = userObject["abstract"].toString();
				item.initDues = userObject["surplus"].toString().toDouble();
				item.surplus = userObject["surplus"].toString().toDouble();
				item.supplier = userObject["supplier"].toString();
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


	 strParam = QString("starttime=%1&endtime=%2").arg(ui->nopay_report_startdateEdit->text()).arg(ui->nopay_report_enddateEdit->text());
	
	SingletonHttpRequest::getInstance()->RequestPost("http://127.0.0.1:80/zerg/public/index.php/getDuesDetail"
		, TempToken, strParam, responseData);


	 parse_doucment = QJsonDocument::fromJson(responseData, &json_error);
	if (json_error.error == QJsonParseError::NoError)
	{
		if (parse_doucment.isArray())
		{
			QJsonArray array = parse_doucment.array();
			for (int i = array.size() - 1; i >= 0; i--)
			{
				QJsonValue userArray = array.at(i);
				QJsonObject userObject = userArray.toObject();
				vector<DuesStruct>&vec = tempList[userObject["supplier"].toString()];
				DuesStruct item;
				item.abstract = userObject["abstract"].toString();
				item.added = userObject["added"].toString().toDouble();
				item.adjustment = userObject["adjustment"].toString().toDouble();
				item.back = userObject["back"].toString().toDouble();
				item.pay = userObject["Payment"].toString().toDouble();
				item.initDues = userObject["initDues"].toString().toDouble();
				item.surplus = userObject["surplus"].toString().toDouble();
				item.supplier = userObject["supplier"].toString();
				vec.push_back(item);
				
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

	for (auto&kvp:m_DuesInfoMap)
	{
		auto &itor = tempList.find(kvp.first);
		if (tempList.end() != itor)
		{
			int nCount = itor->second.size();
			for (auto i = 0;i< nCount;i++)
			{
				if (i == 0)
				{
					kvp.second.initDues = itor->second[i].initDues;
				}
				if (i == nCount -1)
				{
					kvp.second.surplus = itor->second[i].surplus;
				}
				kvp.second.added += itor->second[i].added;
				kvp.second.adjustment += itor->second[i].adjustment;
				kvp.second.back += itor->second[i].back;
				kvp.second.pay += itor->second[i].pay;
			}
		}
	}
	
	int nCount = 0;
	for (auto&kvp : m_DuesInfoMap)
	{
		m_pViewModel->setItem(nCount, 0, new QStandardItem(kvp.second.supplier));
		m_pViewModel->setItem(nCount, 1, new QStandardItem(kvp.second.abstract));
		m_pViewModel->setItem(nCount, 2, new QStandardItem(QString::number(kvp.second.initDues)));
		m_pViewModel->setItem(nCount, 3, new QStandardItem(QString::number(kvp.second.adjustment)));
		m_pViewModel->setItem(nCount, 4, new QStandardItem(QString::number(kvp.second.added)));
		m_pViewModel->setItem(nCount, 5, new QStandardItem(QString::number(kvp.second.back)));
		m_pViewModel->setItem(nCount, 6, new QStandardItem(QString::number(kvp.second.pay)));
		m_pViewModel->setItem(nCount, 7, new QStandardItem(QString::number(kvp.second.surplus)));

		nCount++;
	}
	
	
}

NopayReportManger::NopayReportManger(QWidget *parent)
	:MoveableFramelessWindow(parent)
	, ui(new Ui::noPayReportMannger)
{
	ui->setupUi(this);
	connect(ui->close_btn, &QPushButton::clicked, this, &QWidget::close);
	connect(ui->max_restore_btn, &QPushButton::clicked, this, &NopayReportManger::updateMaximize);
	connect(ui->min_btn, &QPushButton::clicked, this, &QWidget::showMinimized);
	ui->max_restore_btn->setToolTip(QString::fromLocal8Bit("最大化"));
	//设置按钮的属性名为"maximizeProperty"
	ui->max_restore_btn->setProperty("maximizeProperty", "maximize");
	ui->max_restore_btn->setStyle(QApplication::style());
	InitLayout();
	QDateTime current_date_time = QDateTime::currentDateTime();
	ui->nopay_report_enddateEdit->setCalendarPopup(true);
	ui->nopay_report_enddateEdit->setDateTime(current_date_time);
	ui->nopay_report_startdateEdit->setCalendarPopup(true);
	ui->nopay_report_startdateEdit->setDateTime(current_date_time);
	connect(ui->nopay_report_search_btn, &QPushButton::clicked, this, [this]()->void {
		//m_tableViewMap.clear();
		m_pViewModel->removeRows(0, m_pViewModel->rowCount());
		QThread *m_pThread = new QThread;
		connect(m_pThread, SIGNAL(started()), this, SLOT(SlotThreadSearchBakInfo()));
		connect(m_pThread, SIGNAL(finished()), m_pThread, SLOT(deleteLater()));
		m_pThread->start();
	});
}


NopayReportManger::~NopayReportManger()
{
}

void NopayReportManger::updateMaximize()
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

void NopayReportManger::slotCheckBoxStateChanged(bool status)
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

void NopayReportManger::mouseDoubleClickEvent(QMouseEvent *event)
{
	Q_UNUSED(event); //没有实质性的作用，只是用来允许event可以不使用，用来避免编译器警告
	emit ui->max_restore_btn->clicked();
}

void NopayReportManger::paintEvent(QPaintEvent *event)
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

QWidget* NopayReportManger::getDragnWidget()
{
	return ui->child_widget_title;
}


