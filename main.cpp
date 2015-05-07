#include "photomanager.h"
#include <QApplication>
#include <QSplitter>
#include <QListView>
#include <QTreeView>

#include <QItemSelectionModel>

//#include <core/core_c.h>
//#include <highgui.h>
//#include <imgproc/imgproc_c.h>
//#include <opencv/cv.h>
//#include <cv.hpp>

//using namespace std;
//using namespace cv;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PhotoManager w;
    w.show();

    char* imageName = "/Users/kayani/Desktop/realfunc.jpg";

     Mat image;
     image = imread( imageName, 1 );

//     if( argc != 2 || !image.data )
//     {
//       printf( " No image data \n " );
//       return -1;
//     }

     Mat gray_image;
     cvtColor( image, gray_image, CV_BGR2GRAY );

     imwrite( "../../images/Gray_Image.jpg", gray_image );

     namedWindow( imageName, CV_WINDOW_AUTOSIZE );
     namedWindow( "Gray image", CV_WINDOW_AUTOSIZE );

     imshow( imageName, image );
     imshow( "Gray image", gray_image );

     waitKey(0);

    cv::Mat mat;
        mat = cv::imread("img.JPG");
        cvNamedWindow("hello");
        cv::imshow("hello",mat);

        cvWaitKey(0);
    return a.exec();
}
