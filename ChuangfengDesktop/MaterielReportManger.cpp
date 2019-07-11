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
	m_pViewModel->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("��Ŀ"));
	m_pViewModel->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("���"));
	m_pViewModel->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("����"));
	m_pViewModel->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("����"));
	m_pViewModel->setHeaderData(4, Qt::Horizontal, QString::fromLocal8Bit(" "));
	m_pViewModel->setHeaderData(5, Qt::Horizontal, QString::fromLocal8Bit("����"));
	m_pViewModel->setHeaderData(6, Qt::Horizontal, QString::fromLocal8Bit("��̯"));
	m_pViewModel->setHeaderData(7, Qt::Horizontal, QString::fromLocal8Bit("���ڷ�̯"));
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
	ui->max_restore_btn->setToolTip(QString::fromLocal8Bit("���"));
	//���ð�ť��������Ϊ"maximizeProperty"
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
}


MaterielReportManger::~MaterielReportManger()
{
}

void MaterielReportManger::updateMaximize()
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
	Q_UNUSED(event); //û��ʵ���Ե����ã�ֻ����������event���Բ�ʹ�ã������������������
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
	QString strParam = QString("subject_name=%1").arg("");
	QByteArray responseData;
	SingletonHttpRequest::getInstance()->RequestPost("http://127.0.0.1:80/zerg/public/index.php/SerachMaterial"
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

				QJsonValue materialArray = array.at(i);
				QJsonObject materialObject = materialArray.toObject();
				
				all += materialObject["totalprice"].toDouble();
				
			}
		}
	}
}

void MaterielReportManger::getInComeMaterialSearchTime()
{
	QDateTime current_date_time = QDateTime::currentDateTime();
	QString strParam = QString("starttime=%1&endtime=%2")
		.arg(ui->materielreport_startdateEdit->text()).arg(ui->materiel_report_enddateEdit->text());
	QByteArray responseData;
	SingletonHttpRequest::getInstance()->RequestPost("http://127.0.0.1:80/zerg/public/index.php/SearchInMaterialDetail"
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
				QJsonValue materialArray = array.at(i);
				QJsonObject materialObject = materialArray.toObject();
				m_currentAmout += materialObject["price"].toString().toDouble()*materialObject["number"].toInt();
			}
		}
	}
}

void MaterielReportManger::getInComeMaterialCurrentTime(double&add)
{
	QDateTime current_date_time = QDateTime::currentDateTime();
	QString strParam = QString("starttime=%1&endtime=%2")
		.arg(ui->materielreport_startdateEdit->text()).arg(current_date_time.toString("yyyy-MM-dd hh:mm:ss"));
	QByteArray responseData;
	SingletonHttpRequest::getInstance()->RequestPost("http://127.0.0.1:80/zerg/public/index.php/SearchInMaterialDetail"
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
				QJsonValue materialArray = array.at(i);
				QJsonObject materialObject = materialArray.toObject();
				add += materialObject["price"].toString().toDouble()*materialObject["number"].toInt();
			}
		}
	}	
}

void MaterielReportManger::getFixedUse()
{

}

void MaterielReportManger::getFixedAsset()
{

}

void MaterielReportManger::AddTableView()
{
	int nCount = 0;
	double inCome = 0;
	double out = 0;
	m_pViewModel->setItem(nCount, 0, new QStandardItem(QString::fromLocal8Bit("�ڳ����")));
	m_pViewModel->setItem(nCount, 1, new QStandardItem(QString::number(m_initAmount)));
	inCome += m_initAmount;
	nCount++;
	m_pViewModel->setItem(nCount, 0, new QStandardItem(QString::fromLocal8Bit("���¹���")));
	m_pViewModel->setItem(nCount, 1, new QStandardItem(QString::number(m_currentAmout)));
	nCount++;
	inCome += m_currentAmout;
	m_pViewModel->setItem(nCount, 0, new QStandardItem(QString::fromLocal8Bit("��������")));
	m_pViewModel->setItem(nCount, 1, new QStandardItem(QString::number(m_FixedUse)));
	out += m_FixedUse;
	nCount++;

	for (auto&kvp:m_materialUseList)
	{
		m_pViewModel->setItem(nCount, 0, new QStandardItem(QString::fromLocal8Bit("���˺��ڳ����")));
		m_pViewModel->setItem(nCount, 2, new QStandardItem(QString::number(kvp.second)));
		out += kvp.second;
		nCount++;
	}
	m_pViewModel->setItem(nCount, 0, new QStandardItem(QString::fromLocal8Bit("�ϼƣ�")));
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
	m_pViewModel->setItem(nCount, 5, new QStandardItem(QString::fromLocal8Bit("�ϼƣ�")));
	m_pViewModel->setItem(nCount, 6, new QStandardItem(QString::number(inCome)));
	m_pViewModel->setItem(nCount, 7, new QStandardItem(QString::number(out)));

	ui->materiel_report_tableView->setColumnWidth(0, 160);
	ui->materiel_report_tableView->setColumnWidth(1, 80);
	ui->materiel_report_tableView->setColumnWidth(2, 80);
	ui->materiel_report_tableView->setColumnWidth(3, 80);
}

void MaterielReportManger::SlotThreadGetMaterialInfo()
{
	  double dbTotal = 0;
	  getMaterialTotalPrice(dbTotal);
	  double add = 0;
	  getInComeMaterialCurrentTime(add);
	  m_initAmount = dbTotal - add;
	  getInComeMaterialSearchTime();
	  getFixedUse();
	 
	 getFixedAsset();
	 AddTableView();
}
