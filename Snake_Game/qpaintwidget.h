#ifndef QPAINTWIDGET_H
#define QPAINTWIDGET_H

#include <QWidget>
#include "game.h"

class QPaintEvent;

class QPaintWidget : public QWidget
{
    Q_OBJECT
public:
    QPaintWidget(QWidget * parent = 0);
    void DisplayGame();
    void SetGame(Game *game);
    Game *game;
protected:
    void paintEvent(QPaintEvent *);
};

#endif // QPAINTWIDGET_H
