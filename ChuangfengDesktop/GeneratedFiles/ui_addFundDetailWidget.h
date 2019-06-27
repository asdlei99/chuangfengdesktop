/********************************************************************************
** Form generated from reading UI file 'addFundDetailWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDFUNDDETAILWIDGET_H
#define UI_ADDFUNDDETAILWIDGET_H

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

class Ui_addFundDetailWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *pop_widget_title;
    QPushButton *pop_close_btn;
    QPushButton *pop_min_btn;
    QLabel *title_lab;
    QWidget *widget;
    QPushButton *pop_cancle_btn;
    QPushButton *pop_commit_btn;
    QLineEdit *remake_Edit;
    QLabel *remake_lab;
    QLabel *remake_lab_2;
    QDateEdit *dateEdit;
    QLineEdit *incom_Edit;
    QLabel *remake_lab_3;
    QLineEdit *pay_Edit;
    QLabel *remake_lab_4;
    QLabel *remake_lab_5;
    QComboBox *subject_comboBox;
    QLabel *remake_lab_6;
    QComboBox *share_comboBox;
    QLineEdit *subject_Edit;
    QLineEdit *share_Edit;

    void setupUi(QWidget *addFundDetailWidget)
    {
        if (addFundDetailWidget->objectName().isEmpty())
            addFundDetailWidget->setObjectName(QStringLiteral("addFundDetailWidget"));
        addFundDetailWidget->resize(600, 673);
        addFundDetailWidget->setMinimumSize(QSize(600, 673));
        addFundDetailWidget->setMaximumSize(QSize(600, 700));
        verticalLayout = new QVBoxLayout(addFundDetailWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(6, 6, 6, 6);
        pop_widget_title = new QWidget(addFundDetailWidget);
        pop_widget_title->setObjectName(QStringLiteral("pop_widget_title"));
        pop_widget_title->setMinimumSize(QSize(0, 35));
        pop_widget_title->setMaximumSize(QSize(16777214, 35));
        pop_close_btn = new QPushButton(pop_widget_title);
        pop_close_btn->setObjectName(QStringLiteral("pop_close_btn"));
        pop_close_btn->setGeometry(QRect(560, 6, 24, 24));
        pop_min_btn = new QPushButton(pop_widget_title);
        pop_min_btn->setObjectName(QStringLiteral("pop_min_btn"));
        pop_min_btn->setGeometry(QRect(535, 6, 24, 24));
        title_lab = new QLabel(pop_widget_title);
        title_lab->setObjectName(QStringLiteral("title_lab"));
        title_lab->setGeometry(QRect(10, 3, 151, 28));
        title_lab->setStyleSheet(QString::fromUtf8("font: 75 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 200, 255);"));

        verticalLayout->addWidget(pop_widget_title);

        widget = new QWidget(addFundDetailWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setStyleSheet(QStringLiteral(""));
        pop_cancle_btn = new QPushButton(widget);
        pop_cancle_btn->setObjectName(QStringLiteral("pop_cancle_btn"));
        pop_cancle_btn->setGeometry(QRect(70, 540, 95, 32));
        pop_commit_btn = new QPushButton(widget);
        pop_commit_btn->setObjectName(QStringLiteral("pop_commit_btn"));
        pop_commit_btn->setGeometry(QRect(420, 540, 95, 32));
        remake_Edit = new QLineEdit(widget);
        remake_Edit->setObjectName(QStringLiteral("remake_Edit"));
        remake_Edit->setGeometry(QRect(170, 360, 161, 28));
        remake_lab = new QLabel(widget);
        remake_lab->setObjectName(QStringLiteral("remake_lab"));
        remake_lab->setGeometry(QRect(80, 360, 81, 28));
        remake_lab->setStyleSheet(QString::fromUtf8("color: rgb(117, 117, 117);\n"
"font: 75 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        remake_lab->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        remake_lab_2 = new QLabel(widget);
        remake_lab_2->setObjectName(QStringLiteral("remake_lab_2"));
        remake_lab_2->setGeometry(QRect(80, 40, 81, 28));
        remake_lab_2->setStyleSheet(QString::fromUtf8("color: rgb(117, 117, 117);\n"
"font: 75 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        remake_lab_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        dateEdit = new QDateEdit(widget);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(170, 40, 161, 28));
        incom_Edit = new QLineEdit(widget);
        incom_Edit->setObjectName(QStringLiteral("incom_Edit"));
        incom_Edit->setGeometry(QRect(170, 100, 161, 28));
        remake_lab_3 = new QLabel(widget);
        remake_lab_3->setObjectName(QStringLiteral("remake_lab_3"));
        remake_lab_3->setGeometry(QRect(80, 100, 81, 28));
        remake_lab_3->setStyleSheet(QString::fromUtf8("color: rgb(117, 117, 117);\n"
"font: 75 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        remake_lab_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pay_Edit = new QLineEdit(widget);
        pay_Edit->setObjectName(QStringLiteral("pay_Edit"));
        pay_Edit->setGeometry(QRect(170, 160, 161, 28));
        remake_lab_4 = new QLabel(widget);
        remake_lab_4->setObjectName(QStringLiteral("remake_lab_4"));
        remake_lab_4->setGeometry(QRect(80, 160, 81, 28));
        remake_lab_4->setStyleSheet(QString::fromUtf8("color: rgb(117, 117, 117);\n"
"font: 75 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        remake_lab_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        remake_lab_5 = new QLabel(widget);
        remake_lab_5->setObjectName(QStringLiteral("remake_lab_5"));
        remake_lab_5->setGeometry(QRect(80, 220, 81, 28));
        remake_lab_5->setStyleSheet(QString::fromUtf8("color: rgb(117, 117, 117);\n"
"font: 75 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        remake_lab_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        subject_comboBox = new QComboBox(widget);
        subject_comboBox->setObjectName(QStringLiteral("subject_comboBox"));
        subject_comboBox->setGeometry(QRect(170, 220, 161, 28));
        remake_lab_6 = new QLabel(widget);
        remake_lab_6->setObjectName(QStringLiteral("remake_lab_6"));
        remake_lab_6->setGeometry(QRect(80, 290, 81, 28));
        remake_lab_6->setStyleSheet(QString::fromUtf8("color: rgb(117, 117, 117);\n"
"font: 75 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        remake_lab_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        share_comboBox = new QComboBox(widget);
        share_comboBox->setObjectName(QStringLiteral("share_comboBox"));
        share_comboBox->setGeometry(QRect(170, 290, 161, 28));
        subject_Edit = new QLineEdit(widget);
        subject_Edit->setObjectName(QStringLiteral("subject_Edit"));
        subject_Edit->setGeometry(QRect(340, 220, 161, 28));
        share_Edit = new QLineEdit(widget);
        share_Edit->setObjectName(QStringLiteral("share_Edit"));
        share_Edit->setGeometry(QRect(340, 290, 161, 28));
        share_Edit->setFrame(true);

        verticalLayout->addWidget(widget);


        retranslateUi(addFundDetailWidget);

        QMetaObject::connectSlotsByName(addFundDetailWidget);
    } // setupUi

    void retranslateUi(QWidget *addFundDetailWidget)
    {
        addFundDetailWidget->setWindowTitle(QApplication::translate("addFundDetailWidget", "Form", Q_NULLPTR));
        pop_close_btn->setText(QString());
        pop_min_btn->setText(QString());
        title_lab->setText(QString());
        pop_cancle_btn->setText(QString());
        pop_commit_btn->setText(QString());
        remake_lab->setText(QApplication::translate("addFundDetailWidget", "\346\221\230\350\246\201\357\274\232", Q_NULLPTR));
        remake_lab_2->setText(QApplication::translate("addFundDetailWidget", "\346\227\245\346\234\237\357\274\232", Q_NULLPTR));
        remake_lab_3->setText(QApplication::translate("addFundDetailWidget", "\345\200\237\346\226\271\357\274\232", Q_NULLPTR));
        remake_lab_4->setText(QApplication::translate("addFundDetailWidget", "\350\264\267\346\226\271\357\274\232", Q_NULLPTR));
        remake_lab_5->setText(QApplication::translate("addFundDetailWidget", "\351\241\271\347\233\256\357\274\232", Q_NULLPTR));
        remake_lab_6->setText(QApplication::translate("addFundDetailWidget", "\350\264\271\347\224\250\345\210\206\346\221\212\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class addFundDetailWidget: public Ui_addFundDetailWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDFUNDDETAILWIDGET_H
