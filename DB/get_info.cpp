#include "get_info.h"
#include "ui_get_info.h"

get_info::get_info(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::get_info)
{
    ui->setupUi(this);
}

get_info::~get_info()
{
    delete ui;
}
