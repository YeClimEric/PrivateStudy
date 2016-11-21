#ifndef CGIFTANIMATION_H
#define CGIFTANIMATION_H

#include <QWidget>
#include <QPropertyAnimation>

class CGiftAnimation : public QPropertyAnimation
{
public:
    explicit CGiftAnimation(QWidget *parent = 0);
    CGiftAnimation(QWidget *target, const QByteArray &propertyName, QWidget *parent = 0);
};

#endif // CGIFTANIMATION_H
