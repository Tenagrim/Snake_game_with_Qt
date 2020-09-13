#ifndef POS_H
#define POS_H

#include "pos.h"

class Pos
{
public:
    Pos();
    Pos(int x, int y);
    int x;
    int y;
    friend Pos operator+(Pos a, Pos b);
    Pos& operator +=( Pos &right);
    friend bool operator == (const Pos &left, const Pos &right);
    friend bool operator != (const Pos &left, const Pos &right);
    friend Pos& operator +=(Pos &left, Pos &right);

};

#endif // POS_H
