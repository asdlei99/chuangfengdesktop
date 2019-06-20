/********************************************************************************
** Form generated from reading UI file 'MaterielReportManagerQWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATERIELREPORTMANAGERQWIDGET_H
#define UI_MATERIELREPORTMANAGERQWIDGET_H

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

class Ui_materielreport
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_19;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_24;
    QDateEdit *materielreport_startdateEdit;
    QPushButton *materielreport_search_btn;
    QDateEdit *materiel_report_enddateEdit;
    QPushButton *materielreport_export_btn;
    QTableView *materiel_report_tableView;

    void setupUi(QWidget *materielreport)
    {
        if (materielreport->objectName().isEmpty())
            materielreport->setObjectName(QStringLiteral("materielreport"));
        materielreport->resize(719, 300);
        verticalLayout = new QVBoxLayout(materielreport);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widget_19 = new QWidget(materielreport);
        widget_19->setObjectName(QStringLiteral("widget_19"));
        widget_19->setMinimumSize(QSize(0, 60));
        widget_19->setMaximumSize(QSize(16777215, 60));
        label_21 = new QLabel(widget_19);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(10, 0, 60, 28));
        label_21->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_22 = new QLabel(widget_19);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(200, 0, 60, 28));
        label_22->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_23 = new QLabel(widget_19);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(540, 30, 191, 31));
        label_23->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 75 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_24 = new QLabel(widget_19);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(120, 30, 191, 31));
        label_24->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 75 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        materielreport_startdateEdit = new QDateEdit(widget_19);
        materielreport_startdateEdit->setObjectName(QStringLiteral("materielreport_startdateEdit"));
        materielreport_startdateEdit->setGeometry(QRect(80, 0, 110, 28));
        materielreport_startdateEdit->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        materielreport_search_btn = new QPushButton(widget_19);
        materielreport_search_btn->setObjectName(QStringLiteral("materielreport_search_btn"));
        materielreport_search_btn->setGeometry(QRect(390, 0, 80, 28));
        materiel_report_enddateEdit = new QDateEdit(widget_19);
        materiel_report_enddateEdit->setObjectName(QStringLiteral("materiel_report_enddateEdit"));
        materiel_report_enddateEdit->setGeometry(QRect(270, 0, 110, 28));
        materiel_report_enddateEdit->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        materielreport_export_btn = new QPushButton(widget_19);
        materielreport_export_btn->setObjectName(QStringLiteral("materielreport_export_btn"));
        materielreport_export_btn->setGeometry(QRect(490, 0, 80, 28));

        verticalLayout->addWidget(widget_19);

        materiel_report_tableView = new QTableView(materielreport);
        materiel_report_tableView->setObjectName(QStringLiteral("materiel_report_tableView"));

        verticalLayout->addWidget(materiel_report_tableView);


        retranslateUi(materielreport);

        QMetaObject::connectSlotsByName(materielreport);
    } // setupUi

    void retranslateUi(QWidget *materielreport)
    {
        materielreport->setWindowTitle(QApplication::translate("materielreport", "Form", Q_NULLPTR));
        label_21->setText(QApplication::translate("materielreport", "\345\274\200\345\247\213\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        label_22->setText(QApplication::translate("materielreport", "\347\273\223\346\235\237\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        label_23->setText(QApplication::translate("materielreport", "\345\233\272\350\265\204\345\210\206\346\221\212\346\203\205\345\206\265\350\241\250", Q_NULLPTR));
        label_24->setText(QApplication::translate("materielreport", "\347\211\251\346\226\231\351\242\206\347\224\250\346\261\207\346\200\273\350\241\250", Q_NULLPTR));
        materielreport_search_btn->setText(QString());
        materielreport_export_btn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class materielreport: public Ui_materielreport {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATERIELREPORTMANAGERQWIDGET_H
