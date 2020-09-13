#include "snake.h"

Snake::Snake(Pos pos)
{
    body.push_back(Pos(pos.x,pos.y));
    speed.x = 0;
    speed.y = -1;
    length = 1;
}
void Snake::Step()
{
    Pos tmp;
    tmp = body[0];
    body[0] = body[0] + speed;
    for(int i = 1; i < length -1; i++)
    {
        if(tmp != body[i])
            std::swap(tmp, body[i]);
    }

}
int Snake::GetLength()
{
    return length;
}
Pos Snake::GetSpeed()
{
    return speed;
}

void Snake::Turn(int direction)
{
    Pos dir;
    switch(direction)
    {
        case 0:         // move up
            dir.x = 0;
            dir.y = -1;
        break;
        case 1:         //move right
            dir.x = 1;
            dir.y = 0;
        break;
        case 2:         //move down
            dir.x = 0;
            dir.y = 1;
        break;
        case 3:         //move left
            dir.x = -1;
            dir.y = 0;
        break;
    }
    if(dir.x != -speed.x && dir.y != -speed.y)
        speed = dir;
}
bool Snake::inSnake(Pos pos)
{
    for(int i = 0; i < length; i++)
    {
        if(body[i] == pos)
            return true;
    }
    return false;
}
void Snake::Grow(int count)
{
    for(int i = 0; i < count; i++)
    {
        body.push_back(body[length-1]);
        length++;
    }
}
