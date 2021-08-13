//此为查找员工时弹出的输入工号界面
#ifndef DIALOGFIND_H
#define DIALOGFIND_H

#include <QDialog>

namespace Ui {
class Dialogfind;
}

class Dialogfind : public QDialog
{
    Q_OBJECT

public:
    explicit Dialogfind(QWidget *parent = nullptr);
    ~Dialogfind();
    QString id();           //工号

private:
    Ui::Dialogfind *ui;
};

#endif // DIALOGFIND_H
