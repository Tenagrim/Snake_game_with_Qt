#include "game.h"

Game::Game(int width, int height)
{
    this->width = width;
    this->height = height;
    snake = new Snake(Pos(width/2, height/2));
    endGame = false;

    field = new char*[height];
    for(int i = 0; i < height; i++)
    {
        field[i] = new char[width];
        for(int j = 0; j < width; j++)
            field[i][j] = (i == 0 || i == height -1 || j == 0 || j == width - 1) ? 1 : 0;
    }
    QTime time = QTime::currentTime();
    qsrand((uint) time.msec());
    MakeFood();
}
Game::~Game()
{
    for(int i = 0; i < height; i++)
        delete field[i];
}
void Game::Step()
{
    CheckCollision();
    if(!endGame)
    snake->Step();
}
void Game::Control(int dir)
{
    snake->Turn(dir);
}
void Game::CheckCollision()
{
    Pos next_step(snake->body[0] + snake->GetSpeed());
    if(field[next_step.y][next_step.x]==1 || snake->inSnake(next_step))
        endGame = true;
    if(snake->body[0] == food)
    {
        MakeFood();
        snake->Grow(1);
    }
}
void Game::MakeFood()
{
    food.x = qrand() % width;
    food.y = qrand() % height;
    while(field[food.y][food.x] == 1 || snake->inSnake(food))
    {
        food.x = food.x + 1;
        if(food.x >= width)
        {
            food.x = 0;
            food.y = food.y + 1;
        }
    }
}
