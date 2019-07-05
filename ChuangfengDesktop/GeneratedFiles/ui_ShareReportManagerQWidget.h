/********************************************************************************
** Form generated from reading UI file 'ShareReportManagerQWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHAREREPORTMANAGERQWIDGET_H
#define UI_SHAREREPORTMANAGERQWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_shareReport
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *child_widget_title;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *min_btn;
    QPushButton *max_restore_btn;
    QPushButton *close_btn;
    QWidget *widget_17;
    QPushButton *share_report_search_btn;
    QPushButton *sharereport_export_btn;
    QDateEdit *share_report_startdateEdit;
    QLabel *label_16;
    QLabel *label_17;
    QDateEdit *share_report_enddateEdit;
    QTableView *share_report_tableview;

    void setupUi(QWidget *shareReport)
    {
        if (shareReport->objectName().isEmpty())
            shareReport->setObjectName(QStringLiteral("shareReport"));
        shareReport->resize(842, 628);
        shareReport->setMinimumSize(QSize(842, 628));
        verticalLayout = new QVBoxLayout(shareReport);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(1, 1, 1, 1);
        child_widget_title = new QWidget(shareReport);
        child_widget_title->setObjectName(QStringLiteral("child_widget_title"));
        child_widget_title->setMinimumSize(QSize(0, 40));
        child_widget_title->setStyleSheet(QStringLiteral(""));
        horizontalLayout = new QHBoxLayout(child_widget_title);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(741, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        min_btn = new QPushButton(child_widget_title);
        min_btn->setObjectName(QStringLiteral("min_btn"));
        min_btn->setMinimumSize(QSize(32, 23));

        horizontalLayout->addWidget(min_btn);

        max_restore_btn = new QPushButton(child_widget_title);
        max_restore_btn->setObjectName(QStringLiteral("max_restore_btn"));
        max_restore_btn->setMinimumSize(QSize(32, 23));

        horizontalLayout->addWidget(max_restore_btn);

        close_btn = new QPushButton(child_widget_title);
        close_btn->setObjectName(QStringLiteral("close_btn"));
        close_btn->setMinimumSize(QSize(32, 23));

        horizontalLayout->addWidget(close_btn);


        verticalLayout->addWidget(child_widget_title);

        widget_17 = new QWidget(shareReport);
        widget_17->setObjectName(QStringLiteral("widget_17"));
        widget_17->setMinimumSize(QSize(0, 40));
        widget_17->setMaximumSize(QSize(16777215, 40));
        widget_17->setStyleSheet(QStringLiteral("background-color: rgb(54, 78, 111);"));
        share_report_search_btn = new QPushButton(widget_17);
        share_report_search_btn->setObjectName(QStringLiteral("share_report_search_btn"));
        share_report_search_btn->setGeometry(QRect(380, 10, 80, 28));
        sharereport_export_btn = new QPushButton(widget_17);
        sharereport_export_btn->setObjectName(QStringLiteral("sharereport_export_btn"));
        sharereport_export_btn->setGeometry(QRect(480, 10, 80, 28));
        share_report_startdateEdit = new QDateEdit(widget_17);
        share_report_startdateEdit->setObjectName(QStringLiteral("share_report_startdateEdit"));
        share_report_startdateEdit->setGeometry(QRect(70, 10, 110, 28));
        share_report_startdateEdit->setStyleSheet(QLatin1String("color: rgb(171, 171, 171);\n"
"border-color: rgb(255, 255, 255);\n"
"border-style: solid;\n"
"border-width: 1px;"));
        label_16 = new QLabel(widget_17);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(190, 10, 65, 28));
        label_16->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_17 = new QLabel(widget_17);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(0, 10, 65, 28));
        label_17->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        share_report_enddateEdit = new QDateEdit(widget_17);
        share_report_enddateEdit->setObjectName(QStringLiteral("share_report_enddateEdit"));
        share_report_enddateEdit->setGeometry(QRect(260, 10, 110, 28));
        share_report_enddateEdit->setStyleSheet(QLatin1String("color: rgb(171, 171, 171);\n"
"border-color: rgb(255, 255, 255);\n"
"border-style: solid;\n"
"border-width: 1px;"));

        verticalLayout->addWidget(widget_17);

        share_report_tableview = new QTableView(shareReport);
        share_report_tableview->setObjectName(QStringLiteral("share_report_tableview"));
        share_report_tableview->setStyleSheet(QStringLiteral("background-color: rgb(54, 78, 111);"));

        verticalLayout->addWidget(share_report_tableview);


        retranslateUi(shareReport);

        QMetaObject::connectSlotsByName(shareReport);
    } // setupUi

    void retranslateUi(QWidget *shareReport)
    {
        shareReport->setWindowTitle(QApplication::translate("shareReport", "Form", Q_NULLPTR));
        min_btn->setText(QString());
        max_restore_btn->setText(QString());
        close_btn->setText(QString());
        share_report_search_btn->setText(QString());
        sharereport_export_btn->setText(QString());
        label_16->setText(QApplication::translate("shareReport", "\347\273\223\346\235\237\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        label_17->setText(QApplication::translate("shareReport", "\345\274\200\345\247\213\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class shareReport: public Ui_shareReport {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHAREREPORTMANAGERQWIDGET_H
