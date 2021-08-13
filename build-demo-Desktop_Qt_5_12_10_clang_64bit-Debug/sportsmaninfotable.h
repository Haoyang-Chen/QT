#ifndef SPORTSMANINFOTABLE_H
#define SPORTSMANINFOTABLE_H
#include "csportman.h"
#include <vector>
#include <QVector>

class SportsManInfoTable
{
public:
    SportsManInfoTable();
    //对运动员进行排序，排序结果存在运动员的属性 m_place中
    void  CalculateRank();

    bool ReadSportsmanFromFile(const QString &aReadFileName);
    bool SaveSportsmanToFile(const QString &aSaveFileName);

    void AddSportman(CSportMan & sportman);
    CSportMan & GetSportMan(int index);
    int GetSportsmanNum();
protected:
    QVector <CSportMan> m_sportmans; //运动员的列表
    int m_number; //运动员的总数
};

#endif // SPORTSMANINFOTABLE_H
