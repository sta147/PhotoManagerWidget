#ifndef SLIDESHOW_H
#define SLIDESHOW_H

#include <QWidget>

namespace Ui {
class SlideShow;
}

class SlideShow : public QWidget
{
    Q_OBJECT

public:
    explicit SlideShow(QWidget *parent = 0);
    ~SlideShow();

private:
    Ui::SlideShow *ui;
};

#endif // SLIDESHOW_H
