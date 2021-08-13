//此为员工类的头文件
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <QString>
#include "salary.h"


using namespace std;
class Employee
{
public:
    Employee();
    virtual ~Employee();
    Employee(QString id,QString name,QString age,QString date,QString tel,QString address,Income income);   //构造函数
    Employee(const Employee & other);                                                                       //拷贝构造函数
    void SaveFile(QTextStream &aStream);                                                                    //保存文件
    void ReadFile(QTextStream &aStream);                                                                    //读取文件

    QString m_id;                                                                                           //工号
    QString m_name;                                                                                         //姓名
    QString m_age;                                                                                          //年龄
    QString m_date;                                                                                         //日期
    QString m_tel;                                                                                          //电话
    QString m_address;                                                                                      //地址
    Income m_income;                                                                                        //收入

};

#endif // EMPLOYEE_H
