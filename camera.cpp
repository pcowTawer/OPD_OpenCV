#include "camera.h"
#include "ui_camera.h"
#include "snimokcam.h"

#include <QMainWindow>
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QImage>
#include <QPixmap>
#include <QCloseEvent>
#include <QMessageBox>

camera::camera(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::camera)
{
    ui->setupUi(this);
    ui->pushButton->setStyleSheet("QPushButton{background-color: rgb(234, 237, 253); border: 0.5px solid rgb(101, 126, 253); border-radius: 8px; color: rgb(105, 127, 254); text-align: center; font: 75 20pt \"MS Shell Dlg 2\";}"
                                  "QPushButton:hover{background-color: rgb(186, 195, 242); border: 0.5px solid rgb(101, 126, 253); border-radius: 8px; color: rgb(240, 248, 255)}");
    ui->pushButton->setCheckable(true);

    ui->pushButton_2->setStyleSheet("QPushButton{background-color: rgb(234, 237, 253); border: 0.5px solid rgb(101, 126, 253); border-radius: 8px; color: rgb(105, 127, 254); text-align: center; font: 75 20pt \"MS Shell Dlg 2\";}"
                                  "QPushButton:hover{background-color: rgb(186, 195, 242); border: 0.5px solid rgb(101, 126, 253); border-radius: 8px; color: rgb(240, 248, 255)}");
    ui->pushButton_2->setCheckable(true);



    ui->graphicsView->setScene(new QGraphicsScene(this)); // Устанавливает текущую сцену и позволяет её в будущем обновлять.
    ui->graphicsView->scene()->addItem(&pixmap); // Устанавливаем новую сцену
}

camera::~camera()
{
    delete ui;
}

void camera::on_pushButton_2_pressed()
{
    // source code ---- https://amin-ahmadi.com/2018/03/29/how-to-read-process-and-display-videos-using-qt-and-opencv/
    using namespace cv;

    if(video.isOpened())
    {
        video.release();
        return;
    }

    int cameraIndex = 0;

    if(!video.open(cameraIndex))
    {
        QMessageBox::critical(this,
                                  "Что-то не то с камерой",
                                  "Индекс камеры неверный!");
        return;
    }

    Mat frame;
    while(video.isOpened())
    {
        video >> frame;
        if(!frame.empty())
        {
            QImage qimg(frame.data,
                        frame.cols,
                        frame.rows,
                        frame.step,
                        QImage::Format_RGB888);
            pixmap.setPixmap( QPixmap::fromImage(qimg.rgbSwapped()) );
            ui->graphicsView->fitInView(&pixmap, Qt::KeepAspectRatio);
        }
        qApp->processEvents();
    }
    imwrite("C:\\temp\\a_file_that_is_no_longer_needed_and_you_can_delete_it.png", frame);
    snimokCam window;
    window.setModal(true);
    window.setWindowTitle("Распознавание лиц");
    window.exec();

}

void camera::closeEvent(QCloseEvent *event)
{
    if(video.isOpened())
    {
        QMessageBox::warning(this,
                             "Предупреждение",
                             "Остановите видео до того как выйти из окна!");
        event->ignore();
    }
    else
    {
        event->accept();
    }
}
