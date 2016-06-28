#include "Widget.h"
#include <QApplication>

#include <QGraphicsScene>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    Widget w;


    QGraphicsScene oScene;
    oScene.addLine(0,0,150,150);

    QGraphicsView oView(&oScene);
    oView.setWindowTitle("Graphics View");
//    oView.resize(500,500);
    oView.centerOn(500,500);
    oView.rotate(45);
    oView.show();


//    QGraphicsScene oScene;
//    QGraphicsView oView(&oScene);

//    oView.show();

//    oScene.setBackgroundBrush(Qt::red);

//    QRadialGradient gradient(0,0,10);
//    gradient.setSpread(QGradient::RepeatSpread);
//    oScene.setBackgroundBrush(gradient);

//    w.show();

    return a.exec();
}
