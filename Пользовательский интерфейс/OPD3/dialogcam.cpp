#include "dialogcam.h"
#include "ui_dialogcam.h"

DialogCam::DialogCam(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogCam)
{
    ui->setupUi(this);
}

DialogCam::~DialogCam()
{
    delete ui;
}
