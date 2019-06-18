#pragma once
#include <memory>
#include "QtCustomBaseWnd.h"
#include "ui_ChuangfengDesktop.h"
#include "QNavButton.h"
#include "UserLayoutManger.h"
using namespace  std;

class ChuangfengDesktop :  public MoveableFramelessWindow
{
	Q_OBJECT

public:
	ChuangfengDesktop(QWidget *parent = Q_NULLPTR);
	void close();
	//˫�����������н�������/��ԭ
	virtual void mouseDoubleClickEvent(QMouseEvent *event);
	void paintEvent(QPaintEvent *event);
private:
	virtual QWidget*getDragnWidget();
private:
	bool nativeEvent(const QByteArray &eventType, void *message, long *result);
	void initMainOption();
	void initSysLayoutOption();
	void initFinancialLayoutOption();
	void initReportLayoutOption();
signals:
	void CloseMainWidgetSingnal();
public slots:
	void updateMaximize();
	void SlotOptionClick();
	void SlotSysLayoutOptionClick();
	void SlotFinancialLayoutOptionClick();
	void SlotReportLayoutOptionClick();
private:
	Ui::ChuangfengDesktopClass*ui;
	int m_nBorderWidth; //m_nBorder��ʾ���λ�ڱ߿����ŷ�Χ�Ŀ��
	QList< NavButton*> mNavButtonList;
	QList< NavButton*> m_SysLayoutNavButtonList;
	QList< NavButton*> m_FinancialLayoutNavButtonList;
	QList< NavButton*> m_ReportLayoutNavButtonList;
	shared_ptr<UserLayoutManger> m_ptrUserLayoutManger;
};
