#ifndef GET_INFO_H
#define GET_INFO_H

#include <QWidget>

namespace Ui {
class get_info;
}

class get_info : public QWidget
{
    Q_OBJECT

public:
    explicit get_info(QWidget *parent = nullptr);
    ~get_info();

private:
    Ui::get_info *ui;
};

#endif // GET_INFO_H
