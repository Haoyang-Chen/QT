#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "center.h"
#include "graywin.h"

using namespace std;

class Raw_img{
public:
    int **mat;
    int height;
    int width;

    Raw_img(QString fname){
        QFile f(fname);
        f.open(QIODevice::ReadOnly);
        QDataStream data(&f);
        uchar temp[4];
        data >>temp[0]>>temp[1]>>temp[2]>>temp[3];
        for(int i=0;i<4;i++){
            temp[i]=(uint)temp[i];
        }
        this->width = (temp[3]<<24)+(temp[2]<<16)+(temp[1]<<8)+temp[0];

        data >>temp[0]>>temp[1]>>temp[2]>>temp[3];
        for(int i=0;i<4;i++){
            temp[i]=(uint)temp[i];
        }
        this->height = (temp[3]<<24)+(temp[2]<<16)+(temp[1]<<8)+temp[0];

//        qDebug()<<width;
//        qDebug()<<height;

        this->mat=new int*[this->height];
        for (int i=0;i<this->height;i++)
            this->mat[i]=new int[this->width];

        for(int i=0;i<this->height;i++){
            for(int j=0;j<this->width;j++){
                data>>temp[0]>>temp[1];
                temp[0]=(ushort)temp[0];
                temp[1]=(ushort)temp[1];
                this->mat[i][j]=(int)(((((temp[1]&0x0f)<<8)+temp[0])<<4)>>4);
            }
        }
    }

    QImage* show(){
        QImage *temp=new QImage(this->width,this->height,QImage::Format_Indexed8);
        temp->setColorCount(256);
        for (int i =0;i<256;i++){
            temp->setColor(i,qRgb(i,i,i));
        }

        for (int i=0;i<this->height;i++){
            for (int j=0;j<this->width;j++){
//                qDebug()<<this->mat[i][j];
                temp->setPixel(j,i,(int)(((double)this->mat[i][j])/4095*255));
//                qDebug()<<(int)(((double)this->mat[i][j])*256/4096);
            }
        }
        return temp;
    }
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->Open,SIGNAL(clicked()),this,SLOT(openfiletriggered()));
    connect(ui->Clear,SIGNAL(clicked()),this,SLOT(ClearCanvasTriggered()));
    connect(ui->Scale,SIGNAL(valueChanged(int)),this,SLOT(ScaleSet(int)));
    connect(ui->Angle,SIGNAL(valueChanged(int)),this,SLOT(AngleSet(int)));
    connect(ui->Center_Set,SIGNAL(clicked()),this,SLOT(CenterSet()));
    connect(ui->Gray_Win_Set,SIGNAL(clicked()),this,SLOT(GrayWinSet()));
    connect(ui->Save,SIGNAL(clicked()),this,SLOT(Save()));
    connect(ui->Undo,SIGNAL(clicked()),this,SLOT(Undo()));
    connect(ui->Gray_Reverse,SIGNAL(clicked()),this,SLOT(GrayReverse()));
    connect(ui->H_Reverse,SIGNAL(clicked()),this,SLOT(HReverse()));
    ui->Angle->setEnabled(false);
    ui->Scale->setEnabled(false);
    ui->Center_Set->setEnabled(false);
    ui->Gray_Reverse->setEnabled(false);
    ui->Clear->setEnabled(false);
    ui->H_Reverse->setEnabled(false);
    ui->Save->setEnabled(false);
    ui->Undo->setEnabled(false);
    ui->Gray_Win_Set->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openfiletriggered(){
    openfile();
}

void MainWindow::ClearCanvasTriggered(){
    clear();
}

void MainWindow::openfile(){
    QString filepath = QFileDialog::getOpenFileName(this,tr("select your image"),"/Users/haoyangchen/desktop",tr("Image Files (*.png *.jpg *.bmp *.raw)"));
    if(filepath.right(3)=="raw"){
        Raw_img img(filepath);
        this->raw_img=img.show();
        this->mod_img=img.show();
        this->mat=img.mat;
    }else{
        this->raw_img = new QImage, this->mod_img = new QImage;
        if(!raw_img->load(filepath)){
            QMessageBox::information(this,tr("failed"),tr("open image failed"));
            return;
        }
        this->mod_img=this->raw_img;
        this->mat=new int*[this->raw_img->height()];
        for (int i=0;i<this->raw_img->height();i++)
            this->mat[i]=new int[this->raw_img->width()];
        for (int i=0;i<this->raw_img->height();i++)
            for (int j=0;j<this->raw_img->width();j++)
                this->mat[i][j]=this->raw_img->pixelIndex(j,i);
    }
    this->laSharpen();

    this->cx=this->cx_=raw_img->width()/2;
    this->cy=this->cy_=raw_img->height()/2;
    this->H_rev=this->H_rev_=false;
    this->Gray_rev=this->Gray_rev_=false;
    this->scale=this->scale_=1;
    this->angle=this->angle_=0;
    this->win_pos=this->win_pos_=0;
    this->win_wid=this->win_wid_=0;

    ui->raw_image->setPixmap(QPixmap::fromImage(*raw_img));
    ui->scrollArea1->setWidget(ui->raw_image);
    ui->Angle->setEnabled(true);
    ui->Scale->setEnabled(true);
    ui->Center_Set->setEnabled(true);
    ui->Gray_Reverse->setEnabled(true);
    ui->Clear->setEnabled(true);
    ui->H_Reverse->setEnabled(true);
    ui->Save->setEnabled(true);
    ui->Gray_Win_Set->setEnabled(true);
}

void MainWindow::showPic(){
    QImage *temp=new QImage(this->raw_img->width(),this->raw_img->height(),QImage::Format_Indexed8);
    temp->setColorCount(256);
    for (int i =0;i<256;i++){
        temp->setColor(i,qRgb(i,i,i));
    }
    for (int i=0;i<this->raw_img->width();i++)
        for (int j=0;j<this->raw_img->height();j++)
            temp->setPixel(i,j,this->raw_img->pixelIndex(i,j));

    if (this->win_pos||this->win_wid)
        temp=this->grayWinSet(this->win_pos,this->win_wid);
    if (this->H_rev)
        temp=this->hReverse(temp);
    if (this->Gray_rev)
        temp=this->grayReverse(temp);
    if (this->scale!=1.0)
        temp=this->scaleTrans(temp,this->scale);
    if (this->angle!=0)
        temp=this->angleTrans(temp,this->angle,this->cx,this->cy);

    this->mod_img=temp;
    ui->mod_image->setPixmap(QPixmap::fromImage(*temp));
    ui->scrollArea2->setWidget(ui->mod_image);
}

void MainWindow::clear(){
    ui->raw_image->clear();
    ui->Scale->setValue(50);
    ui->Angle->setValue(0);
    ui->mod_image->clear();
    ui->Angle->setEnabled(false);
    ui->Scale->setEnabled(false);
    ui->Center_Set->setEnabled(false);
    ui->Gray_Reverse->setEnabled(false);
    ui->Clear->setEnabled(false);
    ui->H_Reverse->setEnabled(false);
    ui->Save->setEnabled(false);
    ui->Undo->setEnabled(false);
    ui->Gray_Win_Set->setEnabled(false);
}

void MainWindow::ScaleSet(int value){
    ui->Undo->setEnabled(true);
    ui->scale_num->setText(QString::number((double)value/50));
    this->scale_=this->scale;
    this->cx_=this->cx;
    this->cy_=this->cy;
    this->H_rev_=this->H_rev;
    this->Gray_rev_=this->Gray_rev;
    this->scale_=this->scale;
    this->angle_=this->angle;
    this->win_pos_=this->win_pos;
    this->win_wid_=this->win_wid;
    this->scale=(double)value/50;
    this->showPic();
}

QImage *MainWindow::scaleTrans(QImage *raw_pic, double scale){
    int raw_height=raw_pic->height();
    int raw_width=raw_pic->width();
    int mod_height=floor(raw_height*scale);
    int mod_width=floor(raw_width*scale);
    QImage *mod_img= new QImage(mod_width,mod_height,QImage::Format_Indexed8);
    mod_img->setColorCount(256);
    for (int i =0;i<256;i++){
        mod_img->setColor(i,qRgb(i,i,i));
    }

    for (int i=0;i<mod_height;i++){
        for (int j=0;j<mod_width;j++){
            double temp_x=j/scale;
            temp_x=round(temp_x*100/100);
            double temp_y=i/scale;
            temp_y=round(temp_y*100/100);
            int x1=floor(temp_x);
            x1=min(x1,raw_width-1);
            int x2=x1+1;
            x2=min(x2,raw_width-1);
            int y1=floor(temp_y);
            y1=min(y1,raw_height-1);
            int y2=y1+1;
            y2=min(y2,raw_height-1);
            int value_1=raw_pic->pixelIndex(x1,y1);
            int value_2=raw_pic->pixelIndex(x1,y2);
            int value_3=raw_pic->pixelIndex(x2,y1);
            int value_4=raw_pic->pixelIndex(x2,y2);
            double temp_value_x=(x2-temp_x)/(x2-x1)*value_1+(temp_x-x1)/(x2-x1)*value_3;
            double temp_value_y=(x2-temp_x)/(x2-x1)*value_2+(temp_x-x1)/(x2-x1)*value_4;
            double value=(y2-temp_y)/(y2-y1)*temp_value_x+(temp_y-y1)/(y2-y1)*temp_value_y;
            mod_img->setPixel(j,i,value);
        }
    }
    return mod_img;
}


void MainWindow::AngleSet(int angle){
    ui->Undo->setEnabled(true);
    double Angle=((double)angle/180)*3.14;
    this->scale_=this->scale;
    this->cx_=this->cx;
    this->cy_=this->cy;
    this->H_rev_=this->H_rev;
    this->Gray_rev_=this->Gray_rev;
    this->scale_=this->scale;
    this->angle_=this->angle;
    this->win_pos_=this->win_pos;
    this->win_wid_=this->win_wid;
    this->angle = round(Angle*100)/100;
    ui->angle_value->setText(QString::number(Angle));
    this->showPic();
}


int get_x(int cx,int x){
    return x-cx;
}

int get_y(int cy,int y){
    return y-cy;
}

int get_x_t(int x,int y,double angle){
    return floor(x*cos(angle)-y*sin(angle));
}

int get_y_t(int x,int y, double angle){
    return floor(x*sin(angle)+y*cos(angle));
}

double get_x_o(int x_t,int y_t, double angle){
    double x=(double) ((double)x_t/sin(angle)+(double)y_t/cos(angle))/(cos(angle)/sin(angle)+sin(angle)/cos(angle));
    return x;
}

double get_y_o(int x_t,int y_t, double angle){
    double y=(double) ((double) (-x_t)/cos(angle)+(double)y_t/sin(angle))/(cos(angle)/sin(angle)+sin(angle)/cos(angle));
    return y;
}


QImage *MainWindow::angleTrans(QImage *raw_pic, double angle, int cx, int cy){
    int raw_height=raw_pic->height();
    int raw_width=raw_pic->width();

    int maxx=-1000000,minx=1000000,maxy=-1000000,miny=1000000;

    int x1=get_x(cx,0);
//    maxx=max(maxx,x1);
//    minx=min(minx,x1);

    int y1=get_y(cy,0);
//    maxy=max(maxy,y1);
//    miny=min(miny,y1);

    int x2=get_x(cx,raw_width);
//    maxx=max(maxx,x2);
//    minx=min(minx,x2);

    int y2=get_y(cy,raw_height);
//    maxy=max(maxy,y2);
//    miny=min(miny,y2);

    int x1t,x2t,x3t,x4t,y1t,y2t,y3t,y4t;

    x1t=get_x_t(x1,y1,angle);
    maxx=max(maxx,x1t);
    minx=min(minx,x1t);

    x2t=get_x_t(x1,y2,angle);
    maxx=max(maxx,x2t);
    minx=min(minx,x2t);

    x3t=get_x_t(x2,y1,angle);
    maxx=max(maxx,x3t);
    minx=min(minx,x3t);

    x4t=get_x_t(x2,y2,angle);
    maxx=max(maxx,x4t);
    minx=min(minx,x4t);

    y1t=get_y_t(x1,y1,angle);
    maxy=max(maxy,y1t);
    miny=min(miny,y1t);

    y2t=get_y_t(x1,y2,angle);
    maxy=max(maxy,y2t);
    miny=min(miny,y2t);

    y3t=get_y_t(x2,y1,angle);
    maxy=max(maxy,y3t);
    miny=min(miny,y3t);

    y4t=get_y_t(x2,y2,angle);
    maxy=max(maxy,y4t);
    miny=min(miny,y4t);

    int mod_height=maxy-miny;
    int mod_width=maxx-minx;

    QImage *mod_img = new QImage(mod_width,mod_height,QImage::Format_Indexed8);
    mod_img->setColorCount(256);
    for (int i =0;i<256;i++){
        mod_img->setColor(i,qRgb(i,i,i));
    }

    for (int i=0;i<mod_height;i++){
        for (int j=0;j<mod_width;j++)
            mod_img->setPixel(j,i,0);
    }

    for (int i=0;i<mod_height;i++){
        for (int j=0;j<mod_width;j++){
            double x=get_x_t(j-mod_width/2,i-mod_height/2,-angle)+cx;
            x=round(x*100/100);
            double y=get_y_t(j-mod_width/2,i-mod_height/2,-angle)+cy;
            y=round(y*100/100);
            int x1=floor(x);
            int x2=x1+1;
            int y1=floor(y);
            int y2=y1+1;

            if (x1>=raw_width||x1<0||x2>=raw_width||x2<0||y1>=raw_height||y1<0||y2>=raw_height||y2<0){
                mod_img->setPixel(j,i,0);
                continue;
            }

            int value_1=raw_pic->pixelIndex(x1,y1);
            int value_2=raw_pic->pixelIndex(x1,y2);
            int value_3=raw_pic->pixelIndex(x2,y1);
            int value_4=raw_pic->pixelIndex(x2,y2);

            double temp_value_x=(x2-x)/(x2-x1)*value_1+(x-x1)/(x2-x1)*value_3;
            double temp_value_y=(x2-x)/(x2-x1)*value_2+(x-x1)/(x2-x1)*value_4;
            double value=(y2-y)/(y2-y1)*temp_value_x+(y-y1)/(y2-y1)*temp_value_y;
            mod_img->setPixel(j,i,value);
        }
    }
    return mod_img;
}

void MainWindow::CenterSet(){
    center *window=new center(this);
    window->setFixedSize(this->raw_img->width(),this->raw_img->height());
    window->show();
}

void MainWindow::GrayWinSet(){
    ui->Undo->setEnabled(true);
    grayWin *window=new grayWin(this);
    window->show();
}

QImage *MainWindow::grayWinSet(int win_pos,int win_width){
    int left = win_pos-win_width/2;
    int right= win_pos+win_width/2;
    QImage *temp=new QImage(this->raw_img->width(),this->raw_img->height(),QImage::Format_Indexed8);
    temp->setColorCount(256);
    for (int i =0;i<256;i++){
        temp->setColor(i,qRgb(i,i,i));
    }
    for (int i=0;i<this->raw_img->height();i++){
        for (int j=0;j<this->raw_img->width();j++){
            if(this->mat[i][j]>=left&&this->mat[i][j]<=right){
                temp->setPixel(j,i,(1.0*this->mat[i][j]-left)/win_width*255);
            }
            else if(this->mat[i][j]<left)
                temp->setPixel(j,i,0);
            else
                temp->setPixel(j,i,255);
        }
    }
    return temp;
}

void MainWindow::laSharpen(){
    QImage *temp=new QImage(this->raw_img->width(),this->raw_img->height(),QImage::Format_Indexed8);
    temp->setColorCount(256);
    for (int i =0;i<256;i++){
        temp->setColor(i,qRgb(i,i,i));
    }
    int max=0,min=99999;

    int **ori_mat=new int*[this->raw_img->height()];
    for (int i=0;i<this->raw_img->height();i++)
        ori_mat[i]=new int[this->raw_img->width()];

    for (int i=0;i<this->raw_img->height();i++){
        for(int j=0;j<this->raw_img->width();j++){
            ori_mat[i][j]=this->mat[i][j];
        }
    }

    int **temp_mat=new int*[this->raw_img->height()];
    for (int i=0;i<this->raw_img->height();i++)
        temp_mat[i]=new int[this->raw_img->width()];
    for (int i=0;i<this->raw_img->height();i++){
        for(int j=0;j<this->raw_img->width();j++){
            temp_mat[i][j]=this->mat[i][j];
        }
    }

    for (int i=1;i<this->raw_img->width()-1;i++){
        for (int j=1;j<this->raw_img->height()-1;j++){
            int value=-ori_mat[j-1][i]-ori_mat[j+1][i]-ori_mat[j][i-1]-ori_mat[j][i+1]+9*ori_mat[j][i]-ori_mat[j-1][i-1]-ori_mat[j-1][i+1]-ori_mat[j+1][i-1]-ori_mat[j+1][i+1];

            temp_mat[j][i]=value;
            if (temp_mat[j][i]>max)
                max=temp_mat[j][i];
            if (temp_mat[j][i]<min)
                min=temp_mat[j][i];
        }
    }
    this->mat=temp_mat;
    int range=max-min;
    for (int i=0;i<this->raw_img->height();i++){
        for (int j=0;j<this->raw_img->width();j++){
            temp->setPixel(j,i,(temp_mat[i][j]-min)*255/range);
        }
    }
    this->raw_img=temp;
}

void MainWindow::Save(){
    this->save();
}

void MainWindow::save(){
    QString directory = QFileDialog::getExistingDirectory(this,tr("储存路径选择"),QDir::currentPath());
    this->mod_img->save(directory+"/save.BMP","BMP",100);
}

void MainWindow::Undo(){
    this->cx=this->cx_;
    this->cy=this->cy_;
    this->scale=this->scale_;
    this->angle=this->angle_;
    this->H_rev=this->H_rev_;
    this->Gray_rev=this->Gray_rev_;
    this->showPic();
    ui->Undo->setEnabled(false);
}

void MainWindow::GrayReverse(){
    ui->Undo->setEnabled(true);
    this->scale_=this->scale;
    this->cx_=this->cx;
    this->cy_=this->cy;
    this->H_rev_=this->H_rev;
    this->Gray_rev_=this->Gray_rev;
    this->scale_=this->scale;
    this->angle_=this->angle;
    this->win_pos_=this->win_pos;
    this->win_wid_=this->win_wid;
    this->Gray_rev=!this->Gray_rev;
    this->showPic();
}

QImage *MainWindow::grayReverse(QImage *raw_pic){
    QImage *temp=new QImage(raw_pic->width(),raw_pic->height(),QImage::Format_Indexed8);
    temp->setColorCount(256);
    for (int i =0;i<256;i++){
        temp->setColor(i,qRgb(i,i,i));
    }
    for (int i=0;i<raw_pic->height();i++){
        for (int j=0;j<raw_pic->width();j++)
            temp->setPixel(j,i,255-raw_pic->pixelIndex(j,i));
    }
    return temp;
}

void MainWindow::HReverse(){
    ui->Undo->setEnabled(true);
    this->scale_=this->scale;
    this->cx_=this->cx;
    this->cy_=this->cy;
    this->H_rev_=this->H_rev;
    this->Gray_rev_=this->Gray_rev;
    this->scale_=this->scale;
    this->angle_=this->angle;
    this->win_pos_=this->win_pos;
    this->win_wid_=this->win_wid;
    this->H_rev=!this->H_rev;
    this->showPic();
}

QImage *MainWindow::hReverse(QImage *raw_pic){
    QImage *temp=new QImage(raw_pic->width(),raw_pic->height(),QImage::Format_Indexed8);
    temp->setColorCount(256);
    for (int i =0;i<256;i++){
        temp->setColor(i,qRgb(i,i,i));
    }
    for (int i=0;i<raw_pic->height();i++){
        for (int j=0;j<raw_pic->width();j++)
            temp->setPixel(raw_pic->width()-j,i,raw_pic->pixelIndex(j,i));
    }
    return temp;
}
