#include "photomanager.h"
#include <QApplication>
#include <QSplitter>
#include <QListView>
#include <QTreeView>

#include <QItemSelectionModel>

//#include <imgproc/imgproc_c.h>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv/cv.hpp>

#include "opencv/cv.h"
#include "opencv/cxcore.h"
#include "opencv/highgui.h"

#include "math.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <opencv2/videoio.hpp>

using namespace std;
using namespace cv;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PhotoManager w;
    w.show();

//    int c = 0;

//        CvCapture* capture = cvCaptureFromCAM(0);

//            if(!cvQueryFrame(capture)){
//                cout<<"Video capture failed, please check the camera."<<endl;
//            } else{
//                cout<<"Video camera capture status: OK"<<endl;
//            }

//        CvSize sz = cvGetSize(cvQueryFrame(capture));

//        IplImage* src = cvCreateImage( sz, 8, 3 );

//        IplImage* hsv_image = cvCreateImage( sz, 8, 3);

//        IplImage* hsv_mask = cvCreateImage( sz, 8, 1);

//        CvScalar  hsv_min = cvScalar(0, 30, 80, 0);

//        CvScalar  hsv_max = cvScalar(20, 150, 255, 0);


//        while( c != 27) {
//            src = cvQueryFrame(capture);

//                //cvNamedWindow( "src",1); cvShowImage( "src", src);

//            cvCvtColor(src, hsv_image, CV_BGR2HSV);

//            cvInRangeS (hsv_image, hsv_min, hsv_max, hsv_mask);

//                cvNamedWindow( "hsv-msk",1); cvShowImage( "hsv-msk", hsv_mask); hsv_mask->origin = 1;

//            c = cvWaitKey( 10);

//        }
//        cvReleaseCapture( &capture);

//        cvDestroyAllWindows();

    return a.exec();
}
