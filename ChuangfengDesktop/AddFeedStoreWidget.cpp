#include "AddFeedStoreWidget.h"



AddFeedStoreWidget::AddFeedStoreWidget(QWidget *parent)
	:MoveableFramelessWindow(parent)
	,ui(new Ui::AddFeedStoreWidget)
{
	ui->setupUi(this);
	connect(ui->pop_close_btn, &QPushButton::clicked, this, &QWidget::close);
	connect(ui->pop_cancle_btn, &QPushButton::clicked, this, &QWidget::close);
	connect(ui->pop_min_btn, &QPushButton::clicked, this, &QWidget::showMinimized);
	connect(ui->pop_commit_btn, &QPushButton::clicked, this, &AddFeedStoreWidget::SlotCommit);
	QDateTime current_date_time = QDateTime::currentDateTime();
	ui->dateEdit->setCalendarPopup(true);
	ui->dateEdit->setDateTime(current_date_time);
	ui->error_lab->setVisible(false);
	QRegExp regExp("^(([0-9]+\.[0-9]*[1-9][0-9]*)|([0-9]*[1-9][0-9]*\.[0-9]+)|([0-9]*[1-9][0-9]*))$");//创建了一个模式
	QRegExpValidator *pattern = new QRegExpValidator(regExp, this);//创建了一个表达式
	ui->pice_Edit->setValidator(pattern);

	QRegExp regExpr("^[0-9]*[1-9][0-9]*$");
	QRegExpValidator *patternr = new QRegExpValidator(regExpr, this);//创建了一个表达式
	ui->Number_Edit->setValidator(patternr);
}


AddFeedStoreWidget::~AddFeedStoreWidget()
{
}

QWidget* AddFeedStoreWidget::getDragnWidget()
{
	return ui->pop_widget_title;
}

void AddFeedStoreWidget::SlotCommit()
{
	QString subject_name = ui->subject_name_Edit->text();
	QString  price = ui->pice_Edit->text();
	QString number = ui->Number_Edit->text();

	if (subject_name == ""||price == ""|| number == "")
	{
		ui->error_lab->setVisible(true);
		return;
	}
	emit sig_commit(ui->dateEdit->text(), ui->use_Edit->text(), subject_name, price, ui->unit_Edit->text(), ui->norms_Edit->text(), number);
	emit ui->pop_close_btn->clicked();
}
