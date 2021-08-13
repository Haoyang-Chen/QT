//此为添加员工时显示窗口的头文件
#ifndef DIALOGADD_H
#define DIALOGADD_H

#include <QDialog>
#include "salary.h"

namespace Ui {
class Dialogadd;
}

class Dialogadd : public QDialog
{
    Q_OBJECT

public:
    explicit Dialogadd(QWidget *parent = nullptr);
    ~Dialogadd();
    QString m_id();             //员工工号
    QString m_name();           //员工姓名
    QString m_age();            //员工年龄
    QString m_date();           //入职日期
    QString m_tel();            //电话
    QString m_address();        //住址


private:
    Ui::Dialogadd *ui;
};

#endif // DIALOGADD_H
