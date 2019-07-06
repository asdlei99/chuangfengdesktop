/********************************************************************************
** Form generated from reading UI file 'materialStorgeWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATERIALSTORGEWIDGET_H
#define UI_MATERIALSTORGEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_materialStorgeWidget
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
    QLabel *remake_lab_2;
    QDateEdit *dateEdit;
    QLineEdit *use_Edit;
    QLabel *remake_lab_4;
    QLabel *remake_lab_5;
    QLabel *remake_lab_6;
    QLineEdit *subject_name_Edit;
    QLineEdit *unit_Edit;
    QLabel *error_lab;
    QLineEdit *subject_Edit;
    QLabel *remake_lab_8;
    QLabel *remake_lab_9;
    QLineEdit *freight_Edit;
    QLabel *remake_lab_10;
    QLineEdit *pice_Edit;
    QLineEdit *Number_Edit;
    QLabel *remake_lab_11;
    QLineEdit *norms_Edit;
    QLabel *remake_lab_12;

    void setupUi(QWidget *materialStorgeWidget)
    {
        if (materialStorgeWidget->objectName().isEmpty())
            materialStorgeWidget->setObjectName(QStringLiteral("materialStorgeWidget"));
        materialStorgeWidget->resize(600, 673);
        materialStorgeWidget->setMinimumSize(QSize(600, 673));
        materialStorgeWidget->setMaximumSize(QSize(600, 700));
        verticalLayout = new QVBoxLayout(materialStorgeWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(6, 6, 6, 6);
        pop_widget_title = new QWidget(materialStorgeWidget);
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

        widget = new QWidget(materialStorgeWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        pop_cancle_btn = new QPushButton(widget);
        pop_cancle_btn->setObjectName(QStringLiteral("pop_cancle_btn"));
        pop_cancle_btn->setGeometry(QRect(70, 540, 95, 32));
        pop_commit_btn = new QPushButton(widget);
        pop_commit_btn->setObjectName(QStringLiteral("pop_commit_btn"));
        pop_commit_btn->setGeometry(QRect(420, 540, 95, 32));
        remake_lab_2 = new QLabel(widget);
        remake_lab_2->setObjectName(QStringLiteral("remake_lab_2"));
        remake_lab_2->setGeometry(QRect(30, 40, 81, 28));
        remake_lab_2->setStyleSheet(QString::fromUtf8("color: rgb(117, 117, 117);\n"
"font: 75 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        remake_lab_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        dateEdit = new QDateEdit(widget);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(120, 40, 161, 28));
        dateEdit->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        use_Edit = new QLineEdit(widget);
        use_Edit->setObjectName(QStringLiteral("use_Edit"));
        use_Edit->setGeometry(QRect(360, 40, 161, 28));
        remake_lab_4 = new QLabel(widget);
        remake_lab_4->setObjectName(QStringLiteral("remake_lab_4"));
        remake_lab_4->setGeometry(QRect(270, 40, 81, 28));
        remake_lab_4->setStyleSheet(QString::fromUtf8("color: rgb(117, 117, 117);\n"
"font: 75 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        remake_lab_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        remake_lab_5 = new QLabel(widget);
        remake_lab_5->setObjectName(QStringLiteral("remake_lab_5"));
        remake_lab_5->setGeometry(QRect(30, 100, 81, 28));
        remake_lab_5->setStyleSheet(QString::fromUtf8("color: rgb(117, 117, 117);\n"
"font: 75 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        remake_lab_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        remake_lab_6 = new QLabel(widget);
        remake_lab_6->setObjectName(QStringLiteral("remake_lab_6"));
        remake_lab_6->setGeometry(QRect(270, 160, 81, 28));
        remake_lab_6->setStyleSheet(QString::fromUtf8("color: rgb(117, 117, 117);\n"
"font: 75 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        remake_lab_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        subject_name_Edit = new QLineEdit(widget);
        subject_name_Edit->setObjectName(QStringLiteral("subject_name_Edit"));
        subject_name_Edit->setGeometry(QRect(120, 100, 161, 28));
        unit_Edit = new QLineEdit(widget);
        unit_Edit->setObjectName(QStringLiteral("unit_Edit"));
        unit_Edit->setGeometry(QRect(360, 160, 161, 28));
        unit_Edit->setFrame(true);
        error_lab = new QLabel(widget);
        error_lab->setObjectName(QStringLiteral("error_lab"));
        error_lab->setGeometry(QRect(90, 450, 381, 28));
        error_lab->setStyleSheet(QString::fromUtf8("font: 75 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 85, 0);"));
        subject_Edit = new QLineEdit(widget);
        subject_Edit->setObjectName(QStringLiteral("subject_Edit"));
        subject_Edit->setGeometry(QRect(360, 100, 161, 28));
        remake_lab_8 = new QLabel(widget);
        remake_lab_8->setObjectName(QStringLiteral("remake_lab_8"));
        remake_lab_8->setGeometry(QRect(270, 100, 81, 28));
        remake_lab_8->setStyleSheet(QString::fromUtf8("color: rgb(117, 117, 117);\n"
"font: 75 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        remake_lab_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        remake_lab_9 = new QLabel(widget);
        remake_lab_9->setObjectName(QStringLiteral("remake_lab_9"));
        remake_lab_9->setGeometry(QRect(270, 210, 81, 28));
        remake_lab_9->setStyleSheet(QString::fromUtf8("color: rgb(117, 117, 117);\n"
"font: 75 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        remake_lab_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        freight_Edit = new QLineEdit(widget);
        freight_Edit->setObjectName(QStringLiteral("freight_Edit"));
        freight_Edit->setGeometry(QRect(360, 210, 161, 28));
        remake_lab_10 = new QLabel(widget);
        remake_lab_10->setObjectName(QStringLiteral("remake_lab_10"));
        remake_lab_10->setGeometry(QRect(30, 160, 81, 28));
        remake_lab_10->setStyleSheet(QString::fromUtf8("color: rgb(117, 117, 117);\n"
"font: 75 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        remake_lab_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pice_Edit = new QLineEdit(widget);
        pice_Edit->setObjectName(QStringLiteral("pice_Edit"));
        pice_Edit->setGeometry(QRect(120, 160, 161, 28));
        pice_Edit->setFrame(true);
        Number_Edit = new QLineEdit(widget);
        Number_Edit->setObjectName(QStringLiteral("Number_Edit"));
        Number_Edit->setGeometry(QRect(120, 280, 161, 28));
        Number_Edit->setFrame(true);
        remake_lab_11 = new QLabel(widget);
        remake_lab_11->setObjectName(QStringLiteral("remake_lab_11"));
        remake_lab_11->setGeometry(QRect(30, 280, 81, 28));
        remake_lab_11->setStyleSheet(QString::fromUtf8("color: rgb(117, 117, 117);\n"
"font: 75 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        remake_lab_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        norms_Edit = new QLineEdit(widget);
        norms_Edit->setObjectName(QStringLiteral("norms_Edit"));
        norms_Edit->setGeometry(QRect(120, 220, 161, 28));
        norms_Edit->setFrame(true);
        remake_lab_12 = new QLabel(widget);
        remake_lab_12->setObjectName(QStringLiteral("remake_lab_12"));
        remake_lab_12->setGeometry(QRect(30, 220, 81, 28));
        remake_lab_12->setStyleSheet(QString::fromUtf8("color: rgb(117, 117, 117);\n"
"font: 75 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        remake_lab_12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(widget);


        retranslateUi(materialStorgeWidget);

        QMetaObject::connectSlotsByName(materialStorgeWidget);
    } // setupUi

    void retranslateUi(QWidget *materialStorgeWidget)
    {
        materialStorgeWidget->setWindowTitle(QApplication::translate("materialStorgeWidget", "\345\205\245\345\272\223\347\256\241\347\220\206", Q_NULLPTR));
        pop_close_btn->setText(QString());
        pop_min_btn->setText(QString());
        title_lab->setText(QApplication::translate("materialStorgeWidget", "\345\205\245\345\272\223\347\256\241\347\220\206", Q_NULLPTR));
        pop_cancle_btn->setText(QString());
        pop_commit_btn->setText(QString());
        remake_lab_2->setText(QApplication::translate("materialStorgeWidget", "\346\227\245\346\234\237\357\274\232", Q_NULLPTR));
        use_Edit->setText(QString());
        remake_lab_4->setText(QApplication::translate("materialStorgeWidget", "\347\224\250\351\200\224\357\274\232", Q_NULLPTR));
        remake_lab_5->setText(QApplication::translate("materialStorgeWidget", "\347\211\251\345\223\201\345\220\215\347\247\260\357\274\232", Q_NULLPTR));
        remake_lab_6->setText(QApplication::translate("materialStorgeWidget", "\345\215\225\344\275\215\357\274\232", Q_NULLPTR));
        error_lab->setText(QApplication::translate("materialStorgeWidget", "\346\234\211\351\200\211\351\241\271\344\270\272\347\251\272\357\274\214\350\257\267\346\240\270\345\256\236\357\274\201", Q_NULLPTR));
        remake_lab_8->setText(QApplication::translate("materialStorgeWidget", "\347\261\273\345\210\253\357\274\232", Q_NULLPTR));
        remake_lab_9->setText(QApplication::translate("materialStorgeWidget", "\350\277\220\350\264\271\357\274\232", Q_NULLPTR));
        freight_Edit->setText(QApplication::translate("materialStorgeWidget", "0", Q_NULLPTR));
        remake_lab_10->setText(QApplication::translate("materialStorgeWidget", "\346\210\220\346\234\254\344\273\267\346\240\274\357\274\232", Q_NULLPTR));
        pice_Edit->setText(QApplication::translate("materialStorgeWidget", "0", Q_NULLPTR));
        Number_Edit->setText(QApplication::translate("materialStorgeWidget", "0", Q_NULLPTR));
        remake_lab_11->setText(QApplication::translate("materialStorgeWidget", "\346\225\260\351\207\217\357\274\232", Q_NULLPTR));
        norms_Edit->setText(QString());
        remake_lab_12->setText(QApplication::translate("materialStorgeWidget", "\347\211\251\345\223\201\350\247\204\346\240\274\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class materialStorgeWidget: public Ui_materialStorgeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATERIALSTORGEWIDGET_H
