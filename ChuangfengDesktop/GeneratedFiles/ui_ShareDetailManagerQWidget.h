/********************************************************************************
** Form generated from reading UI file 'ShareDetailManagerQWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHAREDETAILMANAGERQWIDGET_H
#define UI_SHAREDETAILMANAGERQWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
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

class Ui_detailsharereport
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *child_widget_title;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *min_btn;
    QPushButton *max_restore_btn;
    QPushButton *close_btn;
    QWidget *widget_18;
    QDateEdit *detailshare_report_enddateEdit;
    QDateEdit *detailshare_report_startdateEdit;
    QLabel *label_18;
    QPushButton *detaishare_report_search_btn;
    QPushButton *detailsharereport_export_btn;
    QLabel *label_19;
    QLabel *label_20;
    QComboBox *area_combox;
    QTableView *detailshare_report_tableview;

    void setupUi(QWidget *detailsharereport)
    {
        if (detailsharereport->objectName().isEmpty())
            detailsharereport->setObjectName(QStringLiteral("detailsharereport"));
        detailsharereport->resize(842, 672);
        QIcon icon;
        icon.addFile(QStringLiteral("Resources/test.png"), QSize(), QIcon::Normal, QIcon::Off);
        detailsharereport->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(detailsharereport);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(9, 1, 1, 1);
        child_widget_title = new QWidget(detailsharereport);
        child_widget_title->setObjectName(QStringLiteral("child_widget_title"));
        child_widget_title->setMinimumSize(QSize(0, 40));
        child_widget_title->setStyleSheet(QStringLiteral(""));
        horizontalLayout = new QHBoxLayout(child_widget_title);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(child_widget_title);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(120, 0));
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout->addWidget(label);

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

        widget_18 = new QWidget(detailsharereport);
        widget_18->setObjectName(QStringLiteral("widget_18"));
        widget_18->setMinimumSize(QSize(0, 40));
        widget_18->setMaximumSize(QSize(16777215, 40));
        widget_18->setStyleSheet(QStringLiteral("background-color: rgb(54, 78, 111);"));
        detailshare_report_enddateEdit = new QDateEdit(widget_18);
        detailshare_report_enddateEdit->setObjectName(QStringLiteral("detailshare_report_enddateEdit"));
        detailshare_report_enddateEdit->setGeometry(QRect(260, 10, 110, 28));
        detailshare_report_enddateEdit->setStyleSheet(QLatin1String("color: rgb(171, 171, 171);\n"
"border-color: rgb(255, 255, 255);\n"
"border-style: solid;\n"
"border-width: 1px;"));
        detailshare_report_startdateEdit = new QDateEdit(widget_18);
        detailshare_report_startdateEdit->setObjectName(QStringLiteral("detailshare_report_startdateEdit"));
        detailshare_report_startdateEdit->setGeometry(QRect(70, 10, 110, 28));
        detailshare_report_startdateEdit->setStyleSheet(QLatin1String("color: rgb(171, 171, 171);\n"
"border-color: rgb(255, 255, 255);\n"
"border-style: solid;\n"
"border-width: 1px;"));
        label_18 = new QLabel(widget_18);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(190, 10, 65, 28));
        label_18->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        detaishare_report_search_btn = new QPushButton(widget_18);
        detaishare_report_search_btn->setObjectName(QStringLiteral("detaishare_report_search_btn"));
        detaishare_report_search_btn->setGeometry(QRect(550, 10, 80, 28));
        detailsharereport_export_btn = new QPushButton(widget_18);
        detailsharereport_export_btn->setObjectName(QStringLiteral("detailsharereport_export_btn"));
        detailsharereport_export_btn->setGeometry(QRect(650, 10, 80, 28));
        label_19 = new QLabel(widget_18);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(0, 10, 65, 28));
        label_19->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_20 = new QLabel(widget_18);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(380, 10, 65, 28));
        label_20->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        area_combox = new QComboBox(widget_18);
        area_combox->setObjectName(QStringLiteral("area_combox"));
        area_combox->setGeometry(QRect(450, 10, 80, 28));
        area_combox->setStyleSheet(QLatin1String("color: rgb(171, 171, 171);\n"
"border-color: rgb(171, 171, 171);"));

        verticalLayout->addWidget(widget_18);

        detailshare_report_tableview = new QTableView(detailsharereport);
        detailshare_report_tableview->setObjectName(QStringLiteral("detailshare_report_tableview"));
        detailshare_report_tableview->setMinimumSize(QSize(823, 562));
        detailshare_report_tableview->setStyleSheet(QStringLiteral("background-color: rgb(54, 78, 111);"));

        verticalLayout->addWidget(detailshare_report_tableview);


        retranslateUi(detailsharereport);

        QMetaObject::connectSlotsByName(detailsharereport);
    } // setupUi

    void retranslateUi(QWidget *detailsharereport)
    {
        detailsharereport->setWindowTitle(QApplication::translate("detailsharereport", "\345\214\272\345\237\237\345\210\206\346\221\212\350\241\250", Q_NULLPTR));
        label->setText(QApplication::translate("detailsharereport", "\345\214\272\345\237\237\345\210\206\346\221\212\350\241\250", Q_NULLPTR));
        min_btn->setText(QString());
        max_restore_btn->setText(QString());
        close_btn->setText(QString());
        label_18->setText(QApplication::translate("detailsharereport", "\347\273\223\346\235\237\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        detaishare_report_search_btn->setText(QString());
        detailsharereport_export_btn->setText(QString());
        label_19->setText(QApplication::translate("detailsharereport", "\345\274\200\345\247\213\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        label_20->setText(QApplication::translate("detailsharereport", "\345\205\273\346\256\226\345\214\272\345\237\237\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class detailsharereport: public Ui_detailsharereport {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHAREDETAILMANAGERQWIDGET_H
