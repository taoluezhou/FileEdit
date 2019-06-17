/********************************************************************************
** Form generated from reading UI file 'subwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUBWINDOW_H
#define UI_SUBWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_subwindow
{
public:
    QTextEdit *newfilename;
    QPushButton *OK;
    QGroupBox *check;
    QVBoxLayout *verticalLayout;
    QRadioButton *check1;
    QRadioButton *check2;
    QRadioButton *check3;

    void setupUi(QWidget *subwindow)
    {
        if (subwindow->objectName().isEmpty())
            subwindow->setObjectName(QStringLiteral("subwindow"));
        subwindow->resize(357, 174);
        newfilename = new QTextEdit(subwindow);
        newfilename->setObjectName(QStringLiteral("newfilename"));
        newfilename->setGeometry(QRect(30, 60, 181, 31));
        OK = new QPushButton(subwindow);
        OK->setObjectName(QStringLiteral("OK"));
        OK->setGeometry(QRect(130, 120, 75, 23));
        check = new QGroupBox(subwindow);
        check->setObjectName(QStringLiteral("check"));
        check->setGeometry(QRect(230, 30, 91, 91));
        check->setCheckable(false);
        check->setChecked(false);
        verticalLayout = new QVBoxLayout(check);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        check1 = new QRadioButton(check);
        check1->setObjectName(QStringLiteral("check1"));

        verticalLayout->addWidget(check1);

        check2 = new QRadioButton(check);
        check2->setObjectName(QStringLiteral("check2"));

        verticalLayout->addWidget(check2);

        check3 = new QRadioButton(check);
        check3->setObjectName(QStringLiteral("check3"));

        verticalLayout->addWidget(check3);


        retranslateUi(subwindow);

        QMetaObject::connectSlotsByName(subwindow);
    } // setupUi

    void retranslateUi(QWidget *subwindow)
    {
        subwindow->setWindowTitle(QApplication::translate("subwindow", "Form", 0));
        OK->setText(QApplication::translate("subwindow", "\347\241\256\345\256\232", 0));
        check->setTitle(QString());
        check1->setText(QApplication::translate("subwindow", ".h\346\226\207\344\273\266", 0));
        check2->setText(QApplication::translate("subwindow", ".cpp\346\226\207\344\273\266", 0));
        check3->setText(QApplication::translate("subwindow", "\347\241\254\344\273\266\346\226\207\344\273\266", 0));
    } // retranslateUi

};

namespace Ui {
    class subwindow: public Ui_subwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUBWINDOW_H
