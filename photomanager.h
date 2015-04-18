#ifndef PHOTOMANAGER_H
#define PHOTOMANAGER_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QFileSystemModel>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

#include <QMediaMetaData>
#include <QImageReader>

#include <slideshow.h>

namespace Ui {
class PhotoManager;
}

class PhotoManager : public QMainWindow
{
    Q_OBJECT

public:
    explicit PhotoManager(QWidget *parent = 0);
    ~PhotoManager();

private slots:
    void on_treeView_clicked(const QModelIndex &index);

    void on_listView_activated(const QModelIndex &index);

    void on_listView_clicked(const QModelIndex &index);

    void on_listView_entered(const QModelIndex &index);

    void listViewSelectionChangedHandler( const QModelIndex & current, const QModelIndex & previous );

    void treeViewSelectionChangedHandler( const QModelIndex & current, const QModelIndex & previous );


    void on_listView_doubleClicked(const QModelIndex &index);

private:
    Ui::PhotoManager *ui;
    SlideShow slideShow;

    QFileSystemModel *dirModel;
    QFileSystemModel *fileModel;
    QGraphicsScene *scene;
    QGraphicsPixmapItem *item;
    QImageReader reader;

};

#endif // PHOTOMANAGER_H
