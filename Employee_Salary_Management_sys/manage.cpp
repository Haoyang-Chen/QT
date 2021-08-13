//此为管理类的cpp文件
#include "manage.h"
#include <qfile.h>
#include <QTextStream>
#include <QTextCodec>


manage::manage()
{
    m_EmpNum=0;                                             //初始化员工数为0
}

int manage::get_Emp_Num()                                   //返回员工数
{
    m_EmpNum=m_Num_Emp.size();
    return m_EmpNum;
}

bool manage::ReadFile(const QString &aReadFileName)         //读文件
{
    QFile aFile(aReadFileName);
    if (!aFile.exists())
        return false;
    if (!aFile.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;
    QTextStream aStream(&aFile);
    aStream.setCodec(QTextCodec::codecForName("system"));

    m_EmpNum=0;
    m_Num_Emp.clear();
    aStream>>m_EmpNum;
    Employee tempemployee;
    if (m_EmpNum>0)
    {
        for (int i=0;i<m_EmpNum;i++)
        {
            tempemployee.ReadFile(aStream);
            m_Num_Emp.push_back(tempemployee);
        }
    }
    aFile.close();
    return true;
}

bool manage::SaveFile(const QString &aSaveFileName)         //写文件
{
    QFile aFile(aSaveFileName);
    if (!aFile.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;
    QTextStream aStream(&aFile);
    aStream.setCodec(QTextCodec::codecForName("system"));

    aStream<<m_EmpNum<<'\n';
    if (m_EmpNum>0)
    {
        for(int i=0;i<m_EmpNum;i++)
        {
            m_Num_Emp[i].SaveFile(aStream);
        }
    }
    aFile.close();
    return true;
}

void manage::AddEmployee(Employee & employ)                 //添加职工
{
    m_Num_Emp.push_back(employ);
    m_EmpNum++;
}

Employee & manage::GetEmployee(int index)                   //拿取职工
{
    return m_Num_Emp[index];
}

manage::~manage()
{

}
