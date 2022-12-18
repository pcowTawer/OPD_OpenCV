#ifndef CAMERA_H
#define CAMERA_H

#include <QDialog>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <QGraphicsPixmapItem>

namespace Ui {
class camera;
}

class camera : public QDialog
{
    Q_OBJECT

public:
    explicit camera(QWidget *parent = nullptr);
    ~camera();

private slots:

    void on_pushButton_2_pressed();

    void closeEvent(QCloseEvent *event);

private:
    Ui::camera *ui;
    QGraphicsPixmapItem pixmap;
    cv::VideoCapture video;
};

#endif // CAMERA_H
