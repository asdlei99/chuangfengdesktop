/********************************************************************************
** Form generated from reading UI file 'StoreReportManagerQWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STOREREPORTMANAGERQWIDGET_H
#define UI_STOREREPORTMANAGERQWIDGET_H

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

class Ui_storereport
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_20;
    QDateEdit *store_report_enddateEdit;
    QLabel *label_25;
    QLabel *label_26;
    QDateEdit *storereport_startdateEdit;
    QPushButton *storereport_export_btn;
    QLabel *label_27;
    QPushButton *storereport_search_btn;
    QLabel *label_28;
    QTableView *store_report_tableView;

    void setupUi(QWidget *storereport)
    {
        if (storereport->objectName().isEmpty())
            storereport->setObjectName(QStringLiteral("storereport"));
        storereport->resize(606, 300);
        verticalLayout = new QVBoxLayout(storereport);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widget_20 = new QWidget(storereport);
        widget_20->setObjectName(QStringLiteral("widget_20"));
        widget_20->setMinimumSize(QSize(0, 60));
        widget_20->setMaximumSize(QSize(16777215, 60));
        store_report_enddateEdit = new QDateEdit(widget_20);
        store_report_enddateEdit->setObjectName(QStringLiteral("store_report_enddateEdit"));
        store_report_enddateEdit->setGeometry(QRect(270, 0, 110, 28));
        store_report_enddateEdit->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_25 = new QLabel(widget_20);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(120, 30, 261, 31));
        label_25->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 75 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_26 = new QLabel(widget_20);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(10, 0, 60, 28));
        label_26->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        storereport_startdateEdit = new QDateEdit(widget_20);
        storereport_startdateEdit->setObjectName(QStringLiteral("storereport_startdateEdit"));
        storereport_startdateEdit->setGeometry(QRect(80, 0, 110, 28));
        storereport_startdateEdit->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        storereport_export_btn = new QPushButton(widget_20);
        storereport_export_btn->setObjectName(QStringLiteral("storereport_export_btn"));
        storereport_export_btn->setGeometry(QRect(490, 0, 80, 28));
        label_27 = new QLabel(widget_20);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setGeometry(QRect(540, 30, 191, 31));
        label_27->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 75 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        storereport_search_btn = new QPushButton(widget_20);
        storereport_search_btn->setObjectName(QStringLiteral("storereport_search_btn"));
        storereport_search_btn->setGeometry(QRect(390, 0, 80, 28));
        label_28 = new QLabel(widget_20);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setGeometry(QRect(200, 0, 60, 28));
        label_28->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(widget_20);

        store_report_tableView = new QTableView(storereport);
        store_report_tableView->setObjectName(QStringLiteral("store_report_tableView"));

        verticalLayout->addWidget(store_report_tableView);


        retranslateUi(storereport);

        QMetaObject::connectSlotsByName(storereport);
    } // setupUi

    void retranslateUi(QWidget *storereport)
    {
        storereport->setWindowTitle(QApplication::translate("storereport", "Form", Q_NULLPTR));
        label_25->setText(QApplication::translate("storereport", "\346\200\273\345\272\223\351\245\262\346\226\231\350\215\257\345\223\201\345\207\272\345\205\245\345\272\223\346\261\207\346\200\273", Q_NULLPTR));
        label_26->setText(QApplication::translate("storereport", "\346\200\273\345\272\223\351\245\262\346\226\231\350\215\257\345\223\201\345\207\272\345\205\245\345\272\223\346\261\207\346\200\273", Q_NULLPTR));
        storereport_export_btn->setText(QString());
        label_27->setText(QApplication::translate("storereport", "\345\210\206\345\272\223\351\245\262\346\226\231\350\215\257\345\223\201\347\224\250\346\226\231\346\261\207\346\200\273", Q_NULLPTR));
        storereport_search_btn->setText(QString());
        label_28->setText(QApplication::translate("storereport", "\346\200\273\345\272\223\351\245\262\346\226\231\350\215\257\345\223\201\345\207\272\345\205\245\345\272\223\346\261\207\346\200\273", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class storereport: public Ui_storereport {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STOREREPORTMANAGERQWIDGET_H
