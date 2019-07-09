#include "AddNoPayDetailWidget.h"
#include "globalVariable.h"

AddNoPayDetailWidget::AddNoPayDetailWidget( QWidget *parent )
	:MoveableFramelessWindow(parent)
	,ui(new Ui::addNoPayDetailWidget)
{
	ui->setupUi(this);
	connect(ui->pop_close_btn, &QPushButton::clicked, this, &QWidget::close);
	connect(ui->pop_cancle_btn, &QPushButton::clicked, this, &QWidget::close);
	connect(ui->pop_min_btn, &QPushButton::clicked, this, &QWidget::showMinimized);
	for (auto&kvp:g_SupplierList)
	{
		ui->comboBox->addItem(kvp.second);
	}
	ui->comboBox->addItem(QString::fromLocal8Bit("自定义"));
	ui->comboBox->setCurrentIndex(0);
	connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(comboBoxValueChanged()));
	connect(ui->pop_commit_btn, &QPushButton::clicked, this, &AddNoPayDetailWidget::SlotCommitAction);
	ui->supplier_edit->setVisible(false);
	QDateTime current_date_time = QDateTime::currentDateTime();
	ui->dateEdit->setCalendarPopup(true);
	ui->dateEdit->setDateTime(current_date_time);
	QRegExp regExp("^(([0-9]+\.[0-9]*[1-9][0-9]*)|([0-9]*[1-9][0-9]*\.[0-9]+)|([0-9]*[1-9][0-9]*))$");//创建了一个模式
	QRegExpValidator *pattern = new QRegExpValidator(regExp, this);//创建了一个表达式
	ui->adjust_edit->setValidator(pattern);
	ui->new_add_edit->setValidator(pattern);
	ui->return_edit->setValidator(pattern);
	ui->pay_edit->setValidator(pattern);
	ui->error_lab->setVisible(false);
}


AddNoPayDetailWidget::~AddNoPayDetailWidget()
{
}

QWidget* AddNoPayDetailWidget::getDragnWidget()
{
	return ui->pop_widget_title;
}

void AddNoPayDetailWidget::comboBoxValueChanged()
{
	if (ui->comboBox->currentText() == QString::fromLocal8Bit("自定义"))
	{
		ui->supplier_edit->setVisible(true);
	}
	else {
		ui->supplier_edit->setVisible(false);
	}
}

void AddNoPayDetailWidget::SlotCommitAction()
{
	QString time = ui->dateEdit->text();
	QString suplier;
	if (ui->comboBox->currentText() == QString::fromLocal8Bit("自定义"))
	{
		suplier = ui->supplier_edit->text();
	}
	else {
		suplier = ui->comboBox->currentText();
	}
	QString adjust = ui->adjust_edit->text();
	QString newAdd = ui->new_add_edit->text();
	QString strReturn = ui->return_edit->text();
	QString pay = ui->pay_edit->text();
	QString remake = ui->remake_edit->text();
	if (pay ==""|| strReturn == ""|| newAdd == ""|| adjust == ""|| suplier=="")
	{
		ui->error_lab->setVisible(true);
		return;
	}
	emit sig_commit(time, suplier, adjust, newAdd, strReturn, pay, remake);
	emit this->ui->pop_close_btn->clicked();
}
