#ifndef HERO_H
#define HERO_H
#include <rpgobj.h>

class Hero: public RPGOBJ
{
public:
    Hero(int type,int sx,int sy,int x,int y,int w,int h,int life,int foot,int power,int team);
    int getLife();
    int getTeam();
    int getFoot();
    void attack(Hero &Enemy);
private:
    int Life;
    int Team;//1:玩家1；   2:玩家2;
    int Foot;//步长，也决定了一定的攻击范围
    int Power;
};

#endif // HERO_H
