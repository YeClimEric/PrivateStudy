#include "lcomponent.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LComponent w;
    w.show();

    return a.exec();
}
