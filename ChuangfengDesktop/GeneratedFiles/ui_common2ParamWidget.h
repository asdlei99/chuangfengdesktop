/********************************************************************************
** Form generated from reading UI file 'common2ParamWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMON2PARAMWIDGET_H
#define UI_COMMON2PARAMWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Common2ParamWidget
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
    QLabel *tagName_lab;
    QLineEdit *tag_name_Edit;
    QLineEdit *remake_Edit;
    QLabel *remake_lab;
    QLabel *error_lab;

    void setupUi(QWidget *Common2ParamWidget)
    {
        if (Common2ParamWidget->objectName().isEmpty())
            Common2ParamWidget->setObjectName(QStringLiteral("Common2ParamWidget"));
        Common2ParamWidget->resize(600, 673);
        Common2ParamWidget->setMinimumSize(QSize(600, 673));
        Common2ParamWidget->setMaximumSize(QSize(600, 700));
        QIcon icon;
        icon.addFile(QStringLiteral("Resources/test.png"), QSize(), QIcon::Normal, QIcon::Off);
        Common2ParamWidget->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(Common2ParamWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(6, 6, 6, 6);
        pop_widget_title = new QWidget(Common2ParamWidget);
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

        widget = new QWidget(Common2ParamWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        pop_cancle_btn = new QPushButton(widget);
        pop_cancle_btn->setObjectName(QStringLiteral("pop_cancle_btn"));
        pop_cancle_btn->setGeometry(QRect(70, 540, 95, 32));
        pop_commit_btn = new QPushButton(widget);
        pop_commit_btn->setObjectName(QStringLiteral("pop_commit_btn"));
        pop_commit_btn->setGeometry(QRect(420, 540, 95, 32));
        tagName_lab = new QLabel(widget);
        tagName_lab->setObjectName(QStringLiteral("tagName_lab"));
        tagName_lab->setGeometry(QRect(80, 50, 81, 28));
        tagName_lab->setStyleSheet(QString::fromUtf8("color: rgb(117, 117, 117);\n"
"font: 75 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        tagName_lab->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        tag_name_Edit = new QLineEdit(widget);
        tag_name_Edit->setObjectName(QStringLiteral("tag_name_Edit"));
        tag_name_Edit->setGeometry(QRect(170, 50, 161, 28));
        remake_Edit = new QLineEdit(widget);
        remake_Edit->setObjectName(QStringLiteral("remake_Edit"));
        remake_Edit->setGeometry(QRect(170, 100, 161, 28));
        remake_lab = new QLabel(widget);
        remake_lab->setObjectName(QStringLiteral("remake_lab"));
        remake_lab->setGeometry(QRect(80, 100, 81, 28));
        remake_lab->setStyleSheet(QString::fromUtf8("color: rgb(117, 117, 117);\n"
"font: 75 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        remake_lab->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        error_lab = new QLabel(widget);
        error_lab->setObjectName(QStringLiteral("error_lab"));
        error_lab->setGeometry(QRect(140, 410, 381, 28));
        error_lab->setStyleSheet(QString::fromUtf8("font: 75 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 85, 0);"));

        verticalLayout->addWidget(widget);


        retranslateUi(Common2ParamWidget);

        QMetaObject::connectSlotsByName(Common2ParamWidget);
    } // setupUi

    void retranslateUi(QWidget *Common2ParamWidget)
    {
        Common2ParamWidget->setWindowTitle(QApplication::translate("Common2ParamWidget", "Form", Q_NULLPTR));
        pop_close_btn->setText(QString());
        pop_min_btn->setText(QString());
        title_lab->setText(QString());
        pop_cancle_btn->setText(QString());
        pop_commit_btn->setText(QString());
        tagName_lab->setText(QString());
        remake_lab->setText(QApplication::translate("Common2ParamWidget", "\345\244\207\346\263\250\357\274\232", Q_NULLPTR));
        error_lab->setText(QApplication::translate("Common2ParamWidget", "\347\261\273\347\233\256\344\270\215\350\203\275\344\270\272\347\251\272\357\274\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Common2ParamWidget: public Ui_Common2ParamWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMON2PARAMWIDGET_H
