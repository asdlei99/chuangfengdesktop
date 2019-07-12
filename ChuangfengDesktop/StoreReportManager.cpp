#include "StoreReportManager.h"
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

void StoreReportManager::InitLayout()
{
	m_pViewModel = new QStandardItemModel();
	ui->store_report_tableView->setModel(m_pViewModel);
	m_pViewModel->setColumnCount(9);
	m_pViewModel->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("项目"));
	m_pViewModel->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("入库"));
	m_pViewModel->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("出库"));
	m_pViewModel->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("结余"));
	m_pViewModel->setHeaderData(4, Qt::Horizontal, QString::fromLocal8Bit(" "));
	m_pViewModel->setHeaderData(5, Qt::Horizontal, QString::fromLocal8Bit("项目"));
	m_pViewModel->setHeaderData(6, Qt::Horizontal, QString::fromLocal8Bit("入库"));
	m_pViewModel->setHeaderData(7, Qt::Horizontal, QString::fromLocal8Bit("用料"));
	m_pViewModel->setHeaderData(8, Qt::Horizontal, QString::fromLocal8Bit("结余"));
	onSetTableAttribute(ui->store_report_tableView, 9);
	ui->store_report_tableView->horizontalHeader()->setStretchLastSection(false);
}


StoreReportManager::StoreReportManager(QWidget *parent)
	:MoveableFramelessWindow(parent)
	, ui(new Ui::storereport)
{
	ui->setupUi(this);
	connect(ui->close_btn, &QPushButton::clicked, this, &QWidget::close);
	connect(ui->max_restore_btn, &QPushButton::clicked, this, &StoreReportManager::updateMaximize);
	connect(ui->min_btn, &QPushButton::clicked, this, &QWidget::showMinimized);
	ui->max_restore_btn->setToolTip(QString::fromLocal8Bit("最大化"));
	//设置按钮的属性名为"maximizeProperty"
	ui->max_restore_btn->setProperty("maximizeProperty", "maximize");
	ui->max_restore_btn->setStyle(QApplication::style());
	InitLayout();
	QDateTime current_date_time = QDateTime::currentDateTime();
	ui->storereport_startdateEdit->setCalendarPopup(true);
	ui->storereport_startdateEdit->setDateTime(current_date_time);
	ui->store_report_enddateEdit->setCalendarPopup(true);
	ui->store_report_enddateEdit->setDateTime(current_date_time);
	connect(ui->storereport_search_btn, &QPushButton::clicked, this, [this]()->void {
		 m_initAmount = 0;
		 m_backList.clear();
		 m_incomeList.clear();
		  m_returnList.clear();
		  m_useList.clear();
		
		m_pViewModel->removeRows(0, m_pViewModel->rowCount());
		QThread *m_pThread = new QThread;
		connect(m_pThread, SIGNAL(started()), this, SLOT(SlotThreadSearchShare()));
		connect(m_pThread, SIGNAL(finished()), m_pThread, SLOT(deleteLater()));
		m_pThread->start();
	});

}


StoreReportManager::~StoreReportManager()
{
}

void StoreReportManager::updateMaximize()
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

void StoreReportManager::slotCheckBoxStateChanged(bool status)
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

void StoreReportManager::mouseDoubleClickEvent(QMouseEvent *event)
{
	Q_UNUSED(event); //没有实质性的作用，只是用来允许event可以不使用，用来避免编译器警告
	emit ui->max_restore_btn->clicked();
}

void StoreReportManager::paintEvent(QPaintEvent *event)
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

QWidget* StoreReportManager::getDragnWidget()
{
	return ui->child_widget_title;
}

void StoreReportManager::getCurrentStore(double&value)
{

}

void StoreReportManager::getCurrentBackStore(double&value)
{

}

void StoreReportManager::getCurrentUse(double&value)
{

}

void StoreReportManager::getCurrentInCome(double&value)
{

}

void StoreReportManager::getCurrentReturn(double&value)
{

}

void StoreReportManager::getBackInfo()
{

}

void StoreReportManager::getIncome()
{

}

void StoreReportManager::getReturn()
{

}

void StoreReportManager::getUse()
{

}

void StoreReportManager::getAreaUse()
{

}

void StoreReportManager::AddTableView()
{
	int nCount = 0;
	double inCome = 0, out = 0;
	m_pViewModel->setItem(nCount, 0, new QStandardItem(QString::fromLocal8Bit("总仓期初总额")));

	m_pViewModel->setItem(nCount, 1, new QStandardItem(QString::number(m_initAmount)));
	m_pViewModel->setItem(nCount, 2, new QStandardItem(""));
	m_pViewModel->setItem(nCount, 3, new QStandardItem(""));
	inCome += m_initAmount;
	nCount++;
	for (auto kvp:m_backList)
	{
		m_pViewModel->setItem(nCount, 0, new QStandardItem(kvp.first));

		m_pViewModel->setItem(nCount, 1, new QStandardItem(""));
		m_pViewModel->setItem(nCount, 2, new QStandardItem(QString::number(kvp.second)));
		m_pViewModel->setItem(nCount, 3, new QStandardItem(""));
		out += kvp.second;
		nCount++;
	}
	for (auto kvp : m_incomeList)
	{
		m_pViewModel->setItem(nCount, 0, new QStandardItem(kvp.first));

		m_pViewModel->setItem(nCount, 1, new QStandardItem(QString::number(kvp.second)));
		m_pViewModel->setItem(nCount, 2, new QStandardItem(""));
		m_pViewModel->setItem(nCount, 3, new QStandardItem(""));
		inCome += kvp.second;
		nCount++;
	}
	for (auto kvp : m_returnList)
	{
		m_pViewModel->setItem(nCount, 0, new QStandardItem(kvp.first));

		m_pViewModel->setItem(nCount, 1, new QStandardItem(QString::number(kvp.second)));
		m_pViewModel->setItem(nCount, 2, new QStandardItem(""));
		m_pViewModel->setItem(nCount, 3, new QStandardItem(""));
		inCome += kvp.second;
		nCount++;
	}
	for (auto kvp : m_useList)
	{
		m_pViewModel->setItem(nCount, 0, new QStandardItem(kvp.first));

		m_pViewModel->setItem(nCount, 1, new QStandardItem(""));
		m_pViewModel->setItem(nCount, 2, new QStandardItem(QString::number(kvp.second)));
		m_pViewModel->setItem(nCount, 3, new QStandardItem(""));
		out += kvp.second;
		nCount++;
	}
	m_pViewModel->setItem(nCount, 0, new QStandardItem(QString::fromLocal8Bit("合计")));
	m_pViewModel->setItem(nCount, 1, new QStandardItem(QString::number(inCome)));
	m_pViewModel->setItem(nCount, 2, new QStandardItem(QString::number(out)));
	m_pViewModel->setItem(nCount, 3, new QStandardItem(QString::number(inCome-out)));

	inCome = 0; out = 0;
	nCount = 0;
	for (auto&kvp: m_areaUseList)
	{
		m_pViewModel->setItem(nCount, 5, new QStandardItem(kvp.first));
		m_pViewModel->setItem(nCount, 6, new QStandardItem(QString::number(get<0>(kvp.second))));
		inCome += get<0>(kvp.second);
		m_pViewModel->setItem(nCount, 7, new QStandardItem(QString::number(get<1>(kvp.second))));
		out += get<1>(kvp.second);
		m_pViewModel->setItem(nCount,8, new QStandardItem(QString::number(get<0>(kvp.second)-get<1>(kvp.second) )));
	}
	m_pViewModel->setItem(nCount, 5, new QStandardItem(QString::fromLocal8Bit("合计")));
	m_pViewModel->setItem(nCount, 6, new QStandardItem(QString::number(inCome)));
	m_pViewModel->setItem(nCount, 7, new QStandardItem(QString::number(out)));
	m_pViewModel->setItem(nCount, 8, new QStandardItem(QString::number(inCome - out)));
	ui->store_report_tableView->setColumnWidth(0, 160);
	ui->store_report_tableView->setColumnWidth(1, 80);
	ui->store_report_tableView->setColumnWidth(2, 80);
	ui->store_report_tableView->setColumnWidth(3, 80);
}

void StoreReportManager::SlotThreadSearchShare()
{
	double CurrentStore = 0, CurrentBackStore = 0, CurrentUse = 0, CurrentInCome = 0, CurrentReturn = 0;
	 getCurrentStore(CurrentStore);
	 getCurrentBackStore(CurrentBackStore);
	 getCurrentUse(CurrentUse);
	 getCurrentInCome(CurrentInCome);
	 getCurrentReturn(CurrentReturn);

	 getBackInfo();
	 getIncome();
	 getReturn();
	 getUse();
	 getAreaUse();
	 AddTableView();
}

