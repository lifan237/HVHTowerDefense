#include "mainwindow.h"
#include <QApplication>
//金钱，血条，人物，动作
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
