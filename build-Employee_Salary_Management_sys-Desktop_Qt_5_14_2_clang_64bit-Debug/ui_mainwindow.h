/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionopen;
    QAction *actionsave;
    QAction *actionadd;
    QAction *actionEmployee;
    QAction *actionSalary;
    QAction *actionaddsalary;
    QAction *actionfind;
    QAction *actiondelete;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTableView *managetableView;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(869, 610);
        actionopen = new QAction(MainWindow);
        actionopen->setObjectName(QString::fromUtf8("actionopen"));
        actionsave = new QAction(MainWindow);
        actionsave->setObjectName(QString::fromUtf8("actionsave"));
        actionadd = new QAction(MainWindow);
        actionadd->setObjectName(QString::fromUtf8("actionadd"));
        actionEmployee = new QAction(MainWindow);
        actionEmployee->setObjectName(QString::fromUtf8("actionEmployee"));
        actionSalary = new QAction(MainWindow);
        actionSalary->setObjectName(QString::fromUtf8("actionSalary"));
        actionaddsalary = new QAction(MainWindow);
        actionaddsalary->setObjectName(QString::fromUtf8("actionaddsalary"));
        actionfind = new QAction(MainWindow);
        actionfind->setObjectName(QString::fromUtf8("actionfind"));
        actiondelete = new QAction(MainWindow);
        actiondelete->setObjectName(QString::fromUtf8("actiondelete"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        managetableView = new QTableView(centralwidget);
        managetableView->setObjectName(QString::fromUtf8("managetableView"));

        verticalLayout->addWidget(managetableView);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 869, 21));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        menu_4 = new QMenu(menubar);
        menu_4->setObjectName(QString::fromUtf8("menu_4"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_3->menuAction());
        menubar->addAction(menu_4->menuAction());
        menu->addAction(actionopen);
        menu->addAction(actionsave);
        menu_2->addAction(actionadd);
        menu_2->addAction(actionaddsalary);
        menu_3->addAction(actionEmployee);
        menu_3->addAction(actionSalary);
        menu_4->addAction(actionfind);
        menu_4->addAction(actiondelete);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionopen->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
        actionsave->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230", nullptr));
        actionadd->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\350\201\214\345\267\245\344\277\241\346\201\257", nullptr));
        actionEmployee->setText(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272\350\201\214\345\267\245\344\277\241\346\201\257", nullptr));
        actionSalary->setText(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272\345\267\245\350\265\204\344\277\241\346\201\257", nullptr));
        actionaddsalary->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\345\267\245\350\265\204\344\277\241\346\201\257", nullptr));
        actionfind->setText(QCoreApplication::translate("MainWindow", "\346\237\245\346\211\276", nullptr));
        actiondelete->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\344\277\241\346\201\257\350\276\223\345\205\245", nullptr));
        menu_3->setTitle(QCoreApplication::translate("MainWindow", "\344\277\241\346\201\257\350\276\223\345\207\272", nullptr));
        menu_4->setTitle(QCoreApplication::translate("MainWindow", "\346\223\215\344\275\234", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
