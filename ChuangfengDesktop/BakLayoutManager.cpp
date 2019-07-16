
#include "BakLayoutManager.h"
#include <QKeyEvent>
#include <QMouseEvent>
#include <QRect>
#include <QPoint>
#include <QGridLayout>
#include <QPainter>
#include <QPen>
#include <QtMath>
#include "iconhelper.h"
#include "AddFundDetailWidget.h"
#include "SingletonHttpRequest.h"
#include "globalVariable.h"

BakLayoutManager::BakLayoutManager(QWidget *parent)
	:MoveableFramelessWindow(parent)
	, ui(new Ui::BakManager)
{
	ui->setupUi(this);
	connect(ui->bak_cose_btn, &QPushButton::clicked, this, &QWidget::close);
	connect(ui->bak_max_restore_btn, &QPushButton::clicked, this, &BakLayoutManager::updateMaximize);
	connect(ui->bak_min_btn, &QPushButton::clicked, this, &QWidget::showMinimized);
	connect(ui->bak_add_btn, &QPushButton::clicked, this, [this]()->void {
		AddFundDetailWidget*pQtWidget = new AddFundDetailWidget(PopFundDetailEnum::enBakLayout);
		connect(pQtWidget, SIGNAL(sig_comit(QString&, QString &, QString&, QString&, QString&, QString&)), this, SLOT(SlotAddGeneral(QString&, QString &, QString&, QString&, QString&, QString&)));
		pQtWidget->setAttribute(Qt::WA_DeleteOnClose);
		pQtWidget->setWindowModality(Qt::ApplicationModal);
		pQtWidget->show();
	});
	connect(ui->bak_search_btn, &QPushButton::clicked, this, &BakLayoutManager::SlotSearchBtnAction);
	connect(ui->bak_del_btn, &QPushButton::clicked, this, [this]()->void {
		QThread *m_pThread = new QThread;
		connect(m_pThread, SIGNAL(started()), this, SLOT(SlotThreadRemoveItem()));
		connect(m_pThread, SIGNAL(finished()), m_pThread, SLOT(deleteLater()));
		m_pThread->start();
	});
	ui->bak_max_restore_btn->setToolTip(QString::fromLocal8Bit("最大化"));
	//设置按钮的属性名为"maximizeProperty"
	ui->bak_max_restore_btn->setProperty("maximizeProperty", "maximize");
	ui->bak_max_restore_btn->setStyle(QApplication::style());
	InitLayout();
	QDateTime current_date_time = QDateTime::currentDateTime();
	ui->bak_startdateEdit->setCalendarPopup(true);
	ui->bak_startdateEdit->setDateTime(current_date_time);
	ui->bak_enddateEdit->setCalendarPopup(true);
	ui->bak_enddateEdit->setDateTime(current_date_time);

}


BakLayoutManager::~BakLayoutManager()
{
}

void BakLayoutManager::updateMaximize()
{
	QWidget *pWindow = this->window(); //获得标题栏所在的窗口
	pWindow->isMaximized() ? pWindow->showNormal() : pWindow->showMaximized();  //窗口最大化/还原显示
	if (pWindow->isTopLevel())
	{
		bool bMaximize = pWindow->isMaximized(); //判断窗口是不是最大化状态，是则返回true，否则返回false
		if (bMaximize)
		{
			//目前窗口是最大化状态，则最大化/还原的toolTip设置为"Restore"
			ui->bak_max_restore_btn->setToolTip(QString::fromLocal8Bit("还原"));
			//设置按钮的属性名为"maximizeProperty"
			ui->bak_max_restore_btn->setProperty("maximizeProperty", "restore");
		}
		else
		{
			//目前窗口是还原状态，则最大化/还原的toolTip设置为"Maximize"
			ui->bak_max_restore_btn->setToolTip(QString::fromLocal8Bit("最大化"));
			//设置按钮的属性名为"maximizeProperty"
			ui->bak_max_restore_btn->setProperty("maximizeProperty", "maximize");
		}

		ui->bak_max_restore_btn->setStyle(QApplication::style());
	}
}

void BakLayoutManager::slotCheckBoxStateChanged(bool status)
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

void BakLayoutManager::mouseDoubleClickEvent(QMouseEvent *event)
{
	Q_UNUSED(event); //没有实质性的作用，只是用来允许event可以不使用，用来避免编译器警告
	emit ui->bak_max_restore_btn->clicked();
}

void BakLayoutManager::paintEvent(QPaintEvent *event)
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

QWidget* BakLayoutManager::getDragnWidget()
{
	return ui->child_widget_title;
}

void BakLayoutManager::InitLayout()
{
	m_pViewHeadDeleagte = new CCheckBoxHeaderView(0, Qt::Horizontal, ui->bak_tableView);
	ui->bak_tableView->setHorizontalHeader(m_pViewHeadDeleagte);
	connect(m_pViewHeadDeleagte, SIGNAL(sig_AllChecked(bool)), this, SLOT(slotCheckBoxStateChanged(bool)));
	m_pViewModel = new QStandardItemModel();
	ui->bak_tableView->setModel(m_pViewModel);
	m_pViewModel->setColumnCount(8);
	m_pViewModel->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit(""));
	m_pViewModel->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("日期"));
	m_pViewModel->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("摘要"));
	m_pViewModel->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("借方"));
	m_pViewModel->setHeaderData(4, Qt::Horizontal, QString::fromLocal8Bit("贷方"));
	m_pViewModel->setHeaderData(5, Qt::Horizontal, QString::fromLocal8Bit("结余"));
	m_pViewModel->setHeaderData(6, Qt::Horizontal, QString::fromLocal8Bit("项目"));
	m_pViewModel->setHeaderData(7, Qt::Horizontal, QString::fromLocal8Bit("费用分摊"));
	onSetTableAttribute(ui->bak_tableView, 8);
}

void BakLayoutManager::SlotSearchBtnAction()
{
	m_pViewModel->removeRows(0, m_pViewModel->rowCount());
	QThread *m_pThread = new QThread;
	connect(m_pThread, SIGNAL(started()), this, SLOT(SlotThreadSearchGeneral()));
	connect(m_pThread, SIGNAL(finished()), m_pThread, SLOT(deleteLater()));
	m_pThread->start();
}

void BakLayoutManager::SlotThreadSearchGeneral()
{
	QString Url = QString(getBakDetail).arg(g_strIpAddr).arg(g_strIpPort);
	QString strParam = QString("starttime=%1&endtime=%2").arg(ui->bak_startdateEdit->dateTime().toString("yyyy-MM-dd")).arg(ui->bak_enddateEdit->dateTime().toString("yyyy-MM-dd"));
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
				QJsonValue userArray = array.at(i);
				QJsonObject userObject = userArray.toObject();
				DetailItemStruct item;
				item.id = userObject["id"].toInt();
				item.strRemake = userObject["remake"].toString();
				item.strCostArea = userObject["costarea_name"].toString();
				item.strSurpls = userObject["surplus"].toString();
				item.strTime = userObject["account_date"].toString().mid(0, 10);
				item.strTaskName = userObject["task_name"].toString();
				item.strPay = userObject["pay"].toString();
				item.strIncome = userObject["income"].toString();
				addTableView(item);
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



void BakLayoutManager::SlotAddGeneral(QString&time, QString &incom, QString&pay, QString&taskName, QString&shareName, QString&remake)
{
	m_addTime = time;
	m_addIncom = incom;
	m_addPay = pay;
	m_addTaskName = taskName;
	m_addShare = shareName;
	m_addRemake = remake;
	m_pViewModel->removeRows(0, m_pViewModel->rowCount());
	QThread *m_pThread = new QThread;
	connect(m_pThread, SIGNAL(started()), this, SLOT(SlotThreadAddGeneral()));
	connect(m_pThread, SIGNAL(finished()), m_pThread, SLOT(deleteLater()));
	m_pThread->start();
}

void BakLayoutManager::SlotThreadAddGeneral()
{
	QString Url = QString(addbak).arg(g_strIpAddr).arg(g_strIpPort);
	QString strParam = QString("account_time=%1&task_name=%2&income=%3&pay=%4&remake=%5&costarea=%6").arg(m_addTime).arg(m_addTaskName)
		.arg(m_addIncom).arg(m_addPay).arg(m_addRemake).arg(m_addShare);
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
				QJsonValue userArray = array.at(i);
				QJsonObject userObject = userArray.toObject();
				DetailItemStruct item;
				item.id = userObject["id"].toInt();
				item.strRemake = userObject["remake"].toString();
				item.strCostArea = userObject["costarea_name"].toString();
				item.strSurpls = userObject["surplus"].toString();
				item.strTime = userObject["account_date"].toString().mid(0, 10);
				item.strTaskName = userObject["task_name"].toString();
				item.strPay = userObject["pay"].toString();
				item.strIncome = userObject["income"].toString();
				addTableView(item);
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

void BakLayoutManager::SlotThreadRemoveItem()
{
	int nCount = 0;
	QString id;
	double dValue = 0;
	int iSelectItem = 0;
	for (int i = 0; i < m_pViewModel->rowCount(); ++i)
	{
		if (Qt::Checked == m_pViewModel->item(i, 0)->checkState())
		{
			iSelectItem = i;
			id = m_pViewModel->item(i, 0)->data().toString();
			dValue = m_pViewModel->item(i, 3)->text().toDouble() - m_pViewModel->item(i, 4)->text().toDouble();
			nCount++;
		}
	}
	if (nCount > 1 || nCount == 0)
	{
		emit sig_NotifyMsg(QString::fromLocal8Bit("请选择节点且只能一个节点！"), 10086);
		return;
	}
	QString Url = QString(deleteBakItem).arg(g_strIpAddr).arg(g_strIpPort);
	QString strParam = QString("id=%1&dvalue=%2").arg(id).arg(QString::number(dValue));
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

			m_pViewModel->removeRow(iSelectItem);
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


void BakLayoutManager::addTableView(DetailItemStruct&item)
{
	int nCount = m_pViewModel->rowCount();
	m_pViewModel->setItem(nCount, 0, new QStandardItem(""));
	m_pViewModel->item(nCount, 0)->setCheckable(true);
	m_pViewModel->item(nCount, 0)->setData(QString::number(item.id));
	m_pViewModel->setItem(nCount, 1, new QStandardItem(item.strTime));
	m_pViewModel->setItem(nCount, 2, new QStandardItem(item.strRemake));
	m_pViewModel->setItem(nCount, 3, new QStandardItem(item.strIncome));
	m_pViewModel->setItem(nCount, 4, new QStandardItem(item.strPay));
	m_pViewModel->setItem(nCount, 5, new QStandardItem(item.strSurpls));
	m_pViewModel->setItem(nCount, 6, new QStandardItem(item.strTaskName));
	m_pViewModel->setItem(nCount, 7, new QStandardItem(item.strCostArea));
	ui->bak_tableView->setColumnWidth(0, 30);
	ui->bak_tableView->setColumnWidth(1, 100);
	ui->bak_tableView->setColumnWidth(2, 180);
}