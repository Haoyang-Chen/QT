#ifndef CSCORE_H
#define CSCORE_H
#include <qstring.h>
#include <QTextStream>

typedef struct Record
{
    QString m_sportname;
    float   m_score;
    float   m_record;
} Record;

class CScore
{
public:
    CScore();
    virtual ~CScore();

    CScore(const CScore & score);
    CScore& operator= (const CScore & score);
    void CalculateTotalScore(); //计算总分
    //根据该项目的成绩表和分数表，线性插值计算分数
    float GetScore(float* mGrade,float* mScore,float record);
    //线性插值
    float GetLinear(float leftr,float rightr, float lefts, float rights,float record);
    //	总分，100米成绩， 100米得分， 110栏成绩， 110栏得分，
    //  1500成绩，1500得分，跳高成绩，跳高得分，铅球成绩，铅球得分
    void SaveScore(QTextStream &aStream); //往流文件中写入成绩
    void ReadScore(QTextStream &aStream); //从流文件中读成绩

    Record  m_record[5];
    float   m_totalscore;

};

#endif // CSCORE_H
