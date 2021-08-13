/********************************************************************************
** Form generated from reading UI file 'dialogfind.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGFIND_H
#define UI_DIALOGFIND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialogfind
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTextEdit *textEditid;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Dialogfind)
    {
        if (Dialogfind->objectName().isEmpty())
            Dialogfind->setObjectName(QString::fromUtf8("Dialogfind"));
        Dialogfind->resize(176, 162);
        verticalLayout = new QVBoxLayout(Dialogfind);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(Dialogfind);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        textEditid = new QTextEdit(Dialogfind);
        textEditid->setObjectName(QString::fromUtf8("textEditid"));

        verticalLayout->addWidget(textEditid);

        buttonBox = new QDialogButtonBox(Dialogfind);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(Dialogfind);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialogfind, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialogfind, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialogfind);
    } // setupUi

    void retranslateUi(QDialog *Dialogfind)
    {
        Dialogfind->setWindowTitle(QCoreApplication::translate("Dialogfind", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Dialogfind", "\345\267\245\345\217\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialogfind: public Ui_Dialogfind {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGFIND_H
