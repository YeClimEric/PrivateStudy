#ifndef SNAKE_H
#define SNAKE_H

#include<QGraphicsItem>

class Snake : public QGraphicsItem
{
//    Q_OBJECT
public:
    explicit Snake(QObject *parent = 0);
    QRectF boundingRect() const;


signals:

public slots:

private:
    QRectF head;
    QRectF tail;



};

#endif // SNAKE_H
