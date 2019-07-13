#include "DetailShareReportManager.h"
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
#include "globalVariable.h"
#include "SingletonHttpRequest.h"

void DetailShareReportManager::InitLayout()
{
	m_pViewModel = new QStandardItemModel();
	ui->detailshare_report_tableview->setModel(m_pViewModel);
	m_pViewModel->setColumnCount(4);
	m_pViewModel->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("����"));
	m_pViewModel->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("����"));
	m_pViewModel->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("ҩƷ"));
	m_pViewModel->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("����"));
// 	m_pViewModel->setHeaderData(4, Qt::Horizontal, QString::fromLocal8Bit("����"));
// 	m_pViewModel->setHeaderData(5, Qt::Horizontal, QString::fromLocal8Bit("���ʷ�̯"));
	onSetTableAttribute(ui->detailshare_report_tableview, 4);
	ui->detailshare_report_tableview->horizontalHeader()->setStretchLastSection(false);
}


DetailShareReportManager::DetailShareReportManager(QWidget *parent)
	:MoveableFramelessWindow(parent)
	, ui(new Ui::detailsharereport)
{
	ui->setupUi(this);
	connect(ui->close_btn, &QPushButton::clicked, this, &QWidget::close);
	connect(ui->max_restore_btn, &QPushButton::clicked, this, &DetailShareReportManager::updateMaximize);
	connect(ui->min_btn, &QPushButton::clicked, this, &QWidget::showMinimized);
	ui->max_restore_btn->setToolTip(QString::fromLocal8Bit("���"));
	//���ð�ť��������Ϊ"maximizeProperty"
	ui->max_restore_btn->setProperty("maximizeProperty", "maximize");
	ui->max_restore_btn->setStyle(QApplication::style());
	InitLayout();
	QDateTime current_date_time = QDateTime::currentDateTime();
	ui->detailshare_report_startdateEdit->setCalendarPopup(true);
	ui->detailshare_report_startdateEdit->setDateTime(current_date_time);
	ui->detailshare_report_enddateEdit->setCalendarPopup(true);
	ui->detailshare_report_enddateEdit->setDateTime(current_date_time);
	for (auto&kvp : g_areaList)
	{
		ui->area_combox->addItem(kvp.second.areaName);
	}
	connect(ui->detaishare_report_search_btn, &QPushButton::clicked, this, [this]()->void {
		m_list.clear();
		auto iter = g_areaList.find(ui->area_combox->currentText());
		if (iter != g_areaList.end())
		{
			for (auto&kvp:iter->second.areaDetailList)
			{
				singleShareStruct&item = m_list[kvp.second];
			}
		}
		else {
			return;
		}
		m_pViewModel->removeRows(0, m_pViewModel->rowCount());
		QThread *m_pThread = new QThread;
		connect(m_pThread, SIGNAL(started()), this, SLOT(SlotThreadSearchShare()));
		connect(m_pThread, SIGNAL(finished()), m_pThread, SLOT(deleteLater()));
		m_pThread->start();
	});
	connect(ui->detailsharereport_export_btn, &QPushButton::clicked, this, [this]()->void {
		QString m_ExcelPath = QFileDialog::getSaveFileName(0, QString::fromLocal8Bit("�������"), ".", "Microsoft Office(*.xlsx)");//��ȡ����·��
		if (!m_ExcelPath.isEmpty()) {
			ui->detailsharereport_export_btn->setEnabled(false);
			singleAreaShare* pthread = new singleAreaShare(m_ExcelPath, m_list);
			connect(pthread, SIGNAL(finished()), this, SLOT(finishedThreadBtnSlot()));
			pthread->start();
		}
	});
}


DetailShareReportManager::~DetailShareReportManager()
{
}

void DetailShareReportManager::updateMaximize()
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

void DetailShareReportManager::slotCheckBoxStateChanged(bool status)
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

void DetailShareReportManager::mouseDoubleClickEvent(QMouseEvent *event)
{
	Q_UNUSED(event); //û��ʵ���Ե����ã�ֻ����������event���Բ�ʹ�ã������������������
	emit ui->max_restore_btn->clicked();
}

void DetailShareReportManager::paintEvent(QPaintEvent *event)
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

QWidget* DetailShareReportManager::getDragnWidget()
{
	return ui->child_widget_title;
}

void DetailShareReportManager::AddTableView()
{
	int nCount = 0;
	for (auto&KVP:m_list)
	{
		m_pViewModel->setItem(nCount, 0, new QStandardItem(KVP.first));
		m_pViewModel->setItem(nCount, 1, new QStandardItem(QString::number(KVP.second.dbFeed)));
		m_pViewModel->setItem(nCount, 2, new QStandardItem(QString::number(KVP.second.dbDrug)));
		m_pViewModel->setItem(nCount, 3, new QStandardItem(QString::number(KVP.second.dbDisinfect)));
		nCount++;
	}
	ui->detailshare_report_tableview->setColumnWidth(0, 160);
	ui->detailshare_report_tableview->setColumnWidth(1, 80);
	ui->detailshare_report_tableview->setColumnWidth(2, 80);
	ui->detailshare_report_tableview->setColumnWidth(3, 80);
}

void DetailShareReportManager::finishedThreadBtnSlot()
{
	ui->detailsharereport_export_btn->setEnabled(true);
	emit sig_NotifyMsg(QString::fromLocal8Bit("�����ɹ���"), 0);
}

void DetailShareReportManager::SlotThreadSearchShare()
{
	QString Url = QString(SEARCHFEEDINGTOREPORT).arg(g_strIpAddr).arg(g_strIpPort);
	QString strParam = QString("starttime=%1&endtime=%2&area=%3")
		.arg(ui->detailshare_report_startdateEdit->text()).arg(ui->detailshare_report_enddateEdit->text()).arg(ui->area_combox->currentText());
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
		
				singleShareStruct&item = m_list[materialObject["areaitem"].toString()];
				if (materialObject["type"].toString() == QString::fromLocal8Bit("����"))
				{
					item.dbFeed += materialObject["number"].toInt()*materialObject["price"].toString().toDouble();
				}
				else if(materialObject["type"].toString() == QString::fromLocal8Bit("ҩƷ")){
					item.dbDrug += materialObject["number"].toInt()*materialObject["price"].toString().toDouble();
				}
				else {
					item.dbDisinfect += materialObject["number"].toInt()*materialObject["price"].toString().toDouble();
				}	
			}
			AddTableView();
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
		emit sig_NotifyMsg(QString::fromLocal8Bit("���������쳣��"), errorcode);
	}
}


