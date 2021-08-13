#ifndef CSPORTMAN_H
#define CSPORTMAN_H
#include <qdatetime.h>
#include <qstring.h>
#include "cscore.h"
#include <QTextStream>

class CSportMan
{
public:
    CSportMan();

    CSportMan(const CSportMan & man);
    CSportMan& operator= (const CSportMan& man);
    virtual ~CSportMan();

    void SaveSportman(QTextStream &aStream);
    void ReadSportman(QTextStream &aStream);

    //号码，姓名，出生年月，身高，体重，成绩，名次
    int			 m_number;
    QString		 m_name;
    QDate        m_date;
    float        m_height;
    float        m_weight;

    CScore       m_score;
    int          m_place;//名次
};

#endif // CSPORTMAN_H
