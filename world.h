#ifndef WORLD_H
#define WORLD_H//发挥创意，什么是英雄呢？
#include<rpgobj.h>
#include<QPainter>
#include<QImage>
#include<select.h>
#include<QMediaPlayer>
#include<hero.h>
class World
{
public://母类可调用子类的公有成员
    World();
    void show(QPainter *painter);
    void moveSelect(char Direct,int Steps);
    void eraseOBJ(int SX,int SY);
    int getSelectX();
    int getSelectY();
    void addHero(int Type,int SX,int SY);
    void conductHero();
private:
    QImage Map;
    vector<RPGOBJ *> OBJS;
    Select Select0;
    vector<Hero *> Heros;
    int Heronum;
};

#endif // WORLD_H
