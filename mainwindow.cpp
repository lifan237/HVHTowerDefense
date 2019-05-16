#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>
#include <QTimer>
#include <QPushButton>
#include<iostream>

using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    Battlefield()//增加世界
{
    ui->setupUi(this);

    Status = 1;
    HeroType = 0;
    //Start = new QPushButton(this);
    //Start->setGeometry(QRect(800,300,200,100));
    //Start->setText("Start Game");
    //connect(Start,SIGNAL(clicked(bool)),this,SLOT(on_Start_clicked()));
    startTimer(100);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timerEvent(QTimerEvent *event){
    this->Battlefield.conductHero();
    repaint();
}



void MainWindow::paintEvent(QPaintEvent *event){
    QPainter *pen;
    pen = new QPainter();
    pen->begin(this);
    //切换世界
    if (Status == 0) {

    }
    else if (Status == 1)
    {this->Battlefield.show(pen);

    }
    pen->end();
    delete pen;
}
//这几个函数应该是同时执行,而且是循环执行
void MainWindow::keyPressEvent(QKeyEvent *event){
    if (Status == 1){
        if (event->key() == Qt::Key_W)  this->Battlefield.moveSelect('W',10);
        if (event->key() == Qt::Key_A)  this->Battlefield.moveSelect('A',10);
        if (event->key() == Qt::Key_S)  this->Battlefield.moveSelect('S',10);
        if (event->key() == Qt::Key_D)  this->Battlefield.moveSelect('D',10);
        if (event->key() == Qt::Key_Q)  {++HeroType;if (HeroType==2) HeroType = HeroType - 2;}
        if (event->key() == Qt::Key_Space)  this->Battlefield.addHero(HeroType,this->Battlefield.getSelectX(),this->Battlefield.getSelectY());
    }

   /* if (event->key() == Qt::Key_Space){
        this->battlefield.Place();
    }
    if (event->key() == Qt::Key_Q){
        this->battlefield.Switch();
    }*/
    this->repaint();

}

//void MainWindow::on_Start_clicked(){
//    Status = 1;
 //   Start->~QPushButton();
 //   this->repaint();
//}
