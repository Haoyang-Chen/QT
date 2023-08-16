#ifndef GRAYWIN_H
#define GRAYWIN_H

#include <QWidget>
#include "mainwindow.h"

namespace Ui {
class grayWin;
}

class grayWin : public QWidget
{
    Q_OBJECT

public:
    explicit grayWin(MainWindow *window, QWidget *parent = nullptr);
    MainWindow *window;
    ~grayWin();
public slots:
    void SetClicked();
    void ClearClicked();


private:
    Ui::grayWin *ui;
};

#endif // GRAYWIN_H
