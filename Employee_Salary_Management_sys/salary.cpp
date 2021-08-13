//此为工资与收入类的cpp文件
#include "salary.h"

Salary::Salary()
{

}
Salary::~Salary()
{

}
Salary::Salary(QString m_month,QString m_J_G,QString m_GW_G,QString m_GL_G,QString m_J_T,QString m_G_T,QString m_B_T,QString m_F_T,QString m_JT_T)
{
    this->m_B_T=m_B_T;
    this->m_F_T=m_F_T;
    this->m_GL_G=m_GL_G;
    this->m_GW_G=m_GW_G;
    this->m_G_T=m_G_T;
    this->m_JT_T=m_JT_T;
    this->m_J_G=m_J_G;
    this->m_J_T=m_J_T;
    this->m_month=m_month;
}
Salary::Salary(const Salary & other)            //拷贝构造
{
    this->m_B_T=other.m_B_T;
    this->m_F_T=other.m_F_T;
    this->m_GL_G=other.m_GL_G;
    this->m_GW_G=other.m_GW_G;
    this->m_G_T=other.m_G_T;
    this->m_JT_T=other.m_JT_T;
    this->m_J_G=other.m_J_G;
    this->m_J_T=other.m_J_T;
    this->m_month=other.m_month;
}
void Salary::SaveFile(QTextStream &aStream)     //写文件
{
    aStream<<m_month<<'\t';
    aStream<<m_totalsalary<<'\n';
    aStream<<m_B_T<<'\t';
    aStream<<m_F_T<<'\t';
    aStream<<m_GL_G<<'\t';
    aStream<<m_GW_G<<'\t';
    aStream<<m_G_T<<'\t';
    aStream<<m_JT_T<<'\t';
    aStream<<m_J_G<<'\t';
    aStream<<m_J_T<<'\t';
}

void Salary::ReadFile(QTextStream &aStream)     //读文件
{
    aStream>>m_month;
    aStream>>m_totalsalary;
    aStream>>m_B_T;
    aStream>>m_F_T;
    aStream>>m_GL_G;
    aStream>>m_GW_G;
    aStream>>m_G_T;
    aStream>>m_JT_T;
    aStream>>m_J_G;
    aStream>>m_J_T;
}
QString Salary::Calculate_Tax(){                //计算税收
//,m_J_G,m_GW_G,m_GL_G,m_J_T,m_G_T,m_B_T,m_F_T,m_JT_T
    float tax=0;
    float salary=m_totalsalary;
    if (salary>800)
    {
        tax+=0;
        salary-=800;
        if(salary>200)
        {
            tax+=10;
            salary-=200;
            if (salary>4000)
            {
                tax+=400;
                salary-=4000;
                if (salary>0)
                {
                    tax+=salary*0.2;
                    salary=0;
                }
                tax+=salary*0.1;
            }
            tax+=salary*0.05;
        }
        tax+=salary*0;
    }
    QString temp;
    temp.setNum(tax);
    return temp;
}

float Salary::CalucateTotal()                   //计算总收入
{
    return m_J_G.toFloat()+m_GW_G.toFloat()+m_GL_G.toFloat()+m_G_T.toFloat()+m_B_T.toFloat()+m_F_T.toFloat()+m_JT_T.toFloat();
}
//Salary& Income::operator[](int index)
//{
//    return this->sala[index];
//}

Income::Income()                                //初始化工资记录数为0
{
    this->sal_num=0;
}

Income::~Income()
{

}
