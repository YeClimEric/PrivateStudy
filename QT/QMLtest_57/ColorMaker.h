#ifndef COLORMAKER_H
#define COLORMAKER_H

#include <QObject>

class ColorMaker : public QObject
{
    Q_OBJECT
    Q_ENUMS(GenerateAlgorithm)
public:
    explicit ColorMaker(QObject *parent = 0);

    enum GenerateAlgorithm{
        RandomRGB,
        RandomRed,
        RandomGreen,
        RandomBlue,
        LinearIncrease
    };

    Q_INVOKABLE GenerateAlgorithm algorithm() const;
    Q_INVOKABLE void setAlgorithm(GenerateAlgorithm algorithm);

signals:
    void colorChanged(const QColor& color);
    void currentTime(const QString& time);

public slots:
    void start();
    void stop();
};

#endif // COLORMAKER_H
