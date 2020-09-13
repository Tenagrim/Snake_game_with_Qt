#include "pos.h"

Pos::Pos()
{
    x = 0;
    y = 0;
}
Pos::Pos(int x, int y)
{
    this->x = x;
    this->y = y;
}
/*
 const Pos& Pos::operator+(const Pos& b)
{
     Pos res(x + b.x, y + b.y);
     return res;
}

*/

Pos operator+(Pos a, Pos b)
{
    return Pos(a.x + b.x, a.y + b.y);
}
bool operator == (const Pos &left, const Pos &right)
{
    return left.x == right.x && left.y == right.y;
}
bool operator != (const Pos &left, const Pos &right)
{
    return !(left.x == right.x && left.y == right.y);
}
Pos& operator +=(Pos &left, Pos &right)
{

    left.x += right.x;
    left.y += right.y;
    return left;
}
