#ifndef CAMERA_H
#define CAMERA_H

#include <QDialog>

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
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::camera *ui;
};

#endif // CAMERA_H
