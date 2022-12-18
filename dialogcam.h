#ifndef DIALOGCAM_H
#define DIALOGCAM_H

#include <QDialog>

namespace Ui {
class DialogCam;
}

class DialogCam : public QDialog
{
    Q_OBJECT

public:
    explicit DialogCam(QWidget *parent = nullptr);
    ~DialogCam();

private:
    Ui::DialogCam *ui;
};

#endif // DIALOGCAM_H
