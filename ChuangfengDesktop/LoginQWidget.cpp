#include "LoginQWidget.h"
#include "ChuangfengDesktop.h"



LoginQWidget::LoginQWidget(QWidget *parent)
	:
	MoveableFramelessWindow(parent),
	ui(new Ui::QtLoginWidget)
{
	ui->setupUi(this);
	ui->user_Edit->setPlaceholderText(QStringLiteral("用户名"));
	ui->user_Edit->setStyleSheet("background:transparent;border-width:0;border-style:outset");
	ui->password_Edit->setPlaceholderText(QStringLiteral("密码"));
	ui->password_Edit->setEchoMode(QLineEdit::Password);
	ui->password_Edit->setStyleSheet("background:transparent;border-width:0;border-style:outset");
	ui->servce_ip->setPlaceholderText(QStringLiteral("IP地址"));
	ui->servce_ip->setStyleSheet("background:transparent;border-width:0;border-style:outset");
	ui->port_Edit->setPlaceholderText(QStringLiteral("端口号"));

	ui->port_Edit->setStyleSheet("background:transparent;border-width:0;border-style:outset");

	connect(ui->servce_set_btn, &QPushButton::clicked, this, [&]()->void {
		ui->stackedWidget->setCurrentIndex(1);
		ui->servce_set_btn->setVisible(false);
	});
	connect(ui->config_ok_btn, &QPushButton::clicked, this, [&]()->void {
		ui->stackedWidget->setCurrentIndex(0);
		ui->servce_set_btn->setVisible(true);
	});
	connect(ui->login_close_btn, &QPushButton::clicked, this, [&]()->void {
		QWidget::close();
	});

	connect(ui->login_btn, &QPushButton::clicked, this, [&]()->void {
		ChuangfengDesktop*pQtWidget = new ChuangfengDesktop();
		connect(pQtWidget, SIGNAL(CloseMainWidgetSingnal()), this, SLOT(SlotCloseMainWidget()));
		pQtWidget->setAttribute(Qt::WA_DeleteOnClose);
		pQtWidget->setWindowModality(Qt::ApplicationModal);
		pQtWidget->show();
		this->hide();
	});
}


LoginQWidget::~LoginQWidget()
{
}

void LoginQWidget::SlotCloseMainWidget()
{
	__super::close();
}

QWidget* LoginQWidget::getDragnWidget()
{
	return  ui->login_title;
}
