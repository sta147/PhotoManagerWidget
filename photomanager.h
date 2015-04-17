#ifndef PHOTOMANAGER_H
#define PHOTOMANAGER_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QFileSystemModel>

namespace Ui {
class PhotoManager;
}

class PhotoManager : public QMainWindow
{
    Q_OBJECT

public:
    explicit PhotoManager(QWidget *parent = 0);
    ~PhotoManager();

private:
    QFileSystemModel *dirModel;
    QFileSystemModel *fileModel;
    Ui::PhotoManager *ui;
};

#endif // PHOTOMANAGER_H
