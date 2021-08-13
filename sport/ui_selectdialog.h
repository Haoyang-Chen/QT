/********************************************************************************
** Form generated from reading UI file 'selectdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTDIALOG_H
#define UI_SELECTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SelectDialog
{
public:
    QGroupBox *groupBox;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioGreater;
    QRadioButton *radioEqual;
    QRadioButton *radioLower;
    QLineEdit *lineEditSelectedValue;
    QLabel *label_2;
    QLabel *label_unit;
    QComboBox *comboSpecialItem;
    QLabel *label;
    QPushButton *btnCancel;
    QPushButton *btnOK;

    void setupUi(QDialog *SelectDialog)
    {
        if (SelectDialog->objectName().isEmpty())
            SelectDialog->setObjectName(QString::fromUtf8("SelectDialog"));
        SelectDialog->resize(326, 261);
        groupBox = new QGroupBox(SelectDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 70, 301, 141));
        horizontalLayoutWidget = new QWidget(groupBox);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(20, 70, 261, 51));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        radioGreater = new QRadioButton(horizontalLayoutWidget);
        radioGreater->setObjectName(QString::fromUtf8("radioGreater"));

        horizontalLayout->addWidget(radioGreater);

        radioEqual = new QRadioButton(horizontalLayoutWidget);
        radioEqual->setObjectName(QString::fromUtf8("radioEqual"));

        horizontalLayout->addWidget(radioEqual);

        radioLower = new QRadioButton(horizontalLayoutWidget);
        radioLower->setObjectName(QString::fromUtf8("radioLower"));

        horizontalLayout->addWidget(radioLower);

        lineEditSelectedValue = new QLineEdit(groupBox);
        lineEditSelectedValue->setObjectName(QString::fromUtf8("lineEditSelectedValue"));
        lineEditSelectedValue->setGeometry(QRect(90, 30, 121, 31));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 40, 54, 21));
        label_unit = new QLabel(groupBox);
        label_unit->setObjectName(QString::fromUtf8("label_unit"));
        label_unit->setGeometry(QRect(220, 40, 54, 21));
        comboSpecialItem = new QComboBox(SelectDialog);
        comboSpecialItem->addItem(QString());
        comboSpecialItem->addItem(QString());
        comboSpecialItem->setObjectName(QString::fromUtf8("comboSpecialItem"));
        comboSpecialItem->setGeometry(QRect(90, 20, 201, 31));
        label = new QLabel(SelectDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 30, 54, 21));
        btnCancel = new QPushButton(SelectDialog);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setGeometry(QRect(180, 220, 75, 23));
        btnOK = new QPushButton(SelectDialog);
        btnOK->setObjectName(QString::fromUtf8("btnOK"));
        btnOK->setGeometry(QRect(70, 220, 75, 23));

        retranslateUi(SelectDialog);
        QObject::connect(btnOK, SIGNAL(clicked()), SelectDialog, SLOT(accept()));
        QObject::connect(btnCancel, SIGNAL(clicked()), SelectDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(SelectDialog);
    } // setupUi

    void retranslateUi(QDialog *SelectDialog)
    {
        SelectDialog->setWindowTitle(QApplication::translate("SelectDialog", "Dialog", nullptr));
        groupBox->setTitle(QApplication::translate("SelectDialog", "\351\200\211\351\241\271", nullptr));
        radioGreater->setText(QApplication::translate("SelectDialog", "\351\253\230\344\272\216", nullptr));
        radioEqual->setText(QApplication::translate("SelectDialog", "\347\255\211\344\272\216", nullptr));
        radioLower->setText(QApplication::translate("SelectDialog", "\344\275\216\344\272\216", nullptr));
        label_2->setText(QApplication::translate("SelectDialog", "<html><head/><body><p><span style=\" font-size:11pt;\">\346\225\260\345\200\274\357\274\232</span></p></body></html>", nullptr));
        label_unit->setText(QApplication::translate("SelectDialog", "<html><head/><body><p><span style=\" font-size:11pt;\">\345\216\230\347\261\263</span></p></body></html>", nullptr));
        comboSpecialItem->setItemText(0, QApplication::translate("SelectDialog", "\350\272\253\351\253\230", nullptr));
        comboSpecialItem->setItemText(1, QApplication::translate("SelectDialog", "\344\275\223\351\207\215", nullptr));

        label->setText(QApplication::translate("SelectDialog", "<html><head/><body><p><span style=\" font-size:11pt;\">\347\211\271\345\276\201\351\241\271\357\274\232</span></p></body></html>", nullptr));
        btnCancel->setText(QApplication::translate("SelectDialog", "Cancel", nullptr));
        btnOK->setText(QApplication::translate("SelectDialog", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SelectDialog: public Ui_SelectDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTDIALOG_H
