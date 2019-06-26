#include "MsgPopWidget.h"



MsgPopWidget::MsgPopWidget( QString strMsg, int iErrorCode, QWidget *parent )
	:MoveableFramelessWindow(parent)
	, ui(new Ui::MsgPopWidget)
	,m_strMsg(strMsg)
	,m_iErrorCode(iErrorCode)
{
	ui->setupUi(this);
	connect(ui->pop_close_btn, &QPushButton::clicked, this, &QWidget::close);
	connect(ui->pop_commit_btn, &QPushButton::clicked, this, &QWidget::close);
	ui->msg_label->setText(m_strMsg);
	
	switch (m_iErrorCode)
	{
	case 0:
		//设置按钮的属性名为"maximizeProperty"
		ui->ico_lab->setProperty("icoProperty", "success");
		ui->ico_lab->setStyle(QApplication::style());
		break;
	
	default:
		ui->error_code_lab->setText(QString::fromLocal8Bit("错误代码：") + QString::number(m_iErrorCode));
		//设置按钮的属性名为"maximizeProperty"
		ui->ico_lab->setProperty("icoProperty", "error");
		ui->ico_lab->setStyle(QApplication::style());
		break;
	}
	
}


MsgPopWidget::~MsgPopWidget()
{
}

QWidget* MsgPopWidget::getDragnWidget()
{
	return ui->pop_widget_title;
}
