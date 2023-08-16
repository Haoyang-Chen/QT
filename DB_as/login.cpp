#include "login.h"
#include "mainwindow.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        db = QSqlDatabase::database("qt_sql_default_connection");
    else
        db = QSqlDatabase::addDatabase("QSQLITE");
    QString path = QCoreApplication::applicationDirPath();
    qDebug()<<path;
    db.setDatabaseName("DB_as.db");
    qDebug()<<db.open();
    QStringList str_table=db.tables();
    qDebug()<<str_table;
}

login::~login()
{
    delete ui;
}

void login::on_login_2_clicked()
{
    QString name=this->ui->name->text();
    QString pwd =this->ui->pwd->text();
    QSqlQuery query("",db);
    query.exec(QString("select pwd "
                       "from users "
                       "where name='%1';").arg(name));
    query.first();
//    qDebug()<<query.value(0);
    if (pwd==query.value(0).toString()){
        MainWindow *w=new MainWindow();
        w->show();
        this->close();
    }
    else{
        QMessageBox::information(this,"infor","密码错误");
    }
}


void login::on_exit_clicked()
{
    exit(0);
}



void login::on_register_2_clicked()
{
    QString name=this->ui->name->text();
    QString pwd=this->ui->pwd->text();
    QSqlQuery query("",db);
    if(query.exec(QString("insert into users values ('%1','%2');").arg(name).arg(pwd)))
        QMessageBox::information(this,"infor","注册成功，请登录");
    else{
        QMessageBox::information(this,"infor","注册失败");
        qDebug()<<query.lastError().text();
    }
}

