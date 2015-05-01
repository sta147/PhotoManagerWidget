#include "photomanager.h"
#include <QApplication>
#include <QSplitter>
//#include <QFileSystemModel>
#include <QListView>
#include <QTreeView>

#include <QItemSelectionModel>

//#include <core/core_c.h>
//#include <highgui.h>
//#include <imgproc/imgproc_c.h>
//#include <cv.h>
//#include <cv.hpp>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PhotoManager w;
    w.show();

//    cv::Mat mat;
//        mat = cv::imread("img.JPG");
//        cvNamedWindow("hello");
//        cv::imshow("hello",mat);

//        cvWaitKey(0);

    return a.exec();
}
