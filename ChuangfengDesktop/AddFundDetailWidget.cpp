#include "AddFundDetailWidget.h"
#include "globalVariable.h"
#include <QCalendarWidget>
#include "AddMaterialWidget.h"
#include <QThread>
#include "SingletonHttpRequest.h"
#include <QJsonDocument>
#include <QJsonObject>
#include "AddFeedStoreWidget.h"

AddFundDetailWidget::AddFundDetailWidget(PopFundDetailEnum type, QWidget *parent)
	:MoveableFramelessWindow(parent)
	,ui(new Ui::addFundDetailWidget)
	,m_enWidgetType(type)
{
	ui->setupUi(this);
	connect(ui->pop_close_btn, &QPushButton::clicked, this, &QWidget::close);
	connect(ui->pop_cancle_btn, &QPushButton::clicked, this, &QWidget::close);
	connect(ui->pop_min_btn, &QPushButton::clicked, this, &QWidget::showMinimized);
	connect(ui->subject_comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(SubjectcomboBoxValueChanged())); 
	connect(ui->share_comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(SharecomboBoxValueChanged()));
	connect(ui->pop_commit_btn, &QPushButton::clicked, this, &AddFundDetailWidget::SlotCommitAction);
	switch (m_enWidgetType)
	{
	case enGeneralLayout:
		setWindowTitle(QString::fromLocal8Bit("总账收支明细"));
		ui->title_lab->setText(QString::fromLocal8Bit("总账收支明细"));
		break;
	case enBakLayout:
		setWindowTitle(QString::fromLocal8Bit("备用金明细"));
		ui->title_lab->setText(QString::fromLocal8Bit("备用金明细"));
		break;
	default:
		break;
	}
	for (auto&kep:g_CategoryList)
	{
		ui->subject_comboBox->addItem(kep.second);
	}
	ui->subject_comboBox->addItem(QString::fromLocal8Bit("自定义"));
	ui->subject_comboBox->setCurrentIndex(0);
	for (auto&kep : g_CostAreaList)
	{
		ui->share_comboBox->addItem(kep.second.costAreaName);
	}
	ui->share_comboBox->addItem(QString::fromLocal8Bit("自定义"));
	ui->share_comboBox->setCurrentIndex(0);
	ui->subject_Edit->setVisible(false);
	ui->share_Edit->setVisible(false);
	QDateTime current_date_time = QDateTime::currentDateTime();
	ui->dateEdit->setCalendarPopup(true);	
	ui->dateEdit->setDateTime(current_date_time);

	QRegExp regExp("^(([0-9]+\.[0-9]*[1-9][0-9]*)|([0-9]*[1-9][0-9]*\.[0-9]+)|([0-9]*[1-9][0-9]*))$");//创建了一个模式
	QRegExpValidator *pattern = new QRegExpValidator(regExp, this);//创建了一个表达式
	ui->incom_Edit->setValidator(pattern);//交付使用 
	ui->pay_Edit->setValidator(pattern);
	ui->error_lab->setVisible(false);
}


AddFundDetailWidget::~AddFundDetailWidget()
{
}

QWidget* AddFundDetailWidget::getDragnWidget()
{
	return ui->pop_widget_title;
}

void AddFundDetailWidget::SlotThreadAddFeedStore()
{
	QString strParam = QString("operat_time=%1&supplier=%2&subject_name=%3&specs=%4&price=%5&unit=%6&number=%7")
		.arg(m_time).arg(m_suplier).arg(m_subject_name).arg(m_specs).arg(m_price).arg(m_unit).
		arg(m_number);
	QByteArray responseData;
	SingletonHttpRequest::getInstance()->RequestPost("http://127.0.0.1:80/zerg/public/index.php/InComFeedStore"
		, TempToken, strParam, responseData);
	QJsonParseError json_error;
	QJsonDocument parse_doucment = QJsonDocument::fromJson(responseData, &json_error);
	if (json_error.error == QJsonParseError::NoError)
	{
		if (parse_doucment.isArray())
		{
			QString time = ui->dateEdit->text();
			QString strInCom = ui->incom_Edit->text();
			QString strPay = ui->pay_Edit->text();
			QString remake = ui->remake_Edit->text();
			QString taskName;
			QString costArea;

			taskName = ui->subject_comboBox->currentText();

			if (ui->share_comboBox->currentText() == QString::fromLocal8Bit("自定义"))
			{
				costArea = ui->share_Edit->text();
			}
			else
			{
				costArea = ui->share_comboBox->currentText();
			}
			if (costArea == "" || taskName == "" || strPay == "" || strInCom == "")
			{

				ui->error_lab->setVisible(true);
				return;
			}
			else {
				emit sig_comit(time, strInCom, strPay, taskName, costArea, remake);
				emit ui->pop_close_btn->clicked();
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

void AddFundDetailWidget::SubjectcomboBoxValueChanged()
{
	if (ui->subject_comboBox->currentText() == QString::fromLocal8Bit("自定义"))
	{
		ui->subject_Edit->setVisible(true);
	}
	else {
		ui->subject_Edit->setVisible(false);
	}
}

void AddFundDetailWidget::SharecomboBoxValueChanged()
{
	if (ui->share_comboBox->currentText() == QString::fromLocal8Bit("自定义"))
	{
		ui->share_Edit->setVisible(true);
	}
	else {
		ui->share_Edit->setVisible(false);
	}
}

void AddFundDetailWidget::SlotCommitAction()
{
	if (ui->subject_comboBox->currentText() == QString::fromLocal8Bit("物料"))
	{

		AddMaterialWidget*pQtWidget = new AddMaterialWidget();
		connect(pQtWidget, SIGNAL(sig_commit(QString&, QString&, QString&, QString&, QString&, QString&, QString&, QString&, QString&)), this, SLOT(SlotAddMaterialDetail(QString&, QString&, QString&, QString&, QString&, QString&, QString&, QString&, QString&)));
		pQtWidget->setAttribute(Qt::WA_DeleteOnClose);
		pQtWidget->setWindowModality(Qt::ApplicationModal);
		pQtWidget->show();
		return;
	}

	if (ui->subject_comboBox->currentText() == QString::fromLocal8Bit("饲料营养品"))
	{
		AddFeedStoreWidget*pQtWidget = new AddFeedStoreWidget();
		connect(pQtWidget, SIGNAL(sig_commit(QString&, QString&, QString&, QString&, QString&, QString&, QString&)), this, SLOT(SlotAddFeedStore(QString&, QString&, QString&, QString&, QString&, QString&, QString&)));
		pQtWidget->setAttribute(Qt::WA_DeleteOnClose);
		pQtWidget->setWindowModality(Qt::ApplicationModal);
		pQtWidget->show();

		return;
	}
	
	QString time = ui->dateEdit->text();
	QString strInCom = ui->incom_Edit->text();
	QString strPay = ui->pay_Edit->text();
	QString remake = ui->remake_Edit->text();
	QString taskName;
	QString costArea;
	if (ui->subject_comboBox->currentText() == QString::fromLocal8Bit("自定义"))
	{
		taskName = ui->subject_Edit->text();
	}
	else
	{
		taskName = ui->subject_comboBox->currentText();
	}
	if (ui->share_comboBox->currentText() == QString::fromLocal8Bit("自定义"))
	{
		costArea = ui->share_Edit->text();
	}
	else
	{
		costArea = ui->share_comboBox->currentText();
	}
	if (costArea == ""|| taskName == ""|| strPay == ""|| strInCom == "")
	{

		ui->error_lab->setVisible(true);
		return;
	}
	else {
		emit sig_comit(time, strInCom, strPay, taskName, costArea, remake);
		emit ui->pop_close_btn->clicked();
	}
}

void AddFundDetailWidget::SlotAddMaterialDetail(QString&time, QString&use, QString&subject_name, QString&category, QString&price, QString&unit, QString&specs, QString&fare, QString&number)
{
	m_addTime = time;
	m_addUse = use;
	m_addSubject_name = subject_name;
	m_addCategory = category;
	m_addPrice = price;
	m_addUnit = unit;
	m_addSpecs = specs;
	m_addFare = fare;
	m_addNumber = number;
	QThread *m_pThread = new QThread;
	connect(m_pThread, SIGNAL(started()), this, SLOT(SlotThreadAddMaterialDetail()));
	connect(m_pThread, SIGNAL(finished()), m_pThread, SLOT(deleteLater()));
	m_pThread->start();
}

void AddFundDetailWidget::SlotThreadAddMaterialDetail()
{
	QString strParam = QString("operat_time=%1&use=%2&subject_name=%3&category=%4&price=%5&unit=%6&specs=%7&number=%8&fare=%9")
		.arg(m_addTime).arg(m_addUse).arg(m_addSubject_name).arg(m_addCategory).arg(m_addPrice).arg(m_addUnit).
		arg(m_addSpecs).arg(m_addNumber).arg(m_addFare);
	QByteArray responseData;
	SingletonHttpRequest::getInstance()->RequestPost("http://127.0.0.1:80/zerg/public/index.php/InsertMaterial"
		, TempToken, strParam, responseData);
	QJsonParseError json_error;
	QJsonDocument parse_doucment = QJsonDocument::fromJson(responseData, &json_error);
	if (json_error.error == QJsonParseError::NoError)
	{
		if (parse_doucment.isArray())
		{
			
			QString time = ui->dateEdit->text();
			QString strInCom = ui->incom_Edit->text();
			QString strPay = ui->pay_Edit->text();
			QString remake = ui->remake_Edit->text();
			QString taskName;
			QString costArea;
			
			taskName = ui->subject_comboBox->currentText();
			
			if (ui->share_comboBox->currentText() == QString::fromLocal8Bit("自定义"))
			{
				costArea = ui->share_Edit->text();
			}
			else
			{
				costArea = ui->share_comboBox->currentText();
			}
			if (costArea == "" || taskName == "" || strPay == "" || strInCom == "")
			{

				ui->error_lab->setVisible(true);
				return;
			}
			else {
				emit sig_comit(time, strInCom, strPay, taskName, costArea, remake);
				emit ui->pop_close_btn->clicked();
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

void AddFundDetailWidget::SlotAddFeedStore(QString&time, QString&suplier, QString&subject_name, QString&price, QString&unit, QString&specs, QString&number)
{
	m_time = time;
	m_suplier = suplier;
	m_subject_name = subject_name;
	m_price = price;
	m_unit = unit;
	m_specs = specs;
	m_number = number;
	QThread *m_pThread = new QThread;
	connect(m_pThread, SIGNAL(started()), this, SLOT(SlotThreadAddFeedStore()));
	connect(m_pThread, SIGNAL(finished()), m_pThread, SLOT(deleteLater()));
	m_pThread->start();
}
