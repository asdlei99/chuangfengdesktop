#include "Common2ParamWidget.h"

Common2ParamWidget::Common2ParamWidget(PopWidgetEnum type, QWidget *parent)
	:MoveableFramelessWindow(parent)
	,ui(new Ui::Common2ParamWidget)
	,m_enWidgetType(type)
{
	ui->setupUi(this);
	connect(ui->pop_cloase_btn, &QPushButton::clicked, this, &QWidget::close);
	connect(ui->pop_cancle_btn, &QPushButton::clicked, this, &QWidget::close);
	connect(ui->pop_min_btn, &QPushButton::clicked, this, &QWidget::showMinimized);
	switch (m_enWidgetType)
	{
	case enCategoryLayout:
	{
		ui->tagName_lab->setText(QString::fromLocal8Bit("��Ŀ���ƣ�"));
		setWindowTitle(QString::fromLocal8Bit("��Ŀ����"));
		ui->title_lab->setText(QString::fromLocal8Bit("��Ŀ����"));
		break;
	}
	case enAreaLayout:
	{
		ui->tagName_lab->setText(QString::fromLocal8Bit("�������ƣ�"));
		setWindowTitle(QString::fromLocal8Bit("�������"));
		ui->title_lab->setText(QString::fromLocal8Bit("�������"));
		break;
	}
	case enSupplierLayout:
	{
		ui->tagName_lab->setText(QString::fromLocal8Bit("��Ӧ�����ƣ�"));
		setWindowTitle(QString::fromLocal8Bit("��Ӧ�̹���"));
		ui->title_lab->setText(QString::fromLocal8Bit("��Ӧ�̹���"));
		break;
	}
	default:
		break;
	}
}


Common2ParamWidget::~Common2ParamWidget()
{
}

QWidget* Common2ParamWidget::getDragnWidget()
{
	return ui->pop_widget_title;
}
