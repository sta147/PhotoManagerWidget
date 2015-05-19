#ifndef SLIDESHOW_H
#define SLIDESHOW_H

#include <QWidget>
#include <QtCore>
#include <QtGui>

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QImageReader>

namespace Ui {
class SlideShow;
}

class SlideShow : public QWidget
{
    Q_OBJECT
public slots:
           void showImage(const QString & currentFile, const QString & currentFilePath);

private slots:

           void on_NextImageBtn_pressed();

public:
    explicit SlideShow(QWidget *parent = 0);
    ~SlideShow();

private:
    Ui::SlideShow *ui;

    QGraphicsScene *scene1;
    QGraphicsPixmapItem *item1;
    QImageReader reader1;
};

#endif // SLIDESHOW_H
