/********************************************************************************
** Form generated from reading UI file 'addNopayDetailWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDNOPAYDETAILWIDGET_H
#define UI_ADDNOPAYDETAILWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addNoPayDetailWidget
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
    QLabel *label_4;
    QLineEdit *new_add_edit;
    QDateEdit *dateEdit;
    QLabel *label_2;
    QComboBox *comboBox;
    QLabel *label_6;
    QLineEdit *adjust_edit;
    QLabel *label_7;
    QLineEdit *return_edit;
    QLineEdit *pay_edit;
    QLabel *label_8;
    QLineEdit *supplier_edit;
    QLabel *label_9;
    QLineEdit *remake_edit;
    QLabel *error_lab;

    void setupUi(QWidget *addNoPayDetailWidget)
    {
        if (addNoPayDetailWidget->objectName().isEmpty())
            addNoPayDetailWidget->setObjectName(QStringLiteral("addNoPayDetailWidget"));
        addNoPayDetailWidget->resize(600, 673);
        addNoPayDetailWidget->setMinimumSize(QSize(600, 673));
        addNoPayDetailWidget->setMaximumSize(QSize(600, 700));
        QIcon icon;
        icon.addFile(QStringLiteral("Resources/test.png"), QSize(), QIcon::Normal, QIcon::Off);
        addNoPayDetailWidget->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(addNoPayDetailWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(6, 6, 6, 6);
        pop_widget_title = new QWidget(addNoPayDetailWidget);
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

        widget = new QWidget(addNoPayDetailWidget);
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
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(50, 230, 111, 28));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(117, 117, 117);\n"
"font: 75 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        new_add_edit = new QLineEdit(widget);
        new_add_edit->setObjectName(QStringLiteral("new_add_edit"));
        new_add_edit->setGeometry(QRect(170, 230, 161, 28));
        dateEdit = new QDateEdit(widget);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(170, 50, 110, 28));
        dateEdit->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(80, 110, 81, 28));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(117, 117, 117);\n"
"font: 75 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        comboBox = new QComboBox(widget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(170, 110, 161, 28));
        label_6 = new QLabel(widget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 170, 141, 28));
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(117, 117, 117);\n"
"font: 75 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        adjust_edit = new QLineEdit(widget);
        adjust_edit->setObjectName(QStringLiteral("adjust_edit"));
        adjust_edit->setGeometry(QRect(170, 170, 161, 28));
        label_7 = new QLabel(widget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(80, 290, 81, 28));
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(117, 117, 117);\n"
"font: 75 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        return_edit = new QLineEdit(widget);
        return_edit->setObjectName(QStringLiteral("return_edit"));
        return_edit->setGeometry(QRect(170, 290, 161, 28));
        pay_edit = new QLineEdit(widget);
        pay_edit->setObjectName(QStringLiteral("pay_edit"));
        pay_edit->setGeometry(QRect(170, 350, 161, 28));
        label_8 = new QLabel(widget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(80, 350, 81, 28));
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(117, 117, 117);\n"
"font: 75 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        supplier_edit = new QLineEdit(widget);
        supplier_edit->setObjectName(QStringLiteral("supplier_edit"));
        supplier_edit->setGeometry(QRect(340, 110, 161, 28));
        label_9 = new QLabel(widget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(80, 400, 81, 28));
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(117, 117, 117);\n"
"font: 75 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        remake_edit = new QLineEdit(widget);
        remake_edit->setObjectName(QStringLiteral("remake_edit"));
        remake_edit->setGeometry(QRect(170, 400, 161, 28));
        error_lab = new QLabel(widget);
        error_lab->setObjectName(QStringLiteral("error_lab"));
        error_lab->setGeometry(QRect(120, 480, 381, 28));
        error_lab->setStyleSheet(QString::fromUtf8("font: 75 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 85, 0);"));

        verticalLayout->addWidget(widget);


        retranslateUi(addNoPayDetailWidget);

        QMetaObject::connectSlotsByName(addNoPayDetailWidget);
    } // setupUi

    void retranslateUi(QWidget *addNoPayDetailWidget)
    {
        addNoPayDetailWidget->setWindowTitle(QApplication::translate("addNoPayDetailWidget", "\345\242\236\345\212\240\345\272\224\344\273\230\346\254\276\346\230\216\347\273\206", Q_NULLPTR));
        pop_close_btn->setText(QString());
        pop_min_btn->setText(QString());
        label_5->setText(QApplication::translate("addNoPayDetailWidget", "\345\242\236\345\212\240\345\272\224\344\273\230\346\254\276\346\230\216\347\273\206", Q_NULLPTR));
        pop_cancle_btn->setText(QString());
        pop_commit_btn->setText(QString());
        label->setText(QApplication::translate("addNoPayDetailWidget", "\346\227\245\346\234\237\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("addNoPayDetailWidget", "\346\226\260\345\242\236\345\272\224\344\273\230\346\254\276\357\274\232", Q_NULLPTR));
        new_add_edit->setText(QApplication::translate("addNoPayDetailWidget", "0", Q_NULLPTR));
        label_2->setText(QApplication::translate("addNoPayDetailWidget", "\344\276\233\345\272\224\345\225\206\357\274\232", Q_NULLPTR));
        label_6->setText(QApplication::translate("addNoPayDetailWidget", "\350\260\203\350\264\246\346\210\226\350\200\205\346\211\243\346\254\276\357\274\232", Q_NULLPTR));
        adjust_edit->setText(QApplication::translate("addNoPayDetailWidget", "0", Q_NULLPTR));
        label_7->setText(QApplication::translate("addNoPayDetailWidget", "\351\200\200\350\264\247\357\274\232", Q_NULLPTR));
        return_edit->setText(QApplication::translate("addNoPayDetailWidget", "0", Q_NULLPTR));
        pay_edit->setText(QApplication::translate("addNoPayDetailWidget", "0", Q_NULLPTR));
        label_8->setText(QApplication::translate("addNoPayDetailWidget", "\345\267\262\344\273\230\346\254\276\357\274\232", Q_NULLPTR));
        supplier_edit->setText(QString());
        label_9->setText(QApplication::translate("addNoPayDetailWidget", "\346\221\230\350\246\201\357\274\232", Q_NULLPTR));
        remake_edit->setText(QString());
        error_lab->setText(QApplication::translate("addNoPayDetailWidget", "\346\234\211\347\261\273\347\233\256\344\270\272\347\251\272\357\274\214\350\257\267\346\240\270\345\256\236~", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class addNoPayDetailWidget: public Ui_addNoPayDetailWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDNOPAYDETAILWIDGET_H
