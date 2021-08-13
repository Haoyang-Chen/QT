#include "sportsmaninfotable.h"
#include <qfile.h>
#include <QTextStream>
#include <QTextCodec>

SportsManInfoTable::SportsManInfoTable()
{
    m_number = 0;
}

////这个排序算法可以优化
//void  SportsManInfoTable::CalculateRank()
//{
//    int i, j; //读写迭代器
//    int total = m_sportmans.size();
//    for(i=0; i<total;i++)
//    {
//        CSportMan & sportman = m_sportmans[i]; //获取当前运动员的引用
//        float totalscore = sportman.m_score.m_totalscore;
//        int rank = 1;

//        //遍历获取当前运动员的排名
//        j=0;
//        while(j<total)
//        {
//            if(totalscore<m_sportmans[j].m_score.m_totalscore)
//                rank++;
//            j++;
//        }
//        sportman.m_place = rank;
//    }

//}

bool SportsManInfoTable::ReadSportsmanFromFile(const QString &aReadFileName)
{
    QFile aFile(aReadFileName);
    if(!aFile.exists()) //文件不存在
        return false;
    if(!aFile.open(QIODevice::ReadOnly | QIODevice::Text)) //以文本方式打开
        return false;
    QTextStream aStream(&aFile); //用文本流读取文件
    aStream.setCodec(QTextCodec::codecForName("system")); //显示汉字

    //初始化
    m_sportmans.clear();
    m_number = 0;

    //逐个读取运动员信息
    aStream>>m_number; //运动员总数
    CSportMan tempSportman;
    if(m_number>0)
    {
        for(int i=0; i<m_number; i++)
        {
            tempSportman.ReadSportman(aStream);
            m_sportmans.push_back(tempSportman);
        }
    }
    aFile.close();//关闭文件
    return true;
}

bool SportsManInfoTable::SaveSportsmanToFile(const QString &aSaveFileName)
{
    QFile aFile(aSaveFileName);
    if(!aFile.open(QIODevice::WriteOnly| QIODevice::Text)) //保存为文本
        return false;
    QTextStream aStream(&aFile);//用文本流保存文件
    aStream.setCodec(QTextCodec::codecForName("system")); //显示汉字

    //逐个写入运动员信息
    aStream<<m_number<<'\n';//运动员总数
    if(m_number>0)
    {
        for(int i=0; i<m_number; i++)
            m_sportmans[i].SaveSportman(aStream);
    }
    aFile.close(); //关闭文件
    return true;
}

void SportsManInfoTable::AddSportman(CSportMan &sportman)
{
    m_sportmans.push_back(sportman);
    m_number++;
}

int SportsManInfoTable::GetSportsmanNum()
{
    m_number = m_sportmans.size();
    return m_number;
}

CSportMan & SportsManInfoTable::GetSportMan(int index)
{
    return m_sportmans[index];
}
