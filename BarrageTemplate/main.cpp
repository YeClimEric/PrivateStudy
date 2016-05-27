#include "cbarragefoundation.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CBarrageFoundation w;
    w.show();

    return a.exec();
}
