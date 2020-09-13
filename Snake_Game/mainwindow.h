#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "game.h"
#include "qpaintwidget.h"
#include <QPainter>
#include <QDebug>
#include <QTime>
#include <QKeyEvent>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QPaintWidget *wtg;
    Game *game;
    void Display();
    int block_size;
    int delay;
    int timerId;
    int direction;
protected:
    void paintEvent(QPaintEvent *e);
    void timerEvent(QTimerEvent *e);
    void keyPressEvent(QKeyEvent *e);
};

#endif // MAINWINDOW_H
