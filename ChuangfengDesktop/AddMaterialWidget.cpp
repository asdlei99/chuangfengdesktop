#include "AddMaterialWidget.h"



AddMaterialWidget::AddMaterialWidget(QWidget *parent )
	:MoveableFramelessWindow(parent)
	, ui(new Ui::materialStorgeWidget)
{
	ui->setupUi(this);
	connect(ui->pop_close_btn, &QPushButton::clicked, this, &QWidget::close);
	connect(ui->pop_cancle_btn, &QPushButton::clicked, this, &QWidget::close);
	connect(ui->pop_min_btn, &QPushButton::clicked, this, &QWidget::showMinimized);
}


AddMaterialWidget::~AddMaterialWidget()
{
}

QWidget* AddMaterialWidget::getDragnWidget()
{
	return ui->pop_widget_title;
}
