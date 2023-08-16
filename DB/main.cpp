#include "mainwindow.h"
#include "get_info.h"
#include "search.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
//    get_info w;
    search w;
    w.show();
    return a.exec();
}
