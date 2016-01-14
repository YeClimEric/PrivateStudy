#include "snake.h"

Snake::Snake(QObject *parent) :
    QObject(parent)
{
}

QRectF Snake::boundingRect() const
{
    qreal minX = head.x();
    qreal minY = head.y();
    qreal maxX = head.x();
    qreal maxY = head.y();

    foreach (QPointF p, tail) {
        maxX = p.x() > maxX? p.x():maxX;
        maxY = p.y() > maxY? p.y():maxY;
        minX = p.x() < minX? p.x():minX;
        minY = p.y() < minY? p.y():minY;
    }
}
