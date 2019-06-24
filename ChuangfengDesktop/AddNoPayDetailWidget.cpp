#include "AddNoPayDetailWidget.h"

AddNoPayDetailWidget::AddNoPayDetailWidget( QWidget *parent )
	:MoveableFramelessWindow(parent)
	,ui(new Ui::addNoPayDetailWidget)
{
	ui->setupUi(this);
	connect(ui->pop_cloase_btn, &QPushButton::clicked, this, &QWidget::close);
	connect(ui->pop_cancle_btn, &QPushButton::clicked, this, &QWidget::close);
	connect(ui->pop_min_btn, &QPushButton::clicked, this, &QWidget::showMinimized);
}


AddNoPayDetailWidget::~AddNoPayDetailWidget()
{
}

QWidget* AddNoPayDetailWidget::getDragnWidget()
{
	return ui->pop_widget_title;
}
