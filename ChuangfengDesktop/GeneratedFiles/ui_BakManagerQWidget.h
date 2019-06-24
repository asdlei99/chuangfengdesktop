/********************************************************************************
** Form generated from reading UI file 'BakManagerQWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BAKMANAGERQWIDGET_H
#define UI_BAKMANAGERQWIDGET_H

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

class Ui_BakManager
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *child_widget_title;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *bak_min_btn;
    QPushButton *bak_max_restore_btn;
    QPushButton *bak_cose_btn;
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

    void setupUi(QWidget *BakManager)
    {
        if (BakManager->objectName().isEmpty())
            BakManager->setObjectName(QStringLiteral("BakManager"));
        BakManager->resize(860, 630);
        BakManager->setMinimumSize(QSize(860, 630));
        verticalLayout = new QVBoxLayout(BakManager);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(9, 1, 1, 1);
        child_widget_title = new QWidget(BakManager);
        child_widget_title->setObjectName(QStringLiteral("child_widget_title"));
        child_widget_title->setMinimumSize(QSize(0, 40));
        child_widget_title->setStyleSheet(QStringLiteral(""));
        horizontalLayout = new QHBoxLayout(child_widget_title);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(child_widget_title);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(100, 0));
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 75 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(744, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        bak_min_btn = new QPushButton(child_widget_title);
        bak_min_btn->setObjectName(QStringLiteral("bak_min_btn"));
        bak_min_btn->setMinimumSize(QSize(32, 23));

        horizontalLayout->addWidget(bak_min_btn);

        bak_max_restore_btn = new QPushButton(child_widget_title);
        bak_max_restore_btn->setObjectName(QStringLiteral("bak_max_restore_btn"));
        bak_max_restore_btn->setMinimumSize(QSize(32, 23));

        horizontalLayout->addWidget(bak_max_restore_btn);

        bak_cose_btn = new QPushButton(child_widget_title);
        bak_cose_btn->setObjectName(QStringLiteral("bak_cose_btn"));
        bak_cose_btn->setMinimumSize(QSize(32, 23));

        horizontalLayout->addWidget(bak_cose_btn);


        verticalLayout->addWidget(child_widget_title);

        widget_8 = new QWidget(BakManager);
        widget_8->setObjectName(QStringLiteral("widget_8"));
        widget_8->setMinimumSize(QSize(0, 40));
        widget_8->setMaximumSize(QSize(16777215, 40));
        widget_8->setStyleSheet(QStringLiteral("background-color: rgb(54, 78, 111);"));
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
        label_6->setGeometry(QRect(190, 10, 65, 28));
        label_6->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_7 = new QLabel(widget_8);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(0, 10, 65, 28));
        label_7->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        bak_startdateEdit = new QDateEdit(widget_8);
        bak_startdateEdit->setObjectName(QStringLiteral("bak_startdateEdit"));
        bak_startdateEdit->setGeometry(QRect(70, 10, 110, 28));
        bak_startdateEdit->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        bak_search_btn = new QPushButton(widget_8);
        bak_search_btn->setObjectName(QStringLiteral("bak_search_btn"));
        bak_search_btn->setGeometry(QRect(380, 10, 80, 28));

        verticalLayout->addWidget(widget_8);

        bak_tableView = new QTableView(BakManager);
        bak_tableView->setObjectName(QStringLiteral("bak_tableView"));
        bak_tableView->setStyleSheet(QStringLiteral("background-color: rgb(54, 78, 111);"));

        verticalLayout->addWidget(bak_tableView);


        retranslateUi(BakManager);

        QMetaObject::connectSlotsByName(BakManager);
    } // setupUi

    void retranslateUi(QWidget *BakManager)
    {
        BakManager->setWindowTitle(QApplication::translate("BakManager", "\345\244\207\347\224\250\351\207\221\346\230\216\347\273\206", Q_NULLPTR));
        label->setText(QApplication::translate("BakManager", "\345\244\207\347\224\250\351\207\221\346\230\216\347\273\206", Q_NULLPTR));
        bak_min_btn->setText(QString());
        bak_max_restore_btn->setText(QString());
        bak_cose_btn->setText(QString());
        bak_del_btn->setText(QString());
        bak_export_btn->setText(QString());
        bak_add_btn->setText(QString());
        label_6->setText(QApplication::translate("BakManager", "\347\273\223\346\235\237\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        label_7->setText(QApplication::translate("BakManager", "\345\274\200\345\247\213\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        bak_search_btn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class BakManager: public Ui_BakManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BAKMANAGERQWIDGET_H
