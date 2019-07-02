#include "DescMaterialWidget.h"



DescMaterialWidget::DescMaterialWidget(QWidget *parent) 
	:MoveableFramelessWindow(parent)
, ui(new Ui::DescMaterialWidget)
{
	ui->setupUi(this);
	connect(ui->pop_close_btn, &QPushButton::clicked, this, &QWidget::close);
	connect(ui->pop_cancle_btn, &QPushButton::clicked, this, &QWidget::close);
	connect(ui->pop_min_btn, &QPushButton::clicked, this, &QWidget::showMinimized);
	for (auto&kvp:g_CostAreaList)
	{
		ui->comboBox->addItem(kvp.second.areaName);
	}
	ui->comboBox->setCurrentIndex(0);
}


DescMaterialWidget::~DescMaterialWidget()
{
}

QWidget* DescMaterialWidget::getDragnWidget()
{
	return ui->pop_widget_title;
}
