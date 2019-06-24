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
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
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
    NavButton *fixacc_opt;
    QLabel *label;
    QStackedWidget *material_stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_3;
    QPushButton *material_search_btn;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QPushButton *material_income_btn;
    QPushButton *material_out_btn;
    QPushButton *material_delete_btn;
    QTableView *tableView;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_4;
    QDateEdit *startdateEdit;
    QPushButton *material_in_out_search_btn;
    QDateEdit *enddateEdit;
    QLabel *label_4;
    QPushButton *material_in_out_delete_btn;
    QLabel *label_5;
    QTableView *material_in_out_detail_tableview;
    QWidget *page_3;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget_5;
    QPushButton *fix_material_search_btn;
    QLineEdit *fix_material_edit;
    QLabel *label_3;
    QTableView *fix_material_tableView;

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
        material_detail_opt->setGeometry(QRect(10, 80, 140, 35));
        material_incom_opt = new NavButton(widget_2);
        material_incom_opt->setObjectName(QStringLiteral("material_incom_opt"));
        material_incom_opt->setGeometry(QRect(10, 130, 140, 35));
        fixacc_opt = new NavButton(widget_2);
        fixacc_opt->setObjectName(QStringLiteral("fixacc_opt"));
        fixacc_opt->setGeometry(QRect(10, 180, 140, 35));

        horizontalLayout->addWidget(widget_2);

        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(1, 0));
        label->setMaximumSize(QSize(1, 16777215));
        label->setStyleSheet(QStringLiteral("background-color: rgb(41, 57, 85);"));

        horizontalLayout->addWidget(label);

        material_stackedWidget = new QStackedWidget(widget);
        material_stackedWidget->setObjectName(QStringLiteral("material_stackedWidget"));
        material_stackedWidget->setMinimumSize(QSize(768, 60));
        material_stackedWidget->setStyleSheet(QStringLiteral("background-color: rgb(54, 78, 111);"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        verticalLayout_2 = new QVBoxLayout(page);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        widget_3 = new QWidget(page);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMinimumSize(QSize(0, 60));
        material_search_btn = new QPushButton(widget_3);
        material_search_btn->setObjectName(QStringLiteral("material_search_btn"));
        material_search_btn->setGeometry(QRect(220, 20, 80, 28));
        label_2 = new QLabel(widget_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 20, 71, 28));
        label_2->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        lineEdit = new QLineEdit(widget_3);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(90, 20, 113, 28));
        lineEdit->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        material_income_btn = new QPushButton(widget_3);
        material_income_btn->setObjectName(QStringLiteral("material_income_btn"));
        material_income_btn->setGeometry(QRect(310, 20, 80, 28));
        material_out_btn = new QPushButton(widget_3);
        material_out_btn->setObjectName(QStringLiteral("material_out_btn"));
        material_out_btn->setGeometry(QRect(400, 20, 80, 28));
        material_delete_btn = new QPushButton(widget_3);
        material_delete_btn->setObjectName(QStringLiteral("material_delete_btn"));
        material_delete_btn->setGeometry(QRect(490, 20, 80, 28));

        verticalLayout_2->addWidget(widget_3);

        tableView = new QTableView(page);
        tableView->setObjectName(QStringLiteral("tableView"));

        verticalLayout_2->addWidget(tableView);

        material_stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        verticalLayout_3 = new QVBoxLayout(page_2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        widget_4 = new QWidget(page_2);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setMinimumSize(QSize(0, 60));
        startdateEdit = new QDateEdit(widget_4);
        startdateEdit->setObjectName(QStringLiteral("startdateEdit"));
        startdateEdit->setGeometry(QRect(80, 20, 110, 28));
        startdateEdit->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        material_in_out_search_btn = new QPushButton(widget_4);
        material_in_out_search_btn->setObjectName(QStringLiteral("material_in_out_search_btn"));
        material_in_out_search_btn->setGeometry(QRect(390, 20, 80, 28));
        enddateEdit = new QDateEdit(widget_4);
        enddateEdit->setObjectName(QStringLiteral("enddateEdit"));
        enddateEdit->setGeometry(QRect(270, 20, 110, 28));
        enddateEdit->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_4 = new QLabel(widget_4);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 20, 65, 28));
        label_4->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        material_in_out_delete_btn = new QPushButton(widget_4);
        material_in_out_delete_btn->setObjectName(QStringLiteral("material_in_out_delete_btn"));
        material_in_out_delete_btn->setGeometry(QRect(480, 20, 80, 28));
        label_5 = new QLabel(widget_4);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(200, 20, 65, 28));
        label_5->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        verticalLayout_3->addWidget(widget_4);

        material_in_out_detail_tableview = new QTableView(page_2);
        material_in_out_detail_tableview->setObjectName(QStringLiteral("material_in_out_detail_tableview"));

        verticalLayout_3->addWidget(material_in_out_detail_tableview);

        material_stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        verticalLayout_4 = new QVBoxLayout(page_3);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        widget_5 = new QWidget(page_3);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setMinimumSize(QSize(0, 60));
        fix_material_search_btn = new QPushButton(widget_5);
        fix_material_search_btn->setObjectName(QStringLiteral("fix_material_search_btn"));
        fix_material_search_btn->setGeometry(QRect(220, 20, 80, 28));
        fix_material_edit = new QLineEdit(widget_5);
        fix_material_edit->setObjectName(QStringLiteral("fix_material_edit"));
        fix_material_edit->setGeometry(QRect(90, 20, 113, 28));
        fix_material_edit->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_3 = new QLabel(widget_5);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 20, 71, 28));
        label_3->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        verticalLayout_4->addWidget(widget_5);

        fix_material_tableView = new QTableView(page_3);
        fix_material_tableView->setObjectName(QStringLiteral("fix_material_tableView"));

        verticalLayout_4->addWidget(fix_material_tableView);

        material_stackedWidget->addWidget(page_3);

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
        material_incom_opt->setText(QApplication::translate("Material", "\345\207\272\345\205\245\345\272\223\346\230\216\347\273\206", Q_NULLPTR));
        fixacc_opt->setText(QApplication::translate("Material", "\345\233\272\345\256\232\350\265\204\344\272\247", Q_NULLPTR));
        label->setText(QApplication::translate("Material", "TextLabel", Q_NULLPTR));
        material_search_btn->setText(QString());
        label_2->setText(QApplication::translate("Material", "\347\211\251\345\223\201\345\220\215\347\247\260\357\274\232", Q_NULLPTR));
        material_income_btn->setText(QString());
        material_out_btn->setText(QString());
        material_delete_btn->setText(QString());
        material_in_out_search_btn->setText(QString());
        label_4->setText(QApplication::translate("Material", "\345\274\200\345\247\213\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        material_in_out_delete_btn->setText(QString());
        label_5->setText(QApplication::translate("Material", "\347\273\223\346\235\237\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        fix_material_search_btn->setText(QString());
        label_3->setText(QApplication::translate("Material", "\345\233\272\345\256\232\350\265\204\344\272\247\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Material: public Ui_Material {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATERIALQWIDGET_H
