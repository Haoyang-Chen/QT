//此为添加工资记录时输入信息的弹窗
#include "dialogsal.h"
#include "ui_dialogsal.h"

Dialogsal::Dialogsal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialogsal)
{
    ui->setupUi(this);
}

Dialogsal::~Dialogsal()
{
    delete ui;
}
QString Dialogsal::m_month()                        //月份
{
    return ui->textEdit_month->toPlainText();
}

QString Dialogsal::m_J_G()                          //基本工资
{
    return ui->textEdit_J_G->toPlainText();
}
QString Dialogsal::m_GW_G()                         //岗位工资
{
    return ui->textEdit_GW_G->toPlainText();
}
QString Dialogsal::m_GL_G()                         //工龄工资
{
    return ui->textEdit_GL_G->toPlainText();
}
QString Dialogsal::m_J_T()                          //津贴
{
    return ui->textEdit_J_T->toPlainText();
}
QString Dialogsal::m_G_T()                          //岗贴
{
    return ui->textEdit_G_T->toPlainText();
}
QString Dialogsal::m_B_T()                          //补贴
{
    return ui->textEdit_B_T->toPlainText();
}
QString Dialogsal::m_F_T()                          //房贴
{
    return ui->textEdit_F_T->toPlainText();
}
QString Dialogsal::m_JT_T()                         //交通补贴
{
    return ui->textEdit_JT_T->toPlainText();
}
