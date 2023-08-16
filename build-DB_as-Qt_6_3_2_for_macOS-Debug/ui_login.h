/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QPushButton *login_2;
    QPushButton *register_2;
    QPushButton *exit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *name;
    QLineEdit *pwd;

    void setupUi(QWidget *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QString::fromUtf8("login"));
        login->resize(506, 361);
        login_2 = new QPushButton(login);
        login_2->setObjectName(QString::fromUtf8("login_2"));
        login_2->setGeometry(QRect(200, 280, 100, 32));
        register_2 = new QPushButton(login);
        register_2->setObjectName(QString::fromUtf8("register_2"));
        register_2->setGeometry(QRect(40, 280, 100, 32));
        exit = new QPushButton(login);
        exit->setObjectName(QString::fromUtf8("exit"));
        exit->setGeometry(QRect(360, 280, 100, 32));
        label = new QLabel(login);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(130, 30, 221, 41));
        QFont font;
        font.setPointSize(24);
        label->setFont(font);
        label_2 = new QLabel(login);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(100, 120, 61, 31));
        QFont font1;
        font1.setPointSize(16);
        label_2->setFont(font1);
        label_3 = new QLabel(login);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(110, 160, 61, 31));
        label_3->setFont(font1);
        name = new QLineEdit(login);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(220, 120, 151, 31));
        pwd = new QLineEdit(login);
        pwd->setObjectName(QString::fromUtf8("pwd"));
        pwd->setGeometry(QRect(220, 160, 151, 31));

        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QWidget *login)
    {
        login->setWindowTitle(QCoreApplication::translate("login", "\347\231\273\351\231\206", nullptr));
        login_2->setText(QCoreApplication::translate("login", "Login", nullptr));
        register_2->setText(QCoreApplication::translate("login", "Register", nullptr));
        exit->setText(QCoreApplication::translate("login", "Exit", nullptr));
        label->setText(QCoreApplication::translate("login", "\351\230\262\347\226\253\345\244\247\346\225\260\346\215\256\345\271\263\345\217\260\347\231\273\351\231\206", nullptr));
        label_2->setText(QCoreApplication::translate("login", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_3->setText(QCoreApplication::translate("login", "\345\257\206\347\240\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
