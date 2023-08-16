#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include <algorithm>
#include <QFile>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QImage *raw_img,*mod_img;

    int cx,cy;
    int cx_,cy_;
    int win_pos,win_wid;
    int win_pos_,win_wid_;
    double scale;
    double scale_;
    double angle;
    double angle_;
    bool Gray_rev;
    bool Gray_rev_;
    bool H_rev;
    bool H_rev_;
    int **mat;

private slots:
    void openfiletriggered();
    void ClearCanvasTriggered();
    void ScaleSet(int value);
    void AngleSet(int value);
    void CenterSet();
    void GrayWinSet();
    void Save();
    void Undo();
    void GrayReverse();
    void HReverse();

public:
    Ui::MainWindow *ui;
    void openfile();
    void clear();
    void showPic();
    QImage *scaleTrans(QImage *raw_pic, double scale);
    QImage *angleTrans(QImage *raw_pic, double angle, int cx, int cy);
    QImage *grayWinSet(int win_pos,int win_width);
    void laSharpen();
    void save();
    QImage *grayReverse(QImage *raw_pic);
    QImage *hReverse(QImage *raw_pic);
};
#endif // MAINWINDOW_H
