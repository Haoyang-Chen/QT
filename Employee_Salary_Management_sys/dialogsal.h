//此为添加员工工资信息时弹出的输入界面
#ifndef DIALOGSAL_H
#define DIALOGSAL_H

#include <QDialog>

namespace Ui {
class Dialogsal;
}

class Dialogsal : public QDialog
{
    Q_OBJECT

public:
    explicit Dialogsal(QWidget *parent = nullptr);
    ~Dialogsal();
    //QString m_month,m_J_G,m_GW_G,m_GL_G,m_J_T,m_G_T,m_B_T,m_F_T,m_JT_T;
    QString m_month();          //月份
    QString m_J_G();            //基本工资
    QString m_GW_G();           //岗位工资
    QString m_GL_G();           //工龄工资
    QString m_J_T();            //津贴
    QString m_G_T();            //岗贴
    QString m_B_T();            //补贴
    QString m_F_T();            //房贴
    QString m_JT_T();           //交通补贴

private:
    Ui::Dialogsal *ui;
};

#endif // DIALOGSAL_H
