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
//#include <opencv/cv.h>
//#include <cv.hpp>

//using namespace std;
//using namespace cv;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PhotoManager w;
    w.show();

//    char* imageName = argv[1];

//     Mat image;
//     image = imread( imageName, 1 );

//     if( argc != 2 || !image.data )
//     {
//       printf( " No image data \n " );
//       return -1;
//     }

//     Mat gray_image;
//     cvtColor( image, gray_image, CV_BGR2GRAY );

//     imwrite( "../../images/Gray_Image.jpg", gray_image );

//     namedWindow( imageName, CV_WINDOW_AUTOSIZE );
//     namedWindow( "Gray image", CV_WINDOW_AUTOSIZE );

//     imshow( imageName, image );
//     imshow( "Gray image", gray_image );

//     waitKey(0);

//    cv::Mat mat;
//        mat = cv::imread("img.JPG");
//        cvNamedWindow("hello");
//        cv::imshow("hello",mat);

//        cvWaitKey(0);

//    try {
//    //Exiv2::Image::AutoPtr image = Exiv2::ImageFactory::open(argv[1]);
//    Exiv2::Image::AutoPtr image = Exiv2::ImageFactory::open("/Users/kayani/Desktop/realfunc.jpg");
//        assert(image.get() != 0);
//        image->readMetadata();

//        Exiv2::ExifData &exifData = image->exifData();
//        if (exifData.empty()) {
//            std::string error(argv[1]);
//            error += ": No Exif data found in the file";
//            throw Exiv2::Error(1, error);
//        }
//        Exiv2::ExifData::const_iterator end = exifData.end();
//        for (Exiv2::ExifData::const_iterator i = exifData.begin(); i != end; ++i) {
//            const char* tn = i->typeName();
//            std::cout << std::setw(44) << std::setfill(' ') << std::left
//                      << i->key() << " "
//                      << "0x" << std::setw(4) << std::setfill('0') << std::right
//                      << std::hex << i->tag() << " "
//                      << std::setw(9) << std::setfill(' ') << std::left
//                      << (tn ? tn : "Unknown") << " "
//                      << std::dec << std::setw(3)
//                      << std::setfill(' ') << std::right
//                      << i->count() << "  "
//                      << std::dec << i->value()
//                      << "\n";
//        }
//}
//catch (Exiv2::AnyError& e) {
//    std::cout << "Caught Exiv2 exception '" << e.what() << "'\n";
//    return -1;
//}

    return a.exec();
}
