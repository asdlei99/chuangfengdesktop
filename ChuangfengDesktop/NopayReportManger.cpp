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

void NopayReportManger::InitLayout()
{
	  	m_pViewModel = new QStandardItemModel();
  	ui->nopayreport_tableView->setModel(m_pViewModel);
  	m_pViewModel->setColumnCount(8);
  	m_pViewModel->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("��Ӧ��"));
  	m_pViewModel->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("ժҪ"));
  	m_pViewModel->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("�ڳ����"));
  	m_pViewModel->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("���˻�ۿ�"));
  	m_pViewModel->setHeaderData(4, Qt::Horizontal, QString::fromLocal8Bit("����Ӧ����"));
  	m_pViewModel->setHeaderData(5, Qt::Horizontal, QString::fromLocal8Bit("�˻�"));
  	m_pViewModel->setHeaderData(6, Qt::Horizontal, QString::fromLocal8Bit("�Ѹ���"));
  	m_pViewModel->setHeaderData(7, Qt::Horizontal, QString::fromLocal8Bit("��ĩ���"));
  	onSetTableAttribute(ui->nopayreport_tableView, 8);
	ui->nopayreport_tableView->horizontalHeader()->setStretchLastSection(false);
  	int nCount = 0;
  	for (auto i = 0; i < 10; i++)
  	{
  		m_pViewModel->setItem(i, 0, new QStandardItem(QString::fromLocal8Bit("���˺��ڳ����")));
  		/*m_pViewModel->item(i, 0)->setCheckable(tru)));
  		m_pViewModel->setItem(i, 2, new QStandardItem()));
  		m_pViewModel->setItem(i, 2, new QStandardItem(e);*/
  
  		m_pViewModel->setItem(i, 1, new QStandardItem(QString::number(209637.89)));
  		m_pViewModel->setItem(i, 2, new QStandardItem(QString::fromLocal8Bit("0")));
  		m_pViewModel->setItem(i, 3, new QStandardItem(QString::fromLocal8Bit("0")));
  
  
  
  		nCount++;
  	}
  	for (auto i = 0; i < 10; i++)
  	{
  		m_pViewModel->setItem(i, 5, new QStandardItem(QString::number(209637.89)));
  		m_pViewModel->setItem(i, 6, new QStandardItem(QString::fromLocal8Bit("0")));
  		m_pViewModel->setItem(i, 7, new QStandardItem(QString::fromLocal8Bit("0")));
  	}
	ui->nopayreport_tableView->setColumnWidth(0, 160);
	ui->nopayreport_tableView->setColumnWidth(1, 80);
	ui->nopayreport_tableView->setColumnWidth(2, 80);
	ui->nopayreport_tableView->setColumnWidth(3, 80);
  
	ui->nopayreport_tableView->setColumnWidth(5, 80);
	ui->nopayreport_tableView->setColumnWidth(6, 80);
	ui->nopayreport_tableView->setColumnWidth(7, 80);
}


NopayReportManger::NopayReportManger(QWidget *parent)
	:MoveableFramelessWindow(parent)
	, ui(new Ui::noPayReportMannger)
{
	ui->setupUi(this);
	connect(ui->close_btn, &QPushButton::clicked, this, &QWidget::close);
	connect(ui->max_restore_btn, &QPushButton::clicked, this, &NopayReportManger::updateMaximize);
	connect(ui->min_btn, &QPushButton::clicked, this, &QWidget::showMinimized);
	ui->max_restore_btn->setToolTip(QString::fromLocal8Bit("���"));
	//���ð�ť��������Ϊ"maximizeProperty"
	ui->max_restore_btn->setProperty("maximizeProperty", "maximize");
	ui->max_restore_btn->setStyle(QApplication::style());
	InitLayout();
}


NopayReportManger::~NopayReportManger()
{
}

void NopayReportManger::updateMaximize()
{
	QWidget *pWindow = this->window(); //��ñ��������ڵĴ���
	pWindow->isMaximized() ? pWindow->showNormal() : pWindow->showMaximized();  //�������/��ԭ��ʾ
	if (pWindow->isTopLevel())
	{
		bool bMaximize = pWindow->isMaximized(); //�жϴ����ǲ������״̬�����򷵻�true�����򷵻�false
		if (bMaximize)
		{
			//Ŀǰ���������״̬�������/��ԭ��toolTip����Ϊ"Restore"
			ui->max_restore_btn->setToolTip(QString::fromLocal8Bit("��ԭ"));
			//���ð�ť��������Ϊ"maximizeProperty"
			ui->max_restore_btn->setProperty("maximizeProperty", "restore");
		}
		else
		{
			//Ŀǰ�����ǻ�ԭ״̬�������/��ԭ��toolTip����Ϊ"Maximize"
			ui->max_restore_btn->setToolTip(QString::fromLocal8Bit("���"));
			//���ð�ť��������Ϊ"maximizeProperty"
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
	Q_UNUSED(event); //û��ʵ���Ե����ã�ֻ����������event���Բ�ʹ�ã������������������
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


