#ifndef PHOTOMANAGER_H
#define PHOTOMANAGER_H

#include <slideshow.h>

#include <QMainWindow>
#include <QFileSystemModel>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

#include <QMediaMetaData>
#include <QImageReader>
#include <QMetaObject>

//OpenCv includes...
#include <opencv2/core/core.hpp>
#include <opencv/cv.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

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

//    cv::VideoCapture webcam;
//    cv::Mat originalMat;
//    cv::Mat processedMat;

    QImage qimgOriginal;
    QImage qimgProcessed;

    std::vector<cv::Vec3f> vecCircles;
    std::vector<cv::Vec3f>::iterator itrCircles;

    QTimer* terTimer;

};

#endif // PHOTOMANAGER_H
