#ifndef PHOTOMANAGER_H
#define PHOTOMANAGER_H

#include <QMainWindow>

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
    Ui::PhotoManager *ui;
};

#endif // PHOTOMANAGER_H
