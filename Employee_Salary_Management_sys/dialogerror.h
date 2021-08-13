//此为查找员工时未找到的弹出界面
#ifndef DIALOGERROR_H
#define DIALOGERROR_H

#include <QDialog>

namespace Ui {
class Dialogerror;
}

class Dialogerror : public QDialog
{
    Q_OBJECT

public:
    explicit Dialogerror(QWidget *parent = nullptr);
    ~Dialogerror();

private:
    Ui::Dialogerror *ui;
};

#endif // DIALOGERROR_H
