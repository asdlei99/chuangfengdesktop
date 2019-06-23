#include "AddUserWidget.h"



AddUserWidget::AddUserWidget(QWidget *parent )
	:MoveableFramelessWindow(parent)
	, ui(new Ui::adduserWidget)
{
	//00C8FF
	ui->setupUi(this);
	connect(ui->pop_cloase_btn, &QPushButton::clicked, this, &QWidget::close);
	connect(ui->pop_min_btn, &QPushButton::clicked, this, &QWidget::showMinimized);

}


AddUserWidget::~AddUserWidget()
{
}

QWidget* AddUserWidget::getDragnWidget()
{
	return ui->pop_widget_title;
}
