#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QPainter>
#include <QTimer>
#include <QPushButton>
#include "world.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *);

protected:
    void addStatus();
    QPushButton *Start;
    void timerEvent(QTimerEvent *event);
private:
    Ui::MainWindow *ui;
    World Battlefield;
    int Status,HeroType;
//private slots:
    //void on_Start_clicked();
};

#endif // MAINWINDOW_H
