/********************************************************************************
** Form generated from reading UI file 'NopayManagerQWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOPAYMANAGERQWIDGET_H
#define UI_NOPAYMANAGERQWIDGET_H

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

class Ui_nopayManager
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *nopay_title;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *min_btn;
    QPushButton *max_restore_btn;
    QPushButton *close_btn;
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

    void setupUi(QWidget *nopayManager)
    {
        if (nopayManager->objectName().isEmpty())
            nopayManager->setObjectName(QStringLiteral("nopayManager"));
        nopayManager->resize(831, 479);
        verticalLayout = new QVBoxLayout(nopayManager);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(1, 1, 1, 1);
        nopay_title = new QWidget(nopayManager);
        nopay_title->setObjectName(QStringLiteral("nopay_title"));
        nopay_title->setMinimumSize(QSize(0, 40));
        nopay_title->setStyleSheet(QStringLiteral("background-color: rgb(56, 59, 67);"));
        horizontalLayout = new QHBoxLayout(nopay_title);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(730, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        min_btn = new QPushButton(nopay_title);
        min_btn->setObjectName(QStringLiteral("min_btn"));
        min_btn->setMinimumSize(QSize(32, 23));

        horizontalLayout->addWidget(min_btn);

        max_restore_btn = new QPushButton(nopay_title);
        max_restore_btn->setObjectName(QStringLiteral("max_restore_btn"));
        max_restore_btn->setMinimumSize(QSize(32, 23));

        horizontalLayout->addWidget(max_restore_btn);

        close_btn = new QPushButton(nopay_title);
        close_btn->setObjectName(QStringLiteral("close_btn"));
        close_btn->setMinimumSize(QSize(32, 23));

        horizontalLayout->addWidget(close_btn);


        verticalLayout->addWidget(nopay_title);

        widget_9 = new QWidget(nopayManager);
        widget_9->setObjectName(QStringLiteral("widget_9"));
        widget_9->setMinimumSize(QSize(0, 40));
        widget_9->setMaximumSize(QSize(16777215, 40));
        widget_9->setStyleSheet(QStringLiteral("background-color: rgb(68, 71, 77);"));
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

        verticalLayout->addWidget(widget_9);

        nopay_tableView = new QTableView(nopayManager);
        nopay_tableView->setObjectName(QStringLiteral("nopay_tableView"));
        nopay_tableView->setStyleSheet(QStringLiteral("background-color: rgb(68, 71, 77);"));

        verticalLayout->addWidget(nopay_tableView);


        retranslateUi(nopayManager);

        QMetaObject::connectSlotsByName(nopayManager);
    } // setupUi

    void retranslateUi(QWidget *nopayManager)
    {
        nopayManager->setWindowTitle(QApplication::translate("nopayManager", "Form", Q_NULLPTR));
        min_btn->setText(QString());
        max_restore_btn->setText(QString());
        close_btn->setText(QString());
        label_8->setText(QApplication::translate("nopayManager", "\345\274\200\345\247\213\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        nopay_search_btn->setText(QString());
        nopay_add_btn->setText(QString());
        nopay_export_btn->setText(QString());
        label_9->setText(QApplication::translate("nopayManager", "\347\273\223\346\235\237\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        nopay_del_btn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class nopayManager: public Ui_nopayManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOPAYMANAGERQWIDGET_H
