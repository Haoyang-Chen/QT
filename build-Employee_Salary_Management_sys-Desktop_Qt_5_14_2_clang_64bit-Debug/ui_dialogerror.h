/********************************************************************************
** Form generated from reading UI file 'dialogerror.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGERROR_H
#define UI_DIALOGERROR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialogerror
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Dialogerror)
    {
        if (Dialogerror->objectName().isEmpty())
            Dialogerror->setObjectName(QString::fromUtf8("Dialogerror"));
        Dialogerror->resize(176, 76);
        verticalLayout = new QVBoxLayout(Dialogerror);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(Dialogerror);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        buttonBox = new QDialogButtonBox(Dialogerror);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(Dialogerror);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialogerror, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialogerror, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialogerror);
    } // setupUi

    void retranslateUi(QDialog *Dialogerror)
    {
        Dialogerror->setWindowTitle(QCoreApplication::translate("Dialogerror", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Dialogerror", "\345\267\245\345\217\267\344\270\215\345\255\230\345\234\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialogerror: public Ui_Dialogerror {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGERROR_H
