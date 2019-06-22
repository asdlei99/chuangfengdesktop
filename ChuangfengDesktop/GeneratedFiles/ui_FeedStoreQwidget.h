/********************************************************************************
** Form generated from reading UI file 'FeedStoreQwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FEEDSTOREQWIDGET_H
#define UI_FEEDSTOREQWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qnavbutton.h>

QT_BEGIN_NAMESPACE

class Ui_FeedStore
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *child_widget_title;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *feedstore_min_btn;
    QPushButton *feedstore_max_restore_btn;
    QPushButton *feedstore_cose_btn;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_2;
    NavButton *feedstore_detail_opt;
    NavButton *feedstore_incom_opt;
    NavButton *feedstore_out_opt;
    NavButton *feedstore_return_opt;
    NavButton *area_detail_opt;
    NavButton *area_return_opt;
    QLabel *label;
    QStackedWidget *feedstore_stackedWidget;
    QWidget *page_6;
    QPushButton *pushButton_6;
    QWidget *page_5;
    QPushButton *pushButton_5;
    QWidget *page;
    QPushButton *pushButton;
    QWidget *page_2;
    QPushButton *pushButton_2;
    QWidget *page_3;
    QPushButton *pushButton_3;
    QWidget *page_4;
    QPushButton *pushButton_4;

    void setupUi(QWidget *FeedStore)
    {
        if (FeedStore->objectName().isEmpty())
            FeedStore->setObjectName(QStringLiteral("FeedStore"));
        FeedStore->resize(960, 640);
        FeedStore->setMinimumSize(QSize(960, 640));
        verticalLayout = new QVBoxLayout(FeedStore);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(1, 1, 1, 1);
        child_widget_title = new QWidget(FeedStore);
        child_widget_title->setObjectName(QStringLiteral("child_widget_title"));
        child_widget_title->setMinimumSize(QSize(0, 40));
        child_widget_title->setMaximumSize(QSize(16777215, 40));
        child_widget_title->setStyleSheet(QStringLiteral(""));
        horizontalLayout_2 = new QHBoxLayout(child_widget_title);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        feedstore_min_btn = new QPushButton(child_widget_title);
        feedstore_min_btn->setObjectName(QStringLiteral("feedstore_min_btn"));
        feedstore_min_btn->setMinimumSize(QSize(32, 23));

        horizontalLayout_2->addWidget(feedstore_min_btn);

        feedstore_max_restore_btn = new QPushButton(child_widget_title);
        feedstore_max_restore_btn->setObjectName(QStringLiteral("feedstore_max_restore_btn"));
        feedstore_max_restore_btn->setMinimumSize(QSize(32, 23));

        horizontalLayout_2->addWidget(feedstore_max_restore_btn);

        feedstore_cose_btn = new QPushButton(child_widget_title);
        feedstore_cose_btn->setObjectName(QStringLiteral("feedstore_cose_btn"));
        feedstore_cose_btn->setMinimumSize(QSize(32, 23));

        horizontalLayout_2->addWidget(feedstore_cose_btn);


        verticalLayout->addWidget(child_widget_title);

        widget = new QWidget(FeedStore);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setStyleSheet(QStringLiteral(""));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(1);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMinimumSize(QSize(160, 0));
        widget_2->setStyleSheet(QStringLiteral("background-color: rgb(54, 78, 111);"));
        feedstore_detail_opt = new NavButton(widget_2);
        feedstore_detail_opt->setObjectName(QStringLiteral("feedstore_detail_opt"));
        feedstore_detail_opt->setGeometry(QRect(10, 90, 140, 35));
        feedstore_incom_opt = new NavButton(widget_2);
        feedstore_incom_opt->setObjectName(QStringLiteral("feedstore_incom_opt"));
        feedstore_incom_opt->setGeometry(QRect(10, 140, 140, 35));
        feedstore_out_opt = new NavButton(widget_2);
        feedstore_out_opt->setObjectName(QStringLiteral("feedstore_out_opt"));
        feedstore_out_opt->setGeometry(QRect(10, 190, 140, 35));
        feedstore_return_opt = new NavButton(widget_2);
        feedstore_return_opt->setObjectName(QStringLiteral("feedstore_return_opt"));
        feedstore_return_opt->setGeometry(QRect(10, 240, 140, 35));
        area_detail_opt = new NavButton(widget_2);
        area_detail_opt->setObjectName(QStringLiteral("area_detail_opt"));
        area_detail_opt->setGeometry(QRect(10, 290, 140, 35));
        area_return_opt = new NavButton(widget_2);
        area_return_opt->setObjectName(QStringLiteral("area_return_opt"));
        area_return_opt->setGeometry(QRect(10, 340, 140, 35));

        horizontalLayout->addWidget(widget_2);

        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(1, 0));
        label->setMaximumSize(QSize(1, 16777215));
        label->setStyleSheet(QStringLiteral("background-color: rgb(41, 57, 86);"));

        horizontalLayout->addWidget(label);

        feedstore_stackedWidget = new QStackedWidget(widget);
        feedstore_stackedWidget->setObjectName(QStringLiteral("feedstore_stackedWidget"));
        feedstore_stackedWidget->setMinimumSize(QSize(768, 581));
        feedstore_stackedWidget->setStyleSheet(QStringLiteral("background-color: rgb(54, 78, 111);"));
        page_6 = new QWidget();
        page_6->setObjectName(QStringLiteral("page_6"));
        pushButton_6 = new QPushButton(page_6);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(530, 170, 75, 23));
        feedstore_stackedWidget->addWidget(page_6);
        page_5 = new QWidget();
        page_5->setObjectName(QStringLiteral("page_5"));
        pushButton_5 = new QPushButton(page_5);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(540, 400, 75, 23));
        feedstore_stackedWidget->addWidget(page_5);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        pushButton = new QPushButton(page);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(90, 30, 75, 23));
        feedstore_stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        pushButton_2 = new QPushButton(page_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(60, 70, 75, 23));
        feedstore_stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        pushButton_3 = new QPushButton(page_3);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(200, 20, 75, 23));
        feedstore_stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        pushButton_4 = new QPushButton(page_4);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(310, 190, 75, 23));
        feedstore_stackedWidget->addWidget(page_4);

        horizontalLayout->addWidget(feedstore_stackedWidget);


        verticalLayout->addWidget(widget);


        retranslateUi(FeedStore);

        QMetaObject::connectSlotsByName(FeedStore);
    } // setupUi

    void retranslateUi(QWidget *FeedStore)
    {
        FeedStore->setWindowTitle(QApplication::translate("FeedStore", "Form", Q_NULLPTR));
        feedstore_min_btn->setText(QString());
        feedstore_max_restore_btn->setText(QString());
        feedstore_cose_btn->setText(QString());
        feedstore_detail_opt->setText(QApplication::translate("FeedStore", "\351\245\262\346\226\231\350\215\257\345\223\201\344\273\223\345\272\223\346\230\216\347\273\206", Q_NULLPTR));
        feedstore_incom_opt->setText(QApplication::translate("FeedStore", "\345\205\245\345\272\223", Q_NULLPTR));
        feedstore_out_opt->setText(QApplication::translate("FeedStore", "\345\207\272\345\272\223", Q_NULLPTR));
        feedstore_return_opt->setText(QApplication::translate("FeedStore", "\351\200\200\350\264\247", Q_NULLPTR));
        area_detail_opt->setText(QApplication::translate("FeedStore", "\345\210\206\344\273\223\346\230\216\347\273\206", Q_NULLPTR));
        area_return_opt->setText(QApplication::translate("FeedStore", "\345\210\206\344\273\223\351\200\200\345\272\223", Q_NULLPTR));
        label->setText(QApplication::translate("FeedStore", "TextLabel", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("FeedStore", "PushButton", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("FeedStore", "PushButton", Q_NULLPTR));
        pushButton->setText(QApplication::translate("FeedStore", "PushButton", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("FeedStore", "PushButton", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("FeedStore", "PushButton", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("FeedStore", "PushButton", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FeedStore: public Ui_FeedStore {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FEEDSTOREQWIDGET_H
