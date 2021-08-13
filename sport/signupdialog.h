#ifndef SIGNUPDIALOG_H
#define SIGNUPDIALOG_H

#include <QDialog>
#include <QString>
#include <QDate>

namespace Ui {
class SignupDialog;
}

class SignupDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SignupDialog(QWidget *parent = nullptr);
    ~SignupDialog();

    QString Name(); //返回运动员姓名
    int Number(); //返回运动员号码
    QDate BirthDate(); //返回运动员生日
    float SportsmanHeight(); //返回运动员身高
    float SportsmanWeight(); //返回运动员体重

private:
    Ui::SignupDialog *ui;
};

#endif // SIGNUPDIALOG_H
