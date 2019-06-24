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
#include "commomdef.h"
#include "AddNoPayDetailWidget.h"
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
		pQtWidget->setAttribute(Qt::WA_DeleteOnClose);
		pQtWidget->setWindowModality(Qt::ApplicationModal);
		pQtWidget->show();
	});
	ui->max_restore_btn->setToolTip(QString::fromLocal8Bit("最大化"));
	//设置按钮的属性名为"maximizeProperty"
	ui->max_restore_btn->setProperty("maximizeProperty", "maximize");
	ui->max_restore_btn->setStyle(QApplication::style());
	InitLayout();
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

	int nCount = 0;
	for (auto i = 0; i < 10; i++)
	{
		m_pViewModel->setItem(i, 0, new QStandardItem(""));
		m_pViewModel->item(i, 0)->setCheckable(true);
		m_pViewModel->setItem(i, 1, new QStandardItem("2019-05-06"));
		m_pViewModel->setItem(i, 2, new QStandardItem(QString::fromLocal8Bit("宋荣生")));
		m_pViewModel->setItem(i, 3, new QStandardItem(QString::fromLocal8Bit("淡水井款")));
		m_pViewModel->setItem(i, 4, new QStandardItem(QString::number(2000)));
		m_pViewModel->setItem(i, 5, new QStandardItem(QString::number(0)));
		m_pViewModel->setItem(i, 6, new QStandardItem(QString::number(0)));
		m_pViewModel->setItem(i, 7, new QStandardItem(QString::number(0)));
		m_pViewModel->setItem(i, 8, new QStandardItem(QString::number(0)));
		m_pViewModel->setItem(i, 9, new QStandardItem(QString::number(2000)));
		nCount++;
	}

	ui->nopay_tableView->setColumnWidth(0, 30);
	ui->nopay_tableView->setColumnWidth(1, 100);
	ui->nopay_tableView->setColumnWidth(2, 180);

}


