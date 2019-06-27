#include "AddNoPayDetailWidget.h"
#include "globalVariable.h"

AddNoPayDetailWidget::AddNoPayDetailWidget( QWidget *parent )
	:MoveableFramelessWindow(parent)
	,ui(new Ui::addNoPayDetailWidget)
{
	ui->setupUi(this);
	connect(ui->pop_close_btn, &QPushButton::clicked, this, &QWidget::close);
	connect(ui->pop_cancle_btn, &QPushButton::clicked, this, &QWidget::close);
	connect(ui->pop_min_btn, &QPushButton::clicked, this, &QWidget::showMinimized);
	for (auto&kvp:g_SupplierList)
	{
		ui->comboBox->addItem(kvp.second);
	}
	ui->comboBox->addItem(QString::fromLocal8Bit("自定义"));
	ui->comboBox->setCurrentIndex(0);
	connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(comboBoxValueChanged()));
	ui->supplier_edit->setVisible(false);
}


AddNoPayDetailWidget::~AddNoPayDetailWidget()
{
}

QWidget* AddNoPayDetailWidget::getDragnWidget()
{
	return ui->pop_widget_title;
}

void AddNoPayDetailWidget::comboBoxValueChanged()
{
	if (ui->comboBox->currentText() == QString::fromLocal8Bit("自定义"))
	{
		ui->supplier_edit->setVisible(true);
	}
	else {
		ui->supplier_edit->setVisible(false);
	}
}
