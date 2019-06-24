#include "CommonDependenceWidget.h"

CommonDependenceWidget::CommonDependenceWidget(PopDependenceWidgetEnum type, QWidget *parent)
	: MoveableFramelessWindow(parent)
	,m_enWidgetType(type)
	, ui(new Ui::CommondenpendenceWidget)
{
	ui->setupUi(this);
	connect(ui->pop_cloase_btn, &QPushButton::clicked, this, &QWidget::close);
	connect(ui->pop_cancle_btn, &QPushButton::clicked, this, &QWidget::close);
	connect(ui->pop_min_btn, &QPushButton::clicked, this, &QWidget::showMinimized);
	switch (m_enWidgetType)
	{
	case enShareItemLayout:
		ui->tagName_lab->setText(QString::fromLocal8Bit("�������ƣ�"));
		setWindowTitle(QString::fromLocal8Bit("���ù���"));
		ui->title_lab->setText(QString::fromLocal8Bit("���ù���"));
		break;
	case enDetailAreaLayout:
		ui->tagName_lab->setText(QString::fromLocal8Bit("�������ƣ�"));
		setWindowTitle(QString::fromLocal8Bit("���ڹ���"));
		ui->title_lab->setText(QString::fromLocal8Bit("���ڹ���"));
		break;
	default:
		break;
	}
}


CommonDependenceWidget::~CommonDependenceWidget()
{
}

QWidget* CommonDependenceWidget::getDragnWidget()
{
	return ui->pop_widget_title;
}
