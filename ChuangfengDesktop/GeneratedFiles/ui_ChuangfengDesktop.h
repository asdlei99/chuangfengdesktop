/********************************************************************************
** Form generated from reading UI file 'ChuangfengDesktop.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHUANGFENGDESKTOP_H
#define UI_CHUANGFENGDESKTOP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qnavbutton.h>

QT_BEGIN_NAMESPACE

class Ui_ChuangfengDesktopClass
{
public:
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *title_Layout;
    QWidget *main_title_widget;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget_2;
    QLabel *label;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_3;
    QWidget *widget;
    NavButton *opt_sysset;
    NavButton *opt_report;
    NavButton *opt_feed_mgr;
    NavButton *opt_store;
    NavButton *opt_finance_mgr;
    QHBoxLayout *horizontalLayout_4;
    QWidget *main_wnd_ctrl_widget;
    QPushButton *min_btn;
    QPushButton *max_restore_btn;
    QPushButton *close_btn;
    QHBoxLayout *work_Layout;
    QStackedWidget *main_stackedWidget;
    QWidget *page;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_4;
    NavButton *financial_opt_totalpay;
    NavButton *financial_opt_imprest;
    NavButton *financial_opt_payable;
    QStackedWidget *financial_StackedWidget;
    QWidget *page_11;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_7;
    QLabel *label_5;
    QLabel *label_4;
    QDateEdit *startdateEdit;
    QDateEdit *enddateEdit;
    QPushButton *general_search_btn;
    QPushButton *general_add_btn;
    QPushButton *general_del_btn;
    QPushButton *general_export_btn;
    QTableView *general_table_view;
    QWidget *page_12;
    QVBoxLayout *verticalLayout_5;
    QWidget *widget_8;
    QPushButton *bak_del_btn;
    QPushButton *bak_export_btn;
    QPushButton *bak_add_btn;
    QDateEdit *bak_enddateEdit;
    QLabel *label_6;
    QLabel *label_7;
    QDateEdit *bak_startdateEdit;
    QPushButton *bak_search_btn;
    QTableView *bak_tableView;
    QWidget *page_13;
    QVBoxLayout *verticalLayout_6;
    QWidget *widget_9;
    QDateEdit *nopay_enddateEdit;
    QLabel *label_8;
    QPushButton *nopay_search_btn;
    QPushButton *nopay_add_btn;
    QPushButton *nopay_export_btn;
    QDateEdit *nopay_startdateEdit;
    QLabel *label_9;
    QPushButton *nopay_del_btn;
    QTableView *nopay_tableView;
    QWidget *page_2;
    QPushButton *pushButton_2;
    QWidget *page_3;
    QWidget *page_4;
    QWidget *widget_5;
    NavButton *report_opt_totaltask;
    NavButton *report_opt_payable;
    NavButton *report_opt_share;
    NavButton *report_opt_signal;
    NavButton *report_opt_materiel;
    NavButton *report_opt_totalfeed;
    QStackedWidget *Report_StackedWidget;
    QWidget *page_14;
    QPushButton *pushButton_9;
    QWidget *page_19;
    QWidget *page_20;
    QWidget *page_21;
    QWidget *page_15;
    QPushButton *pushButton_10;
    QWidget *page_16;
    QPushButton *pushButton_11;
    QWidget *page_5;
    QHBoxLayout *horizontalLayout_9;
    QWidget *widget_3;
    NavButton *set_opt_person;
    NavButton *set_opt_account;
    NavButton *set_opt_detail_area;
    NavButton *set_opt_supplier;
    NavButton *set_opt_task;
    NavButton *set_opt_area;
    QStackedWidget *sysLayout_StackedWidget;
    QWidget *page_6;
    QGridLayout *gridLayout;
    QTableView *user_table_view;
    QWidget *widget_6;
    QPushButton *user_add_btn;
    QPushButton *user_remove_btn;
    QWidget *page_7;
    QVBoxLayout *verticalLayout_7;
    QWidget *widget_10;
    QPushButton *category_remove_btn;
    QPushButton *category_add_btn;
    QTableView *category_tableView;
    QWidget *page_8;
    QVBoxLayout *verticalLayout_8;
    QWidget *widget_11;
    QPushButton *area_remove_btn;
    QPushButton *area_add_btn;
    QTableView *area_tableView;
    QWidget *page_9;
    QVBoxLayout *verticalLayout_9;
    QWidget *widget_12;
    QPushButton *supplier_remove_btn;
    QPushButton *supplier_add_btn;
    QTableView *supplier_tableView;
    QWidget *page_17;
    QVBoxLayout *verticalLayout_10;
    QWidget *widget_13;
    QPushButton *shareitem_remove_btn;
    QPushButton *shareitem_add_btn;
    QTableView *shareitem_tableView;
    QWidget *page_10;
    QVBoxLayout *verticalLayout;
    QWidget *widget_14;
    QPushButton *detailarea_add_btn;
    QPushButton *detailarea_remove_btn;
    QTableView *detailarea_tableView;

    void setupUi(QWidget *ChuangfengDesktopClass)
    {
        if (ChuangfengDesktopClass->objectName().isEmpty())
            ChuangfengDesktopClass->setObjectName(QStringLiteral("ChuangfengDesktopClass"));
        ChuangfengDesktopClass->resize(1090, 582);
        ChuangfengDesktopClass->setMinimumSize(QSize(1090, 580));
        verticalLayout_4 = new QVBoxLayout(ChuangfengDesktopClass);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(2, 2, 2, 2);
        title_Layout = new QHBoxLayout();
        title_Layout->setSpacing(6);
        title_Layout->setObjectName(QStringLiteral("title_Layout"));
        main_title_widget = new QWidget(ChuangfengDesktopClass);
        main_title_widget->setObjectName(QStringLiteral("main_title_widget"));
        main_title_widget->setMinimumSize(QSize(0, 82));
        main_title_widget->setMaximumSize(QSize(16777215, 82));
        main_title_widget->setBaseSize(QSize(0, 82));
        horizontalLayout_5 = new QHBoxLayout(main_title_widget);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        widget_2 = new QWidget(main_title_widget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMinimumSize(QSize(90, 0));
        widget_2->setMaximumSize(QSize(90, 16777215));
        label = new QLabel(widget_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 50, 50));
        label->setStyleSheet(QStringLiteral("border-image: url(:/ChuangfengDesktop/Resources/test.png);"));

        horizontalLayout_2->addWidget(widget_2);


        horizontalLayout_5->addLayout(horizontalLayout_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_2 = new QLabel(main_title_widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QLatin1String("font-family: \"Microsoft YaHei\";\n"
"	font-size:26px;\n"
"	color: #ffffff;"));

        verticalLayout_2->addWidget(label_2);

        label_3 = new QLabel(main_title_widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QLatin1String("font-family: \"Microsoft YaHei\";\n"
"	font-size:14px;\n"
"	color: #ffffff;"));

        verticalLayout_2->addWidget(label_3);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer_3);


        horizontalLayout_5->addLayout(verticalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        widget = new QWidget(main_title_widget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(700, 0));
        widget->setMaximumSize(QSize(700, 16777215));
        opt_sysset = new NavButton(widget);
        opt_sysset->setObjectName(QStringLiteral("opt_sysset"));
        opt_sysset->setGeometry(QRect(460, 40, 105, 40));
        opt_sysset->setStyleSheet(QString::fromUtf8("font: 75 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        opt_report = new NavButton(widget);
        opt_report->setObjectName(QStringLiteral("opt_report"));
        opt_report->setGeometry(QRect(350, 40, 105, 40));
        opt_report->setStyleSheet(QString::fromUtf8("font: 75 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        opt_feed_mgr = new NavButton(widget);
        opt_feed_mgr->setObjectName(QStringLiteral("opt_feed_mgr"));
        opt_feed_mgr->setGeometry(QRect(240, 40, 105, 40));
        opt_feed_mgr->setStyleSheet(QString::fromUtf8("font: 75 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        opt_store = new NavButton(widget);
        opt_store->setObjectName(QStringLiteral("opt_store"));
        opt_store->setGeometry(QRect(130, 40, 105, 40));
        opt_store->setStyleSheet(QString::fromUtf8("font: 75 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        opt_finance_mgr = new NavButton(widget);
        opt_finance_mgr->setObjectName(QStringLiteral("opt_finance_mgr"));
        opt_finance_mgr->setGeometry(QRect(20, 40, 105, 40));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(11);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(9);
        opt_finance_mgr->setFont(font);
        opt_finance_mgr->setStyleSheet(QString::fromUtf8("font: 75 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout_3->addWidget(widget);


        horizontalLayout_5->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        main_wnd_ctrl_widget = new QWidget(main_title_widget);
        main_wnd_ctrl_widget->setObjectName(QStringLiteral("main_wnd_ctrl_widget"));
        main_wnd_ctrl_widget->setMinimumSize(QSize(90, 0));
        main_wnd_ctrl_widget->setMaximumSize(QSize(90, 82));
        min_btn = new QPushButton(main_wnd_ctrl_widget);
        min_btn->setObjectName(QStringLiteral("min_btn"));
        min_btn->setGeometry(QRect(0, 0, 30, 23));
        max_restore_btn = new QPushButton(main_wnd_ctrl_widget);
        max_restore_btn->setObjectName(QStringLiteral("max_restore_btn"));
        max_restore_btn->setGeometry(QRect(30, 0, 30, 23));
        close_btn = new QPushButton(main_wnd_ctrl_widget);
        close_btn->setObjectName(QStringLiteral("close_btn"));
        close_btn->setGeometry(QRect(60, 0, 30, 23));

        horizontalLayout_4->addWidget(main_wnd_ctrl_widget);


        horizontalLayout_5->addLayout(horizontalLayout_4);


        title_Layout->addWidget(main_title_widget);


        verticalLayout_4->addLayout(title_Layout);

        work_Layout = new QHBoxLayout();
        work_Layout->setSpacing(6);
        work_Layout->setObjectName(QStringLiteral("work_Layout"));
        main_stackedWidget = new QStackedWidget(ChuangfengDesktopClass);
        main_stackedWidget->setObjectName(QStringLiteral("main_stackedWidget"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        horizontalLayout = new QHBoxLayout(page);
        horizontalLayout->setSpacing(1);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        widget_4 = new QWidget(page);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setMinimumSize(QSize(160, 0));
        widget_4->setStyleSheet(QStringLiteral("background-color:#44474D;  "));
        financial_opt_totalpay = new NavButton(widget_4);
        financial_opt_totalpay->setObjectName(QStringLiteral("financial_opt_totalpay"));
        financial_opt_totalpay->setGeometry(QRect(10, 50, 140, 35));
        financial_opt_totalpay->setStyleSheet(QString::fromUtf8("font: 75 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        financial_opt_imprest = new NavButton(widget_4);
        financial_opt_imprest->setObjectName(QStringLiteral("financial_opt_imprest"));
        financial_opt_imprest->setGeometry(QRect(10, 100, 140, 35));
        financial_opt_imprest->setStyleSheet(QString::fromUtf8("font: 75 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        financial_opt_payable = new NavButton(widget_4);
        financial_opt_payable->setObjectName(QStringLiteral("financial_opt_payable"));
        financial_opt_payable->setGeometry(QRect(10, 150, 140, 35));
        financial_opt_payable->setStyleSheet(QString::fromUtf8("font: 75 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout->addWidget(widget_4);

        financial_StackedWidget = new QStackedWidget(page);
        financial_StackedWidget->setObjectName(QStringLiteral("financial_StackedWidget"));
        financial_StackedWidget->setMinimumSize(QSize(925, 491));
        financial_StackedWidget->setMaximumSize(QSize(16777215, 16777215));
        financial_StackedWidget->setStyleSheet(QStringLiteral("background-color:#44474D;  "));
        page_11 = new QWidget();
        page_11->setObjectName(QStringLiteral("page_11"));
        page_11->setStyleSheet(QStringLiteral(""));
        verticalLayout_3 = new QVBoxLayout(page_11);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        widget_7 = new QWidget(page_11);
        widget_7->setObjectName(QStringLiteral("widget_7"));
        widget_7->setMinimumSize(QSize(0, 40));
        label_5 = new QLabel(widget_7);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(190, 10, 60, 28));
        label_5->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_4 = new QLabel(widget_7);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(0, 10, 60, 28));
        label_4->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        startdateEdit = new QDateEdit(widget_7);
        startdateEdit->setObjectName(QStringLiteral("startdateEdit"));
        startdateEdit->setGeometry(QRect(70, 10, 110, 28));
        startdateEdit->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        enddateEdit = new QDateEdit(widget_7);
        enddateEdit->setObjectName(QStringLiteral("enddateEdit"));
        enddateEdit->setGeometry(QRect(260, 10, 110, 28));
        enddateEdit->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        general_search_btn = new QPushButton(widget_7);
        general_search_btn->setObjectName(QStringLiteral("general_search_btn"));
        general_search_btn->setGeometry(QRect(380, 10, 80, 28));
        general_add_btn = new QPushButton(widget_7);
        general_add_btn->setObjectName(QStringLiteral("general_add_btn"));
        general_add_btn->setGeometry(QRect(470, 10, 80, 28));
        general_del_btn = new QPushButton(widget_7);
        general_del_btn->setObjectName(QStringLiteral("general_del_btn"));
        general_del_btn->setGeometry(QRect(560, 10, 80, 28));
        general_export_btn = new QPushButton(widget_7);
        general_export_btn->setObjectName(QStringLiteral("general_export_btn"));
        general_export_btn->setGeometry(QRect(650, 10, 80, 28));

        verticalLayout_3->addWidget(widget_7);

        general_table_view = new QTableView(page_11);
        general_table_view->setObjectName(QStringLiteral("general_table_view"));
        general_table_view->setEnabled(true);

        verticalLayout_3->addWidget(general_table_view);

        financial_StackedWidget->addWidget(page_11);
        page_12 = new QWidget();
        page_12->setObjectName(QStringLiteral("page_12"));
        verticalLayout_5 = new QVBoxLayout(page_12);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        widget_8 = new QWidget(page_12);
        widget_8->setObjectName(QStringLiteral("widget_8"));
        widget_8->setMinimumSize(QSize(0, 40));
        widget_8->setMaximumSize(QSize(16777215, 40));
        bak_del_btn = new QPushButton(widget_8);
        bak_del_btn->setObjectName(QStringLiteral("bak_del_btn"));
        bak_del_btn->setGeometry(QRect(560, 10, 80, 28));
        bak_export_btn = new QPushButton(widget_8);
        bak_export_btn->setObjectName(QStringLiteral("bak_export_btn"));
        bak_export_btn->setGeometry(QRect(650, 10, 80, 28));
        bak_add_btn = new QPushButton(widget_8);
        bak_add_btn->setObjectName(QStringLiteral("bak_add_btn"));
        bak_add_btn->setGeometry(QRect(470, 10, 80, 28));
        bak_enddateEdit = new QDateEdit(widget_8);
        bak_enddateEdit->setObjectName(QStringLiteral("bak_enddateEdit"));
        bak_enddateEdit->setGeometry(QRect(260, 10, 110, 28));
        bak_enddateEdit->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_6 = new QLabel(widget_8);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(190, 10, 60, 28));
        label_6->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_7 = new QLabel(widget_8);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(0, 10, 60, 28));
        label_7->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        bak_startdateEdit = new QDateEdit(widget_8);
        bak_startdateEdit->setObjectName(QStringLiteral("bak_startdateEdit"));
        bak_startdateEdit->setGeometry(QRect(70, 10, 110, 28));
        bak_startdateEdit->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        bak_search_btn = new QPushButton(widget_8);
        bak_search_btn->setObjectName(QStringLiteral("bak_search_btn"));
        bak_search_btn->setGeometry(QRect(380, 10, 80, 28));

        verticalLayout_5->addWidget(widget_8);

        bak_tableView = new QTableView(page_12);
        bak_tableView->setObjectName(QStringLiteral("bak_tableView"));

        verticalLayout_5->addWidget(bak_tableView);

        financial_StackedWidget->addWidget(page_12);
        page_13 = new QWidget();
        page_13->setObjectName(QStringLiteral("page_13"));
        verticalLayout_6 = new QVBoxLayout(page_13);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        widget_9 = new QWidget(page_13);
        widget_9->setObjectName(QStringLiteral("widget_9"));
        widget_9->setMinimumSize(QSize(0, 40));
        widget_9->setMaximumSize(QSize(16777215, 40));
        nopay_enddateEdit = new QDateEdit(widget_9);
        nopay_enddateEdit->setObjectName(QStringLiteral("nopay_enddateEdit"));
        nopay_enddateEdit->setGeometry(QRect(260, 10, 110, 28));
        nopay_enddateEdit->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_8 = new QLabel(widget_9);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(0, 10, 60, 28));
        label_8->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        nopay_search_btn = new QPushButton(widget_9);
        nopay_search_btn->setObjectName(QStringLiteral("nopay_search_btn"));
        nopay_search_btn->setGeometry(QRect(380, 10, 80, 28));
        nopay_add_btn = new QPushButton(widget_9);
        nopay_add_btn->setObjectName(QStringLiteral("nopay_add_btn"));
        nopay_add_btn->setGeometry(QRect(470, 10, 80, 28));
        nopay_export_btn = new QPushButton(widget_9);
        nopay_export_btn->setObjectName(QStringLiteral("nopay_export_btn"));
        nopay_export_btn->setGeometry(QRect(650, 10, 80, 28));
        nopay_startdateEdit = new QDateEdit(widget_9);
        nopay_startdateEdit->setObjectName(QStringLiteral("nopay_startdateEdit"));
        nopay_startdateEdit->setGeometry(QRect(70, 10, 110, 28));
        nopay_startdateEdit->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_9 = new QLabel(widget_9);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(190, 10, 60, 28));
        label_9->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        nopay_del_btn = new QPushButton(widget_9);
        nopay_del_btn->setObjectName(QStringLiteral("nopay_del_btn"));
        nopay_del_btn->setGeometry(QRect(560, 10, 80, 28));

        verticalLayout_6->addWidget(widget_9);

        nopay_tableView = new QTableView(page_13);
        nopay_tableView->setObjectName(QStringLiteral("nopay_tableView"));

        verticalLayout_6->addWidget(nopay_tableView);

        financial_StackedWidget->addWidget(page_13);

        horizontalLayout->addWidget(financial_StackedWidget);

        main_stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        pushButton_2 = new QPushButton(page_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(360, 190, 75, 23));
        main_stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        main_stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        widget_5 = new QWidget(page_4);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setGeometry(QRect(0, 0, 160, 16777215));
        widget_5->setMinimumSize(QSize(160, 0));
        widget_5->setStyleSheet(QStringLiteral("background-color:#44474D;  "));
        report_opt_totaltask = new NavButton(widget_5);
        report_opt_totaltask->setObjectName(QStringLiteral("report_opt_totaltask"));
        report_opt_totaltask->setGeometry(QRect(10, 50, 140, 35));
        report_opt_totaltask->setStyleSheet(QString::fromUtf8("font: 75 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        report_opt_payable = new NavButton(widget_5);
        report_opt_payable->setObjectName(QStringLiteral("report_opt_payable"));
        report_opt_payable->setGeometry(QRect(10, 100, 140, 35));
        report_opt_payable->setStyleSheet(QString::fromUtf8("font: 75 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        report_opt_share = new NavButton(widget_5);
        report_opt_share->setObjectName(QStringLiteral("report_opt_share"));
        report_opt_share->setGeometry(QRect(10, 150, 140, 35));
        report_opt_share->setStyleSheet(QString::fromUtf8("font: 75 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        report_opt_signal = new NavButton(widget_5);
        report_opt_signal->setObjectName(QStringLiteral("report_opt_signal"));
        report_opt_signal->setGeometry(QRect(10, 200, 140, 35));
        report_opt_signal->setStyleSheet(QString::fromUtf8("font: 75 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        report_opt_materiel = new NavButton(widget_5);
        report_opt_materiel->setObjectName(QStringLiteral("report_opt_materiel"));
        report_opt_materiel->setGeometry(QRect(10, 250, 140, 35));
        report_opt_materiel->setStyleSheet(QString::fromUtf8("font: 75 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        report_opt_totalfeed = new NavButton(widget_5);
        report_opt_totalfeed->setObjectName(QStringLiteral("report_opt_totalfeed"));
        report_opt_totalfeed->setGeometry(QRect(10, 300, 140, 35));
        report_opt_totalfeed->setStyleSheet(QString::fromUtf8("font: 75 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        Report_StackedWidget = new QStackedWidget(page_4);
        Report_StackedWidget->setObjectName(QStringLiteral("Report_StackedWidget"));
        Report_StackedWidget->setGeometry(QRect(161, 0, 16777215, 16777215));
        Report_StackedWidget->setMinimumSize(QSize(925, 491));
        Report_StackedWidget->setMaximumSize(QSize(16777215, 16777215));
        Report_StackedWidget->setStyleSheet(QStringLiteral("background-color:#44474D;  "));
        page_14 = new QWidget();
        page_14->setObjectName(QStringLiteral("page_14"));
        page_14->setStyleSheet(QStringLiteral(""));
        pushButton_9 = new QPushButton(page_14);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(230, 160, 75, 23));
        Report_StackedWidget->addWidget(page_14);
        page_19 = new QWidget();
        page_19->setObjectName(QStringLiteral("page_19"));
        Report_StackedWidget->addWidget(page_19);
        page_20 = new QWidget();
        page_20->setObjectName(QStringLiteral("page_20"));
        Report_StackedWidget->addWidget(page_20);
        page_21 = new QWidget();
        page_21->setObjectName(QStringLiteral("page_21"));
        Report_StackedWidget->addWidget(page_21);
        page_15 = new QWidget();
        page_15->setObjectName(QStringLiteral("page_15"));
        pushButton_10 = new QPushButton(page_15);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setGeometry(QRect(220, 160, 75, 23));
        Report_StackedWidget->addWidget(page_15);
        page_16 = new QWidget();
        page_16->setObjectName(QStringLiteral("page_16"));
        pushButton_11 = new QPushButton(page_16);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setGeometry(QRect(110, 170, 75, 23));
        Report_StackedWidget->addWidget(page_16);
        main_stackedWidget->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName(QStringLiteral("page_5"));
        horizontalLayout_9 = new QHBoxLayout(page_5);
        horizontalLayout_9->setSpacing(0);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        widget_3 = new QWidget(page_5);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMinimumSize(QSize(160, 0));
        widget_3->setStyleSheet(QStringLiteral("background-color:#44474D;  "));
        set_opt_person = new NavButton(widget_3);
        set_opt_person->setObjectName(QStringLiteral("set_opt_person"));
        set_opt_person->setGeometry(QRect(10, 50, 140, 35));
        set_opt_person->setStyleSheet(QString::fromUtf8("font: 75 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        set_opt_account = new NavButton(widget_3);
        set_opt_account->setObjectName(QStringLiteral("set_opt_account"));
        set_opt_account->setGeometry(QRect(10, 100, 140, 35));
        set_opt_account->setStyleSheet(QString::fromUtf8("font: 75 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        set_opt_detail_area = new NavButton(widget_3);
        set_opt_detail_area->setObjectName(QStringLiteral("set_opt_detail_area"));
        set_opt_detail_area->setGeometry(QRect(10, 300, 140, 35));
        set_opt_detail_area->setStyleSheet(QString::fromUtf8("font: 75 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        set_opt_supplier = new NavButton(widget_3);
        set_opt_supplier->setObjectName(QStringLiteral("set_opt_supplier"));
        set_opt_supplier->setGeometry(QRect(10, 200, 140, 35));
        set_opt_supplier->setStyleSheet(QString::fromUtf8("font: 75 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        set_opt_task = new NavButton(widget_3);
        set_opt_task->setObjectName(QStringLiteral("set_opt_task"));
        set_opt_task->setGeometry(QRect(10, 250, 140, 35));
        set_opt_task->setStyleSheet(QString::fromUtf8("font: 75 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        set_opt_area = new NavButton(widget_3);
        set_opt_area->setObjectName(QStringLiteral("set_opt_area"));
        set_opt_area->setGeometry(QRect(10, 150, 140, 35));
        set_opt_area->setStyleSheet(QString::fromUtf8("font: 75 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout_9->addWidget(widget_3);

        sysLayout_StackedWidget = new QStackedWidget(page_5);
        sysLayout_StackedWidget->setObjectName(QStringLiteral("sysLayout_StackedWidget"));
        sysLayout_StackedWidget->setMinimumSize(QSize(925, 491));
        sysLayout_StackedWidget->setMaximumSize(QSize(16777215, 16777215));
        sysLayout_StackedWidget->setStyleSheet(QStringLiteral("background-color:#44474D;  "));
        page_6 = new QWidget();
        page_6->setObjectName(QStringLiteral("page_6"));
        page_6->setStyleSheet(QStringLiteral(""));
        gridLayout = new QGridLayout(page_6);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        user_table_view = new QTableView(page_6);
        user_table_view->setObjectName(QStringLiteral("user_table_view"));
        user_table_view->setEnabled(true);

        gridLayout->addWidget(user_table_view, 6, 0, 1, 1);

        widget_6 = new QWidget(page_6);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        widget_6->setMinimumSize(QSize(0, 40));
        user_add_btn = new QPushButton(widget_6);
        user_add_btn->setObjectName(QStringLiteral("user_add_btn"));
        user_add_btn->setGeometry(QRect(0, 10, 80, 28));
        user_remove_btn = new QPushButton(widget_6);
        user_remove_btn->setObjectName(QStringLiteral("user_remove_btn"));
        user_remove_btn->setGeometry(QRect(90, 10, 80, 28));

        gridLayout->addWidget(widget_6, 0, 0, 1, 1);

        sysLayout_StackedWidget->addWidget(page_6);
        page_7 = new QWidget();
        page_7->setObjectName(QStringLiteral("page_7"));
        verticalLayout_7 = new QVBoxLayout(page_7);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        widget_10 = new QWidget(page_7);
        widget_10->setObjectName(QStringLiteral("widget_10"));
        widget_10->setMinimumSize(QSize(0, 40));
        widget_10->setMaximumSize(QSize(16777215, 40));
        category_remove_btn = new QPushButton(widget_10);
        category_remove_btn->setObjectName(QStringLiteral("category_remove_btn"));
        category_remove_btn->setGeometry(QRect(90, 10, 80, 28));
        category_add_btn = new QPushButton(widget_10);
        category_add_btn->setObjectName(QStringLiteral("category_add_btn"));
        category_add_btn->setGeometry(QRect(0, 10, 80, 28));

        verticalLayout_7->addWidget(widget_10);

        category_tableView = new QTableView(page_7);
        category_tableView->setObjectName(QStringLiteral("category_tableView"));

        verticalLayout_7->addWidget(category_tableView);

        sysLayout_StackedWidget->addWidget(page_7);
        page_8 = new QWidget();
        page_8->setObjectName(QStringLiteral("page_8"));
        verticalLayout_8 = new QVBoxLayout(page_8);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        widget_11 = new QWidget(page_8);
        widget_11->setObjectName(QStringLiteral("widget_11"));
        widget_11->setMinimumSize(QSize(0, 40));
        widget_11->setMaximumSize(QSize(16777215, 40));
        area_remove_btn = new QPushButton(widget_11);
        area_remove_btn->setObjectName(QStringLiteral("area_remove_btn"));
        area_remove_btn->setGeometry(QRect(90, 10, 80, 28));
        area_add_btn = new QPushButton(widget_11);
        area_add_btn->setObjectName(QStringLiteral("area_add_btn"));
        area_add_btn->setGeometry(QRect(0, 10, 80, 28));

        verticalLayout_8->addWidget(widget_11);

        area_tableView = new QTableView(page_8);
        area_tableView->setObjectName(QStringLiteral("area_tableView"));

        verticalLayout_8->addWidget(area_tableView);

        sysLayout_StackedWidget->addWidget(page_8);
        page_9 = new QWidget();
        page_9->setObjectName(QStringLiteral("page_9"));
        verticalLayout_9 = new QVBoxLayout(page_9);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        widget_12 = new QWidget(page_9);
        widget_12->setObjectName(QStringLiteral("widget_12"));
        widget_12->setMinimumSize(QSize(0, 40));
        widget_12->setMaximumSize(QSize(16777215, 40));
        supplier_remove_btn = new QPushButton(widget_12);
        supplier_remove_btn->setObjectName(QStringLiteral("supplier_remove_btn"));
        supplier_remove_btn->setGeometry(QRect(90, 10, 80, 28));
        supplier_add_btn = new QPushButton(widget_12);
        supplier_add_btn->setObjectName(QStringLiteral("supplier_add_btn"));
        supplier_add_btn->setGeometry(QRect(0, 10, 80, 28));

        verticalLayout_9->addWidget(widget_12);

        supplier_tableView = new QTableView(page_9);
        supplier_tableView->setObjectName(QStringLiteral("supplier_tableView"));

        verticalLayout_9->addWidget(supplier_tableView);

        sysLayout_StackedWidget->addWidget(page_9);
        page_17 = new QWidget();
        page_17->setObjectName(QStringLiteral("page_17"));
        verticalLayout_10 = new QVBoxLayout(page_17);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        widget_13 = new QWidget(page_17);
        widget_13->setObjectName(QStringLiteral("widget_13"));
        widget_13->setMinimumSize(QSize(0, 40));
        widget_13->setMaximumSize(QSize(16777215, 40));
        shareitem_remove_btn = new QPushButton(widget_13);
        shareitem_remove_btn->setObjectName(QStringLiteral("shareitem_remove_btn"));
        shareitem_remove_btn->setGeometry(QRect(90, 10, 80, 28));
        shareitem_add_btn = new QPushButton(widget_13);
        shareitem_add_btn->setObjectName(QStringLiteral("shareitem_add_btn"));
        shareitem_add_btn->setGeometry(QRect(0, 10, 80, 28));

        verticalLayout_10->addWidget(widget_13);

        shareitem_tableView = new QTableView(page_17);
        shareitem_tableView->setObjectName(QStringLiteral("shareitem_tableView"));

        verticalLayout_10->addWidget(shareitem_tableView);

        sysLayout_StackedWidget->addWidget(page_17);
        page_10 = new QWidget();
        page_10->setObjectName(QStringLiteral("page_10"));
        verticalLayout = new QVBoxLayout(page_10);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widget_14 = new QWidget(page_10);
        widget_14->setObjectName(QStringLiteral("widget_14"));
        widget_14->setMinimumSize(QSize(0, 40));
        widget_14->setMaximumSize(QSize(16777215, 40));
        detailarea_add_btn = new QPushButton(widget_14);
        detailarea_add_btn->setObjectName(QStringLiteral("detailarea_add_btn"));
        detailarea_add_btn->setGeometry(QRect(0, 10, 80, 28));
        detailarea_remove_btn = new QPushButton(widget_14);
        detailarea_remove_btn->setObjectName(QStringLiteral("detailarea_remove_btn"));
        detailarea_remove_btn->setGeometry(QRect(90, 10, 80, 28));

        verticalLayout->addWidget(widget_14);

        detailarea_tableView = new QTableView(page_10);
        detailarea_tableView->setObjectName(QStringLiteral("detailarea_tableView"));

        verticalLayout->addWidget(detailarea_tableView);

        sysLayout_StackedWidget->addWidget(page_10);

        horizontalLayout_9->addWidget(sysLayout_StackedWidget);

        main_stackedWidget->addWidget(page_5);

        work_Layout->addWidget(main_stackedWidget);


        verticalLayout_4->addLayout(work_Layout);


        retranslateUi(ChuangfengDesktopClass);

        main_stackedWidget->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(ChuangfengDesktopClass);
    } // setupUi

    void retranslateUi(QWidget *ChuangfengDesktopClass)
    {
        ChuangfengDesktopClass->setWindowTitle(QApplication::translate("ChuangfengDesktopClass", "\345\210\233\344\270\260\345\205\273\346\256\226", Q_NULLPTR));
        label->setText(QString());
        label_2->setText(QApplication::translate("ChuangfengDesktopClass", "\345\210\233\344\270\260\345\205\273\346\256\226\347\256\241\347\220\206\345\271\263\345\217\260", Q_NULLPTR));
        label_3->setText(QApplication::translate("ChuangfengDesktopClass", "ChuangFeng aquaculture management Platform", Q_NULLPTR));
        opt_sysset->setText(QApplication::translate("ChuangfengDesktopClass", "\345\220\216\345\217\260\350\256\276\347\275\256", Q_NULLPTR));
        opt_report->setText(QApplication::translate("ChuangfengDesktopClass", "\346\212\245\350\241\250\347\256\241\347\220\206", Q_NULLPTR));
        opt_feed_mgr->setText(QApplication::translate("ChuangfengDesktopClass", "\345\226\202\346\226\231\347\256\241\347\220\206", Q_NULLPTR));
        opt_store->setText(QApplication::translate("ChuangfengDesktopClass", "\344\273\223\345\272\223\347\256\241\347\220\206", Q_NULLPTR));
        opt_finance_mgr->setText(QApplication::translate("ChuangfengDesktopClass", "\350\264\242\345\212\241\347\256\241\347\220\206", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        min_btn->setToolTip(QApplication::translate("ChuangfengDesktopClass", "\346\234\200\345\260\217\345\214\226", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        min_btn->setText(QString());
        max_restore_btn->setText(QString());
#ifndef QT_NO_TOOLTIP
        close_btn->setToolTip(QApplication::translate("ChuangfengDesktopClass", "\345\205\263\351\227\255", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        close_btn->setText(QString());
        financial_opt_totalpay->setText(QApplication::translate("ChuangfengDesktopClass", "\346\200\273\350\264\246\346\224\266\346\224\257", Q_NULLPTR));
        financial_opt_imprest->setText(QApplication::translate("ChuangfengDesktopClass", "\345\244\207\347\224\250\351\207\221\346\230\216\347\273\206", Q_NULLPTR));
        financial_opt_payable->setText(QApplication::translate("ChuangfengDesktopClass", "\345\272\224\344\273\230\346\254\276", Q_NULLPTR));
        label_5->setText(QApplication::translate("ChuangfengDesktopClass", "\347\273\223\346\235\237\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("ChuangfengDesktopClass", "\345\274\200\345\247\213\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        general_search_btn->setText(QString());
        general_add_btn->setText(QString());
        general_del_btn->setText(QString());
        general_export_btn->setText(QString());
        bak_del_btn->setText(QString());
        bak_export_btn->setText(QString());
        bak_add_btn->setText(QString());
        label_6->setText(QApplication::translate("ChuangfengDesktopClass", "\347\273\223\346\235\237\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        label_7->setText(QApplication::translate("ChuangfengDesktopClass", "\345\274\200\345\247\213\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        bak_search_btn->setText(QString());
        label_8->setText(QApplication::translate("ChuangfengDesktopClass", "\345\274\200\345\247\213\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        nopay_search_btn->setText(QString());
        nopay_add_btn->setText(QString());
        nopay_export_btn->setText(QString());
        label_9->setText(QApplication::translate("ChuangfengDesktopClass", "\347\273\223\346\235\237\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        nopay_del_btn->setText(QString());
        pushButton_2->setText(QApplication::translate("ChuangfengDesktopClass", "PushButton", Q_NULLPTR));
        report_opt_totaltask->setText(QApplication::translate("ChuangfengDesktopClass", "\346\200\273\346\224\266\346\224\257\350\241\250", Q_NULLPTR));
        report_opt_payable->setText(QApplication::translate("ChuangfengDesktopClass", "\345\272\224\344\273\230\346\254\276\350\241\250", Q_NULLPTR));
        report_opt_share->setText(QApplication::translate("ChuangfengDesktopClass", "\345\210\206\346\221\212\350\241\250", Q_NULLPTR));
        report_opt_signal->setText(QApplication::translate("ChuangfengDesktopClass", "\345\215\225\345\241\230\345\210\206\346\221\212\346\230\216\347\273\206", Q_NULLPTR));
        report_opt_materiel->setText(QApplication::translate("ChuangfengDesktopClass", "\347\211\251\346\226\231\351\242\206\347\224\250\346\261\207\346\200\273", Q_NULLPTR));
        report_opt_totalfeed->setText(QApplication::translate("ChuangfengDesktopClass", "\344\273\223\345\272\223\351\242\206\347\224\250\346\261\207\346\200\273", Q_NULLPTR));
        pushButton_9->setText(QApplication::translate("ChuangfengDesktopClass", "1", Q_NULLPTR));
        pushButton_10->setText(QApplication::translate("ChuangfengDesktopClass", "2", Q_NULLPTR));
        pushButton_11->setText(QApplication::translate("ChuangfengDesktopClass", "3", Q_NULLPTR));
        set_opt_person->setText(QApplication::translate("ChuangfengDesktopClass", "\344\272\272\345\221\230\347\256\241\347\220\206", Q_NULLPTR));
        set_opt_account->setText(QApplication::translate("ChuangfengDesktopClass", "\350\264\246\347\233\256\347\256\241\347\220\206", Q_NULLPTR));
        set_opt_detail_area->setText(QApplication::translate("ChuangfengDesktopClass", "\345\205\273\346\256\226\345\241\230\345\217\243", Q_NULLPTR));
        set_opt_supplier->setText(QApplication::translate("ChuangfengDesktopClass", "\344\276\233\345\272\224\345\225\206", Q_NULLPTR));
        set_opt_task->setText(QApplication::translate("ChuangfengDesktopClass", "\350\264\271\347\224\250\345\210\206\346\221\212\347\261\273\347\233\256", Q_NULLPTR));
        set_opt_area->setText(QApplication::translate("ChuangfengDesktopClass", "\345\214\272\345\237\237\347\256\241\347\220\206", Q_NULLPTR));
        user_add_btn->setText(QString());
        user_remove_btn->setText(QString());
        category_remove_btn->setText(QString());
        category_add_btn->setText(QString());
        area_remove_btn->setText(QString());
        area_add_btn->setText(QString());
        supplier_remove_btn->setText(QString());
        supplier_add_btn->setText(QString());
        shareitem_remove_btn->setText(QString());
        shareitem_add_btn->setText(QString());
        detailarea_add_btn->setText(QString());
        detailarea_remove_btn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ChuangfengDesktopClass: public Ui_ChuangfengDesktopClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHUANGFENGDESKTOP_H
