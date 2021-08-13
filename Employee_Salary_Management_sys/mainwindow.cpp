//此主界面
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qdir.h"
#include "qfiledialog.h"
#include "Employee.h"
#include <QStandardItem>
#include <qvariant.h>
#include <QMessageBox>
#include <QAbstractItemDelegate>
#include <QModelIndex>
#include <QString>
#include "readonlydelegate.h"
#include "dialogadd.h"
#include "dialogsal.h"
#include "dialogfind.h"
#include "dialogerror.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->managetableView->setSelectionMode(QAbstractItemView::SingleSelection);      //改为单选模式
    ui->managetableView->setSelectionBehavior(QAbstractItemView::SelectItems);      //改为选定项目模式

    manageModel= new QStandardItemModel;                                            //开辟新内存

    ui->managetableView->setModel(manageModel);                                     //链接表格与显示对象
    connect(ui->managetableView->itemDelegate(),&QAbstractItemDelegate::closeEditor,this,&MainWindow::on_manageTableView_changed);
    m_iCurTable=0;                                                                  //当前界面初始化为0
}

MainWindow::~MainWindow()
{
    delete ui;
    delete manageModel;
}

void MainWindow::on_manageTableView_changed()                                       //当表格内容被修改时调用
{
    QModelIndex index = ui->managetableView->currentIndex();                        //index记录当前点选的位置
    int iemployee=m_row;                                                            //提出行，为对应员工索引
    int iCol=index.column();                                                        //列为对应项目索引
    Employee & employee=m_manage.GetEmployee(iemployee);                            //拿取对应员工
    QVariant data;                                                                  //data记录变化后的数据
    switch (m_iCurTable) {                                                          //判断当前是员工窗口还是工资窗口
    case 1:                                                                         //此时为员工界面
        data=manageModel->data(index);                                              //提出改动的信息
        switch (iCol)                                                               //判断当前改动的对应内容
        {
        case 0:
            employee.m_id=data.toString();                                          //改动的是工号
            break;
        case 1:
            employee.m_name=data.toString();                                        //改动的是姓名
            break;
        case 2:
            employee.m_age=data.toString();                                         //改动的是年龄
            break;
        case 3:
            employee.m_date=data.toString();                                        //改动的是入职日期
            break;
        case 4:
            employee.m_address=data.toString();                                     //改动的是地址
            break;
        case 5:
            employee.m_tel=data.toString();                                         //改动的是电话
            break;
        default:
            break;
        }
        ShowEmpInfo();                                                              //刷新显示员工信息
        break;
    case 2:                                                                         //此时为工资界面
        data = manageModel->data(index);                                            //提出改动的数据
        switch (iCol) {
        case 2:
            employee.m_income.sala[index.row()].m_month=data.toString();            //改动的是月份
            break;
        case 3:
            employee.m_income.sala[index.row()].m_J_G=data.toString();              //改动的是基本工资
            break;
        case 4:
            employee.m_income.sala[index.row()].m_GW_G=data.toString();             //改动的是岗位工资
            break;
        case 5:
            employee.m_income.sala[index.row()].m_GL_G=data.toString();             //改动的是工龄工资
            break;
        case 6:
            employee.m_income.sala[index.row()].m_J_T=data.toString();              //改动的是津贴
            break;
        case 7:
            employee.m_income.sala[index.row()].m_G_T=data.toString();              //改动的是岗贴
            break;
        case 8:
            employee.m_income.sala[index.row()].m_B_T=data.toString();              //改动的是补贴
            break;
        case 9:
            employee.m_income.sala[index.row()].m_F_T=data.toString();              //改动的是房贴
            break;
        case 10:
            employee.m_income.sala[index.row()].m_JT_T=data.toString();             //改动的是交通补贴
            break;
        default:
            break;
        }
        ShowSalInfo(employee);                                                      //刷新显示工资信息
        break;

    }
}


void MainWindow::resizeEvent(QResizeEvent *event)                                   //表格随窗口大小变化
{
    QMainWindow::resizeEvent(event);

    int x =this->frameGeometry().width();
    int y=this->frameGeometry().height();

    ui->managetableView->setGeometry(5,5,x,y);
}

void MainWindow::ShowEmpInfo()                                                      //显示员工信息
{
    m_row=-1;                                                                       //员工索引初始化为-1
    m_row1=-1;                                                                      //员工工资索引初始化为-1
    m_iCurTable=1;                                                                  //当前界面状态记录为1
    manageModel->clear();                                                           //清空当前表格
    manageModel->setColumnCount(6);                                                 //设置列数为6

    QStringList templist;                                                           //创建临时表头
    templist.append("工号");                                                         //添加项目名称
    templist.append("姓名");
    templist.append("年龄");
    templist.append("入职信息");
    templist.append("住址");
    templist.append("电话");
    manageModel->setHorizontalHeaderLabels(templist);                               //设置表头

    int RowCnt=m_manage.get_Emp_Num();                                              //获取列数
    manageModel->setRowCount(RowCnt);                                               //设置列数

    QStandardItem *aTempItem;                                                       //临时指针变量
    QString tempStr;                                                                //临时字符串变量
    for (int i=0;i<RowCnt;++i)
    {
        Employee tempemp=m_manage.GetEmployee(i);                                   //拿取当前员工

        tempStr=tempemp.m_id;                                                       //工号转换
        aTempItem=new QStandardItem(tempStr);                                       //开辟新内存
        manageModel->setItem(i,0,aTempItem);                                        //导入数据

        aTempItem=new QStandardItem(tempemp.m_name);
        manageModel->setItem(i,1,aTempItem);

        aTempItem=new QStandardItem(tempemp.m_age);
        manageModel->setItem(i,2,aTempItem);

        aTempItem=new QStandardItem(tempemp.m_date);
        manageModel->setItem(i,3,aTempItem);

        aTempItem=new QStandardItem(tempemp.m_address);
        manageModel->setItem(i,4,aTempItem);

        aTempItem=new QStandardItem(tempemp.m_tel);
        manageModel->setItem(i,5,aTempItem);

    }
    ReadOnlyDelegate * readOnlyDelegate=new ReadOnlyDelegate(this);                 //新建只读类的指针
    ui->managetableView->setItemDelegateForColumn(0,readOnlyDelegate);              //设置工号为只读
}

void MainWindow::ShowSalInfo(Employee employee)                                     //显示工资信息，传入当前员工
{
    m_iCurTable=2;                                                                  //当前界面状态记录为2
    manageModel->clear();                                                           //清空表格
    manageModel->setColumnCount(14);                                                //设置列数为14

    QStringList templist;                                                           //临时表头
    templist.append("工号");                                                         //添加项目名称
    templist.append("姓名");
    templist.append("月份");
    templist.append("基本工资");
    templist.append("岗位工资");
    templist.append("工龄工资");
    templist.append("津贴");
    templist.append("岗贴");
    templist.append("补贴");
    templist.append("房贴");
    templist.append("交通补贴");
    templist.append("总工资");
    templist.append("个人所得税");
    templist.append("实发数");
    manageModel->setHorizontalHeaderLabels(templist);                               //设置表头

    int RowCnt=employee.m_income.sala.size();                                       //获取行数
    manageModel->setRowCount(RowCnt);                                               //设置行数

//    QModelIndex index = ui->managetableView->currentIndex();
//    int iemployee=index.row();
//    Employee & employee=m_manage.GetEmployee(iemployee);

    QStandardItem *aTempItem;                                                       //临时指针变量
    QString tempStr;                                                                //临时字符串变量
    for (int i=0;i<RowCnt;++i)
    {
        employee.m_income.sala[i].m_totalsalary=employee.m_income.sala[i].CalucateTotal();  //计算总收入
        aTempItem=new QStandardItem(employee.m_id);                                 //导入工号
        manageModel->setItem(i,0,aTempItem);

        aTempItem=new QStandardItem(employee.m_name);                               //导入姓名
        manageModel->setItem(i,1,aTempItem);

        aTempItem=new QStandardItem(employee.m_income.sala[i].m_month);             //导入月份
        manageModel->setItem(i,2,aTempItem);

        aTempItem=new QStandardItem(employee.m_income.sala[i].m_J_G);               //导入基本工资
        manageModel->setItem(i,3,aTempItem);

        aTempItem=new QStandardItem(employee.m_income.sala[i].m_GW_G);              //导入岗位工资
        manageModel->setItem(i,4,aTempItem);

        aTempItem=new QStandardItem(employee.m_income.sala[i].m_GL_G);              //导入工龄工资
        manageModel->setItem(i,5,aTempItem);

        aTempItem=new QStandardItem(employee.m_income.sala[i].m_J_T);               //导入津贴
        manageModel->setItem(i,6,aTempItem);

        aTempItem=new QStandardItem(employee.m_income.sala[i].m_G_T);               //导入岗贴
        manageModel->setItem(i,7,aTempItem);

        aTempItem=new QStandardItem(employee.m_income.sala[i].m_B_T);               //导入补贴
        manageModel->setItem(i,8,aTempItem);

        aTempItem=new QStandardItem(employee.m_income.sala[i].m_F_T);               //导入房贴
        manageModel->setItem(i,9,aTempItem);

        aTempItem=new QStandardItem(employee.m_income.sala[i].m_JT_T);              //导入交通补贴
        manageModel->setItem(i,10,aTempItem);

        aTempItem=new QStandardItem(QString::number(employee.m_income.sala[i].CalucateTotal()));
        manageModel->setItem(i,11,aTempItem);                                       //导入总工资

        aTempItem=new QStandardItem(employee.m_income.sala[i].Calculate_Tax());     //导入个人所得税
        manageModel->setItem(i,12,aTempItem);

        aTempItem=new QStandardItem(QString::number(employee.m_income.sala[i].CalucateTotal() -employee.m_income.sala[i].Calculate_Tax().toFloat()));
        manageModel->setItem(i,13,aTempItem);                                       //导入实发数

    }
    ReadOnlyDelegate* readOnlyDelegate=new ReadOnlyDelegate(this);
    ui->managetableView->setItemDelegateForColumn(0, readOnlyDelegate);             //设置工号只读
    ui->managetableView->setItemDelegateForColumn(1, readOnlyDelegate);             //设置姓名只读
}



void MainWindow::on_actionSalary_triggered()                                        //显示员工工资信息触发
{
    if (ui->managetableView->currentIndex().isValid())                              //当前已经选定员工
    {
        QModelIndex index = ui->managetableView->currentIndex();
        int iemployee=index.row();
        Employee & employee=m_manage.GetEmployee(iemployee);                        //获取员工
        ShowSalInfo(employee);                                                      //显示信息
    }
}


void MainWindow::on_actionEmployee_triggered()                                      //显示员工信息触发
{
    ShowEmpInfo();                                                                  //显示员工信息
}

void MainWindow::on_actionopen_triggered()                                          //打开文件触发
{
    QString curPath = QDir::currentPath();
    QString dlgTitle = "选择一个文件";
    QString filter = "文本文件(*.txt);;所有文件(*.*)";
    QString aFileName = QFileDialog::getOpenFileName(this, dlgTitle, curPath, filter);

    if(aFileName.isEmpty())
        return;

    //创建成功，打开文件
    m_manage.ReadFile(aFileName);
    ShowEmpInfo();
}

void MainWindow::on_actionsave_triggered()                                          //保存文件触发
{
    QString curPath = QDir::currentPath();
    QString dlgTitle = "另存为一个文件";
    QString filter = "文本文件(*.txt);;所有文件(*.*)";
    QString aFileName = QFileDialog::getSaveFileName(this, dlgTitle, curPath, filter);
    if(aFileName.isEmpty())
        return;

    m_manage.SaveFile(aFileName);

}

void MainWindow::on_actionadd_triggered()                                           //添加员工信息触发
{
    Dialogadd dlgadd(this);
    int ret = dlgadd.exec();                                                        //以模态方式显示对话框
    if(ret==QDialog::Accepted)
    {//OK按钮被按下
        Employee tempemployee;                                                      //新建员工对象
        tempemployee.m_id = dlgadd.m_id();
        tempemployee.m_name=dlgadd.m_name();
        tempemployee.m_age=dlgadd.m_age();
        tempemployee.m_date=dlgadd.m_date();
        tempemployee.m_address=dlgadd.m_address();
        tempemployee.m_tel=dlgadd.m_tel();
        m_manage.AddEmployee(tempemployee);                                         //拷贝构造
        ShowEmpInfo();                                                              //刷新显示员工信息
    }
}

void MainWindow::on_actionaddsalary_triggered()                                     //添加工资记录触发
{
    if(ui->managetableView->currentIndex().isValid())                               //当前已选定员工
    {
        QModelIndex index = ui->managetableView->currentIndex();                    //拿取当前员工
        int iemployee=index.row();
        Employee & employee=m_manage.GetEmployee(iemployee);
        //ShowSalInfo(employee);
        Dialogsal dlgaddsal(this);                                                  //显示添加窗口
        int ret =dlgaddsal.exec();
        if (ret==QDialog::Accepted)
        {
            Salary tempsalary;                                                      //新建工资对象
            tempsalary.m_month=dlgaddsal.m_month();
            tempsalary.m_J_G=dlgaddsal.m_J_G();
            tempsalary.m_GW_G=dlgaddsal.m_GW_G();
            tempsalary.m_GL_G=dlgaddsal.m_GL_G();
            tempsalary.m_J_T=dlgaddsal.m_J_T();
            tempsalary.m_G_T=dlgaddsal.m_G_T();
            tempsalary.m_B_T=dlgaddsal.m_B_T();
            tempsalary.m_F_T=dlgaddsal.m_F_T();
            tempsalary.m_JT_T=dlgaddsal.m_JT_T();
            tempsalary.m_totalsalary=tempsalary.CalucateTotal();
            employee.m_income.sala.push_back(tempsalary);
            ShowSalInfo(employee);                                                  //刷新显示工资信息
            employee.m_income.sal_num+=1;                                           //工资记录数加一
        }
    }
}

void MainWindow::on_actiondelete_triggered()                                        //删除触发
{
    if(m_row>=0 && m_row1>=0)                                                       //选中选项
    {
        if (m_iCurTable==1)                                                         //选中的是员工
        {
            m_manage.m_Num_Emp.remove(m_row);
            ShowEmpInfo();                                                          //刷新显示
        }
        if (m_iCurTable==2)                                                         //选中的是工资记录
        {
            m_manage.GetEmployee(m_row).m_income.sala.remove(m_row1);
            ShowSalInfo(m_manage.GetEmployee(m_row));                               //刷新显示
        }
    }
}

void MainWindow::on_managetableView_clicked(const QModelIndex &index)               //选定表格中项目
{

    if(m_iCurTable==1)                                                              //员工界面选定
    {
        m_row=index.row();                                                          //记录员工
    }
    if(m_iCurTable==2)                                                              //工资界面选定
    {
        m_row1=index.row();                                                         //记录工资
    }

}

void MainWindow::on_actionfind_triggered()                                          //查找触发
{
    Dialogfind dlgfind(this);
    int ret=dlgfind.exec();
    if(ret==QDialog::Accepted)
    {
        QString id =dlgfind.id();
        int index=-1;
        for (int i=0;i<m_manage.get_Emp_Num();i++)                                  //遍历
        {
            if (m_manage.m_Num_Emp[i].m_id==id)
            {
                index=i;
                break;
            }

        }
        if(index==-1)                                                               //未找到
        {
            Dialogerror dlgerr(this);
            int ret1=dlgerr.exec();
            if(ret1==QDialog::Accepted)
            {
                return;
            }
        }
        m_iCurTable=1;                                                              //当前窗口记录为1
        manageModel->clear();                                                       //清空
        manageModel->setColumnCount(6);                                             //初始化6列

        QStringList templist;                                                       //以下为单独显示一个员工信息
        templist.append("工号");
        templist.append("姓名");
        templist.append("年龄");
        templist.append("入职信息");
        templist.append("住址");
        templist.append("电话");
        manageModel->setHorizontalHeaderLabels(templist);

        manageModel->setRowCount(1);

        QStandardItem *aTempItem;
        QString tempStr;
        Employee tempemp=m_manage.GetEmployee(index);
        tempStr=tempemp.m_id;
        aTempItem=new QStandardItem(tempStr);
        manageModel->setItem(0,0,aTempItem);
        aTempItem=new QStandardItem(tempemp.m_name);
        manageModel->setItem(0,1,aTempItem);
        aTempItem=new QStandardItem(tempemp.m_age);
        manageModel->setItem(0,2,aTempItem);
        aTempItem=new QStandardItem(tempemp.m_date);
        manageModel->setItem(0,3,aTempItem);
        aTempItem=new QStandardItem(tempemp.m_address);
        manageModel->setItem(0,4,aTempItem);
        aTempItem=new QStandardItem(tempemp.m_tel);
        manageModel->setItem(0,5,aTempItem);
        ReadOnlyDelegate * readOnlyDelegate=new ReadOnlyDelegate(this);
        ui->managetableView->setItemDelegateForColumn(0,readOnlyDelegate);
    }
}
