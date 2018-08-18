#include "main_interface.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	main_interface w;
	w.show();
	return a.exec();
}
