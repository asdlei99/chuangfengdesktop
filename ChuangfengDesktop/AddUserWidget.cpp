#include "AddUserWidget.h"



AddUserWidget::AddUserWidget(QWidget *parent )
	:MoveableFramelessWindow(parent)
	, ui(new Ui::adduserWidget)
{
	//00C8FF
	ui->setupUi(this);
	connect(ui->pop_cloase_btn, &QPushButton::clicked, this, &QWidget::close);
	connect(ui->pop_cancle_btn, &QPushButton::clicked, this, &QWidget::close);
	connect(ui->pop_min_btn, &QPushButton::clicked, this, &QWidget::showMinimized);
	ui->comboBox->addItem(QString::fromLocal8Bit("����Ա"));
	ui->comboBox->addItem(QString::fromLocal8Bit("����Ա"));
	ui->comboBox->setCurrentIndex(0);
	ui->error_lab->setVisible(false);
	ui->sure_password_edit->setEchoMode(QLineEdit::Password);
	ui->password_edit->setEchoMode(QLineEdit::Password);
	connect(ui->pop_commit_btn, &QPushButton::clicked, this, [this]()->void {
		this->DoCommit();
	});
}


AddUserWidget::~AddUserWidget()
{
}

void AddUserWidget::DoCommit()
{
	if (ui->password_edit->text() != ui->sure_password_edit->text())
	{
		ui->password_edit->setText("");
		ui->sure_password_edit->setText("");
		ui->error_lab->setVisible(true);
		return;
	}
	emit RequestAddUser(ui->userName_Edit->text(), ui->password_edit->text(),ui->comboBox->currentText());
	emit this->ui->pop_cloase_btn->clicked();
}

QWidget* AddUserWidget::getDragnWidget()
{
	return ui->pop_widget_title;
}
