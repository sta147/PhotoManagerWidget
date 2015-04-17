#include "photomanager.h"
#include "ui_photomanager.h"

PhotoManager::PhotoManager(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PhotoManager)
{
    ui->setupUi(this);

    QString sPath = "/";
    QStringList filters =  (QStringList() << "*.jpeg" << "*.jpg" << "*.png" << "*.PNG" << "*JPEG" << "*.JPG");

    dirModel = new QFileSystemModel(this);
    dirModel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
    dirModel->setNameFilters(filters);

    dirModel->setRootPath(QDir::toNativeSeparators(sPath));


    fileModel = new QFileSystemModel(this);
    fileModel->setFilter(QDir::Files);
    fileModel->setNameFilters(filters);
    fileModel->setNameFilterDisables(false);
    fileModel->setRootPath(QDir::toNativeSeparators(sPath));

    ui->treeView->setModel(dirModel);
    ui->listView->setModel(fileModel);
    //ui->listView->
}

PhotoManager::~PhotoManager()
{
    delete ui;
}

void PhotoManager::on_treeView_clicked(const QModelIndex &index)
{
    QString filePath = dirModel->fileInfo(index).absoluteFilePath();
    ui->listView->setRootIndex(fileModel->setRootPath(filePath));
    //ui->graphicsView->setWindowFilePath(filePath);
}

/* What happens when the button is clicked. */
void PhotoManager::on_listView_activated(const QModelIndex &index)
{
    QString filePath = dirModel->fileInfo(index).absoluteFilePath();
//    ui->listView->setRootIndex(fileModel->setRootPath(filePath));

}

void PhotoManager::on_listView_clicked(const QModelIndex &index)
{
    QString filePath = dirModel->fileInfo(index).absoluteFilePath();

    scene = new QGraphicsScene();

    item = new QGraphicsPixmapItem(QPixmap(filePath));
    scene->addItem(item);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->fitInView(scene->itemsBoundingRect() ,Qt::KeepAspectRatio);
}

void PhotoManager::on_listView_entered(const QModelIndex &index)
{
    QString filePath = dirModel->fileInfo(index).absoluteFilePath();

    scene = new QGraphicsScene();
    item = new QGraphicsPixmapItem(QPixmap(filePath));
    scene->addItem(item);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->fitInView(scene->itemsBoundingRect() ,Qt::KeepAspectRatio);
}
