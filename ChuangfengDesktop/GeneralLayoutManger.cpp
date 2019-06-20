#include "GeneralLayoutManger.h"
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
GeneralLayoutManger::GeneralLayoutManger(QWidget *parent)
	:MoveableFramelessWindow(parent)
	, ui(new Ui::generalManager)
{
	ui->setupUi(this);
	connect(ui->general_cose_btn, &QPushButton::clicked, this, &QWidget::close);
	connect(ui->general_max_restore_btn, &QPushButton::clicked, this, &GeneralLayoutManger::updateMaximize);
	connect(ui->general_min_btn, &QPushButton::clicked, this, &QWidget::showMinimized);
	ui->general_max_restore_btn->setToolTip(QString::fromLocal8Bit("���"));
	//���ð�ť��������Ϊ"maximizeProperty"
	ui->general_max_restore_btn->setProperty("maximizeProperty", "maximize");
	ui->general_max_restore_btn->setStyle(QApplication::style());
	InitLayout();
}


GeneralLayoutManger::~GeneralLayoutManger()
{
}

void GeneralLayoutManger::updateMaximize()
{
	QWidget *pWindow = this->window(); //��ñ��������ڵĴ���
	pWindow->isMaximized() ? pWindow->showNormal() : pWindow->showMaximized();  //�������/��ԭ��ʾ
	if (pWindow->isTopLevel())
	{
		bool bMaximize = pWindow->isMaximized(); //�жϴ����ǲ������״̬�����򷵻�true�����򷵻�false
		if (bMaximize)
		{
			//Ŀǰ���������״̬�������/��ԭ��toolTip����Ϊ"Restore"
			ui->general_max_restore_btn->setToolTip(QString::fromLocal8Bit("��ԭ"));
			//���ð�ť��������Ϊ"maximizeProperty"
			ui->general_max_restore_btn->setProperty("maximizeProperty", "restore");
		}
		else
		{
			//Ŀǰ�����ǻ�ԭ״̬�������/��ԭ��toolTip����Ϊ"Maximize"
			ui->general_max_restore_btn->setToolTip(QString::fromLocal8Bit("���"));
			//���ð�ť��������Ϊ"maximizeProperty"
			ui->general_max_restore_btn->setProperty("maximizeProperty", "maximize");
		}

		ui->general_max_restore_btn->setStyle(QApplication::style());
	}
}

void GeneralLayoutManger::slotCheckBoxStateChanged(bool status)
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

void GeneralLayoutManger::mouseDoubleClickEvent(QMouseEvent *event)
{
	Q_UNUSED(event); //û��ʵ���Ե����ã�ֻ����������event���Բ�ʹ�ã������������������
	emit ui->general_max_restore_btn->clicked();
}

void GeneralLayoutManger::paintEvent(QPaintEvent *event)
{
	QPainterPath path;
	path.setFillRule(Qt::WindingFill);
	path.addRect(0, 0, this->width(), 40);
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing, true);
	painter.fillPath(path, QBrush(QColor(56, 59, 67)));
	{
		QPainterPath path;
		path.setFillRule(Qt::WindingFill);
		path.addRect(0, 40, this->width(), this->height());
		QPainter painter(this);
		painter.setRenderHint(QPainter::Antialiasing, true);
		//painter.fillPath(path, QBrush(QColor(68, 71, 77)));
		painter.fillPath(path, QBrush(QColor(56, 59, 67)));
	}
}

QWidget* GeneralLayoutManger::getDragnWidget()
{
	return ui->general_title;
}

void GeneralLayoutManger::InitLayout()
{
 	m_pViewHeadDeleagte = new CCheckBoxHeaderView(0, Qt::Horizontal, ui->general_table_view);
	ui->general_table_view->setHorizontalHeader(m_pViewHeadDeleagte);
 	connect(m_pViewHeadDeleagte, SIGNAL(sig_AllChecked(bool)), this, SLOT(slotCheckBoxStateChanged(bool)));
 	m_pViewModel = new QStandardItemModel();
	ui->general_table_view->setModel(m_pViewModel);
 	m_pViewModel->setColumnCount(8);
 	m_pViewModel->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit(""));
 	m_pViewModel->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("����"));
 	m_pViewModel->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("ժҪ"));
 	m_pViewModel->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("�跽"));
 	m_pViewModel->setHeaderData(4, Qt::Horizontal, QString::fromLocal8Bit("����"));
 	m_pViewModel->setHeaderData(5, Qt::Horizontal, QString::fromLocal8Bit("����"));
 	m_pViewModel->setHeaderData(6, Qt::Horizontal, QString::fromLocal8Bit("��Ŀ"));
 	m_pViewModel->setHeaderData(7, Qt::Horizontal, QString::fromLocal8Bit("���÷�̯"));
 	onSetTableAttribute(ui->general_table_view, 8);
 
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
 
	ui->general_table_view->setColumnWidth(0, 30);
	ui->general_table_view->setColumnWidth(1, 100);
	ui->general_table_view->setColumnWidth(2, 180);
	
}

