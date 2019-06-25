#include "AddFundDetailWidget.h"



AddFundDetailWidget::AddFundDetailWidget(PopFundDetailEnum type, QWidget *parent)
	:MoveableFramelessWindow(parent)
	,ui(new Ui::addFundDetailWidget)
	,m_enWidgetType(type)
{
	ui->setupUi(this);
	connect(ui->pop_close_btn, &QPushButton::clicked, this, &QWidget::close);
	connect(ui->pop_cancle_btn, &QPushButton::clicked, this, &QWidget::close);
	connect(ui->pop_min_btn, &QPushButton::clicked, this, &QWidget::showMinimized);
	switch (m_enWidgetType)
	{
	case enGeneralLayout:
		setWindowTitle(QString::fromLocal8Bit("������֧��ϸ"));
		ui->title_lab->setText(QString::fromLocal8Bit("������֧��ϸ"));
		break;
	case enBakLayout:
		setWindowTitle(QString::fromLocal8Bit("���ý���ϸ"));
		ui->title_lab->setText(QString::fromLocal8Bit("���ý���ϸ"));
		break;
	default:
		break;
	}
}


AddFundDetailWidget::~AddFundDetailWidget()
{
}

QWidget* AddFundDetailWidget::getDragnWidget()
{
	return ui->pop_widget_title;
}
