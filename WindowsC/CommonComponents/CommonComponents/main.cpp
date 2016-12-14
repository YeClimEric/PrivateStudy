#include "commoncomponents.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	CommonComponents w;
	w.show();
	return a.exec();
}
