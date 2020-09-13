#include "qpaintwidget.h"
#include <QPainter>
#include "game.h"

QPaintWidget::QPaintWidget(QWidget * parent) : QWidget(parent)
{
}

void QPaintWidget::DisplayGame()
{

}

void QPaintWidget::paintEvent(QPaintEvent *) {
    QPainter p(this);
    p.setWindow(0,0, game->width * 10, game->height * 10);
    p.setPen(QPen(Qt::red,1,Qt::SolidLine));
    p.drawLine(0,0,width(),height());
    //this->DisplayGame();
}
void QPaintWidget::SetGame(Game *game)
{
    this->game = game;
}
