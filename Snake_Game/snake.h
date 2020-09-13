#ifndef SNAKE_H
#define SNAKE_H
#include <vector>
#include "pos.h"

class Snake
{
public:
    Snake(Pos pos);
    std::vector<Pos> body;
    void Step();
    void Turn(int direction);
    void Grow(int count);
    int GetLength();
    Pos GetSpeed();
    bool inSnake(Pos pos);
private:
    Pos speed;
    int length;
    int way;
};

#endif // SNAKE_H
