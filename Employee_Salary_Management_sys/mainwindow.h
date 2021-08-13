//此为窗口主体mainwindow的头文件
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include "manage.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void ShowEmpInfo();                                                 //显示职工信息
    void ShowSalInfo(Employee employee);                                //显示工资信息
    int m_row;                                                          //当前选定的员工编号
    int m_row1;                                                         //当前选定的工资编号

protected:
    virtual void resizeEvent(QResizeEvent *event) override;             //窗口大小变换时的辅助函数

private slots:
    void on_manageTableView_changed();                                  //表格显示发生变化的槽函数

    void on_actionSalary_triggered();                                   //点选显示职工工资的槽函数

    void on_actionEmployee_triggered();                                 //点选显示职工信息的槽函数

    void on_actionopen_triggered();                                     //点选打开文件的槽函数

    void on_actionsave_triggered();                                     //点选保存文件的槽函数

    void on_actionadd_triggered();                                      //点选添加员工信息的槽函数

    void on_actionaddsalary_triggered();                                //点选添加工资信息的槽函数

    void on_actiondelete_triggered();                                   //点选删除项目的槽函数

    void on_managetableView_clicked(const QModelIndex &index);          //点击显示表格时的槽函数

    void on_actionfind_triggered();                                     //点击查找时的槽函数

private:
    Ui::MainWindow *ui;
    QStandardItemModel * manageModel;                                   //表格对象
    manage m_manage;                                                    //manage类对象
    int m_iCurTable;                                                    //记录当前所在页面的成员变量
};
#endif // MAINWINDOW_H
