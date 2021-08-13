#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "testdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionaction_triggered()
{
    TestDialog dlg;
    dlg.exec();

}
