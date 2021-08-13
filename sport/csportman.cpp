#include "csportman.h"

CSportMan::CSportMan()
{

}
CSportMan::~CSportMan()
{

}

CSportMan::CSportMan(const CSportMan & man)
{
    m_number = man.m_number;
    m_name = man.m_name;
    m_date = man.m_date;
    m_height = man.m_height;
    m_weight = man.m_weight;
    m_score = man.m_score;
    m_place = man.m_place; //名次
}

CSportMan& CSportMan::operator= (const CSportMan& man)
{
    m_number = man.m_number;
    m_name = man.m_name;
    m_date = man.m_date;
    m_height = man.m_height;
    m_weight = man.m_weight;
    m_score = man.m_score;
    m_place = man.m_place; //名次
    return *this;
}

void CSportMan::SaveSportman(QTextStream &aStream)
{
    aStream << m_date.year()<<" "<<m_date.month()<<" "<<m_date.day()<<'\n';
    aStream << m_height<<'\n';
    aStream << m_name<<'\n';
    aStream << m_number<<'\n';
    aStream << m_place<<'\n';
    aStream << m_weight<<'\n';
    m_score.SaveScore(aStream);
}

void CSportMan::ReadSportman(QTextStream &aStream)
{
    int year, month, day;
    aStream>>year>>month>>day;
    m_date.setDate(year, month, day);
    aStream >> m_height;
    aStream >> m_name;
    aStream >> m_number;
    aStream >> m_place;
    aStream >> m_weight;
    m_score.ReadScore(aStream);
}
