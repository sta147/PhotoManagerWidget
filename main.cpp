#include "photomanager.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PhotoManager w;
    w.show();

    return a.exec();
}
