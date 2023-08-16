#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>
#include <QMessageBox>

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    QSqlDatabase db;
    ~login();

private slots:
    void on_login_2_clicked();

    void on_exit_clicked();

    void on_register_2_clicked();

private:
    Ui::login *ui;
};

#endif // LOGIN_H
