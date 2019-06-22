/********************************************************************************
** Form generated from reading UI file 'MaterialQWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATERIALQWIDGET_H
#define UI_MATERIALQWIDGET_H

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

class Ui_Material
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *child_widget_title;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *material_min_btn;
    QPushButton *material_max_restore_btn;
    QPushButton *material_cose_btn;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_2;
    NavButton *material_detail_opt;
    NavButton *material_incom_opt;
    NavButton *material_out_opt;
    NavButton *fixacc_opt;
    QLabel *label;
    QStackedWidget *material_stackedWidget;
    QWidget *page;
    QPushButton *pushButton;
    QWidget *page_2;
    QPushButton *pushButton_2;
    QWidget *page_3;
    QPushButton *pushButton_3;
    QWidget *page_4;
    QPushButton *pushButton_4;

    void setupUi(QWidget *Material)
    {
        if (Material->objectName().isEmpty())
            Material->setObjectName(QStringLiteral("Material"));
        Material->resize(960, 640);
        Material->setMinimumSize(QSize(960, 640));
        verticalLayout = new QVBoxLayout(Material);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(1, 1, 1, 1);
        child_widget_title = new QWidget(Material);
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

        material_min_btn = new QPushButton(child_widget_title);
        material_min_btn->setObjectName(QStringLiteral("material_min_btn"));
        material_min_btn->setMinimumSize(QSize(32, 23));

        horizontalLayout_2->addWidget(material_min_btn);

        material_max_restore_btn = new QPushButton(child_widget_title);
        material_max_restore_btn->setObjectName(QStringLiteral("material_max_restore_btn"));
        material_max_restore_btn->setMinimumSize(QSize(32, 23));

        horizontalLayout_2->addWidget(material_max_restore_btn);

        material_cose_btn = new QPushButton(child_widget_title);
        material_cose_btn->setObjectName(QStringLiteral("material_cose_btn"));
        material_cose_btn->setMinimumSize(QSize(32, 23));

        horizontalLayout_2->addWidget(material_cose_btn);


        verticalLayout->addWidget(child_widget_title);

        widget = new QWidget(Material);
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
        material_detail_opt = new NavButton(widget_2);
        material_detail_opt->setObjectName(QStringLiteral("material_detail_opt"));
        material_detail_opt->setGeometry(QRect(10, 90, 140, 35));
        material_incom_opt = new NavButton(widget_2);
        material_incom_opt->setObjectName(QStringLiteral("material_incom_opt"));
        material_incom_opt->setGeometry(QRect(10, 140, 140, 35));
        material_out_opt = new NavButton(widget_2);
        material_out_opt->setObjectName(QStringLiteral("material_out_opt"));
        material_out_opt->setGeometry(QRect(10, 190, 140, 35));
        fixacc_opt = new NavButton(widget_2);
        fixacc_opt->setObjectName(QStringLiteral("fixacc_opt"));
        fixacc_opt->setGeometry(QRect(10, 240, 140, 35));

        horizontalLayout->addWidget(widget_2);

        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(1, 0));
        label->setMaximumSize(QSize(1, 16777215));
        label->setStyleSheet(QStringLiteral("background-color: rgb(41, 57, 85);"));

        horizontalLayout->addWidget(label);

        material_stackedWidget = new QStackedWidget(widget);
        material_stackedWidget->setObjectName(QStringLiteral("material_stackedWidget"));
        material_stackedWidget->setMinimumSize(QSize(768, 581));
        material_stackedWidget->setStyleSheet(QStringLiteral("background-color: rgb(54, 78, 111);"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        pushButton = new QPushButton(page);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(90, 30, 75, 23));
        material_stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        pushButton_2 = new QPushButton(page_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(60, 70, 75, 23));
        material_stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        pushButton_3 = new QPushButton(page_3);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(200, 20, 75, 23));
        material_stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        pushButton_4 = new QPushButton(page_4);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(310, 190, 75, 23));
        material_stackedWidget->addWidget(page_4);

        horizontalLayout->addWidget(material_stackedWidget);


        verticalLayout->addWidget(widget);


        retranslateUi(Material);

        QMetaObject::connectSlotsByName(Material);
    } // setupUi

    void retranslateUi(QWidget *Material)
    {
        Material->setWindowTitle(QApplication::translate("Material", "Form", Q_NULLPTR));
        material_min_btn->setText(QString());
        material_max_restore_btn->setText(QString());
        material_cose_btn->setText(QString());
        material_detail_opt->setText(QApplication::translate("Material", "\347\211\251\346\226\231\346\230\216\347\273\206", Q_NULLPTR));
        material_incom_opt->setText(QApplication::translate("Material", "\347\211\251\346\226\231\345\205\245\345\272\223", Q_NULLPTR));
        material_out_opt->setText(QApplication::translate("Material", "\347\211\251\346\226\231\345\207\272\345\272\223", Q_NULLPTR));
        fixacc_opt->setText(QApplication::translate("Material", "\345\233\272\345\256\232\350\265\204\344\272\247", Q_NULLPTR));
        label->setText(QApplication::translate("Material", "TextLabel", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Material", "PushButton", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Material", "PushButton", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("Material", "PushButton", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("Material", "PushButton", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Material: public Ui_Material {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATERIALQWIDGET_H
