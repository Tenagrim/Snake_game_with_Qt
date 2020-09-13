#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    game = new Game(30,30);
    wtg = new QPaintWidget(this);
    wtg->SetGame(game);
    round = Pos(2,2);
    qDebug( " Info message");
    block_size = 15;
    delay = 100;
    direction = 0;
    resize(game->width*block_size,game->height*block_size);
    timerId = startTimer(delay);
    Display();
}

MainWindow::~MainWindow()
{
    delete ui;
    wtg->deleteLater();
}

void MainWindow::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    Display();
}

void MainWindow::timerEvent(QTimerEvent *e)
{
    Q_UNUSED(e);
    if(game->endGame == false)
    {
        game->Control(direction);
        game->Step();
        update();
    }
    else
        game->Restart();

}

void MainWindow::Display()
{
    QPainter qp(this);
    qp.setRenderHint(QPainter::Antialiasing);

    for(int i = 0; i < game->height; i++)
    {
        for(int j = 0; j < game->height; j++)
        {
            QPainterPath path;
            //path.addRoundedRect(QRectF(j*block_size, i*block_size, block_size-1,block_size-1), round.x, round.y);
            path.addRect(QRectF(j*block_size, i*block_size, block_size,block_size));
            switch(game->field[i][j])
            {
                case 0:
                    //qp.setPen(QColor(Qt::black));
                    qp.fillPath(path, Qt::black);
                break;
                case 1:
                    qp.fillPath(path, Qt::green);
                    //qp.setPen(QColor(Qt::white));
                break;
            }
           //  qp.drawRect(j*block_size, i*block_size, block_size-1,block_size-1);
        }
    }
    for(int i = 0; i < game->snake->GetLength(); i++)
    {
        QPainterPath path;
        path.addRoundedRect(QRectF(game->snake->body[i].x *block_size, game->snake->body[i].y*block_size, block_size-1,block_size-1), round.x, round.y);
        qp.fillPath(path,Qt::gray);
    }
    QPainterPath path;
    path.addRoundedRect(QRectF(game->food.x *block_size, game->food.y *block_size, block_size-1,block_size-1), round.x, round.y);
    qp.fillPath(path,Qt::red);
}
void MainWindow::keyPressEvent(QKeyEvent *e) {

    int key = e->key();

    switch (key)
    {
    case Qt::Key_Left :
        direction = 3;
        break;
    case Qt::Key_Right:
        direction = 1;
        break;
    case Qt::Key_Up:
           direction = 0;
           break;
    case Qt::Key_Down:
        direction = 2;
        break;
    }
    QWidget::keyPressEvent(e);
}



