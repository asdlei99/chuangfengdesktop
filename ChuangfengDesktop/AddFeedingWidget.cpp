#include "AddFeedingWidget.h"
#include "globalVariable.h"



AddFeedingWidget::AddFeedingWidget(QString&subject_name, QString&price, int maxNumber, QString&areaName, QWidget *parent)
	:MoveableFramelessWindow(parent)
	, ui(new Ui::AddFeedingWidget)
	, m_subject_name(subject_name)
	, m_price(price)
	, maxNumber(maxNumber)
	, m_areaName(areaName)
{
	ui->setupUi(this);
	connect(ui->pop_close_btn, &QPushButton::clicked, this, &QWidget::close);
	connect(ui->pop_cancle_btn, &QPushButton::clicked, this, &QWidget::close);
	connect(ui->pop_min_btn, &QPushButton::clicked, this, &QWidget::showMinimized);
	connect(ui->pop_commit_btn, &QPushButton::clicked, this, &AddFeedingWidget::SlotCommit);
	ui->subject_name_Edit->setText(m_subject_name);
	ui->pice_Edit->setText(m_price);
	ui->area_Edit->setText(areaName);
	for (auto&kvp:g_areaList)
	{
		if (kvp.second.areaName == m_areaName)
		{
			for (auto&kvpi:kvp.second.areaDetailList)
			{
				ui->comboBox->addItem(kvpi.second);
			}
		}
	}

	QRegExp regExpr("^[0-9]*[1-9][0-9]*$");
	QRegExpValidator *patternr = new QRegExpValidator(regExpr, this);//创建了一个表达式
	ui->Number_Edit->setValidator(patternr);
	ui->error_lab->setVisible(false);
}


AddFeedingWidget::~AddFeedingWidget()
{

}

QWidget* AddFeedingWidget::getDragnWidget()
{
	return ui->pop_widget_title;
}

void AddFeedingWidget::SlotCommit()
{
	QString Number = ui->Number_Edit->text();

	if (Number.toInt()>maxNumber)
	{
		ui->error_lab->setText(QString::fromLocal8Bit("库存不足！"));
		ui->error_lab->setVisible(true);
		return;
	}
	else if (Number == "")
	{
		ui->error_lab->setText(QString::fromLocal8Bit("数量不能为空"));
		ui->error_lab->setVisible(true);
		return;
	}
	emit sig_commit(ui->dateEdit->text(), Number, ui->comboBox->currentText());
	emit ui->pop_close_btn->clicked();

}
