#ifndef SELECT_H
#define SELECT_H
#include "rpgobj.h"

class Select: public RPGOBJ
{
public:
    Select(int type,int sx,int sy,int x,int y,int w,int h);
};

#endif // SELECT_H
