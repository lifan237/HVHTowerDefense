#include "select.h"//有一种过家家的感觉。。。
Select::Select(int type, int sx, int sy, int x, int y, int w, int h){
    this->SX = sx;
    this->SY = sy;
    this->W = w;
    this->H = h;
    this->Type = type;
    QImage all;
    all.load(":/pics/Select.png");
    this->Pic = all.copy(QRect(x,y,w,h));
}
