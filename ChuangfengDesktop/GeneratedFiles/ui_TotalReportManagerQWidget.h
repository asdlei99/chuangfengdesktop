/********************************************************************************
** Form generated from reading UI file 'TotalReportManagerQWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOTALREPORTMANAGERQWIDGET_H
#define UI_TOTALREPORTMANAGERQWIDGET_H

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

class Ui_totalreportmanager
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_15;
    QDateEdit *totalreport_startdateEdit;
    QLabel *label_10;
    QDateEdit *total_report_enddateEdit;
    QLabel *label_11;
    QPushButton *totalreport_search_btn;
    QLabel *label_12;
    QLabel *label_13;
    QPushButton *totalreport_export_btn;
    QTableView *total_reporttableView;

    void setupUi(QWidget *totalreportmanager)
    {
        if (totalreportmanager->objectName().isEmpty())
            totalreportmanager->setObjectName(QStringLiteral("totalreportmanager"));
        totalreportmanager->resize(933, 423);
        verticalLayout = new QVBoxLayout(totalreportmanager);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widget_15 = new QWidget(totalreportmanager);
        widget_15->setObjectName(QStringLiteral("widget_15"));
        widget_15->setMinimumSize(QSize(0, 60));
        widget_15->setMaximumSize(QSize(16777215, 60));
        totalreport_startdateEdit = new QDateEdit(widget_15);
        totalreport_startdateEdit->setObjectName(QStringLiteral("totalreport_startdateEdit"));
        totalreport_startdateEdit->setGeometry(QRect(70, 0, 110, 28));
        totalreport_startdateEdit->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_10 = new QLabel(widget_15);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(190, 0, 60, 28));
        label_10->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        total_report_enddateEdit = new QDateEdit(widget_15);
        total_report_enddateEdit->setObjectName(QStringLiteral("total_report_enddateEdit"));
        total_report_enddateEdit->setGeometry(QRect(260, 0, 110, 28));
        total_report_enddateEdit->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_11 = new QLabel(widget_15);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(0, 0, 60, 28));
        label_11->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        totalreport_search_btn = new QPushButton(widget_15);
        totalreport_search_btn->setObjectName(QStringLiteral("totalreport_search_btn"));
        totalreport_search_btn->setGeometry(QRect(380, 0, 80, 28));
        label_12 = new QLabel(widget_15);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(110, 30, 191, 31));
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 75 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_13 = new QLabel(widget_15);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(530, 30, 191, 31));
        label_13->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 75 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        totalreport_export_btn = new QPushButton(widget_15);
        totalreport_export_btn->setObjectName(QStringLiteral("totalreport_export_btn"));
        totalreport_export_btn->setGeometry(QRect(480, 0, 80, 28));

        verticalLayout->addWidget(widget_15);

        total_reporttableView = new QTableView(totalreportmanager);
        total_reporttableView->setObjectName(QStringLiteral("total_reporttableView"));

        verticalLayout->addWidget(total_reporttableView);


        retranslateUi(totalreportmanager);

        QMetaObject::connectSlotsByName(totalreportmanager);
    } // setupUi

    void retranslateUi(QWidget *totalreportmanager)
    {
        totalreportmanager->setWindowTitle(QApplication::translate("totalreportmanager", "Form", Q_NULLPTR));
        label_10->setText(QApplication::translate("totalreportmanager", "\347\273\223\346\235\237\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        label_11->setText(QApplication::translate("totalreportmanager", "\345\274\200\345\247\213\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        totalreport_search_btn->setText(QString());
        label_12->setText(QApplication::translate("totalreportmanager", "\346\200\273\350\264\246\346\224\266\346\224\257", Q_NULLPTR));
        label_13->setText(QApplication::translate("totalreportmanager", "\345\244\207\347\224\250\351\207\221\346\224\266\346\224\257", Q_NULLPTR));
        totalreport_export_btn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class totalreportmanager: public Ui_totalreportmanager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOTALREPORTMANAGERQWIDGET_H
