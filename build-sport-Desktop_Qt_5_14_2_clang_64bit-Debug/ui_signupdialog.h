/********************************************************************************
** Form generated from reading UI file 'signupdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUPDIALOG_H
#define UI_SIGNUPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_SignupDialog
{
public:
    QTextEdit *textEditName;
    QLabel *label_5;
    QDateEdit *dateEditBirth;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_6;
    QLabel *label_4;
    QTextEdit *textEditHigh;
    QTextEdit *textEditNumber;
    QTextEdit *textEditWeight;
    QLabel *label_7;
    QPushButton *btnOK;
    QPushButton *btnCancel;

    void setupUi(QDialog *SignupDialog)
    {
        if (SignupDialog->objectName().isEmpty())
            SignupDialog->setObjectName(QString::fromUtf8("SignupDialog"));
        SignupDialog->resize(262, 240);
        textEditName = new QTextEdit(SignupDialog);
        textEditName->setObjectName(QString::fromUtf8("textEditName"));
        textEditName->setGeometry(QRect(70, 50, 161, 31));
        textEditName->setAcceptRichText(false);
        label_5 = new QLabel(SignupDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 10, 41, 31));
        dateEditBirth = new QDateEdit(SignupDialog);
        dateEditBirth->setObjectName(QString::fromUtf8("dateEditBirth"));
        dateEditBirth->setGeometry(QRect(70, 90, 161, 31));
        label_3 = new QLabel(SignupDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 130, 41, 31));
        label = new QLabel(SignupDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 50, 41, 31));
        label_2 = new QLabel(SignupDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 90, 41, 31));
        label_6 = new QLabel(SignupDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(190, 130, 41, 31));
        label_4 = new QLabel(SignupDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 170, 41, 31));
        textEditHigh = new QTextEdit(SignupDialog);
        textEditHigh->setObjectName(QString::fromUtf8("textEditHigh"));
        textEditHigh->setGeometry(QRect(70, 130, 104, 31));
        textEditHigh->setAcceptRichText(false);
        textEditNumber = new QTextEdit(SignupDialog);
        textEditNumber->setObjectName(QString::fromUtf8("textEditNumber"));
        textEditNumber->setGeometry(QRect(70, 10, 161, 31));
        textEditNumber->setAcceptRichText(false);
        textEditWeight = new QTextEdit(SignupDialog);
        textEditWeight->setObjectName(QString::fromUtf8("textEditWeight"));
        textEditWeight->setGeometry(QRect(70, 170, 104, 31));
        textEditWeight->setAcceptRichText(false);
        label_7 = new QLabel(SignupDialog);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(190, 170, 41, 31));
        btnOK = new QPushButton(SignupDialog);
        btnOK->setObjectName(QString::fromUtf8("btnOK"));
        btnOK->setGeometry(QRect(40, 210, 75, 23));
        btnCancel = new QPushButton(SignupDialog);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setGeometry(QRect(150, 210, 75, 23));

        retranslateUi(SignupDialog);
        QObject::connect(btnOK, SIGNAL(clicked()), SignupDialog, SLOT(accept()));
        QObject::connect(btnCancel, SIGNAL(clicked()), SignupDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(SignupDialog);
    } // setupUi

    void retranslateUi(QDialog *SignupDialog)
    {
        SignupDialog->setWindowTitle(QCoreApplication::translate("SignupDialog", "Dialog", nullptr));
        label_5->setText(QCoreApplication::translate("SignupDialog", "\345\217\267\347\240\201", nullptr));
        label_3->setText(QCoreApplication::translate("SignupDialog", "\350\272\253\351\253\230", nullptr));
        label->setText(QCoreApplication::translate("SignupDialog", "\345\247\223\345\220\215", nullptr));
        label_2->setText(QCoreApplication::translate("SignupDialog", "\347\224\237\346\227\245", nullptr));
        label_6->setText(QCoreApplication::translate("SignupDialog", "\345\216\230\347\261\263", nullptr));
        label_4->setText(QCoreApplication::translate("SignupDialog", "\344\275\223\351\207\215", nullptr));
        label_7->setText(QCoreApplication::translate("SignupDialog", "\345\205\254\346\226\244", nullptr));
        btnOK->setText(QCoreApplication::translate("SignupDialog", "OK", nullptr));
        btnCancel->setText(QCoreApplication::translate("SignupDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SignupDialog: public Ui_SignupDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUPDIALOG_H
