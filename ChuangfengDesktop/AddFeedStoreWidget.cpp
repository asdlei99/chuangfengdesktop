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

}
