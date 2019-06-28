#include "AddFundDetailWidget.h"
#include "globalVariable.h"
#include <QCalendarWidget>



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
	QString time = ui->dateEdit->text();
	QString strInCom = ui->incom_Edit->text();
	QString strPay = ui->pay_Edit->text();
	QString remake = ui->remake_Edit->text();
	QString taskName;
	QString costArea;
	if (ui->share_comboBox->currentText() == QString::fromLocal8Bit("自定义"))
	{
		taskName = ui->subject_Edit->text();
	}
	else
	{
		taskName = ui->share_comboBox->currentText();
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
