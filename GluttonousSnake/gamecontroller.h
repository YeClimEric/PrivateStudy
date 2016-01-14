#ifndef GAMECONTROLLE_H
#define GAMECONTROLLE_H

#include <QObject>
#include <QGraphicsScene>
#include <QTimer>
#include "food.h"

class Snake;

class GameController : public QObject
{
    Q_OBJECT
public:
    explicit GameController(QGraphicsScene *s, QObject *parent);

signals:

public slots:
private:
    void pause();
    void resume();

private:
    QGraphicsScene *scene;
    Snake *snake;
    QTimer timer;

};

#endif // GAMECONTROLLE_H
