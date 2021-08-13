//此为工资类和收入类的头函数
#ifndef SALARY_H
#define SALARY_H
#include <QString>
#include <QTextStream>
#include <QList>

class Salary                                //工资类
{
public:
    Salary();
    virtual ~Salary();
    Salary(QString m_month,QString m_J_G,QString m_GW_G,QString m_GL_G,QString m_J_T,QString m_G_T,QString m_B_T,QString m_F_T,QString m_JT_T);
    Salary(const Salary & other);           //拷贝构造函数

    QString m_month,m_J_G,m_GW_G,m_GL_G,m_J_T,m_G_T,m_B_T,m_F_T,m_JT_T;     //工资的各个属性

    QString Calculate_Tax();                //计算税收
    void SaveFile(QTextStream &aStream);    //保存文件
    void ReadFile(QTextStream &aStream);    //读取文件
    float CalucateTotal();                  //计算总收入

    float   m_totalsalary=m_J_G.toFloat()+m_GW_G.toFloat()+m_GL_G.toFloat()+m_G_T.toFloat()+m_B_T.toFloat()+m_F_T.toFloat()+m_JT_T.toFloat();//总收入
};

class Income                                //收入类
{
public:
    Income();
    //Salary sal[12];
    QVector <Salary> sala;                  //储存工资记录的Vector容器
    int sal_num;                            //记录工资记录数
    virtual ~Income();
    //Salary& operator[](int index);
};

#endif // SALARY_H
