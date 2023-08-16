#include "center.h"
#include "ui_center.h"
#include "mainwindow.h"

center::center( MainWindow *window, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::center)
{
    ui->setupUi(this);
    this->window=window;
    QImage *raw_img=window->raw_img;
    int height=raw_img->height();
    int width=raw_img->width();
    ui->scrollArea->setGeometry(0,0,width,height);
    ui->label->setScaledContents(true);

    ui->label->setGeometry(0,0,width,height);
    ui->label->setPixmap(QPixmap::fromImage(*raw_img));
    ui->scrollArea->setWidget(ui->label);
}

void center::mousePressEvent(QMouseEvent *event){
    if(event->button()==Qt::LeftButton){
        this->window->scale_=this->window->scale;
        this->window->cx_=this->window->cx;
        this->window->cy_=this->window->cy;
        this->window->H_rev_=this->window->H_rev;
        this->window->Gray_rev_=this->window->Gray_rev;
        this->window->scale_=this->window->scale;
        this->window->angle_=this->window->angle;
        this->window->win_pos_=this->window->win_pos;
        this->window->win_wid_=this->window->win_wid;
        this->window->cx=event->position().x();
        this->window->cy=event->position().y();
        this->close();
    }
}

center::~center()
{
    delete ui;
}
