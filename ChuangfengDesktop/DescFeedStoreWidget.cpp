#include "DescFeedStoreWidget.h"



DescFeedStoreWidget::DescFeedStoreWidget(FeedTypeEnum _type,QString&subject, QString&price, int&number, QString&area, QWidget *parent)
	:MoveableFramelessWindow(parent)
	, ui(new Ui::DescFeedStoreWidget)
	, m_type(_type)
	,m_subject(subject)
	,m_price(price)
	,m_maxNumber(number)
{
	ui->setupUi(this);
	connect(ui->pop_close_btn, &QPushButton::clicked, this, &QWidget::close);
	connect(ui->pop_cancle_btn, &QPushButton::clicked, this, &QWidget::close);
	connect(ui->pop_min_btn, &QPushButton::clicked, this, &QWidget::showMinimized);
	connect(ui->pop_commit_btn, &QPushButton::clicked, this, [this]()->void {
		if (m_maxNumber < (ui->Number_Edit->text().toInt()))
		{
			ui->error_lab->setText(QString::fromLocal8Bit("库存不足"));
			ui->error_lab->setVisible(true);
			return;
		}
		if (ui->Number_Edit->text() == "")
		{
			ui->error_lab->setText(QString::fromLocal8Bit("数量不能为空"));
			ui->error_lab->setVisible(true);
			return;
		}
		int number = ui->Number_Edit->text().toInt();
		QString time = ui->dateEdit->text();
		QString area = ui->comboBox->currentText();
		emit sig_commit(m_type,number, time, area);
		emit ui->pop_close_btn->clicked();
	});
	
	
	ui->pice_Edit->setText(m_price);
	ui->subject_name_Edit->setText(m_subject);
	QDateTime current_date_time = QDateTime::currentDateTime();
	ui->dateEdit->setCalendarPopup(true);
	ui->dateEdit->setDateTime(current_date_time);
	ui->error_lab->setVisible(false);

	QRegExp regExpr("^[0-9]*[1-9][0-9]*$");
	QRegExpValidator *patternr = new QRegExpValidator(regExpr, this);//创建了一个表达式
	ui->Number_Edit->setValidator(patternr);
	ui->error_lab->setVisible(false);
	if (m_type == _enRenturnStore)
	{

		ui->comboBox->setVisible(false);
		ui->area_lab->setVisible(false);
	}
	if (m_type == _enBack)
	{	
		ui->area_lab->setText(QString::fromLocal8Bit("退库账目"));
		ui->comboBox->addItem(QString::fromLocal8Bit("总账"));
		ui->comboBox->addItem(QString::fromLocal8Bit("备用金"));
		ui->comboBox->addItem(QString::fromLocal8Bit("应付款"));	
	}
	if (m_type == _enOutStore)
	{
		for (auto&kvp : g_areaList)
		{
			ui->comboBox->addItem(kvp.second.areaName);
		}
		ui->comboBox->setCurrentIndex(0);
	}
}


DescFeedStoreWidget::~DescFeedStoreWidget()
{
}

QWidget* DescFeedStoreWidget::getDragnWidget()
{
	return ui->pop_widget_title;
}
