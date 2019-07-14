/********************************************************************************
** Form generated from reading UI file 'DescMaterialWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DESCMATERIALWIDGET_H
#define UI_DESCMATERIALWIDGET_H

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

class Ui_DescMaterialWidget
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
    QLabel *remake_lab_5;
    QLineEdit *subject_name_Edit;
    QLabel *error_lab;
    QLabel *remake_lab_10;
    QLineEdit *pice_Edit;
    QLineEdit *Number_Edit;
    QLabel *remake_lab_11;
    QLabel *remake_lab_12;
    QComboBox *comboBox;

    void setupUi(QWidget *DescMaterialWidget)
    {
        if (DescMaterialWidget->objectName().isEmpty())
            DescMaterialWidget->setObjectName(QStringLiteral("DescMaterialWidget"));
        DescMaterialWidget->resize(600, 673);
        DescMaterialWidget->setMinimumSize(QSize(600, 673));
        DescMaterialWidget->setMaximumSize(QSize(600, 700));
        QIcon icon;
        icon.addFile(QStringLiteral("Resources/test.png"), QSize(), QIcon::Normal, QIcon::Off);
        DescMaterialWidget->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(DescMaterialWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(6, 6, 6, 6);
        pop_widget_title = new QWidget(DescMaterialWidget);
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

        widget = new QWidget(DescMaterialWidget);
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
        remake_lab_2->setGeometry(QRect(100, 40, 81, 28));
        remake_lab_2->setStyleSheet(QString::fromUtf8("color: rgb(117, 117, 117);\n"
"font: 75 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        remake_lab_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        dateEdit = new QDateEdit(widget);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(190, 40, 161, 28));
        dateEdit->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        remake_lab_5 = new QLabel(widget);
        remake_lab_5->setObjectName(QStringLiteral("remake_lab_5"));
        remake_lab_5->setGeometry(QRect(100, 100, 81, 28));
        remake_lab_5->setStyleSheet(QString::fromUtf8("color: rgb(117, 117, 117);\n"
"font: 75 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        remake_lab_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        subject_name_Edit = new QLineEdit(widget);
        subject_name_Edit->setObjectName(QStringLiteral("subject_name_Edit"));
        subject_name_Edit->setGeometry(QRect(190, 100, 161, 28));
        subject_name_Edit->setReadOnly(true);
        error_lab = new QLabel(widget);
        error_lab->setObjectName(QStringLiteral("error_lab"));
        error_lab->setGeometry(QRect(90, 450, 381, 28));
        error_lab->setStyleSheet(QString::fromUtf8("font: 75 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 85, 0);"));
        remake_lab_10 = new QLabel(widget);
        remake_lab_10->setObjectName(QStringLiteral("remake_lab_10"));
        remake_lab_10->setGeometry(QRect(100, 160, 81, 28));
        remake_lab_10->setStyleSheet(QString::fromUtf8("color: rgb(117, 117, 117);\n"
"font: 75 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        remake_lab_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pice_Edit = new QLineEdit(widget);
        pice_Edit->setObjectName(QStringLiteral("pice_Edit"));
        pice_Edit->setGeometry(QRect(190, 160, 161, 28));
        pice_Edit->setFrame(true);
        pice_Edit->setReadOnly(true);
        Number_Edit = new QLineEdit(widget);
        Number_Edit->setObjectName(QStringLiteral("Number_Edit"));
        Number_Edit->setGeometry(QRect(190, 220, 161, 28));
        Number_Edit->setFrame(true);
        remake_lab_11 = new QLabel(widget);
        remake_lab_11->setObjectName(QStringLiteral("remake_lab_11"));
        remake_lab_11->setGeometry(QRect(100, 220, 81, 28));
        remake_lab_11->setStyleSheet(QString::fromUtf8("color: rgb(117, 117, 117);\n"
"font: 75 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        remake_lab_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        remake_lab_12 = new QLabel(widget);
        remake_lab_12->setObjectName(QStringLiteral("remake_lab_12"));
        remake_lab_12->setGeometry(QRect(100, 280, 81, 28));
        remake_lab_12->setStyleSheet(QString::fromUtf8("color: rgb(117, 117, 117);\n"
"font: 75 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        remake_lab_12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        comboBox = new QComboBox(widget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(190, 280, 161, 28));

        verticalLayout->addWidget(widget);


        retranslateUi(DescMaterialWidget);

        QMetaObject::connectSlotsByName(DescMaterialWidget);
    } // setupUi

    void retranslateUi(QWidget *DescMaterialWidget)
    {
        DescMaterialWidget->setWindowTitle(QApplication::translate("DescMaterialWidget", "\345\207\272\345\272\223\347\256\241\347\220\206", Q_NULLPTR));
        pop_close_btn->setText(QString());
        pop_min_btn->setText(QString());
        title_lab->setText(QApplication::translate("DescMaterialWidget", "\345\207\272\345\272\223\347\256\241\347\220\206", Q_NULLPTR));
        pop_cancle_btn->setText(QString());
        pop_commit_btn->setText(QString());
        remake_lab_2->setText(QApplication::translate("DescMaterialWidget", "\346\227\245\346\234\237\357\274\232", Q_NULLPTR));
        remake_lab_5->setText(QApplication::translate("DescMaterialWidget", "\347\211\251\345\223\201\345\220\215\347\247\260\357\274\232", Q_NULLPTR));
        error_lab->setText(QApplication::translate("DescMaterialWidget", "\346\234\211\351\200\211\351\241\271\344\270\272\347\251\272\357\274\214\350\257\267\346\240\270\345\256\236\357\274\201", Q_NULLPTR));
        remake_lab_10->setText(QApplication::translate("DescMaterialWidget", "\346\210\220\346\234\254\344\273\267\346\240\274\357\274\232", Q_NULLPTR));
        remake_lab_11->setText(QApplication::translate("DescMaterialWidget", "\346\225\260\351\207\217\357\274\232", Q_NULLPTR));
        remake_lab_12->setText(QApplication::translate("DescMaterialWidget", "\351\242\206\347\224\250\345\214\272\345\237\237\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DescMaterialWidget: public Ui_DescMaterialWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DESCMATERIALWIDGET_H
