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
	ui->error_code_lab->setText(QString::fromLocal8Bit("´íÎó´úÂë£º") + QString::number(m_iErrorCode));
	switch (m_iErrorCode)
	{
	
	default:
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
