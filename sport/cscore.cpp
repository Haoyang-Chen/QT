#include "cscore.h"
#include <math.h>

CScore::CScore(const CScore & score)
{
    for(int i=0;i<5;i++)
        m_record[i] = score.m_record[i];
    m_totalscore = score.m_totalscore;

}

CScore& CScore::operator= (const CScore & score)
{
    for(int i=0;i<5;i++)
        m_record[i] = score.m_record[i];
    m_totalscore = score.m_totalscore;
    return *this;
}

CScore::CScore()
{
    m_record[0].m_sportname = "100米";
    m_record[1].m_sportname = "110米栏";
    m_record[2].m_sportname = "1500米";
    m_record[3].m_sportname = "跳高";
    m_record[4].m_sportname = "铅球";
    //缺省成绩都是0
    for(int i=0; i<5; i++)
    {
        m_record[i].m_record = 0;
        m_record[i].m_score = 0.0;
    }
    m_totalscore = 0;
}

CScore::~CScore()
{

}

void CScore::SaveScore(QTextStream &aStream)
{
    aStream<<m_totalscore<<'\n';
    for(int i=0;i<5;i++)
    {
        aStream << m_record[i].m_record<<'\t';
        aStream << m_record[i].m_score<<'\t';
        aStream << m_record[i].m_sportname<<'\n';
    }

}

void CScore::ReadScore(QTextStream &aStream)
{
    aStream >> m_totalscore;
    for(int i=0;i<5;i++)
    {
        aStream >> m_record[i].m_record;
        aStream >> m_record[i].m_score;
        aStream >> m_record[i].m_sportname;
    }

}

float CScore::GetLinear(float leftr,float rightr, float lefts, float rights,float record)
{
    return (float)fabs(record-leftr) / fabs(rightr-leftr) * fabs(rights - lefts) + lefts;
}

float CScore::GetScore(float* mGrade,float* mScore,float record)
{
    bool brun;
    if(mGrade[0] > mGrade[5] )
        brun = true;
    else
        brun = false;

    if(brun)
    {
        if(record >= mGrade[0])
            return mScore[0];
        else if(record < mGrade[0] && record >= mGrade[1])
            return GetLinear(mGrade[0],mGrade[1],mScore[0],mScore[1],record);
        else if(record < mGrade[1] && record >= mGrade[2])
            return GetLinear(mGrade[1],mGrade[2],mScore[1],mScore[2],record);
        else if(record < mGrade[2] && record >= mGrade[3])
            return GetLinear(mGrade[2],mGrade[3],mScore[2],mScore[3],record);
        else if(record < mGrade[3] && record >= mGrade[4])
            return GetLinear(mGrade[3],mGrade[4],mScore[3],mScore[4],record);
        else if(record < mGrade[4] && record >= mGrade[5])
            return GetLinear(mGrade[4],mGrade[5],mScore[4],mScore[5],record);
        else if(record < mGrade[5] && record > 1.0)
            return mScore[5];
        else
            return 0;
    }
    else
    {
        if(record <= mGrade[0 && record > 1.0])
            return mScore[0];
        else if(record > mGrade[0] && record <= mGrade[1])
            return GetLinear(mGrade[0],mGrade[1],mScore[0],mScore[1],record);
        else if(record > mGrade[1] && record <= mGrade[2])
            return GetLinear(mGrade[1],mGrade[2],mScore[1],mScore[2],record);
        else if(record > mGrade[2] && record <= mGrade[3])
            return GetLinear(mGrade[2],mGrade[3],mScore[2],mScore[3],record);
        else if(record > mGrade[3] && record <= mGrade[4])
            return GetLinear(mGrade[3],mGrade[4],mScore[3],mScore[4],record);
        else if(record > mGrade[4] && record <= mGrade[5])
            return GetLinear(mGrade[4],mGrade[5],mScore[4],mScore[5],record);
        else if(record > mGrade[5])
            return mScore[5];
        else
            return 0;
    }

}

void CScore::CalculateTotalScore()
{
    //成绩表，分数表
    float mGrade[5][6],mScore[5][6];
    mGrade[0][0] = 14;
    mGrade[0][1] = 13;
    mGrade[0][2] = 12;
    mGrade[0][3] = 11;
    mGrade[0][4] = 10;
    mGrade[0][5] = 9.5;
    mScore[0][0] = 300;
    mScore[0][1] = 400;
    mScore[0][2] = 600;
    mScore[0][3] = 900;
    mScore[0][4] = 1300;
    mScore[0][5] = 1600;

    mGrade[1][0] = 17;
    mGrade[1][1] = 16;
    mGrade[1][2] = 15;
    mGrade[1][3] = 14;
    mGrade[1][4] = 13;
    mGrade[1][5] = 12;
    mScore[1][0] = 300;
    mScore[1][1] = 400;
    mScore[1][2] = 600;
    mScore[1][3] = 900;
    mScore[1][4] = 1300;
    mScore[1][5] = 1600;

    mGrade[2][0] = 6;
    mGrade[2][1] = 5.5;
    mGrade[2][2] = 5;
    mGrade[2][3] = 4.5;
    mGrade[2][4] = 4;
    mGrade[2][5] = 3.5;
    mScore[2][0] = 200;
    mScore[2][1] = 300;
    mScore[2][2] = 500;
    mScore[2][3] = 800;
    mScore[2][4] = 1200;
    mScore[2][5] = 1700;

    mGrade[3][0] = 1.7;
    mGrade[3][1] = 1.9;
    mGrade[3][2] = 2.1;
    mGrade[3][3] = 2.25;
    mGrade[3][4] = 2.35;
    mGrade[3][5] = 2.45;
    mScore[3][0] = 200;
    mScore[3][1] = 300;
    mScore[3][2] = 500;
    mScore[3][3] = 800;
    mScore[3][4] = 1200;
    mScore[3][5] = 1700;

    mGrade[4][0] = 14;
    mGrade[4][1] = 16;
    mGrade[4][2] = 18;
    mGrade[4][3] = 20;
    mGrade[4][4] = 22;
    mGrade[4][5] = 24;
    mScore[4][0] = 100;
    mScore[4][1] = 200;
    mScore[4][2] = 400;
    mScore[4][3] = 700;
    mScore[4][4] = 1100;
    mScore[4][5] = 1600;
    m_totalscore = 0;
    for(int i=0; i<5; i++)
    {
        m_record[i].m_score = GetScore(&mGrade[i][0], &mScore[i][0],m_record[i].m_record);
        m_totalscore += m_record[i].m_score;
    }
}
