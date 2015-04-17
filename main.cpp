#include "photomanager.h"
#include <QApplication>
#include <QSplitter>
#include <QFileSystemModel>
#include <QListView>
#include <QTreeView>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);



//    QSplitter *splitter = new QSplitter;
//    QFileSystemModel *imageModel = new QFileSystemModel;
//    imageModel->setRootPath(QDir::rootPath());

//    QListView *list = new QListView(splitter);
//    list->setModel(imageModel);
//    list->setRootIndex(imageModel->index(QDir::rootPath()));

//    QTreeView *tree = new QTreeView(splitter);
//    tree->setModel(imageModel);
//    tree->setRootIndex(imageModel->index(QDir::rootPath()));

    PhotoManager w;
    w.show();

//    splitter->setWindowTitle("Photo Manager");
//    splitter->show();
    return a.exec();
}
