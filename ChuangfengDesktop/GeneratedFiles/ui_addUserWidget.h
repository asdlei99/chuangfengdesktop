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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_adduserWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *pop_widget_title;
    QPushButton *pop_cloase_btn;
    QPushButton *pop_min_btn;
    QWidget *widget;
    QPushButton *pop_cancle_btn;

    void setupUi(QWidget *adduserWidget)
    {
        if (adduserWidget->objectName().isEmpty())
            adduserWidget->setObjectName(QStringLiteral("adduserWidget"));
        adduserWidget->resize(600, 673);
        adduserWidget->setMinimumSize(QSize(600, 673));
        adduserWidget->setMaximumSize(QSize(600, 700));
        verticalLayout = new QVBoxLayout(adduserWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(6, 6, 6, 6);
        pop_widget_title = new QWidget(adduserWidget);
        pop_widget_title->setObjectName(QStringLiteral("pop_widget_title"));
        pop_widget_title->setMinimumSize(QSize(0, 35));
        pop_widget_title->setMaximumSize(QSize(16777214, 35));
        pop_cloase_btn = new QPushButton(pop_widget_title);
        pop_cloase_btn->setObjectName(QStringLiteral("pop_cloase_btn"));
        pop_cloase_btn->setGeometry(QRect(560, 6, 24, 24));
        pop_min_btn = new QPushButton(pop_widget_title);
        pop_min_btn->setObjectName(QStringLiteral("pop_min_btn"));
        pop_min_btn->setGeometry(QRect(535, 6, 24, 24));

        verticalLayout->addWidget(pop_widget_title);

        widget = new QWidget(adduserWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        pop_cancle_btn = new QPushButton(widget);
        pop_cancle_btn->setObjectName(QStringLiteral("pop_cancle_btn"));
        pop_cancle_btn->setGeometry(QRect(100, 470, 100, 35));

        verticalLayout->addWidget(widget);


        retranslateUi(adduserWidget);

        QMetaObject::connectSlotsByName(adduserWidget);
    } // setupUi

    void retranslateUi(QWidget *adduserWidget)
    {
        adduserWidget->setWindowTitle(QApplication::translate("adduserWidget", "Form", Q_NULLPTR));
        pop_cloase_btn->setText(QString());
        pop_min_btn->setText(QString());
        pop_cancle_btn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class adduserWidget: public Ui_adduserWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDUSERWIDGET_H
