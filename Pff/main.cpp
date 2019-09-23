#include "Pff.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Pff w;
	w.show();
	return a.exec();
}
