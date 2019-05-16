#include "hero.h"

Hero::Hero(int type, int sx, int sy, int x, int y, int w, int h,int life,int foot,int power, int team){
    this->SX = sx;
    this->SY = sy;
    this->W = w;
    this->H = h;
    this->Type = type;
    QImage all;
    all.load(":/pics/Heros.png");
    this->Pic = all.copy(QRect(x,y,w,h));
    this->Life = life;
    this->Foot = foot;
    this->Team = team;
    this->Power = power;
}

int Hero::getLife(){
    return this->Life;
}

int Hero::getTeam(){
    return this->Team;
}

int Hero::getFoot(){
    return this->Foot;
}

void Hero::attack(Hero &Enemy){
    Enemy.Life = Enemy.Life - this->Power;
    if (Enemy.Life<=0) Enemy.change(195,285,26,36);
}
