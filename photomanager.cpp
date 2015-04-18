#include "photomanager.h"
#include "ui_photomanager.h"

PhotoManager::PhotoManager(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PhotoManager)
{
    ui->setupUi(this);

    QStringList filters =  (QStringList() << "*.jpeg" << "*.jpg" << "*.png" << "*.PNG" << "*JPEG" << "*.JPG" << "*.GIF" << "*.gif" << "*.BMP" << "*.bmp" << "*.tiff" << "*.TIFF");

    dirModel = new QFileSystemModel(this);
    dirModel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
    dirModel->setNameFilters(filters);

    dirModel->setRootPath(QDir::rootPath());

    fileModel = new QFileSystemModel(this);
    fileModel->setFilter(QDir::Files);
    fileModel->setNameFilters(filters);
    fileModel->setNameFilterDisables(false);
    fileModel->setRootPath(QDir::rootPath());

    ui->treeView->setModel(dirModel);
    ui->listView->setModel(fileModel);


    connect(ui->listView->selectionModel(), SIGNAL(currentChanged(const QModelIndex& , const QModelIndex&)), this, SLOT(listViewSelectionChangedHandler(const QModelIndex& , const QModelIndex&)));

    connect(ui->treeView->selectionModel(), SIGNAL(currentChanged(const QModelIndex& , const QModelIndex&)), this, SLOT(treeViewSelectionChangedHandler(const QModelIndex& , const QModelIndex&)));
}

PhotoManager::~PhotoManager()
{
    delete ui;
}

void PhotoManager::on_treeView_clicked(const QModelIndex &index)
{
    QString filePath = dirModel->fileInfo(index).absoluteFilePath();
    QImageReader readerr(filePath);


    ui->listView->setRootIndex(fileModel->setRootPath(filePath));
    //ui->graphicsView->setWindowFilePath(filePath);
}

/* What happens when the button is clicked or entered. */
void PhotoManager::on_listView_activated(const QModelIndex &index)
{
        slideShow.showFullScreen();
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
//    slideShow.showFullScreen();
//    slideShow.show();
}

void PhotoManager::listViewSelectionChangedHandler( const QModelIndex & current, const QModelIndex & previous )
{
    QString filePath = dirModel->fileInfo(current).absoluteFilePath();

    scene = new QGraphicsScene();
    item = new QGraphicsPixmapItem(QPixmap(filePath));
    scene->addItem(item);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->fitInView(scene->itemsBoundingRect() ,Qt::KeepAspectRatio);
}
void PhotoManager::treeViewSelectionChangedHandler( const QModelIndex & current, const QModelIndex & previous )
{
    QString filePath = dirModel->fileInfo(current).absoluteFilePath();
    ui->listView->setRootIndex(fileModel->setRootPath(filePath));
}

void PhotoManager::on_listView_doubleClicked(const QModelIndex &index)
{
    slideShow.showFullScreen();
    slideShow.show();
}
