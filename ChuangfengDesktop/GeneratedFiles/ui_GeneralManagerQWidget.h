/********************************************************************************
** Form generated from reading UI file 'GeneralManagerQWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GENERALMANAGERQWIDGET_H
#define UI_GENERALMANAGERQWIDGET_H

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

class Ui_generalManager
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *general_title;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *general_min_btn;
    QPushButton *general_max_restore_btn;
    QPushButton *general_cose_btn;
    QWidget *widget;
    QDateEdit *startdateEdit;
    QPushButton *general_export_btn;
    QLabel *label_5;
    QLabel *label_4;
    QPushButton *general_add_btn;
    QDateEdit *enddateEdit;
    QPushButton *general_search_btn;
    QPushButton *general_del_btn;
    QTableView *general_table_view;

    void setupUi(QWidget *generalManager)
    {
        if (generalManager->objectName().isEmpty())
            generalManager->setObjectName(QStringLiteral("generalManager"));
        generalManager->resize(867, 631);
        generalManager->setStyleSheet(QStringLiteral("background-color: rgb(68, 71, 77);"));
        verticalLayout = new QVBoxLayout(generalManager);
        verticalLayout->setSpacing(1);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(1, 1, 1, 1);
        general_title = new QWidget(generalManager);
        general_title->setObjectName(QStringLiteral("general_title"));
        general_title->setMinimumSize(QSize(0, 40));
        general_title->setStyleSheet(QStringLiteral("background-color: rgb(56, 59, 67);"));
        horizontalLayout = new QHBoxLayout(general_title);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(766, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        general_min_btn = new QPushButton(general_title);
        general_min_btn->setObjectName(QStringLiteral("general_min_btn"));
        general_min_btn->setMinimumSize(QSize(32, 23));

        horizontalLayout->addWidget(general_min_btn);

        general_max_restore_btn = new QPushButton(general_title);
        general_max_restore_btn->setObjectName(QStringLiteral("general_max_restore_btn"));
        general_max_restore_btn->setMinimumSize(QSize(32, 23));

        horizontalLayout->addWidget(general_max_restore_btn);

        general_cose_btn = new QPushButton(general_title);
        general_cose_btn->setObjectName(QStringLiteral("general_cose_btn"));
        general_cose_btn->setMinimumSize(QSize(32, 23));

        horizontalLayout->addWidget(general_cose_btn);


        verticalLayout->addWidget(general_title);

        widget = new QWidget(generalManager);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(0, 40));
        widget->setStyleSheet(QStringLiteral("background-color: rgb(68, 71, 77);"));
        startdateEdit = new QDateEdit(widget);
        startdateEdit->setObjectName(QStringLiteral("startdateEdit"));
        startdateEdit->setGeometry(QRect(80, 0, 110, 28));
        startdateEdit->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        general_export_btn = new QPushButton(widget);
        general_export_btn->setObjectName(QStringLiteral("general_export_btn"));
        general_export_btn->setGeometry(QRect(660, 0, 80, 28));
        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(200, 0, 60, 28));
        label_5->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 0, 60, 28));
        label_4->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        general_add_btn = new QPushButton(widget);
        general_add_btn->setObjectName(QStringLiteral("general_add_btn"));
        general_add_btn->setGeometry(QRect(480, 0, 80, 28));
        enddateEdit = new QDateEdit(widget);
        enddateEdit->setObjectName(QStringLiteral("enddateEdit"));
        enddateEdit->setGeometry(QRect(270, 0, 110, 28));
        enddateEdit->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        general_search_btn = new QPushButton(widget);
        general_search_btn->setObjectName(QStringLiteral("general_search_btn"));
        general_search_btn->setGeometry(QRect(390, 0, 80, 28));
        general_del_btn = new QPushButton(widget);
        general_del_btn->setObjectName(QStringLiteral("general_del_btn"));
        general_del_btn->setGeometry(QRect(570, 0, 80, 28));

        verticalLayout->addWidget(widget);

        general_table_view = new QTableView(generalManager);
        general_table_view->setObjectName(QStringLiteral("general_table_view"));
        general_table_view->setMinimumSize(QSize(865, 547));
        general_table_view->setStyleSheet(QStringLiteral("background-color: rgb(68, 71, 77);"));

        verticalLayout->addWidget(general_table_view);


        retranslateUi(generalManager);

        QMetaObject::connectSlotsByName(generalManager);
    } // setupUi

    void retranslateUi(QWidget *generalManager)
    {
        generalManager->setWindowTitle(QApplication::translate("generalManager", "Form", Q_NULLPTR));
        general_min_btn->setText(QString());
        general_max_restore_btn->setText(QString());
        general_cose_btn->setText(QString());
        general_export_btn->setText(QString());
        label_5->setText(QApplication::translate("generalManager", "\347\273\223\346\235\237\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("generalManager", "\345\274\200\345\247\213\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        general_add_btn->setText(QString());
        general_search_btn->setText(QString());
        general_del_btn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class generalManager: public Ui_generalManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENERALMANAGERQWIDGET_H
