#pragma once
#include "QtCustomBaseWnd.h"
#include "ui_MsgPopWidget.h"


class MsgPopWidget :
	public MoveableFramelessWindow
{
	Q_OBJECT
public:
	MsgPopWidget( QString strMsg, int iErrorCode,QWidget *parent = Q_NULLPTR);
	~MsgPopWidget();
private:
	virtual QWidget*getDragnWidget();
private:
	Ui::MsgPopWidget*ui;
	QString m_strMsg;
	int m_iErrorCode;
};

