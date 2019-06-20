#pragma once
#include <memory>
#include "QtCustomBaseWnd.h"
#include "ui_ChuangfengDesktop.h"
#include "QNavButton.h"
#include "UserLayoutManger.h"
#include "CategoryLayoutManager.h"
#include "AreaLayoutManager.h"
#include "SupplierLayoutManager.h"
#include "ShareItemLayoutManager.h"
#include "DetailAreaLayoutManager.h"
#include "TotalReportManager.h"
#include "NopayReportManger.h"
#include "ShareReportManager.h"
#include "DetailShareReportManager.h"
#include "MaterielReportManger.h"
#include "StoreReportManager.h"
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

	void initMainOption();
	void initSysLayoutOption();

	void initReportLayoutOption();
signals:
	void CloseMainWidgetSingnal();
public slots:
	void updateMaximize();
	void SlotOptionClick();
	void SlotSysLayoutOptionClick();
private:
	Ui::ChuangfengDesktopClass*ui;
	QList< NavButton*> mNavButtonList;
	QList< NavButton*> m_SysLayoutNavButtonList;
	shared_ptr<UserLayoutManger> m_ptrUserLayoutManger;
	shared_ptr<CategoryLayoutManager> m_ptrCategoryLayoutManager;
	shared_ptr<AreaLayoutManager> m_ptrAreaLayoutManager;
	shared_ptr<SupplierLayoutManager> m_ptrSupplierLayoutManager;
	shared_ptr<ShareItemLayoutManager> m_ptrShareItemLayoutManager;
	shared_ptr<DetailAreaLayoutManager> m_ptrDetailAreaLayoutManager;
};
