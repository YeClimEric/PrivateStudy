#ifndef FOOD_H
#define FOOD_H

#include <QGraphicsItem>
#include <QPainter>

class Food : public QGraphicsItem
{
//    Q_OBJECT
public:
    explicit Food(qreal x, qreal y);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QPainterPath shape() const;
    QRectF boundingRect() const;
};

#endif // FOOD_H
