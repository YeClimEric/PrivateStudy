#ifndef CBARRAGEFOUNDATION_H
#define CBARRAGEFOUNDATION_H

#include <QWidget>

namespace Ui {
class CBarrageFoundation;
}

class CBarrageFoundation : public QWidget
{
    Q_OBJECT

public:
    explicit CBarrageFoundation(QWidget *parent = 0);
    ~CBarrageFoundation();

private:
    Ui::CBarrageFoundation *ui;
};

#endif // CBARRAGEFOUNDATION_H
