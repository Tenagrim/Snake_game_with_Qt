#ifndef GAME_H
#define GAME_H
#include "pos.h"
#include "snake.h"
#include <QTime>

class Game
{
public:
    Game(int width, int height);
    ~Game();
    void Step();
    void Control(int dir);
    void CheckCollision();
    void MakeFood();
    void Restart();
    char    **field;
    Snake   *snake;
    Pos     food;
    int     width;
    int     height;
    bool    endGame;
};

#endif // GAME_H
