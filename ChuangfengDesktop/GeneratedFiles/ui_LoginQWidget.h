/********************************************************************************
** Form generated from reading UI file 'LoginQWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINQWIDGET_H
#define UI_LOGINQWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtLoginWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *login_title;
    QLabel *label;
    QPushButton *login_close_btn;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *login_logo;
    QLineEdit *user_Edit;
    QLineEdit *password_Edit;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *login_btn;
    QLabel *error_lab;
    QWidget *page_2;
    QLineEdit *port_Edit;
    QLineEdit *servce_ip;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *servce_set_btn;

    void setupUi(QWidget *QtLoginWidget)
    {
        if (QtLoginWidget->objectName().isEmpty())
            QtLoginWidget->setObjectName(QStringLiteral("QtLoginWidget"));
        QtLoginWidget->resize(279, 405);
        QIcon icon;
        icon.addFile(QStringLiteral("Resources/test.png"), QSize(), QIcon::Normal, QIcon::Off);
        QtLoginWidget->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(QtLoginWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(4, 4, 4, 4);
        login_title = new QWidget(QtLoginWidget);
        login_title->setObjectName(QStringLiteral("login_title"));
        label = new QLabel(login_title);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 61, 20));
        label->setStyleSheet(QStringLiteral("color:#747678"));
        login_close_btn = new QPushButton(login_title);
        login_close_btn->setObjectName(QStringLiteral("login_close_btn"));
        login_close_btn->setGeometry(QRect(250, 10, 16, 16));
        stackedWidget = new QStackedWidget(login_title);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(10, 30, 251, 361));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        login_logo = new QLabel(page);
        login_logo->setObjectName(QStringLiteral("login_logo"));
        login_logo->setGeometry(QRect(60, 30, 128, 128));
        user_Edit = new QLineEdit(page);
        user_Edit->setObjectName(QStringLiteral("user_Edit"));
        user_Edit->setGeometry(QRect(40, 180, 171, 28));
        password_Edit = new QLineEdit(page);
        password_Edit->setObjectName(QStringLiteral("password_Edit"));
        password_Edit->setGeometry(QRect(40, 240, 171, 28));
        label_2 = new QLabel(page);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(36, 210, 180, 1));
        label_2->setStyleSheet(QStringLiteral("background-color: rgb(240, 240, 240);"));
        label_3 = new QLabel(page);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(36, 270, 180, 1));
        label_3->setStyleSheet(QStringLiteral("background-color: rgb(240, 240, 240);"));
        login_btn = new QPushButton(page);
        login_btn->setObjectName(QStringLiteral("login_btn"));
        login_btn->setGeometry(QRect(40, 290, 180, 32));
        error_lab = new QLabel(page);
        error_lab->setObjectName(QStringLiteral("error_lab"));
        error_lab->setGeometry(QRect(10, 330, 231, 28));
        error_lab->setStyleSheet(QStringLiteral("color: rgb(255, 85, 0);"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        port_Edit = new QLineEdit(page_2);
        port_Edit->setObjectName(QStringLiteral("port_Edit"));
        port_Edit->setGeometry(QRect(100, 120, 121, 28));
        servce_ip = new QLineEdit(page_2);
        servce_ip->setObjectName(QStringLiteral("servce_ip"));
        servce_ip->setGeometry(QRect(100, 60, 121, 28));
        label_4 = new QLabel(page_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(95, 90, 121, 1));
        label_4->setStyleSheet(QStringLiteral("background-color: rgb(240, 240, 240);"));
        label_5 = new QLabel(page_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(95, 150, 121, 1));
        label_5->setStyleSheet(QStringLiteral("background-color: rgb(240, 240, 240);"));
        label_6 = new QLabel(page_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(0, 60, 71, 28));
        label_6->setStyleSheet(QStringLiteral("color: rgb(94, 94, 94);"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_7 = new QLabel(page_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(0, 120, 71, 28));
        label_7->setStyleSheet(QStringLiteral("color: rgb(94, 94, 94);"));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        stackedWidget->addWidget(page_2);
        servce_set_btn = new QPushButton(login_title);
        servce_set_btn->setObjectName(QStringLiteral("servce_set_btn"));
        servce_set_btn->setGeometry(QRect(220, 10, 16, 16));

        verticalLayout->addWidget(login_title);


        retranslateUi(QtLoginWidget);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(QtLoginWidget);
    } // setupUi

    void retranslateUi(QWidget *QtLoginWidget)
    {
        QtLoginWidget->setWindowTitle(QApplication::translate("QtLoginWidget", "\347\231\273\345\275\225", Q_NULLPTR));
        label->setText(QApplication::translate("QtLoginWidget", "\345\210\233\344\270\260\345\205\273\346\256\226", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        login_close_btn->setToolTip(QApplication::translate("QtLoginWidget", "\345\205\263\351\227\255", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        login_close_btn->setText(QString());
        login_logo->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        login_btn->setText(QApplication::translate("QtLoginWidget", "\347\231\273\345\275\225", Q_NULLPTR));
        error_lab->setText(QApplication::translate("QtLoginWidget", "\347\224\250\346\210\267\345\220\215\346\210\226\350\200\205\345\257\206\347\240\201\351\224\231\350\257\257\357\274\201", Q_NULLPTR));
        port_Edit->setText(QApplication::translate("QtLoginWidget", "80", Q_NULLPTR));
        servce_ip->setText(QApplication::translate("QtLoginWidget", "127.0.0.1", Q_NULLPTR));
        label_4->setText(QString());
        label_5->setText(QString());
        label_6->setText(QApplication::translate("QtLoginWidget", "\346\234\215\345\212\241\345\231\250IP\357\274\232", Q_NULLPTR));
        label_7->setText(QApplication::translate("QtLoginWidget", "\347\253\257\345\217\243\345\217\267\357\274\232", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        servce_set_btn->setToolTip(QApplication::translate("QtLoginWidget", "\350\256\276\347\275\256", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        servce_set_btn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class QtLoginWidget: public Ui_QtLoginWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINQWIDGET_H
