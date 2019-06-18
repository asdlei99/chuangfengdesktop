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
	//双击标题栏进行界面的最大化/还原
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
	int m_nBorderWidth; //m_nBorder表示鼠标位于边框缩放范围的宽度
	QList< NavButton*> mNavButtonList;
	QList< NavButton*> m_SysLayoutNavButtonList;
	QList< NavButton*> m_FinancialLayoutNavButtonList;
	QList< NavButton*> m_ReportLayoutNavButtonList;
	shared_ptr<UserLayoutManger> m_ptrUserLayoutManger;
};
