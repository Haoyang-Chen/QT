//此为管理类的头函数
#ifndef MANAGE_H
#define MANAGE_H
#include "Employee.h"
#include "salary.h"
#include <QString>
#include <fstream>
#include <vector>
#include <QVector>
#define FILENAME = "/Users/haoyangchen/Desktop/ChenHaoyang/coding/qt/Employee_Salary_Management_sys/data.txt"

class manage
{
public:
    manage();
    int m_EmpNum;                                       //记录员工数
    bool ReadFile(const QString &aReadFileName);        //读文件
    bool SaveFile(const QString &aSaveFileName);        //保存文件

    int get_Emp_Num();                                  //获取员工数

    virtual ~manage();
    void AddEmployee(Employee & employ);                //添加新员工
    Employee & GetEmployee(int index);                  //获取制定员工
    QVector <Employee> m_Num_Emp;                       //储存员工的Vector容器
};

#endif // MANAGE_H
