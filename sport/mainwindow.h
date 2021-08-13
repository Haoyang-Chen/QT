#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "sportsmaninfotable.h"
#include <QStandardItemModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //在表格中显示报名表
    void ShowSignupTable();
    //在表格中显示成绩表
    void ShowGradeTable();
    //在表格中显示领奖名单
    void ShowWinList();
    //在表格中显示筛选名单
    void ShowSpecialList(int typeID, int RatioID, float valuedata);

protected:
    virtual void resizeEvent(QResizeEvent *event) override;

private slots:
    void on_actionOpen_triggered();//打开文件操作

    void on_actionSave_triggered();

    void on_actionbaoming_triggered();

    void on_actionxianshibaom_triggered();

    void on_actionhengji_triggered();

    void on_ShowInfotableView_changed();

    void on_actionlingjiangmingdan_triggered();

    void on_actionmingdanshaixuan_triggered();

private:
    Ui::MainWindow *ui; //窗口类
    QStandardItemModel * sportsmanInforModel; //显示表格信息数据模型
    SportsManInfoTable m_InfoTable; //数据汇总类
    int m_iCurTable; //表示当前表格显示的信息，0--初始状态；1--显示是运动员信息；2--显示是运动员成绩；3--显示领奖名单；4--显示筛选名单
};
#endif // MAINWINDOW_H
