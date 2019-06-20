/********************************************************************************
** Form generated from reading UI file 'NoPayReportManagerQWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOPAYREPORTMANAGERQWIDGET_H
#define UI_NOPAYREPORTMANAGERQWIDGET_H

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

class Ui_noPayReportMannger
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_16;
    QLabel *label_14;
    QLabel *label_15;
    QDateEdit *nopay_report_startdateEdit;
    QPushButton *nopay_report_search_btn;
    QDateEdit *nopay_report_enddateEdit;
    QPushButton *nopay_report_export_btn;
    QTableView *nopayreport_tableView;

    void setupUi(QWidget *noPayReportMannger)
    {
        if (noPayReportMannger->objectName().isEmpty())
            noPayReportMannger->setObjectName(QStringLiteral("noPayReportMannger"));
        noPayReportMannger->resize(704, 385);
        verticalLayout = new QVBoxLayout(noPayReportMannger);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widget_16 = new QWidget(noPayReportMannger);
        widget_16->setObjectName(QStringLiteral("widget_16"));
        widget_16->setMinimumSize(QSize(0, 40));
        widget_16->setMaximumSize(QSize(16777215, 40));
        label_14 = new QLabel(widget_16);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(0, 10, 60, 28));
        label_14->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_15 = new QLabel(widget_16);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(190, 10, 60, 28));
        label_15->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        nopay_report_startdateEdit = new QDateEdit(widget_16);
        nopay_report_startdateEdit->setObjectName(QStringLiteral("nopay_report_startdateEdit"));
        nopay_report_startdateEdit->setGeometry(QRect(70, 10, 110, 28));
        nopay_report_startdateEdit->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        nopay_report_search_btn = new QPushButton(widget_16);
        nopay_report_search_btn->setObjectName(QStringLiteral("nopay_report_search_btn"));
        nopay_report_search_btn->setGeometry(QRect(380, 10, 80, 28));
        nopay_report_enddateEdit = new QDateEdit(widget_16);
        nopay_report_enddateEdit->setObjectName(QStringLiteral("nopay_report_enddateEdit"));
        nopay_report_enddateEdit->setGeometry(QRect(260, 10, 110, 28));
        nopay_report_enddateEdit->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        nopay_report_export_btn = new QPushButton(widget_16);
        nopay_report_export_btn->setObjectName(QStringLiteral("nopay_report_export_btn"));
        nopay_report_export_btn->setGeometry(QRect(480, 10, 80, 28));

        verticalLayout->addWidget(widget_16);

        nopayreport_tableView = new QTableView(noPayReportMannger);
        nopayreport_tableView->setObjectName(QStringLiteral("nopayreport_tableView"));

        verticalLayout->addWidget(nopayreport_tableView);


        retranslateUi(noPayReportMannger);

        QMetaObject::connectSlotsByName(noPayReportMannger);
    } // setupUi

    void retranslateUi(QWidget *noPayReportMannger)
    {
        noPayReportMannger->setWindowTitle(QApplication::translate("noPayReportMannger", "Form", Q_NULLPTR));
        label_14->setText(QApplication::translate("noPayReportMannger", "\345\274\200\345\247\213\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        label_15->setText(QApplication::translate("noPayReportMannger", "\347\273\223\346\235\237\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        nopay_report_search_btn->setText(QString());
        nopay_report_export_btn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class noPayReportMannger: public Ui_noPayReportMannger {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOPAYREPORTMANAGERQWIDGET_H
