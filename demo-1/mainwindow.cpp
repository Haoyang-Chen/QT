#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "testdialog.h"
#include "qdir.h"
#include <QAbstractItemDelegate>
#include <QStandardItemModel>
#include "qfiledialog.h"
#include <QStandardItem>
#include "qvariant.h"
#include <QMessageBox>
#include <QModelIndex>
#include <QFileDialog>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectItems);
    mo=new QStandardItemModel;
    ui->tableView->setModel(mo);
    //connect(ui.tableView->itemDelegate(),&QAbstractItemDelegate::closeEditor,this,&MainWindow::)

}

MainWindow::~MainWindow()
{
    delete ui;
    delete mo;
}


void MainWindow::on_actionaction_triggered()
{
    testDialog dlg;
    dlg.exec();
    if (testDialog::Accepted)
    {
        QString i;
        i=dlg.back();
        ui->label->setText(i);
    }
}

void MainWindow::on_actionsave_triggered()
{
    QString curPath=QDir::currentPath();
    QString dlgTitle="选择一个文件";
    QString filter = "文本文件(*.txt);;所有文件(*.*)";
    QString aFileName=QFileDialog::getSaveFileName(this,dlgTitle,curPath,filter);
    if(aFileName.isEmpty())
        return;
}
