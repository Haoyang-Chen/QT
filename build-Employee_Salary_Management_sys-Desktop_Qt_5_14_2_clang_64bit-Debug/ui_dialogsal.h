/********************************************************************************
** Form generated from reading UI file 'dialogsal.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGSAL_H
#define UI_DIALOGSAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialogsal
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *labelmonth;
    QTextEdit *textEdit_month;
    QLabel *label_J_G;
    QTextEdit *textEdit_J_G;
    QLabel *label_GW_G;
    QTextEdit *textEdit_GW_G;
    QLabel *label_GL_G;
    QTextEdit *textEdit_GL_G;
    QLabel *label_J_T;
    QTextEdit *textEdit_J_T;
    QLabel *label_G_T;
    QTextEdit *textEdit_G_T;
    QLabel *label_B_T;
    QTextEdit *textEdit_B_T;
    QLabel *label_F_T;
    QTextEdit *textEdit_F_T;
    QLabel *label_JT_T;
    QTextEdit *textEdit_JT_T;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Dialogsal)
    {
        if (Dialogsal->objectName().isEmpty())
            Dialogsal->setObjectName(QString::fromUtf8("Dialogsal"));
        Dialogsal->resize(295, 928);
        verticalLayout = new QVBoxLayout(Dialogsal);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        labelmonth = new QLabel(Dialogsal);
        labelmonth->setObjectName(QString::fromUtf8("labelmonth"));

        verticalLayout->addWidget(labelmonth);

        textEdit_month = new QTextEdit(Dialogsal);
        textEdit_month->setObjectName(QString::fromUtf8("textEdit_month"));

        verticalLayout->addWidget(textEdit_month);

        label_J_G = new QLabel(Dialogsal);
        label_J_G->setObjectName(QString::fromUtf8("label_J_G"));

        verticalLayout->addWidget(label_J_G);

        textEdit_J_G = new QTextEdit(Dialogsal);
        textEdit_J_G->setObjectName(QString::fromUtf8("textEdit_J_G"));

        verticalLayout->addWidget(textEdit_J_G);

        label_GW_G = new QLabel(Dialogsal);
        label_GW_G->setObjectName(QString::fromUtf8("label_GW_G"));

        verticalLayout->addWidget(label_GW_G);

        textEdit_GW_G = new QTextEdit(Dialogsal);
        textEdit_GW_G->setObjectName(QString::fromUtf8("textEdit_GW_G"));

        verticalLayout->addWidget(textEdit_GW_G);

        label_GL_G = new QLabel(Dialogsal);
        label_GL_G->setObjectName(QString::fromUtf8("label_GL_G"));

        verticalLayout->addWidget(label_GL_G);

        textEdit_GL_G = new QTextEdit(Dialogsal);
        textEdit_GL_G->setObjectName(QString::fromUtf8("textEdit_GL_G"));

        verticalLayout->addWidget(textEdit_GL_G);

        label_J_T = new QLabel(Dialogsal);
        label_J_T->setObjectName(QString::fromUtf8("label_J_T"));

        verticalLayout->addWidget(label_J_T);

        textEdit_J_T = new QTextEdit(Dialogsal);
        textEdit_J_T->setObjectName(QString::fromUtf8("textEdit_J_T"));

        verticalLayout->addWidget(textEdit_J_T);

        label_G_T = new QLabel(Dialogsal);
        label_G_T->setObjectName(QString::fromUtf8("label_G_T"));

        verticalLayout->addWidget(label_G_T);

        textEdit_G_T = new QTextEdit(Dialogsal);
        textEdit_G_T->setObjectName(QString::fromUtf8("textEdit_G_T"));

        verticalLayout->addWidget(textEdit_G_T);

        label_B_T = new QLabel(Dialogsal);
        label_B_T->setObjectName(QString::fromUtf8("label_B_T"));

        verticalLayout->addWidget(label_B_T);

        textEdit_B_T = new QTextEdit(Dialogsal);
        textEdit_B_T->setObjectName(QString::fromUtf8("textEdit_B_T"));

        verticalLayout->addWidget(textEdit_B_T);

        label_F_T = new QLabel(Dialogsal);
        label_F_T->setObjectName(QString::fromUtf8("label_F_T"));

        verticalLayout->addWidget(label_F_T);

        textEdit_F_T = new QTextEdit(Dialogsal);
        textEdit_F_T->setObjectName(QString::fromUtf8("textEdit_F_T"));

        verticalLayout->addWidget(textEdit_F_T);

        label_JT_T = new QLabel(Dialogsal);
        label_JT_T->setObjectName(QString::fromUtf8("label_JT_T"));

        verticalLayout->addWidget(label_JT_T);

        textEdit_JT_T = new QTextEdit(Dialogsal);
        textEdit_JT_T->setObjectName(QString::fromUtf8("textEdit_JT_T"));

        verticalLayout->addWidget(textEdit_JT_T);

        buttonBox = new QDialogButtonBox(Dialogsal);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(Dialogsal);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialogsal, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialogsal, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialogsal);
    } // setupUi

    void retranslateUi(QDialog *Dialogsal)
    {
        Dialogsal->setWindowTitle(QCoreApplication::translate("Dialogsal", "Dialog", nullptr));
        labelmonth->setText(QCoreApplication::translate("Dialogsal", "\346\234\210\344\273\275", nullptr));
        label_J_G->setText(QCoreApplication::translate("Dialogsal", "\345\237\272\346\234\254\345\267\245\350\265\204", nullptr));
        label_GW_G->setText(QCoreApplication::translate("Dialogsal", "\345\262\227\344\275\215\345\267\245\350\265\204", nullptr));
        label_GL_G->setText(QCoreApplication::translate("Dialogsal", "\345\267\245\351\276\204\345\267\245\350\265\204", nullptr));
        label_J_T->setText(QCoreApplication::translate("Dialogsal", "\346\264\245\350\264\264", nullptr));
        label_G_T->setText(QCoreApplication::translate("Dialogsal", "\345\262\227\350\264\264", nullptr));
        label_B_T->setText(QCoreApplication::translate("Dialogsal", "\350\241\245\350\264\264", nullptr));
        label_F_T->setText(QCoreApplication::translate("Dialogsal", "\346\210\277\350\264\264", nullptr));
        label_JT_T->setText(QCoreApplication::translate("Dialogsal", "\344\272\244\351\200\232\350\241\245\350\264\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialogsal: public Ui_Dialogsal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGSAL_H
