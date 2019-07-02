#include "NoPayLayoutManager.h"
#include <QKeyEvent>
#include <QMouseEvent>
#include <QRect>
#include <QPoint>
#include <QGridLayout>
#include <QPainter>
#include <QPen>
#include <QtMath>
#include "iconhelper.h"

#include "AddNoPayDetailWidget.h"
#include "MsgPopWidget.h"
#include "SingletonHttpRequest.h"
#include "globalVariable.h"
NoPayLayoutManager::NoPayLayoutManager(QWidget *parent)
	:MoveableFramelessWindow(parent)
	, ui(new Ui::nopayManager)
{
	ui->setupUi(this);
	connect(ui->close_btn, &QPushButton::clicked, this, &QWidget::close);
	connect(ui->max_restore_btn, &QPushButton::clicked, this, &NoPayLayoutManager::updateMaximize);
	connect(ui->min_btn, &QPushButton::clicked, this, &QWidget::showMinimized);
	connect(ui->nopay_add_btn, &QPushButton::clicked, this, [this]()->void {
		AddNoPayDetailWidget*pQtWidget = new AddNoPayDetailWidget();
		connect(pQtWidget, SIGNAL(sig_commit(QString&, QString&, QString&, QString&, QString&, QString&, QString&)), this, SLOT(SlotAddNopayDetail(QString&, QString&, QString&, QString&, QString&, QString&, QString&)));
		pQtWidget->setAttribute(Qt::WA_DeleteOnClose);
		pQtWidget->setWindowModality(Qt::ApplicationModal);
		pQtWidget->show();
	});
	connect(ui->nopay_search_btn, &QPushButton::clicked, this, &NoPayLayoutManager::SlotSearchThread);
	connect(ui->nopay_del_btn, &QPushButton::clicked, this, [this]()->void {
		QThread *m_pThread = new QThread;
		connect(m_pThread, SIGNAL(started()), this, SLOT(SlotThreadRemoveItem()));
		connect(m_pThread, SIGNAL(finished()), m_pThread, SLOT(deleteLater()));
		m_pThread->start();
	});
	ui->max_restore_btn->setToolTip(QString::fromLocal8Bit("最大化"));
	//设置按钮的属性名为"maximizeProperty"
	ui->max_restore_btn->setProperty("maximizeProperty", "maximize");
	ui->max_restore_btn->setStyle(QApplication::style());
	InitLayout();
	QDateTime current_date_time = QDateTime::currentDateTime();
	ui->nopay_startdateEdit->setCalendarPopup(true);
	ui->nopay_startdateEdit->setDateTime(current_date_time);
	ui->nopay_enddateEdit->setCalendarPopup(true);
	ui->nopay_enddateEdit->setDateTime(current_date_time);
	connect(this, SIGNAL(sig_NotifyMsg(QString, int)), this, SLOT(SlotMsgPop(QString, int)));
}


NoPayLayoutManager::~NoPayLayoutManager()
{
}

void NoPayLayoutManager::updateMaximize()
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

void NoPayLayoutManager::slotCheckBoxStateChanged(bool status)
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

void NoPayLayoutManager::SlotMsgPop(QString msg, int errorcode)
{
	MsgPopWidget*pQtWidget = new MsgPopWidget(msg, errorcode);
	pQtWidget->setAttribute(Qt::WA_DeleteOnClose);
	pQtWidget->setWindowModality(Qt::ApplicationModal);
	pQtWidget->show();
}

void NoPayLayoutManager::SlotAddNopayDetail(QString&time, QString&suplier, QString&adjust, QString&newAdd, QString&returnValue, QString&pay, QString&remake)
{
	m_pViewModel->removeRows(0, m_pViewModel->rowCount());
	m_strTime = time;
	m_strSuplier = suplier;
	m_remake = remake;
	m_adjust = adjust;
	m_newadd = newAdd;
	m_returnValue = returnValue;
	m_pay = pay;
	QThread *m_pThread = new QThread;
	connect(m_pThread, SIGNAL(started()), this, SLOT(SlothreadAddnopay()));
	connect(m_pThread, SIGNAL(finished()), m_pThread, SLOT(deleteLater()));
	m_pThread->start();
}

void NoPayLayoutManager::SlothreadAddnopay()
{
	QString strParam = QString("operat_time=%1&adjustment=%2&added=%3&back=%4&Payment=%5&supplier=%6&abstract=%7")
		.arg(m_strTime).arg(m_adjust).arg(m_newadd).arg(m_returnValue).arg(m_pay).arg(m_strSuplier).arg(m_remake);
	QByteArray responseData;
	SingletonHttpRequest::getInstance()->RequestPost("http://127.0.0.1:80/zerg/public/index.php/addDue"
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
				QJsonValue nopayArray = array.at(i);
				QJsonObject nopayDetailObject = nopayArray.toObject();
				noPayDetailItem item;
				item.id = nopayDetailObject["id"].toInt();
				item.strTime = nopayDetailObject["operat_time"].toString();
				item.strAdd = nopayDetailObject["added"].toString();
				item.strAdjust = nopayDetailObject["adjustment"].toString();
				item.strReturn = nopayDetailObject["back"].toString();
				item.strMake = nopayDetailObject["abstract"].toString();
				item.strSuplier = nopayDetailObject["supplier"].toString();
				item.strSurplus = nopayDetailObject["surplus"].toString();
				item.strPayment = nopayDetailObject["Payment"].toString();
				item.strInitValue = nopayDetailObject["init_amount"].toString();
				AddTableViewItem(item);
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

void NoPayLayoutManager::SlotSearchThread()
{
	m_pViewModel->removeRows(0, m_pViewModel->rowCount());
	QString strParam = QString("starttime=%1&endtime=%2")
		.arg(ui->nopay_startdateEdit->text()).arg(ui->nopay_enddateEdit->text());
	QByteArray responseData;
	SingletonHttpRequest::getInstance()->RequestPost("http://127.0.0.1:80/zerg/public/index.php/getDuesDetail"
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
				QJsonValue nopayArray = array.at(i);
				QJsonObject nopayDetailObject = nopayArray.toObject();
				noPayDetailItem item;
				item.id = nopayDetailObject["id"].toInt();
				item.strTime = nopayDetailObject["operat_time"].toString();
				item.strAdd = nopayDetailObject["added"].toString();
				item.strAdjust = nopayDetailObject["adjustment"].toString();
				item.strReturn = nopayDetailObject["back"].toString();
				item.strMake = nopayDetailObject["abstract"].toString();
				item.strSuplier = nopayDetailObject["supplier"].toString();
				item.strSurplus = nopayDetailObject["surplus"].toString();
				item.strPayment = nopayDetailObject["Payment"].toString();
				item.strInitValue = nopayDetailObject["init_amount"].toString();
				AddTableViewItem(item);
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

void NoPayLayoutManager::mouseDoubleClickEvent(QMouseEvent *event)
{
	Q_UNUSED(event); //没有实质性的作用，只是用来允许event可以不使用，用来避免编译器警告
	emit ui->max_restore_btn->clicked();
}

void NoPayLayoutManager::paintEvent(QPaintEvent *event)
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

QWidget* NoPayLayoutManager::getDragnWidget()
{
	return ui->child_widget_title;
}

void NoPayLayoutManager::AddTableViewItem(noPayDetailItem&item)
{
	int nCount = m_pViewModel->rowCount();

	m_pViewModel->setItem(nCount, 0, new QStandardItem(""));
	m_pViewModel->item(nCount, 0)->setCheckable(true);
	m_pViewModel->item(nCount, 0)->setData(QString::number(item.id));
	m_pViewModel->setItem(nCount, 1, new QStandardItem(item.strTime.mid(0,10)));
	m_pViewModel->setItem(nCount, 2, new QStandardItem(item.strSuplier));
	m_pViewModel->setItem(nCount, 3, new QStandardItem(item.strMake));
	m_pViewModel->setItem(nCount, 4, new QStandardItem(item.strInitValue));
	m_pViewModel->setItem(nCount, 5, new QStandardItem(item.strAdjust));
	m_pViewModel->setItem(nCount, 6, new QStandardItem(item.strAdd));
	m_pViewModel->setItem(nCount, 7, new QStandardItem(item.strReturn));
	m_pViewModel->setItem(nCount, 8, new QStandardItem(item.strPayment));
	m_pViewModel->setItem(nCount, 9, new QStandardItem(item.strSurplus));
	ui->nopay_tableView->setColumnWidth(0, 30);
	ui->nopay_tableView->setColumnWidth(1, 100);
	ui->nopay_tableView->setColumnWidth(2, 180);
}

void NoPayLayoutManager::SlotThreadRemoveItem()
{
	int nCount = 0;
	QString id;
	double dValue = 0;
	QString strsupplier;
	int iSelectItem = 0;
	for (int i = 0; i < m_pViewModel->rowCount(); ++i)
	{
		if (Qt::Checked == m_pViewModel->item(i, 0)->checkState())
		{
			iSelectItem = i;
			id = m_pViewModel->item(i, 0)->data().toString();
			dValue = m_pViewModel->item(i, 6)->text().toDouble() - m_pViewModel->item(i, 7)->text().toDouble()-
				m_pViewModel->item(i, 8)->text().toDouble()+ m_pViewModel->item(i, 5)->text().toDouble();
			strsupplier = m_pViewModel->item(i, 2)->text();
			nCount++;
		}
	}
	if (nCount > 1)
	{
		return;
	}

	QString strParam = QString("id=%1&supplier=%2&dvalue=%3").arg(id).arg(strsupplier).arg(QString::number(dValue));
	QByteArray responseData;
	SingletonHttpRequest::getInstance()->RequestPost("http://localhost/zerg/public/index.php/deleteDuesItem?XDEBUG_SESSION_START=16141"
		, TempToken, strParam, responseData);
	QString test = responseData;
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

void NoPayLayoutManager::InitLayout()
{
	m_pViewHeadDeleagte = new CCheckBoxHeaderView(0, Qt::Horizontal, ui->nopay_tableView);
	ui->nopay_tableView->setHorizontalHeader(m_pViewHeadDeleagte);
	connect(m_pViewHeadDeleagte, SIGNAL(sig_AllChecked(bool)), this, SLOT(slotCheckBoxStateChanged(bool)));
	m_pViewModel = new QStandardItemModel();
	ui->nopay_tableView->setModel(m_pViewModel);
	m_pViewModel->setColumnCount(11);
	m_pViewModel->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit(""));
	m_pViewModel->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("日期"));
	m_pViewModel->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("供应商"));
	m_pViewModel->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("摘要"));
	m_pViewModel->setHeaderData(4, Qt::Horizontal, QString::fromLocal8Bit("初期金额"));
	m_pViewModel->setHeaderData(5, Qt::Horizontal, QString::fromLocal8Bit("调账或扣款"));
	m_pViewModel->setHeaderData(6, Qt::Horizontal, QString::fromLocal8Bit("新增应付款"));
	m_pViewModel->setHeaderData(7, Qt::Horizontal, QString::fromLocal8Bit("退货"));
	m_pViewModel->setHeaderData(8, Qt::Horizontal, QString::fromLocal8Bit("已付款"));
	m_pViewModel->setHeaderData(9, Qt::Horizontal, QString::fromLocal8Bit("期末余额"));
	m_pViewModel->setHeaderData(10, Qt::Horizontal, QString::fromLocal8Bit("备注"));
	onSetTableAttribute(ui->nopay_tableView, 11);
}


