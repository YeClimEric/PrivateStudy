#include "food.h"
#include "common.h"


Food::Food(qreal x, qreal y)
{
    setPos(x, y);
    //为图形添加额外的数据信息
    setData(GD_Type, GO_Food);
}

void Food::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->save();
    painter->setRenderHint(QPainter::Antialiasing);
    painter->fillPath(shape(), Qt::red);
    painter->restore();
}

QPainterPath Food::shape() const
{
    QPainterPath p;
    p.addEllipse(QPointF(TILE_SIZE / 2, TILE_SIZE / 2), FOOD_RADIUS, FOOD_RADIUS);
    return p;
}

QRectF Food::boundingRect() const
{
    return QRectF(-TILE_SIZE, -TILE_SIZE,
                  TILE_SIZE*2, TILE_SIZE *2);

}
