#include "slideshow.h"
#include "ui_slideshow.h"

SlideShow::SlideShow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SlideShow)
{
    ui->setupUi(this);
}

SlideShow::~SlideShow() {
    delete ui;
}

/* Method for displaying images. */
void SlideShow::showImage(const QString &currentFile,const QString &currentFilePath){

    scene1 = new QGraphicsScene();

    item1 = new QGraphicsPixmapItem(QPixmap(currentFile));
    scene1->addItem(item1);
    ui->graphicsView->setScene(scene1);
    ui->graphicsView->fitInView(scene1->itemsBoundingRect() ,Qt::KeepAspectRatio);
}

void SlideShow::on_NextImageBtn_pressed()
{

}
