//此为添加员工时显示的窗口
#include "dialogadd.h"
#include "ui_dialogadd.h"

Dialogadd::Dialogadd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialogadd)
{
    ui->setupUi(this);
}

Dialogadd::~Dialogadd()
{
    delete ui;
}

QString Dialogadd::m_id()                           //工号
{
    return ui->textEdit_id->toPlainText();
}
QString Dialogadd::m_name()                         //姓名
{
    return ui->textEdit_name->toPlainText();
}
QString Dialogadd::m_age()                          //年龄
{
    return ui->textEdit_age->toPlainText();
}
QString Dialogadd::m_tel()                          //电话
{
    return ui->textEdit_tel->toPlainText();
}
QString Dialogadd::m_date()                         //入职日期
{
    return ui->textEdit_date->toPlainText();
}
QString Dialogadd::m_address()                      //地址
{
    return ui->textEdit_address->toPlainText();
}
