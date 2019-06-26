#include "CommonDependenceWidget.h"
#include "globalVariable.h"

CommonDependenceWidget::CommonDependenceWidget(PopDependenceWidgetEnum type, QWidget *parent)
	: MoveableFramelessWindow(parent)
	,m_enWidgetType(type)
	, ui(new Ui::CommondenpendenceWidget)
{
	ui->setupUi(this);
	connect(ui->pop_close_btn, &QPushButton::clicked, this, &QWidget::close);
	connect(ui->pop_cancle_btn, &QPushButton::clicked, this, &QWidget::close);
	connect(ui->pop_min_btn, &QPushButton::clicked, this, &QWidget::showMinimized);
	connect(ui->area_combox, SIGNAL(currentIndexChanged(int)), this, SLOT(comboBoxValueChanged()));
	ui->custom_name_Edit->setVisible(false);
	switch (m_enWidgetType)
	{
	case enShareItemLayout:
		ui->tagName_lab->setText(QString::fromLocal8Bit("费用名称："));
		setWindowTitle(QString::fromLocal8Bit("费用管理"));
		ui->title_lab->setText(QString::fromLocal8Bit("费用管理"));
		break;
	case enDetailAreaLayout:
		ui->tagName_lab->setText(QString::fromLocal8Bit("塘号名称："));
		setWindowTitle(QString::fromLocal8Bit("塘口管理"));
		ui->title_lab->setText(QString::fromLocal8Bit("塘口管理"));
		break;
	default:
		break;
	}
	for (auto&kvp:g_areaList)
	{
		ui->area_combox->addItem(kvp.second.areaName);
	}
	ui->area_combox->addItem(QString::fromLocal8Bit("自定义"));
	ui->area_combox->setCurrentIndex(0);
	ui->error_lab->setVisible(false);
	connect(ui->pop_commit_btn, &QPushButton::clicked, this, [this]()->void {
		if (ui->tag_name_Edit->text() == "" || (ui->area_combox->currentText() == QString::fromLocal8Bit("自定义") && ui->custom_name_Edit->text() == ""))
		{
			ui->error_lab->setVisible(true);
			return;
		}
		QString strArea = ui->area_combox->currentText() == QString::fromLocal8Bit("自定义") ? ui->custom_name_Edit->text() : ui->area_combox->currentText();
		emit sig_comit(ui->tag_name_Edit->text(), strArea);
		emit ui->pop_close_btn->clicked();
	});
}


CommonDependenceWidget::~CommonDependenceWidget()
{
}

QWidget* CommonDependenceWidget::getDragnWidget()
{
	return ui->pop_widget_title;
}

void CommonDependenceWidget::comboBoxValueChanged()
{
	if (ui->area_combox->currentText() == QString::fromLocal8Bit("自定义"))
	{
		ui->custom_name_Edit->setVisible(true);
	}
	else {
		ui->custom_name_Edit->setVisible(false);
	}
}
