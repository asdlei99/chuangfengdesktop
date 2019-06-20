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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_shareReport
{
public:
    QVBoxLayout *verticalLayout;
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
        shareReport->resize(726, 365);
        verticalLayout = new QVBoxLayout(shareReport);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widget_17 = new QWidget(shareReport);
        widget_17->setObjectName(QStringLiteral("widget_17"));
        widget_17->setMinimumSize(QSize(0, 40));
        widget_17->setMaximumSize(QSize(16777215, 40));
        share_report_search_btn = new QPushButton(widget_17);
        share_report_search_btn->setObjectName(QStringLiteral("share_report_search_btn"));
        share_report_search_btn->setGeometry(QRect(380, 10, 80, 28));
        sharereport_export_btn = new QPushButton(widget_17);
        sharereport_export_btn->setObjectName(QStringLiteral("sharereport_export_btn"));
        sharereport_export_btn->setGeometry(QRect(480, 10, 80, 28));
        share_report_startdateEdit = new QDateEdit(widget_17);
        share_report_startdateEdit->setObjectName(QStringLiteral("share_report_startdateEdit"));
        share_report_startdateEdit->setGeometry(QRect(70, 10, 110, 28));
        share_report_startdateEdit->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_16 = new QLabel(widget_17);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(190, 10, 60, 28));
        label_16->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_17 = new QLabel(widget_17);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(0, 10, 60, 28));
        label_17->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        share_report_enddateEdit = new QDateEdit(widget_17);
        share_report_enddateEdit->setObjectName(QStringLiteral("share_report_enddateEdit"));
        share_report_enddateEdit->setGeometry(QRect(260, 10, 110, 28));
        share_report_enddateEdit->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(widget_17);

        share_report_tableview = new QTableView(shareReport);
        share_report_tableview->setObjectName(QStringLiteral("share_report_tableview"));

        verticalLayout->addWidget(share_report_tableview);


        retranslateUi(shareReport);

        QMetaObject::connectSlotsByName(shareReport);
    } // setupUi

    void retranslateUi(QWidget *shareReport)
    {
        shareReport->setWindowTitle(QApplication::translate("shareReport", "Form", Q_NULLPTR));
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
