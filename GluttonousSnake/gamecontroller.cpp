#include "gamecontroller.h"

GameController::GameController(QGraphicsScene *s, QObject *parent):
    QObject(parent),
    scene(s)/*,
    snake(new Snake(this))*/
{
    timer.start(1000/33);

    Food *food1 = new Food(0, 0);
    scene->addItem(food1);
//    scene->addItem(snake);
    scene->installEventFilter(this);
    resume();
}

void GameController::pause()
{
    disconnect(&timer, &QTimer::timeout, scene, &QGraphicsScene::advance);
}

void GameController::resume()
{
    connect(&timer, SIGNAL(timeout()), scene, SLOT(advance()));
}
