#include "graywin.h"
#include "ui_graywin.h"

grayWin::grayWin(MainWindow *window, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::grayWin)
{
    ui->setupUi(this);
    connect(ui->clear,SIGNAL(clicked()),this,SLOT(ClearClicked()));
    connect(ui->set,SIGNAL(clicked()),this,SLOT(SetClicked()));
    this->window=window;
}

void grayWin::ClearClicked(){
    ui->position->setText(0);
    ui->width->setText(0);
}

void grayWin::SetClicked(){
    this->window->scale_=this->window->scale;
    this->window->cx_=this->window->cx;
    this->window->cy_=this->window->cy;
    this->window->H_rev_=this->window->H_rev;
    this->window->Gray_rev_=this->window->Gray_rev;
    this->window->scale_=this->window->scale;
    this->window->angle_=this->window->angle;
    this->window->win_pos_=this->window->win_pos;
    this->window->win_wid_=this->window->win_wid;
    this->window->win_pos=ui->position->text().toInt();
    this->window->win_wid=ui->width->text().toInt();
    this->close();
//    this->window->grayWinSet(this->window->win_pos,this->window->win_wid);
    this->window->showPic();
}

grayWin::~grayWin()
{
    delete ui;
}
