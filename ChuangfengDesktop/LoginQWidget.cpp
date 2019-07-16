
#include "LoginQWidget.h"
#include "ChuangfengDesktop.h"
#include "ThreadPool.hpp"
#include "globalVariable.h"
#include "SingletonHttpRequest.h"
#include "commomdef.h"


LoginQWidget::LoginQWidget(QWidget *parent)
	:
	MoveableFramelessWindow(parent),
	ui(new Ui::QtLoginWidget)
	, m_bIsLoginLayout(true)
{
	ui->setupUi(this);
	ui->user_Edit->setPlaceholderText(QStringLiteral("ÓÃ»§Ãû"));
	ui->user_Edit->setStyleSheet("background:transparent;border-width:0;border-style:outset");
	ui->password_Edit->setPlaceholderText(QStringLiteral("ÃÜÂë"));
	ui->password_Edit->setEchoMode(QLineEdit::Password);
	ui->password_Edit->setStyleSheet("background:transparent;border-width:0;border-style:outset");
	ui->servce_ip->setPlaceholderText(QStringLiteral("IPµØÖ·"));
	ui->servce_ip->setStyleSheet("background:transparent;border-width:0;border-style:outset");
	ui->port_Edit->setPlaceholderText(QStringLiteral("¶Ë¿ÚºÅ"));

	ui->port_Edit->setStyleSheet("background:transparent;border-width:0;border-style:outset");

	ui->servce_set_btn->setProperty("loginProperty", "login");
	ui->servce_set_btn->setStyle(QApplication::style());

	connect(ui->servce_set_btn, &QPushButton::clicked, this, [&]()->void {	
		m_bIsLoginLayout = !m_bIsLoginLayout;
		if (m_bIsLoginLayout)
		{
			ui->stackedWidget->setCurrentIndex(0);
			ui->servce_set_btn->setProperty("loginProperty", "login");
			ui->servce_set_btn->setStyle(QApplication::style());
		}
		else {
			ui->servce_set_btn->setProperty("loginProperty", "set");
			ui->servce_set_btn->setStyle(QApplication::style());
			ui->stackedWidget->setCurrentIndex(1);
		}	
	});
	
	connect(ui->login_close_btn, &QPushButton::clicked, this, [&]()->void {
		QWidget::close();
	});

	connect(ui->login_btn, &QPushButton::clicked, this, [&]()->void {
		g_strIpAddr = ui->servce_ip->text();
		 g_strIpPort = ui->port_Edit->text();
		 ui->login_btn->setEnabled(false);
		QThread *m_pThread = new QThread;
		connect(m_pThread, SIGNAL(started()), this, SLOT(SlotThreadLogin()));
		connect(m_pThread, SIGNAL(finished()), m_pThread, SLOT(deleteLater()));
		m_pThread->start();
	});
	ui->error_lab->setVisible(false);
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

void LoginQWidget::SlotThreadLogin()
{
	QString Url = QString(LONGINURL).arg(g_strIpAddr).arg(g_strIpPort);
	QString md5;
	QByteArray bb;
	bb = QCryptographicHash::hash(ui->password_Edit->text().toLocal8Bit(), QCryptographicHash::Md5);
	md5.append(bb.toHex());
	QString strParam = QString("username=%1&password=%2").arg(ui->user_Edit->text()).arg(md5);
	QByteArray responseData;
	SingletonHttpRequest::getInstance()->RequestPost(Url, "", strParam, responseData);
	
	QJsonParseError json_error;
	QJsonDocument parse_doucment = QJsonDocument::fromJson(responseData, &json_error);
	if (json_error.error == QJsonParseError::NoError)
	{
		QJsonObject rootObject = parse_doucment.object();
		int errorcode = rootObject["error_code"].toInt();
		QString strMsg = rootObject["msg"].toString();
		
		if (errorcode == 0)//³É¹¦
		{
			g_token = rootObject["token"].toString();
			ui->login_btn->setEnabled(true);
			this->hide();
			ChuangfengDesktop*pQtWidget = new ChuangfengDesktop();
			connect(pQtWidget, SIGNAL(CloseMainWidgetSingnal()), this, SLOT(SlotCloseMainWidget()));
			pQtWidget->setAttribute(Qt::WA_DeleteOnClose);
			pQtWidget->setWindowModality(Qt::ApplicationModal);
			pQtWidget->show();
			return;
			
		}
		else {//Ê§°Ü
			emit sig_NotifyMsg(strMsg, errorcode);
		}
	}
	else {
		emit sig_NotifyMsg(QString::fromLocal8Bit("µÇÂ¼Ê§°Ü£¡"), 404);
	}

	//ui->error_lab->setVisible(true);
	ui->login_btn->setEnabled(true);
	/*this->show();*/
}
