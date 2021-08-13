/********************************************************************************
** Form generated from reading UI file 'dialogadd.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGADD_H
#define UI_DIALOGADD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialogadd
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_id;
    QTextEdit *textEdit_id;
    QLabel *label_name;
    QTextEdit *textEdit_name;
    QLabel *label_age;
    QTextEdit *textEdit_age;
    QLabel *label_date;
    QTextEdit *textEdit_date;
    QLabel *label_tel;
    QTextEdit *textEdit_tel;
    QLabel *label_address;
    QTextEdit *textEdit_address;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Dialogadd)
    {
        if (Dialogadd->objectName().isEmpty())
            Dialogadd->setObjectName(QString::fromUtf8("Dialogadd"));
        Dialogadd->resize(444, 743);
        verticalLayout = new QVBoxLayout(Dialogadd);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_id = new QLabel(Dialogadd);
        label_id->setObjectName(QString::fromUtf8("label_id"));

        verticalLayout->addWidget(label_id);

        textEdit_id = new QTextEdit(Dialogadd);
        textEdit_id->setObjectName(QString::fromUtf8("textEdit_id"));

        verticalLayout->addWidget(textEdit_id);

        label_name = new QLabel(Dialogadd);
        label_name->setObjectName(QString::fromUtf8("label_name"));

        verticalLayout->addWidget(label_name);

        textEdit_name = new QTextEdit(Dialogadd);
        textEdit_name->setObjectName(QString::fromUtf8("textEdit_name"));

        verticalLayout->addWidget(textEdit_name);

        label_age = new QLabel(Dialogadd);
        label_age->setObjectName(QString::fromUtf8("label_age"));

        verticalLayout->addWidget(label_age);

        textEdit_age = new QTextEdit(Dialogadd);
        textEdit_age->setObjectName(QString::fromUtf8("textEdit_age"));

        verticalLayout->addWidget(textEdit_age);

        label_date = new QLabel(Dialogadd);
        label_date->setObjectName(QString::fromUtf8("label_date"));

        verticalLayout->addWidget(label_date);

        textEdit_date = new QTextEdit(Dialogadd);
        textEdit_date->setObjectName(QString::fromUtf8("textEdit_date"));

        verticalLayout->addWidget(textEdit_date);

        label_tel = new QLabel(Dialogadd);
        label_tel->setObjectName(QString::fromUtf8("label_tel"));

        verticalLayout->addWidget(label_tel);

        textEdit_tel = new QTextEdit(Dialogadd);
        textEdit_tel->setObjectName(QString::fromUtf8("textEdit_tel"));

        verticalLayout->addWidget(textEdit_tel);

        label_address = new QLabel(Dialogadd);
        label_address->setObjectName(QString::fromUtf8("label_address"));

        verticalLayout->addWidget(label_address);

        textEdit_address = new QTextEdit(Dialogadd);
        textEdit_address->setObjectName(QString::fromUtf8("textEdit_address"));

        verticalLayout->addWidget(textEdit_address);

        buttonBox = new QDialogButtonBox(Dialogadd);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(Dialogadd);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialogadd, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialogadd, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialogadd);
    } // setupUi

    void retranslateUi(QDialog *Dialogadd)
    {
        Dialogadd->setWindowTitle(QCoreApplication::translate("Dialogadd", "Dialog", nullptr));
        label_id->setText(QCoreApplication::translate("Dialogadd", "\345\267\245\345\217\267", nullptr));
        label_name->setText(QCoreApplication::translate("Dialogadd", "\345\247\223\345\220\215", nullptr));
        label_age->setText(QCoreApplication::translate("Dialogadd", "\345\271\264\351\276\204", nullptr));
        label_date->setText(QCoreApplication::translate("Dialogadd", "\345\205\245\350\201\214\346\227\245\346\234\237", nullptr));
        label_tel->setText(QCoreApplication::translate("Dialogadd", "\347\224\265\350\257\235", nullptr));
        label_address->setText(QCoreApplication::translate("Dialogadd", "\344\275\217\345\235\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialogadd: public Ui_Dialogadd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGADD_H
