#include "photomanager.h"
#include <QApplication>
#include <QSplitter>
//#include <QFileSystemModel>
#include <QListView>
#include <QTreeView>

#include <QItemSelectionModel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PhotoManager w;
    w.show();
    return a.exec();
}
