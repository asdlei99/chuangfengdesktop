/********************************************************************************
** Form generated from reading UI file 'ChuangfengDesktop.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHUANGFENGDESKTOP_H
#define UI_CHUANGFENGDESKTOP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChuangfengDesktopClass
{
public:
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QWidget *main_title_widget;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QWidget *main_wnd_ctrl_widget;
    QPushButton *min_btn;
    QPushButton *max_restore_btn;
    QPushButton *close_btn;
    QVBoxLayout *verticalLayout;
    QStackedWidget *main_stackedWidget;
    QWidget *page;
    QWidget *page_2;

    void setupUi(QWidget *ChuangfengDesktopClass)
    {
        if (ChuangfengDesktopClass->objectName().isEmpty())
            ChuangfengDesktopClass->setObjectName(QStringLiteral("ChuangfengDesktopClass"));
        ChuangfengDesktopClass->resize(1090, 582);
        ChuangfengDesktopClass->setMinimumSize(QSize(1090, 580));
        verticalLayout_4 = new QVBoxLayout(ChuangfengDesktopClass);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(2, 2, 2, 2);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        main_title_widget = new QWidget(ChuangfengDesktopClass);
        main_title_widget->setObjectName(QStringLiteral("main_title_widget"));
        main_title_widget->setMinimumSize(QSize(0, 82));
        main_title_widget->setMaximumSize(QSize(16777215, 82));
        main_title_widget->setBaseSize(QSize(0, 82));
        horizontalLayout_5 = new QHBoxLayout(main_title_widget);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        widget_2 = new QWidget(main_title_widget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMinimumSize(QSize(90, 0));
        widget_2->setMaximumSize(QSize(90, 16777215));

        horizontalLayout_2->addWidget(widget_2);


        horizontalLayout_5->addLayout(horizontalLayout_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        widget_3 = new QWidget(main_title_widget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMinimumSize(QSize(140, 0));
        widget_3->setMaximumSize(QSize(140, 16777215));

        verticalLayout_2->addWidget(widget_3);


        horizontalLayout_5->addLayout(verticalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        horizontalLayout_5->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        main_wnd_ctrl_widget = new QWidget(main_title_widget);
        main_wnd_ctrl_widget->setObjectName(QStringLiteral("main_wnd_ctrl_widget"));
        main_wnd_ctrl_widget->setMinimumSize(QSize(90, 0));
        main_wnd_ctrl_widget->setMaximumSize(QSize(90, 82));
        min_btn = new QPushButton(main_wnd_ctrl_widget);
        min_btn->setObjectName(QStringLiteral("min_btn"));
        min_btn->setGeometry(QRect(0, 0, 30, 23));
        max_restore_btn = new QPushButton(main_wnd_ctrl_widget);
        max_restore_btn->setObjectName(QStringLiteral("max_restore_btn"));
        max_restore_btn->setGeometry(QRect(30, 0, 30, 23));
        close_btn = new QPushButton(main_wnd_ctrl_widget);
        close_btn->setObjectName(QStringLiteral("close_btn"));
        close_btn->setGeometry(QRect(60, 0, 30, 23));

        horizontalLayout_4->addWidget(main_wnd_ctrl_widget);


        horizontalLayout_5->addLayout(horizontalLayout_4);


        horizontalLayout->addWidget(main_title_widget);


        verticalLayout_4->addLayout(horizontalLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        main_stackedWidget = new QStackedWidget(ChuangfengDesktopClass);
        main_stackedWidget->setObjectName(QStringLiteral("main_stackedWidget"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        main_stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        main_stackedWidget->addWidget(page_2);

        verticalLayout->addWidget(main_stackedWidget);


        verticalLayout_4->addLayout(verticalLayout);


        retranslateUi(ChuangfengDesktopClass);

        QMetaObject::connectSlotsByName(ChuangfengDesktopClass);
    } // setupUi

    void retranslateUi(QWidget *ChuangfengDesktopClass)
    {
        ChuangfengDesktopClass->setWindowTitle(QApplication::translate("ChuangfengDesktopClass", "\345\210\233\344\270\260\345\205\273\346\256\226", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        min_btn->setToolTip(QApplication::translate("ChuangfengDesktopClass", "\346\234\200\345\260\217\345\214\226", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        min_btn->setText(QString());
        max_restore_btn->setText(QString());
#ifndef QT_NO_TOOLTIP
        close_btn->setToolTip(QApplication::translate("ChuangfengDesktopClass", "\345\205\263\351\227\255", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        close_btn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ChuangfengDesktopClass: public Ui_ChuangfengDesktopClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHUANGFENGDESKTOP_H
