#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qdir.h"
#include "qfiledialog.h"
#include "signupdialog.h"
#include "csportman.h"
#include <QStandardItem>
#include <qvariant.h>
#include <QMessageBox>
#include <QAbstractItemDelegate>
#include <QModelIndex>
#include "readonlydelegate.h"
#include "selectdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->ShowInfotableView->setSelectionMode(QAbstractItemView::SingleSelection); //单次选择
    ui->ShowInfotableView->setSelectionBehavior(QAbstractItemView::SelectItems); //选中一个item

    sportsmanInforModel = new QStandardItemModel();

    //建立关联
    ui->ShowInfotableView->setModel(sportsmanInforModel);

    connect(ui->ShowInfotableView->itemDelegate(), &QAbstractItemDelegate::closeEditor, this, &MainWindow::on_ShowInfotableView_changed);

    m_iCurTable = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete sportsmanInforModel;
}

//void MainWindow::on_actionOpen_triggered()
//{
//    QString curPath = QDir::currentPath();
//    QString dlgTitle = "选择一个文件";
//    QString filter = "文本文件(*.txt);;所有文件(*.*)";
//    QString aFileName = QFileDialog::getOpenFileName(this, dlgTitle, curPath, filter);

//    if(aFileName.isEmpty())
//        return;

//    //创建成功，打开文件
//    m_InfoTable.ReadSportsmanFromFile(aFileName);
//    ShowSignupTable();

//}

//void MainWindow::on_actionSave_triggered()
//{
//    QString curPath = QDir::currentPath();
//    QString dlgTitle = "另存为一个文件";
//    QString filter = "文本文件(*.txt);;所有文件(*.*)";
//    QString aFileName = QFileDialog::getSaveFileName(this, dlgTitle, curPath, filter);
//    if(aFileName.isEmpty())
//        return;

//    m_InfoTable.SaveSportsmanToFile(aFileName);

//}

void MainWindow::on_actionbaoming_triggered()
{
    SignupDialog dlgSignup(this);
    int ret = dlgSignup.exec(); //以模态方式显示对话框
    if(ret==QDialog::Accepted)
    {//OK按钮被按下
        CSportMan tempsportman;
        tempsportman.m_name = dlgSignup.Name();
        tempsportman.m_number = dlgSignup.Number();
        tempsportman.m_date = dlgSignup.BirthDate();
        tempsportman.m_height = dlgSignup.SportsmanHeight();
        tempsportman.m_weight = dlgSignup.SportsmanWeight();
        m_InfoTable.AddSportman(tempsportman);
        ShowSignupTable();
    }

}

//void MainWindow::ShowSignupTable()
//{
//    m_iCurTable = 1; //表示当前显示的是运动员信息
//    sportsmanInforModel->clear();
//    sportsmanInforModel->setColumnCount(5); //5列

//    //表头
//    //号码，姓名，出生日期，身高，体重
//    QStringList templist;
//    templist.append("号码");
//    templist.append("姓名");
//    templist.append("出生日期");
//    templist.append("身高");
//    templist.append("体重");
//    sportsmanInforModel->setHorizontalHeaderLabels(templist);

//    int RowCnt = m_InfoTable.GetSportsmanNum(); //行数（不含标题）
//    sportsmanInforModel->setRowCount(RowCnt);

//    //遍历，插入数据
//    QStandardItem *aTempItem; //临时的item
//    QString tempStr;
//    for(int i=0; i<RowCnt; ++i)
//    {
//       CSportMan tempsportman=m_InfoTable.GetSportMan(i);
//       tempStr = QString::number(tempsportman.m_number);
//       aTempItem = new QStandardItem(tempStr);
//       sportsmanInforModel->setItem(i, 0, aTempItem);
//       aTempItem = new QStandardItem(tempsportman.m_name);
//       sportsmanInforModel->setItem(i, 1, aTempItem);
//       tempStr = tempsportman.m_date.toString("yyyy-MM-dd");
//       aTempItem = new QStandardItem(tempStr);
//       sportsmanInforModel->setItem(i, 2, aTempItem);
//       tempStr = QString::number(tempsportman.m_height);
//       aTempItem = new QStandardItem(tempStr);
//       sportsmanInforModel->setItem(i, 3, aTempItem);
//       tempStr = QString::number(tempsportman.m_weight);
//       aTempItem = new QStandardItem(tempStr);
//       sportsmanInforModel->setItem(i, 4, aTempItem);
//    }
//    //设置号码为只读
//    ReadOnlyDelegate* readOnlyDelegate = new ReadOnlyDelegate(this);
//    ui->ShowInfotableView->setItemDelegateForColumn(0, readOnlyDelegate);

//}

//void MainWindow::ShowGradeTable()
//{
//    m_iCurTable = 2;//表示当前显示的是运动员成绩
//    sportsmanInforModel->clear();
//    sportsmanInforModel->setColumnCount(13); //13列

//    //表头
//    //姓名，100米成绩，100米得分，110米栏成绩，110米栏得分，1500米成绩，1500米得分，跳高成绩，跳高得分，铅球成绩，铅球得分，总分，名次
//    QStringList templist;
//    templist.append("姓名");
//    templist.append("100米成绩");
//    templist.append("100米得分");
//    templist.append("110米栏成绩");
//    templist.append("110米栏分");
//    templist.append("1500米成绩");
//    templist.append("1500米得分");
//    templist.append("跳高成绩");
//    templist.append("跳高得分");
//    templist.append("铅球成绩");
//    templist.append("铅球得分");
//    templist.append("总分");
//    templist.append("名次");
//    sportsmanInforModel->setHorizontalHeaderLabels(templist);

//    int RowCnt = m_InfoTable.GetSportsmanNum(); //行数（不含标题）
//    sportsmanInforModel->setRowCount(RowCnt);

//    //遍历，插入数据
//    QStandardItem *aTempItem; //临时的item
//    QString tempStr;
//    m_InfoTable.CalculateRank(); //计算排名
//    for(int i=0; i<RowCnt; ++i)
//    {
//        CSportMan tempsportman=m_InfoTable.GetSportMan(i);

//        aTempItem = new QStandardItem(tempsportman.m_name);
//        sportsmanInforModel->setItem(i, 0, aTempItem);

//        tempStr = QString::number(tempsportman.m_score.m_record[0].m_record);
//        aTempItem = new QStandardItem(tempStr);
//        sportsmanInforModel->setItem(i, 1, aTempItem);

//        tempStr = QString::number(tempsportman.m_score.m_record[0].m_score);
//        aTempItem = new QStandardItem(tempStr);
//        sportsmanInforModel->setItem(i, 2, aTempItem);

//        tempStr = QString::number(tempsportman.m_score.m_record[1].m_record);
//        aTempItem = new QStandardItem(tempStr);
//        sportsmanInforModel->setItem(i, 3, aTempItem);

//        tempStr = QString::number(tempsportman.m_score.m_record[1].m_score);
//        aTempItem = new QStandardItem(tempStr);
//        sportsmanInforModel->setItem(i, 4, aTempItem);

//        tempStr = QString::number(tempsportman.m_score.m_record[2].m_record);
//        aTempItem = new QStandardItem(tempStr);
//        sportsmanInforModel->setItem(i, 5, aTempItem);

//        tempStr = QString::number(tempsportman.m_score.m_record[2].m_score);
//        aTempItem = new QStandardItem(tempStr);
//        sportsmanInforModel->setItem(i, 6, aTempItem);

//        tempStr = QString::number(tempsportman.m_score.m_record[3].m_record);
//        aTempItem = new QStandardItem(tempStr);
//        sportsmanInforModel->setItem(i, 7, aTempItem);

//        tempStr = QString::number(tempsportman.m_score.m_record[3].m_score);
//        aTempItem = new QStandardItem(tempStr);
//        sportsmanInforModel->setItem(i, 8, aTempItem);

//        tempStr = QString::number(tempsportman.m_score.m_record[4].m_record);
//        aTempItem = new QStandardItem(tempStr);
//        sportsmanInforModel->setItem(i, 9, aTempItem);

//        tempStr = QString::number(tempsportman.m_score.m_record[4].m_score);
//        aTempItem = new QStandardItem(tempStr);
//        sportsmanInforModel->setItem(i, 10, aTempItem);

//        tempStr = QString::number(tempsportman.m_score.m_totalscore);
//        aTempItem = new QStandardItem(tempStr);
//        sportsmanInforModel->setItem(i, 11, aTempItem);

//        tempStr = QString::number(tempsportman.m_place);
//        aTempItem = new QStandardItem(tempStr);
//        sportsmanInforModel->setItem(i, 12, aTempItem);
//    }

//    //设置姓名、各项目得分、总分、名次为只读
//    ReadOnlyDelegate* readOnlyDelegate = new ReadOnlyDelegate(this);
//    ui->ShowInfotableView->setItemDelegateForColumn(0, readOnlyDelegate);
//    ui->ShowInfotableView->setItemDelegateForColumn(2, readOnlyDelegate);
//    ui->ShowInfotableView->setItemDelegateForColumn(4, readOnlyDelegate);
//    ui->ShowInfotableView->setItemDelegateForColumn(6, readOnlyDelegate);
//    ui->ShowInfotableView->setItemDelegateForColumn(8, readOnlyDelegate);
//    ui->ShowInfotableView->setItemDelegateForColumn(10, readOnlyDelegate);
//    ui->ShowInfotableView->setItemDelegateForColumn(11, readOnlyDelegate);
//    ui->ShowInfotableView->setItemDelegateForColumn(12, readOnlyDelegate);

//}

//void MainWindow::ShowWinList()
//{
//    m_iCurTable = 3;//表示当前显示的是领奖名单
//    sportsmanInforModel->clear();
//    sportsmanInforModel->setColumnCount(3); //3列

//    //表头
//    //姓名，总分，名次
//    QStringList templist;
//    templist.append("姓名");
//    templist.append("总分");
//    templist.append("名次");
//    sportsmanInforModel->setHorizontalHeaderLabels(templist);

//    int RowCnt = m_InfoTable.GetSportsmanNum(); //行数（不含标题）
//    sportsmanInforModel->setRowCount(RowCnt);

//    //遍历，插入数据
//    QStandardItem *aTempItem; //临时的item
//    QString tempStr;
//    for(int i=0; i<RowCnt; ++i)
//    {
//       CSportMan tempsportman=m_InfoTable.GetSportMan(i);
//       aTempItem = new QStandardItem(tempsportman.m_name);
//       sportsmanInforModel->setItem(i, 0, aTempItem);
//       tempStr = QString::number(tempsportman.m_score.m_totalscore);
//       aTempItem = new QStandardItem(tempStr);
//       sportsmanInforModel->setItem(i, 1, aTempItem);
//       tempStr = QString::number(tempsportman.m_place);
//       aTempItem = new QStandardItem(tempStr);
//       sportsmanInforModel->setItem(i, 2, aTempItem);
//    }
//    //设置号码为只读
//    ReadOnlyDelegate* readOnlyDelegate = new ReadOnlyDelegate(this);
//    ui->ShowInfotableView->setItemDelegateForColumn(0, readOnlyDelegate);
//    ui->ShowInfotableView->setItemDelegateForColumn(1, readOnlyDelegate);
//    ui->ShowInfotableView->setItemDelegateForColumn(2, readOnlyDelegate);


//}

//void MainWindow::ShowSpecialList(int typeID, int RatioID, float valuedata)
//{
//    m_iCurTable = 4;//表示当前显示的是领奖名单
//    sportsmanInforModel->clear();
//    sportsmanInforModel->setColumnCount(8); //8列

//    //表头
//    //姓名，类型type，100米，110米栏，1500米，跳高，铅球，总分，名次
//    QStringList templist;
//    templist.append("姓名");
//    QString strType;
//    if(typeID==0)
//        strType = "身高";
//    else
//        strType = "体重";
//    templist.append(strType);
//    templist.append("100米");
//    templist.append("110米栏");
//    templist.append("1500米");
//    templist.append("跳高");
//    templist.append("铅球");
//    templist.append("总分");
//    templist.append("名次");
//    sportsmanInforModel->setHorizontalHeaderLabels(templist);

//    int SportsmanNum = m_InfoTable.GetSportsmanNum(); //运动员总数
//    int RowIndex = 0;

//    float Var;
//    QString strTemp;
//    QStandardItem *aTempItem; //临时的item
//    for(int i=0; i<SportsmanNum; i++)
//    {
//       CSportMan tempsportman=m_InfoTable.GetSportMan(i);

//       //筛选
//       if(typeID==0) //身高
//           Var = tempsportman.m_height;
//       else //体重
//           Var = tempsportman.m_weight;

//       switch (RatioID)
//       {
//       case 0: //高于
//           if(Var<=valuedata)
//               continue;
//           break;
//       case 1: //等于
//           if(Var!=valuedata)
//               continue;
//           break;
//       case 2: //低于
//           if(Var>=valuedata)
//               continue;
//           break;
//       default:
//           break;
//       }

//       aTempItem = new QStandardItem(tempsportman.m_name);
//       sportsmanInforModel->setItem(RowIndex, 0, aTempItem);
//       strTemp = QString::number(Var);
//       aTempItem = new QStandardItem(strTemp);
//       sportsmanInforModel->setItem(RowIndex, 1, aTempItem);
//       strTemp = QString::number(tempsportman.m_score.m_record[0].m_record);
//       aTempItem = new QStandardItem(strTemp);
//       sportsmanInforModel->setItem(RowIndex, 2, aTempItem);
//       strTemp = QString::number(tempsportman.m_score.m_record[1].m_record);
//       aTempItem = new QStandardItem(strTemp);
//       sportsmanInforModel->setItem(RowIndex, 3, aTempItem);
//       strTemp = QString::number(tempsportman.m_score.m_record[2].m_record);
//       aTempItem = new QStandardItem(strTemp);
//       sportsmanInforModel->setItem(RowIndex, 4, aTempItem);
//       strTemp = QString::number(tempsportman.m_score.m_record[3].m_record);
//       aTempItem = new QStandardItem(strTemp);
//       sportsmanInforModel->setItem(RowIndex, 5, aTempItem);
//       strTemp = QString::number(tempsportman.m_score.m_record[4].m_record);
//       aTempItem = new QStandardItem(strTemp);
//       sportsmanInforModel->setItem(RowIndex, 6, aTempItem);
//       strTemp = QString::number(tempsportman.m_score.m_totalscore);
//       aTempItem = new QStandardItem(strTemp);
//       sportsmanInforModel->setItem(RowIndex, 7, aTempItem);
//       strTemp = QString::number(tempsportman.m_place);
//       aTempItem = new QStandardItem(strTemp);
//       sportsmanInforModel->setItem(RowIndex, 8, aTempItem);

//       RowIndex++;
//    }

//}

//void MainWindow::on_actionxianshibaom_triggered()
//{
//    ShowSignupTable();

//}

//void MainWindow::on_actionhengji_triggered()
//{
//    ShowGradeTable();
//}

//void MainWindow::on_ShowInfotableView_changed()
//{
//    QModelIndex index = ui->ShowInfotableView->currentIndex();
//    int isportman = index.row(); //哪个运动员
//    int iCol = index.column(); //哪个列
//    CSportMan & sportman = m_InfoTable.GetSportMan(isportman); //获取当前运动员，一定要是引用
//    QVariant data; //数据

//    switch (m_iCurTable) //根据当前选择的表格不同进行对应的运动员信息的修改
//    {
//    case 1: //当前是运动员信息表
//        //修改运动员对应的数值
//        data = sportsmanInforModel->data(index);//获取数值

//        switch (iCol)
//        {
//        case 0: //号码
//            sportman.m_number = data.toInt();
//            break;
//        case 1: //姓名
//            sportman.m_name = data.toString();
//            break;
//        case 2:
//            sportman.m_date = data.toDate();
//            break;
//        case 3:
//            sportman.m_height = data.toFloat();
//            break;
//        case 4:
//            sportman.m_weight = data.toFloat();
//            break;
//        default:
//            break;
//        }
//        break;
//   case 2://当前是运动员成绩表
//        //姓名，各项成绩得分，总分和名次这里修改了都不起作用
//        data = sportsmanInforModel->data(index);//获取数值
//        switch (iCol)
//        {
//        case 1: //110米成绩
//            sportman.m_score.m_record[0].m_record = data.toFloat();
//            break;
//        case 3://110米栏成绩
//            sportman.m_score.m_record[1].m_record = data.toFloat();
//            break;
//        case 5://1500米成绩
//            sportman.m_score.m_record[2].m_record = data.toFloat();
//            break;
//        case 7://跳高成绩
//            sportman.m_score.m_record[3].m_record = data.toFloat();
//            break;
//        case 9:// 铅球成绩
//            sportman.m_score.m_record[4].m_record = data.toFloat();
//            break;
//        default:
//            break;
//        }
//        sportman.m_score.CalculateTotalScore();
//        m_InfoTable.CalculateRank(); //更新排名
//        ShowGradeTable(); //重新显示，更新数据
//        break;

//    }

//}

//void MainWindow::resizeEvent(QResizeEvent *event)
//{
//    //父类的保持
//    QMainWindow::resizeEvent(event);

//    int x = this->frameGeometry().width();
//    int y = this->frameGeometry().height();

//    //窗口改变大小的时候列表控件跟着改变
//    ui->ShowInfotableView->setGeometry(5,5,x*0.99,y*0.99);
//}

//void MainWindow::on_actionlingjiangmingdan_triggered()
//{
//    ShowWinList();
//}

//void MainWindow::on_actionmingdanshaixuan_triggered()
//{
//    SelectDialog dlgSelectDlg(this);
//    int ret = dlgSelectDlg.exec(); //以模态方式显示对话框
//    int typeID;
//    float dataValue;
//    int radioType; //选中的是高于、等于还是低于
//    if(ret==QDialog::Accepted)
//    {//OK按钮被按下
//        typeID = dlgSelectDlg.m_iSelectIndex;
//        dataValue = dlgSelectDlg.GetValue();
//        radioType = dlgSelectDlg.m_iRadioID;
//        ShowSpecialList(typeID, radioType, dataValue);
//    }

//}
