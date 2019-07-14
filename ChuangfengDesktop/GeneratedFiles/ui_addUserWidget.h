/********************************************************************************
** Form generated from reading UI file 'addUserWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDUSERWIDGET_H
#define UI_ADDUSERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_adduserWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *pop_widget_title;
    QPushButton *pop_close_btn;
    QPushButton *pop_min_btn;
    QLabel *label_5;
    QWidget *widget;
    QPushButton *pop_cancle_btn;
    QPushButton *pop_commit_btn;
    QLabel *label;
    QLineEdit *userName_Edit;
    QLabel *label_2;
    QLineEdit *password_edit;
    QLabel *label_3;
    QLineEdit *sure_password_edit;
    QLabel *label_4;
    QComboBox *comboBox;
    QLabel *error_lab;

    void setupUi(QWidget *adduserWidget)
    {
        if (adduserWidget->objectName().isEmpty())
            adduserWidget->setObjectName(QStringLiteral("adduserWidget"));
        adduserWidget->resize(600, 673);
        adduserWidget->setMinimumSize(QSize(600, 673));
        adduserWidget->setMaximumSize(QSize(600, 700));
        QIcon icon;
        icon.addFile(QStringLiteral("Resources/test.png"), QSize(), QIcon::Normal, QIcon::Off);
        adduserWidget->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(adduserWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(6, 6, 6, 6);
        pop_widget_title = new QWidget(adduserWidget);
        pop_widget_title->setObjectName(QStringLiteral("pop_widget_title"));
        pop_widget_title->setMinimumSize(QSize(0, 35));
        pop_widget_title->setMaximumSize(QSize(16777214, 35));
        pop_close_btn = new QPushButton(pop_widget_title);
        pop_close_btn->setObjectName(QStringLiteral("pop_close_btn"));
        pop_close_btn->setGeometry(QRect(560, 6, 24, 24));
        pop_min_btn = new QPushButton(pop_widget_title);
        pop_min_btn->setObjectName(QStringLiteral("pop_min_btn"));
        pop_min_btn->setGeometry(QRect(535, 6, 24, 24));
        label_5 = new QLabel(pop_widget_title);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 3, 151, 28));
        label_5->setStyleSheet(QString::fromUtf8("font: 75 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 200, 255);"));

        verticalLayout->addWidget(pop_widget_title);

        widget = new QWidget(adduserWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        pop_cancle_btn = new QPushButton(widget);
        pop_cancle_btn->setObjectName(QStringLiteral("pop_cancle_btn"));
        pop_cancle_btn->setGeometry(QRect(70, 540, 95, 32));
        pop_commit_btn = new QPushButton(widget);
        pop_commit_btn->setObjectName(QStringLiteral("pop_commit_btn"));
        pop_commit_btn->setGeometry(QRect(420, 540, 95, 32));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 50, 81, 28));
        label->setStyleSheet(QString::fromUtf8("color: rgb(117, 117, 117);\n"
"font: 75 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        userName_Edit = new QLineEdit(widget);
        userName_Edit->setObjectName(QStringLiteral("userName_Edit"));
        userName_Edit->setGeometry(QRect(170, 50, 161, 28));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(80, 110, 81, 28));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(117, 117, 117);\n"
"font: 75 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        password_edit = new QLineEdit(widget);
        password_edit->setObjectName(QStringLiteral("password_edit"));
        password_edit->setGeometry(QRect(170, 110, 161, 28));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(80, 170, 81, 28));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(117, 117, 117);\n"
"font: 75 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        sure_password_edit = new QLineEdit(widget);
        sure_password_edit->setObjectName(QStringLiteral("sure_password_edit"));
        sure_password_edit->setGeometry(QRect(170, 170, 161, 28));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(80, 230, 81, 28));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(117, 117, 117);\n"
"font: 75 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        comboBox = new QComboBox(widget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(170, 230, 161, 28));
        error_lab = new QLabel(widget);
        error_lab->setObjectName(QStringLiteral("error_lab"));
        error_lab->setGeometry(QRect(90, 340, 381, 28));
        error_lab->setStyleSheet(QString::fromUtf8("font: 75 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 85, 0);"));

        verticalLayout->addWidget(widget);


        retranslateUi(adduserWidget);

        QMetaObject::connectSlotsByName(adduserWidget);
    } // setupUi

    void retranslateUi(QWidget *adduserWidget)
    {
        adduserWidget->setWindowTitle(QApplication::translate("adduserWidget", "\347\224\250\346\210\267\347\256\241\347\220\206", Q_NULLPTR));
        pop_close_btn->setText(QString());
        pop_min_btn->setText(QString());
        label_5->setText(QApplication::translate("adduserWidget", "\347\224\250\346\210\267\347\256\241\347\220\206", Q_NULLPTR));
        pop_cancle_btn->setText(QString());
        pop_commit_btn->setText(QString());
        label->setText(QApplication::translate("adduserWidget", "\347\224\250\346\210\267\345\220\215\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("adduserWidget", "\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("adduserWidget", "\347\241\256\350\256\244\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("adduserWidget", "\346\235\203\351\231\220\357\274\232", Q_NULLPTR));
        error_lab->setText(QApplication::translate("adduserWidget", "\345\257\206\347\240\201\344\270\215\344\270\200\350\207\264\357\274\214\350\257\267\346\240\270\345\256\236\357\274\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class adduserWidget: public Ui_adduserWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDUSERWIDGET_H
