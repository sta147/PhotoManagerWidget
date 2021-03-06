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
    currentFilePath = QString();
    terTimer = new QTimer(this);
    connect(terTimer,SIGNAL (timeout()), this, SLOT(processFrameAndUpdateGUI()));
    terTimer->start(20);
}

PhotoManager::~PhotoManager() {
    delete ui;
}

void PhotoManager::processFrameAndUpdateGUI(){

}


/* What happens when the button is clicked or entered. */
void PhotoManager::on_listView_activated(const QModelIndex &index) {
    QString filePath = dirModel->fileInfo(index).absoluteFilePath();

    scene = new QGraphicsScene();

    item = new QGraphicsPixmapItem(QPixmap(filePath));
    scene->addItem(item);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->fitInView(scene->itemsBoundingRect() ,Qt::KeepAspectRatio);
    currentFile = filePath;
        slideShow.showImage(filePath, currentFilePath);

}

/* Method for listening to listView for clicks.*/
void PhotoManager::on_listView_clicked(const QModelIndex &index)
{
    QString filePath = dirModel->fileInfo(index).absoluteFilePath();

    scene = new QGraphicsScene();

    item = new QGraphicsPixmapItem(QPixmap(filePath));
    scene->addItem(item);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->fitInView(scene->itemsBoundingRect() ,Qt::KeepAspectRatio);
    currentFile = filePath;
    get_Meta_Data(filePath);
}
/* Method for listening to listView keyboard select.*/
void PhotoManager::on_listView_entered(const QModelIndex &index) {
//    slideShow.showFullScreen();
}

/* Method for listening to listView for selection change.*/
void PhotoManager::listViewSelectionChangedHandler( const QModelIndex & current, const QModelIndex & previous ) {
    QString filePath = dirModel->fileInfo(current).absoluteFilePath();

    scene = new QGraphicsScene();
    item = new QGraphicsPixmapItem(QPixmap(filePath));
    scene->addItem(item);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->fitInView(scene->itemsBoundingRect() ,Qt::KeepAspectRatio);
    currentFile = filePath;
    get_Meta_Data(filePath);
}
/* Method for listening to Treeview for selection change.*/
void PhotoManager::treeViewSelectionChangedHandler( const QModelIndex & current, const QModelIndex & previous ) {
    QString filePath = dirModel->fileInfo(current).absoluteFilePath();
    ui->listView->setRootIndex(fileModel->setRootPath(filePath));
    currentFilePath = filePath;
}
/* Method for listening to listView for double clicks.*/
void PhotoManager::on_listView_doubleClicked(const QModelIndex &index) {
    slideShow.showFullScreen();
    slideShow.show();
}

/* Method for Meta Data via the use of the exiv2 Library.*/
void PhotoManager::get_Meta_Data(const QString &filePath) {
    Exiv2::Image::AutoPtr image = Exiv2::ImageFactory::open(filePath.toStdString());
        assert(image.get() != 0);
        image->readMetadata();

        Exiv2::ExifData &exifData = image->exifData();
        if (exifData.empty()) {
//            std::string error();
//            error += ": No Exif data found in the file";
//            throw Exiv2::Error(1, error);
        }
        QString labelString;
        Exiv2::ExifData::const_iterator end = exifData.end();
        for (Exiv2::ExifData::const_iterator i = exifData.begin(); i != end; ++i) {
                    QString tagExiv = QString(i->key().c_str());
                    Exiv2::Exifdatum exifDatum = exifData[tagExiv.toStdString()];
                        labelString += tagExiv +": \t " + QString::fromStdString(exifDatum.toString()) +"\n";
                }
        qDebug()<<labelString;
//ui->label->setText(labelString);
ui->textBrowser->setText(labelString);
}
