//此为查找员工失败时的弹窗
#include "dialogerror.h"
#include "ui_dialogerror.h"

Dialogerror::Dialogerror(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialogerror)
{
    ui->setupUi(this);
}

Dialogerror::~Dialogerror()
{
    delete ui;
}
