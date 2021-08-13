//此为员工类的cpp文件
#include "Employee.h"


Employee::Employee()
{

}
Employee::~Employee()
{

}
Employee::Employee(QString id,QString name,QString age,QString date,QString tel,QString address,Income income)  //构造函数
{
    this->m_address=address;
    this->m_age=age;
    this->m_date=date;
    this->m_id=id;
    this->m_name=name;
    this->m_income=income;
    this->m_tel=tel;
}
Employee::Employee(const Employee & other)              //拷贝构造函数
{
    this->m_address=other.m_address;
    this->m_age=other.m_age;
    this->m_date=other.m_date;
    this->m_id=other.m_id;
    this->m_name=other.m_name;
    this->m_income=other.m_income;
    this->m_tel=other.m_tel;
}

void Employee::SaveFile(QTextStream &aStream)           //保存文件
{
    aStream << m_income.sal_num<<'\n';
    aStream << m_id<<'\n';
    aStream << m_name<<'\n';
    aStream << m_age<<'\n';
    aStream << m_date<<'\n';
    aStream << m_address<<'\n';
    aStream << m_tel<<'\n';
    for(int i=0;i<m_income.sal_num;i++)
    {
        this->m_income.sala[i].SaveFile(aStream);
    }
}

void Employee::ReadFile(QTextStream &aStream)           //读取文件
{
    //QString id,name,age,date,address,tel;
    //aStream>>id>>name>>age>>date>>address>>tel;
    aStream >> m_income.sal_num;
    aStream >> m_id;
    aStream >> m_name;
    aStream >> m_age;
    aStream >> m_date;
    aStream >> m_address;
    aStream >> m_tel;
    Salary tempSalary;
    if (m_income.sal_num>0)
    {
        for (int i=0;i<m_income.sal_num;i++)
        {
            tempSalary.ReadFile(aStream);
            m_income.sala.push_back(tempSalary);
        }
    }
}

