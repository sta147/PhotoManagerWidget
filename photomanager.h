#ifndef PHOTOMANAGER_H
#define PHOTOMANAGER_H

//OpenCv includes...
#include <opencv2/opencv.hpp>

#include <slideshow.h>
#include <opencv/cv.h>
#include <QDebug>

#include <QMainWindow>
#include <QFileSystemModel>


#include <QMediaMetaData>
//#include <QImageReader>
#include <QMetaObject>
#include <exiv2/exif.hpp>
#include <exiv2/image.hpp>
#include <exiv2/properties.hpp>
#include <c++/v1/string>
#include <exiv2/metadatum.hpp>
#include <exiv2/easyaccess.hpp>


using namespace std;
using namespace cv;

namespace Ui {
class PhotoManager;
}

class PhotoManager : public QMainWindow
{
    Q_OBJECT

public slots:
    void processFrameAndUpdateGUI();

private slots:
//    void on_treeView_clicked(const QModelIndex &index);

    void on_listView_activated(const QModelIndex &index);

    void on_listView_clicked(const QModelIndex &index);

    void on_listView_entered(const QModelIndex &index);

    void listViewSelectionChangedHandler( const QModelIndex & current, const QModelIndex & previous );

    void treeViewSelectionChangedHandler( const QModelIndex & current, const QModelIndex & previous );

    void on_listView_doubleClicked(const QModelIndex &index);

    void get_Meta_Data(const QString &filePath);
public:
    explicit PhotoManager(QWidget *parent = 0);
    ~PhotoManager();

private:

    SlideShow slideShow;

    QFileSystemModel *dirModel;
    QFileSystemModel *fileModel;
    Ui::PhotoManager *ui;
    QGraphicsScene *scene;
    QGraphicsPixmapItem *item;
    QImageReader reader;

    cv::VideoCapture webcam;
    cv::Mat originalMat;
    cv::Mat processedMat;

    QImage qimgOriginal;
    QImage qimgProcessed;

    std::vector<cv::Vec3f> vecCircles;
    std::vector<cv::Vec3f>::iterator itrCircles;

    QTimer* terTimer;

    QString currentFile;
    QString currentFilePath;
};

#endif // PHOTOMANAGER_H
