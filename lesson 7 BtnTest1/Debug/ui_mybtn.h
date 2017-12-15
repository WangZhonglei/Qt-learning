/********************************************************************************
** Form generated from reading UI file 'mybtn.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYBTN_H
#define UI_MYBTN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_MyBtn
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton1;
    QPushButton *pushButton3;
    QPushButton *pushButton2;
    QPushButton *pushButton4;

    void setupUi(QDialog *MyBtn)
    {
        if (MyBtn->objectName().isEmpty())
            MyBtn->setObjectName(QStringLiteral("MyBtn"));
        MyBtn->resize(478, 417);
        gridLayout = new QGridLayout(MyBtn);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton1 = new QPushButton(MyBtn);
        pushButton1->setObjectName(QStringLiteral("pushButton1"));

        gridLayout->addWidget(pushButton1, 0, 0, 1, 1);

        pushButton3 = new QPushButton(MyBtn);
        pushButton3->setObjectName(QStringLiteral("pushButton3"));

        gridLayout->addWidget(pushButton3, 0, 1, 1, 1);

        pushButton2 = new QPushButton(MyBtn);
        pushButton2->setObjectName(QStringLiteral("pushButton2"));

        gridLayout->addWidget(pushButton2, 1, 0, 1, 1);

        pushButton4 = new QPushButton(MyBtn);
        pushButton4->setObjectName(QStringLiteral("pushButton4"));

        gridLayout->addWidget(pushButton4, 1, 1, 1, 1);


        retranslateUi(MyBtn);

        QMetaObject::connectSlotsByName(MyBtn);
    } // setupUi

    void retranslateUi(QDialog *MyBtn)
    {
        MyBtn->setWindowTitle(QApplication::translate("MyBtn", "MyBtn", Q_NULLPTR));
        pushButton1->setText(QApplication::translate("MyBtn", "PushButton", Q_NULLPTR));
        pushButton3->setText(QApplication::translate("MyBtn", "PushButton", Q_NULLPTR));
        pushButton2->setText(QApplication::translate("MyBtn", "PushButton", Q_NULLPTR));
        pushButton4->setText(QApplication::translate("MyBtn", "PushButton", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MyBtn: public Ui_MyBtn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYBTN_H
