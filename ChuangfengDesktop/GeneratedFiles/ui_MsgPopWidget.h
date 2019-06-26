/********************************************************************************
** Form generated from reading UI file 'MsgPopWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MSGPOPWIDGET_H
#define UI_MSGPOPWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MsgPopWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *pop_widget_title;
    QPushButton *pop_close_btn;
    QLabel *title_lab;
    QWidget *widget;
    QPushButton *pop_commit_btn;
    QLabel *ico_lab;
    QLabel *msg_label;
    QLabel *error_code_lab;

    void setupUi(QWidget *MsgPopWidget)
    {
        if (MsgPopWidget->objectName().isEmpty())
            MsgPopWidget->setObjectName(QStringLiteral("MsgPopWidget"));
        MsgPopWidget->resize(439, 248);
        MsgPopWidget->setMinimumSize(QSize(439, 248));
        MsgPopWidget->setMaximumSize(QSize(439, 248));
        verticalLayout = new QVBoxLayout(MsgPopWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(6, 6, 6, 6);
        pop_widget_title = new QWidget(MsgPopWidget);
        pop_widget_title->setObjectName(QStringLiteral("pop_widget_title"));
        pop_widget_title->setMinimumSize(QSize(0, 30));
        pop_widget_title->setMaximumSize(QSize(16777214, 35));
        pop_close_btn = new QPushButton(pop_widget_title);
        pop_close_btn->setObjectName(QStringLiteral("pop_close_btn"));
        pop_close_btn->setGeometry(QRect(400, 3, 24, 24));
        title_lab = new QLabel(pop_widget_title);
        title_lab->setObjectName(QStringLiteral("title_lab"));
        title_lab->setGeometry(QRect(10, 1, 71, 28));
        title_lab->setStyleSheet(QString::fromUtf8("font: 75 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 200, 255);"));

        verticalLayout->addWidget(pop_widget_title);

        widget = new QWidget(MsgPopWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        pop_commit_btn = new QPushButton(widget);
        pop_commit_btn->setObjectName(QStringLiteral("pop_commit_btn"));
        pop_commit_btn->setGeometry(QRect(300, 140, 95, 32));
        ico_lab = new QLabel(widget);
        ico_lab->setObjectName(QStringLiteral("ico_lab"));
        ico_lab->setGeometry(QRect(40, 50, 50, 50));
        msg_label = new QLabel(widget);
        msg_label->setObjectName(QStringLiteral("msg_label"));
        msg_label->setGeometry(QRect(130, 30, 261, 28));
        msg_label->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        error_code_lab = new QLabel(widget);
        error_code_lab->setObjectName(QStringLiteral("error_code_lab"));
        error_code_lab->setGeometry(QRect(130, 70, 261, 28));
        error_code_lab->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(170, 0, 0);"));

        verticalLayout->addWidget(widget);


        retranslateUi(MsgPopWidget);

        QMetaObject::connectSlotsByName(MsgPopWidget);
    } // setupUi

    void retranslateUi(QWidget *MsgPopWidget)
    {
        MsgPopWidget->setWindowTitle(QApplication::translate("MsgPopWidget", "Form", Q_NULLPTR));
        pop_close_btn->setText(QString());
        title_lab->setText(QApplication::translate("MsgPopWidget", "\346\217\220\347\244\272", Q_NULLPTR));
        pop_commit_btn->setText(QString());
        ico_lab->setText(QString());
        msg_label->setText(QString());
        error_code_lab->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MsgPopWidget: public Ui_MsgPopWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MSGPOPWIDGET_H
