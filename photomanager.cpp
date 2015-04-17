#include "photomanager.h"
#include "ui_photomanager.h"

PhotoManager::PhotoManager(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PhotoManager)
{
    ui->setupUi(this);
    dirModel = new QFileSystemModel(this);
    dirModel->setRootPath(QDir::rootPath());

    fileModel = new QFileSystemModel(this);
    fileModel->setRootPath(QDir::rootPath());

    ui->treeView->setModel(dirModel);
    ui->listView->setModel(fileModel);
}

PhotoManager::~PhotoManager()
{
    delete ui;
}
