#include "rpgobj.h"

RPGOBJ::RPGOBJ(int type, int sx, int sy, int x, int y, int w, int h){
    this->SX = sx;
    this->SY = sy;
    this->W = w;
    this->H = h;
    this->Type = type;
    QImage all;
    all.load(":/pics/Tile.png");
    this->Pic = all.copy(QRect(x,y,w,h));
}

void RPGOBJ::move(char Direct, int Step){
    if (Direct == 'W') {this->SY = this->SY - Step;}
    else if (Direct == 'S') {this->SY = this->SY + Step;}
    else if (Direct == 'A') {this->SX = this->SX - Step;}
    else if (Direct == 'D') {this->SX = this->SX + Step;}
}

void RPGOBJ::show(QPainter *painter){//传导绘图窗体位置
    painter->drawImage(SX,SY,Pic);
}

void RPGOBJ::change(int x,int y,int w,int h){
    QImage all;
    all.load(":/pics/Tile.png");
    this->Pic = all.copy(QRect(x,y,w,h));
}
