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
#include "commomdef.h"
BakLayoutManager::BakLayoutManager(QWidget *parent)
	:MoveableFramelessWindow(parent)
	, ui(new Ui::BakManager)
{
	ui->setupUi(this);
	connect(ui->bak_cose_btn, &QPushButton::clicked, this, &QWidget::close);
	connect(ui->bak_max_restore_btn, &QPushButton::clicked, this, &BakLayoutManager::updateMaximize);
	connect(ui->bak_min_btn, &QPushButton::clicked, this, &QWidget::showMinimized);
	ui->bak_max_restore_btn->setToolTip(QString::fromLocal8Bit("���"));
	//���ð�ť��������Ϊ"maximizeProperty"
	ui->bak_max_restore_btn->setProperty("maximizeProperty", "maximize");
	ui->bak_max_restore_btn->setStyle(QApplication::style());
	InitLayout();
}


BakLayoutManager::~BakLayoutManager()
{
}

void BakLayoutManager::updateMaximize()
{
	QWidget *pWindow = this->window(); //��ñ��������ڵĴ���
	pWindow->isMaximized() ? pWindow->showNormal() : pWindow->showMaximized();  //�������/��ԭ��ʾ
	if (pWindow->isTopLevel())
	{
		bool bMaximize = pWindow->isMaximized(); //�жϴ����ǲ������״̬�����򷵻�true�����򷵻�false
		if (bMaximize)
		{
			//Ŀǰ���������״̬�������/��ԭ��toolTip����Ϊ"Restore"
			ui->bak_max_restore_btn->setToolTip(QString::fromLocal8Bit("��ԭ"));
			//���ð�ť��������Ϊ"maximizeProperty"
			ui->bak_max_restore_btn->setProperty("maximizeProperty", "restore");
		}
		else
		{
			//Ŀǰ�����ǻ�ԭ״̬�������/��ԭ��toolTip����Ϊ"Maximize"
			ui->bak_max_restore_btn->setToolTip(QString::fromLocal8Bit("���"));
			//���ð�ť��������Ϊ"maximizeProperty"
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
	Q_UNUSED(event); //û��ʵ���Ե����ã�ֻ����������event���Բ�ʹ�ã������������������
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
	m_pViewModel->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("����"));
	m_pViewModel->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("ժҪ"));
	m_pViewModel->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("�跽"));
	m_pViewModel->setHeaderData(4, Qt::Horizontal, QString::fromLocal8Bit("����"));
	m_pViewModel->setHeaderData(5, Qt::Horizontal, QString::fromLocal8Bit("����"));
	m_pViewModel->setHeaderData(6, Qt::Horizontal, QString::fromLocal8Bit("��Ŀ"));
	m_pViewModel->setHeaderData(7, Qt::Horizontal, QString::fromLocal8Bit("���÷�̯"));
	onSetTableAttribute(ui->bak_tableView, 8);

	int nCount = 0;
	for (auto i = 0; i < 10; i++)
	{
		m_pViewModel->setItem(i, 0, new QStandardItem(""));
		m_pViewModel->item(i, 0)->setCheckable(true);
		m_pViewModel->setItem(i, 1, new QStandardItem("2019-05-06"));
		m_pViewModel->setItem(i, 2, new QStandardItem(QString::fromLocal8Bit("Ϻ����")));
		m_pViewModel->setItem(i, 3, new QStandardItem(QString::number(3000)));
		m_pViewModel->setItem(i, 4, new QStandardItem(QString::number(2000)));
		m_pViewModel->setItem(i, 5, new QStandardItem(QString::number(1000)));
		m_pViewModel->setItem(i, 6, new QStandardItem(QString::fromLocal8Bit("Ϻ����")));
		nCount++;
	}

	ui->bak_tableView->setColumnWidth(0, 30);
	ui->bak_tableView->setColumnWidth(1, 100);
	ui->bak_tableView->setColumnWidth(2, 180);

}


