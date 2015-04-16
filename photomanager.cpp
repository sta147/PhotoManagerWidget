#include "photomanager.h"
#include "ui_photomanager.h"

PhotoManager::PhotoManager(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PhotoManager)
{
    ui->setupUi(this);
}

PhotoManager::~PhotoManager()
{
    delete ui;
}
