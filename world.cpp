#include "world.h"
#include<QPaintEvent>
#include<QPainter>
#include <QImage>
#include <QPainter>
#include <QMediaPlayer>
#include <math.h>
World::World():Select0(1,0,0,0,0,100,100){//初始化世界，在这里添加一些起始塔
    QImage all;
    all.load(":/pics/Map.png");
    this->Map = all.copy(QRect(0,0,1600,900));

    RPGOBJ *P1 = new RPGOBJ(2,300,300,96,416,65,96);
    RPGOBJ *P2 = new RPGOBJ(3,1000,200,257,385,32,63);
    this->OBJS.push_back(P1);
    this->OBJS.push_back(P2);

    Heronum = 1;
    Hero *E0 = new Hero(0,1400,500,64,326,62,92,200,0,5,2);
    this->Heros.push_back(E0);

    Heronum = 2;
    Hero *H1 = new Hero(0,1035,600,32,426,32,54,100,5,20,2);
    this->Heros.push_back(H1);

    QMediaPlayer * Speaker = new QMediaPlayer;
    Speaker->setMedia(QUrl("qrc:/sounds/Song1.mp3"));
    Speaker->setVolume(30);
    Speaker->play();
}

void World::show(QPainter *painter){
    int i,n;
    painter->drawImage(0,0,this->Map);
    n = this->OBJS.size();
    for (i = 0;i<n;++i){
        this->OBJS[i]->show(painter);
    }
    this->Select0.show(painter);
    for (i = 0;i<Heros.size();++i){
        this->Heros[i]->show(painter);
    }

}

void World::eraseOBJ(int SX, int SY){
    vector<RPGOBJ*>::iterator it;
    for (it = this->OBJS.begin();it!=this->OBJS.end();it++){
        if (((*it)->getPosX()==SX)&&((*it)->getPosY()==SY)){
            delete (*it);
            break;//重叠问题
        }
    }
}

int World::getSelectX(){
    return Select0.getPosX();
}

int World::getSelectY(){
    return Select0.getPosY();
}

void World::moveSelect(char Direct, int Steps){
    this->Select0.move(Direct,Steps);
    //this->eraseOBJ(this->Select0->getPosX());
}

void World::addHero(int Type, int SX, int SY){
    //int type, int sx, int sy, int x, int y, int w, int h,int life,int foot,int power, int team;
    //0,稻草人，32,426,32,54
    ++Heronum;
    if (Type==0){
        Hero *H1 = new Hero(0,SX,SY,32,426,32,54,100,10,10,1);
        this->Heros.push_back(H1);
    }
    if (Type==1){
        Hero *H2 = new Hero(1,SX,SY,225,416,31,33,100,50,10,1);
        this->Heros.push_back(H2);
    }
}

void World::conductHero(){
    int i,j;
    bool meetEnemy;//*-----><--*
    for (i = 0;i<this->Heros.size();++i){


        if ((Heros[i]->getTeam()==1)&&(Heros[i]->getLife()>0))     {
        meetEnemy = 0;
        for (j = 0;j<this->Heros.size();++j)
            if ((Heros[j]->getTeam()==2)&&(Heros[j]->getLife()>0))
            if ((Heros[i]->getPosX()+Heros[i]->getWidth()<Heros[j]->getPosX())&&
            (Heros[i]->getPosX()+Heros[i]->getWidth()+Heros[i]->getFoot()>=Heros[j]->getPosX()-Heros[j]->getFoot())&&
            (fmin(Heros[i]->getPosY()+Heros[i]->getHeight(),Heros[j]->getPosY()+Heros[j]->getHeight())-
            fmax(Heros[i]->getPosY(),Heros[j]->getPosY())
                     >=0))
            {
                Heros[i]->attack(*Heros[j]);
                meetEnemy = 1;
            }
        if ((meetEnemy == 0)&&(Heros[i]->getPosX()<1400))   Heros[i]->move('D',Heros[i]->getFoot());
        if (Heros[i]->getPosX()>=1400)
            if (Heros[i]->getPosY()-Heros[i]->getFoot()>500)   Heros[i]->setPosY(Heros[i]->getPosY()-Heros[i]->getFoot());
            else if (Heros[i]->getPosY()+Heros[i]->getFoot()<500)  Heros[i]->setPosY(Heros[i]->getPosY()+Heros[i]->getFoot());
        }


        if ((Heros[i]->getTeam()==2)&&(Heros[i]->getLife()>0))     {
        meetEnemy = 0;
        for (j = 0;j<this->Heros.size();++j)
            if ((Heros[j]->getTeam()==1)&&(Heros[j]->getLife()>0))
            if ((Heros[j]->getPosX()+Heros[j]->getWidth()<Heros[i]->getPosX())&&
            (Heros[j]->getPosX()+Heros[j]->getWidth()+Heros[j]->getFoot()>=Heros[i]->getPosX()-Heros[i]->getFoot())&&
            (fmin(Heros[i]->getPosY()+Heros[i]->getHeight(),Heros[j]->getPosY()+Heros[j]->getHeight())-
            fmax(Heros[i]->getPosY(),Heros[j]->getPosY())
            >=0))
            {
                Heros[i]->attack(*Heros[j]);
                meetEnemy = 1;
            }

        if ((meetEnemy == 0)&&(Heros[i]->getPosX()>200))   Heros[i]->move('A',Heros[i]->getFoot());
        if (Heros[i]->getPosX()<=200)
            if (Heros[i]->getPosY()-Heros[i]->getFoot()>500)   Heros[i]->setPosY(Heros[i]->getPosY()-Heros[i]->getFoot());
            else if (Heros[i]->getPosY()+Heros[i]->getFoot()<500)  Heros[i]->setPosY(Heros[i]->getPosY()+Heros[i]->getFoot());

        }

    }
}
