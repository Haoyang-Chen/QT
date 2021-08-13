#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include <QModelIndex>

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


void MainWindow::on_actionsign_up_triggered()
{

}

void MainWindow::Show_Sign_up_table()
{

}
