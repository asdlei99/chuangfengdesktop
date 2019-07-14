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
    QWidget *child_widget_title;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
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
        nopayManager->resize(860, 630);
        nopayManager->setMinimumSize(QSize(860, 630));
        QIcon icon;
        icon.addFile(QStringLiteral("Resources/test.png"), QSize(), QIcon::Normal, QIcon::Off);
        nopayManager->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(nopayManager);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(9, 1, 1, 1);
        child_widget_title = new QWidget(nopayManager);
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
"font: 75 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(730, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

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

        widget_9 = new QWidget(nopayManager);
        widget_9->setObjectName(QStringLiteral("widget_9"));
        widget_9->setMinimumSize(QSize(0, 40));
        widget_9->setMaximumSize(QSize(16777215, 40));
        widget_9->setStyleSheet(QStringLiteral("background-color: rgb(54, 78, 111);"));
        nopay_enddateEdit = new QDateEdit(widget_9);
        nopay_enddateEdit->setObjectName(QStringLiteral("nopay_enddateEdit"));
        nopay_enddateEdit->setGeometry(QRect(260, 10, 110, 28));
        nopay_enddateEdit->setStyleSheet(QLatin1String("color: rgb(171, 171, 171);\n"
"border-color: rgb(255, 255, 255);\n"
"border-style: solid;\n"
"border-width: 1px;"));
        label_8 = new QLabel(widget_9);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(0, 10, 65, 28));
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
        nopay_startdateEdit->setStyleSheet(QLatin1String("color: rgb(171, 171, 171);\n"
"border-color: rgb(255, 255, 255);\n"
"border-style: solid;\n"
"border-width: 1px;"));
        label_9 = new QLabel(widget_9);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(190, 10, 65, 28));
        label_9->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        nopay_del_btn = new QPushButton(widget_9);
        nopay_del_btn->setObjectName(QStringLiteral("nopay_del_btn"));
        nopay_del_btn->setGeometry(QRect(560, 10, 80, 28));

        verticalLayout->addWidget(widget_9);

        nopay_tableView = new QTableView(nopayManager);
        nopay_tableView->setObjectName(QStringLiteral("nopay_tableView"));
        nopay_tableView->setStyleSheet(QStringLiteral("background-color: rgb(54, 78, 111);"));

        verticalLayout->addWidget(nopay_tableView);


        retranslateUi(nopayManager);

        QMetaObject::connectSlotsByName(nopayManager);
    } // setupUi

    void retranslateUi(QWidget *nopayManager)
    {
        nopayManager->setWindowTitle(QApplication::translate("nopayManager", "\345\272\224\344\273\230\346\254\276\346\230\216\347\273\206", Q_NULLPTR));
        label->setText(QApplication::translate("nopayManager", "\345\272\224\344\273\230\346\254\276\346\230\216\347\273\206", Q_NULLPTR));
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
