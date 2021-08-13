//此为查找员工时输入工号的弹窗
#include "dialogfind.h"
#include "ui_dialogfind.h"

Dialogfind::Dialogfind(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialogfind)
{
    ui->setupUi(this);
}

Dialogfind::~Dialogfind()
{
    delete ui;
}

QString Dialogfind::id()        //工号
{
    return ui->textEditid->toPlainText();
}
