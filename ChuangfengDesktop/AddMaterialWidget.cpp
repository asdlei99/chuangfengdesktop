#include "AddMaterialWidget.h"



AddMaterialWidget::AddMaterialWidget(QWidget *parent )
	:MoveableFramelessWindow(parent)
	, ui(new Ui::materialStorgeWidget)
{
	ui->setupUi(this);
	connect(ui->pop_close_btn, &QPushButton::clicked, this, &QWidget::close);
	connect(ui->pop_cancle_btn, &QPushButton::clicked, this, &QWidget::close);
	connect(ui->pop_min_btn, &QPushButton::clicked, this, &QWidget::showMinimized);
	connect(ui->pop_commit_btn, &QPushButton::clicked, this, &AddMaterialWidget::SlotCommit);
	QDateTime current_date_time = QDateTime::currentDateTime();
	ui->dateEdit->setCalendarPopup(true);
	ui->dateEdit->setDateTime(current_date_time);
	ui->error_lab->setVisible(false);
	QRegExp regExp("^(([0-9]+\.[0-9]*[1-9][0-9]*)|([0-9]*[1-9][0-9]*\.[0-9]+)|([0-9]*[1-9][0-9]*))$");//创建了一个模式
	QRegExpValidator *pattern = new QRegExpValidator(regExp, this);//创建了一个表达式
	ui->pice_Edit->setValidator(pattern);
	ui->freight_Edit->setValidator(pattern);

	QRegExp regExpr("^[0-9]*[1-9][0-9]*$");
	QRegExpValidator *patternr = new QRegExpValidator(regExpr, this);//创建了一个表达式
	ui->Number_Edit->setValidator(patternr);
}


AddMaterialWidget::~AddMaterialWidget()
{
}

QWidget* AddMaterialWidget::getDragnWidget()
{
	return ui->pop_widget_title;
}

void AddMaterialWidget::SlotCommit()
{
	QString m_addTime = ui->dateEdit->text();
	QString m_addUse = ui->use_Edit->text();
	QString m_addSubject_name = ui->subject_name_Edit->text();
	QString m_addCategory = ui->subject_Edit->text();
	QString m_addPrice = ui->pice_Edit->text();
	QString m_addUnit = ui->unit_Edit->text();
	QString m_addSpecs = ui->norms_Edit->text();
	QString m_addFare = ui->freight_Edit->text();
	QString m_addNumber = ui->Number_Edit->text();
	if (m_addPrice ==""|| m_addSubject_name==""|| m_addNumber=="")
	{
		ui->error_lab->setVisible(true);
		return;
	}
	emit sig_commit(m_addTime, m_addUse, m_addSubject_name, m_addCategory, m_addPrice,
		m_addUnit, m_addSpecs, m_addFare, m_addNumber);
	emit ui->pop_close_btn->clicked();
}
