#pragma once
#include <memory>
#include "QtCustomBaseWnd.h"
#include "ui_ChuangfengDesktop.h"
#include "QNavButton.h"
#include "UserLayoutManger.h"
#include "GeneralLayoutManger.h"
#include "BakLayoutManager.h"
#include "NoPayLayoutManager.h"
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
	shared_ptr<BakLayoutManager> m_ptrBakLayoutManager;
	shared_ptr<GeneralLayoutManger> m_ptrGeneralLayoutManger;
	shared_ptr<NoPayLayoutManager> m_ptrNoPayLayoutManager;
	shared_ptr<CategoryLayoutManager> m_ptrCategoryLayoutManager;
	shared_ptr<AreaLayoutManager> m_ptrAreaLayoutManager;
	shared_ptr<SupplierLayoutManager> m_ptrSupplierLayoutManager;
	shared_ptr<ShareItemLayoutManager> m_ptrShareItemLayoutManager;
	shared_ptr<DetailAreaLayoutManager> m_ptrDetailAreaLayoutManager;
	shared_ptr<TotalReportManager> m_ptrTotalReportManager;
	shared_ptr<NopayReportManger> m_ptrNopayReportManger;
	shared_ptr<ShareReportManager> m_ptrShareReportManager;
	shared_ptr<DetailShareReportManager> m_ptrDetailShareReportManager;
	shared_ptr<MaterielReportManger> m_ptrMaterielReportManger;
	shared_ptr<StoreReportManager> m_ptrStoreReportManager;
};
