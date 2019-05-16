#ifndef RPGOBJ_H
#define RPGOBJ_H
#include <QMediaPlayer>
#include <QImage>
#include <QPainter>
#include <string>
#include <map>//类：大写 动词：小写 名词：大写
using namespace std;
class RPGOBJ//任何地图上显示的物体
{
public:
    RPGOBJ(){}
    RPGOBJ(int type,int sx,int sy,int x,int y,int w,int h);//(sx,sy) (sx+w,sy)(sx,sy+h)(sx+w,sy+h)
    void show(QPainter *painter);
    void setPosX(int x){this->SX=x;}
    void setPosY(int y){this->SY=y;}

    int getPosX() const{return this->SX;}
    int getPosY() const{return this->SY;}
    int getHeight() const{return this->H;}
    int getWidth() const{return this->W;}

    void move(char Direct, int Step);
    void change(int x,int y,int w,int h);

    //bool canCover() const{return this->_coverable;}
    //bool canEat() const{return this->_eatable;}

    //virtual void onErase();
protected:
    int Type;//1:select;2:H;3:T
    QImage Pic;
    int SX,SY,W,H;
    //bool coverable;

};

#endif // RPGOBJ_H
