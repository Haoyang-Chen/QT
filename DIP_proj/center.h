#ifndef CENTER_H
#define CENTER_H

#include <QWidget>
#include "mainwindow.h"
#include <QMouseEvent>

namespace Ui {
class center;
}

class center : public QWidget
{
    Q_OBJECT

public:
    explicit center(MainWindow *window, QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *event);
    MainWindow *window;
    ~center();

private:
    Ui::center *ui;
};

#endif // CENTER_H
