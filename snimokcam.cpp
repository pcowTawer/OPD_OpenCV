#include "snimokcam.h"
#include "ui_snimokcam.h"
#include "registrationNew.h"
#include "izmenenie.h"
#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QListView>
#include "people.h"

snimokCam::snimokCam(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::snimokCam)
{
    ui->setupUi(this);

    ui->pushButton_2->setStyleSheet("QPushButton{background-color: rgb(234, 237, 253); border: 0.5px solid rgb(101, 126, 253); border-radius: 8px; color: rgb(105, 127, 254); text-align: center; font: 75 20pt \"MS Shell Dlg 2\";}"
                                  "QPushButton:hover{background-color: rgb(186, 195, 242); border: 0.5px solid rgb(101, 126, 253); border-radius: 8px; color: rgb(240, 248, 255)}");
    ui->pushButton_2->setCheckable(true);

    ui->pushButton_3->setStyleSheet("QPushButton{background-color: rgb(234, 237, 253); border: 0.5px solid rgb(101, 126, 253); border-radius: 8px; color: rgb(105, 127, 254); text-align: center; font: 75 13pt \"MS Shell Dlg 2\";}"
                                  "QPushButton:hover{background-color: rgb(186, 195, 242); border: 0.5px solid rgb(101, 126, 253); border-radius: 8px; color: rgb(240, 248, 255)}");
    ui->pushButton_3->setCheckable(true);

    ui->pushButton_4->setStyleSheet("QPushButton{background-color: rgb(234, 237, 253); border: 0.5px solid rgb(101, 126, 253); border-radius: 8px; color: rgb(105, 127, 254); text-align: center; font: 75 13pt \"MS Shell Dlg 2\";}"
                                  "QPushButton:hover{background-color: rgb(186, 195, 242); border: 0.5px solid rgb(101, 126, 253); border-radius: 8px; color: rgb(240, 248, 255)}");
    ui->pushButton_4->setCheckable(true);

    ui->pushButton_5->setStyleSheet("QPushButton{background-color: rgb(234, 237, 253); border: 0.5px solid rgb(101, 126, 253); border-radius: 8px; color: rgb(105, 127, 254);text-align: left; padding-left: 5px; font: 75 13pt \"MS Shell Dlg 2\";}"
                                  "QPushButton:hover{background-color: rgb(186, 195, 242); border: 0.5px solid rgb(101, 126, 253); border-radius: 8px; color: rgb(240, 248, 255)}");
    ui->pushButton_5->setCheckable(true);

    ui->pushButton_6->setStyleSheet("QPushButton{background-color: rgb(234, 237, 253); border: 0.5px solid rgb(101, 126, 253); border-radius: 8px; color: rgb(105, 127, 254);text-align: left; padding-left: 5px; font: 75 13pt \"MS Shell Dlg 2\";}"
                                  "QPushButton:hover{background-color: rgb(186, 195, 242); border: 0.5px solid rgb(101, 126, 253); border-radius: 8px; color: rgb(240, 248, 255)}");
    ui->pushButton_6->setCheckable(true);


    ui->pushButton_7->setStyleSheet("QPushButton{background-color: rgb(234, 237, 253); border: 0.5px solid rgb(101, 126, 253); border-radius: 8px; color: rgb(105, 127, 254);text-align: left; padding-left: 5px; font: 75 13pt \"MS Shell Dlg 2\";}"
                                  "QPushButton:hover{background-color: rgb(186, 195, 242); border: 0.5px solid rgb(101, 126, 253); border-radius: 8px; color: rgb(240, 248, 255)}");
    ui->pushButton_7->setCheckable(true);

    //ui->pushButton_5->setText("Людей на фото: ");


}

snimokCam::~snimokCam()
{
    delete ui;
}

void snimokCam::setImage(QPixmap image)
{
    ui->label->setPixmap(image);
//    ui->label->setBackgroundRole(QPalette::Base);
    ui->label->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Ignored);
//    ui->label->setScaledContents(true);
    ui->label->setAlignment(Qt::AlignCenter);
}

void snimokCam::on_pushButton_2_clicked()
{
    close();
}

void snimokCam::on_pushButton_4_clicked()
{
    people window;
    window.setModal(true);
    window.setWindowTitle("Регистрация");
    window.exec();
}

void snimokCam::on_pushButton_clicked()
{
    QMessageBox::about(this, " ", "тут откроется проводник, пользователь выберет путь сохранения");
}

void snimokCam::on_pushButton_3_clicked()
{
    people window;
    window.setModal(true);
    window.setWindowTitle("Изменить информацию");
    window.exec();
}

void snimokCam::on_pushButton_5_clicked()
{
    people window;
    window.setModal(true);
    window.setWindowTitle("Люди на фото");
    window.exec();
}

void snimokCam::on_pushButton_6_clicked()
{
    people window;
    window.setModal(true);
    window.setWindowTitle("Зарегистрированные люди");
    window.exec();
}

void snimokCam::on_pushButton_7_clicked()
{
    people window;
    window.setModal(true);
    window.setWindowTitle("Неарегистрированные люди");
    window.exec();
}
