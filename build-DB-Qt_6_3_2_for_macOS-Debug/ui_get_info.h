/********************************************************************************
** Form generated from reading UI file 'get_info.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GET_INFO_H
#define UI_GET_INFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_get_info
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;
    QTextEdit *textEdit_3;
    QTextEdit *textEdit_4;
    QTextEdit *textEdit_5;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *get_info)
    {
        if (get_info->objectName().isEmpty())
            get_info->setObjectName(QString::fromUtf8("get_info"));
        get_info->resize(482, 542);
        label = new QLabel(get_info);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(160, 50, 171, 41));
        QFont font;
        font.setPointSize(24);
        label->setFont(font);
        label_2 = new QLabel(get_info);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(80, 160, 121, 31));
        QFont font1;
        font1.setPointSize(17);
        label_2->setFont(font1);
        label_3 = new QLabel(get_info);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(80, 210, 121, 31));
        label_3->setFont(font1);
        label_4 = new QLabel(get_info);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(80, 260, 121, 31));
        label_4->setFont(font1);
        label_5 = new QLabel(get_info);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(80, 310, 121, 31));
        label_5->setFont(font1);
        label_6 = new QLabel(get_info);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(80, 360, 121, 31));
        label_6->setFont(font1);
        textEdit = new QTextEdit(get_info);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(200, 160, 211, 31));
        textEdit_2 = new QTextEdit(get_info);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setGeometry(QRect(200, 210, 211, 31));
        textEdit_3 = new QTextEdit(get_info);
        textEdit_3->setObjectName(QString::fromUtf8("textEdit_3"));
        textEdit_3->setGeometry(QRect(200, 260, 211, 31));
        textEdit_4 = new QTextEdit(get_info);
        textEdit_4->setObjectName(QString::fromUtf8("textEdit_4"));
        textEdit_4->setGeometry(QRect(200, 310, 211, 31));
        textEdit_5 = new QTextEdit(get_info);
        textEdit_5->setObjectName(QString::fromUtf8("textEdit_5"));
        textEdit_5->setGeometry(QRect(200, 360, 211, 31));
        pushButton = new QPushButton(get_info);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(100, 440, 91, 41));
        pushButton_2 = new QPushButton(get_info);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(280, 440, 91, 41));

        retranslateUi(get_info);

        QMetaObject::connectSlotsByName(get_info);
    } // setupUi

    void retranslateUi(QWidget *get_info)
    {
        get_info->setWindowTitle(QCoreApplication::translate("get_info", "Form", nullptr));
        label->setText(QCoreApplication::translate("get_info", "\347\224\250\346\210\267\344\277\241\346\201\257\345\275\225\345\205\245", nullptr));
        label_2->setText(QCoreApplication::translate("get_info", "\350\272\253\344\273\275\350\257\201\345\217\267\347\240\201", nullptr));
        label_3->setText(QCoreApplication::translate("get_info", "\345\247\223\345\220\215", nullptr));
        label_4->setText(QCoreApplication::translate("get_info", "\345\271\264\351\276\204", nullptr));
        label_5->setText(QCoreApplication::translate("get_info", "\347\224\265\350\257\235\345\217\267\347\240\201", nullptr));
        label_6->setText(QCoreApplication::translate("get_info", "\345\201\245\345\272\267\347\212\266\345\206\265", nullptr));
        pushButton->setText(QCoreApplication::translate("get_info", "\347\241\256\345\256\232", nullptr));
        pushButton_2->setText(QCoreApplication::translate("get_info", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class get_info: public Ui_get_info {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GET_INFO_H
