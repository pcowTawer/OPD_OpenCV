#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "camera.h"
#include "snimokcam.h"
#include <QMessageBox>
#include <QListWidget>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton_10->setStyleSheet("QPushButton{background-color: rgb(234, 237, 253); border: 0.5px solid rgb(101, 126, 253); border-radius: 8px;}"
                                     "QPushButton:hover{background-color: rgb(186, 195, 242); border: 0.5px solid rgb(101, 126, 253); border-radius: 8px;}");
    ui->pushButton_10->setCheckable(true);

    ui->pushButton_11->setStyleSheet("QPushButton{background-color: rgb(234, 237, 253); border: 0.5px solid rgb(101, 126, 253); border-radius: 8px;}"
                                     "QPushButton:hover{background-color: rgb(186, 195, 242); border: 0.5px solid rgb(101, 126, 253); border-radius: 8px;}");
    ui->pushButton_11->setCheckable(true);

    ui->pushButton->setStyleSheet("QPushButton{background-color: rgb(234, 237, 253); border: 0.5px solid rgb(101, 126, 253); border-radius: 8px; color: rgb(105, 127, 254); text-align: center; font: 75 20pt \"MS Shell Dlg 2\";}"
                                  "QPushButton:hover{background-color: rgb(186, 195, 242); border: 0.5px solid rgb(101, 126, 253); border-radius: 8px; color: rgb(240, 248, 255)}");
    ui->pushButton->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Выход", "Вы действительно хотите выйти?", QMessageBox::Yes | QMessageBox::No);
    if(reply==QMessageBox::Yes){
        close();
    }
}

void MainWindow::on_pushButton_10_clicked()
{
    camera window;
    window.setModal(true);
    window.setWindowTitle("Распознавание лиц");
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Доступ к камере", "Разрешить приложению доступ к Web-камере?", QMessageBox::Yes | QMessageBox::No);
    if(reply==QMessageBox::Yes){
        window.exec();
    }
}

void MainWindow::on_pushButton_11_clicked()
{
    QMessageBox::about(this, " ", "тут откроется проводник, пользователь выберет изображение для распознавания");
    snimokCam window;
    window.setModal(true);
    window.setWindowTitle("Распознавание лиц");
    window.exec();
}

void MainWindow::on_pushButton_10_clicked(bool checked)
{
    //if(checked)
    //{
    //    ui->pushButton_10->setStyleSheet(QString::fromUtf8("background-color: rgb(186, 195, 242); border: 0.5px solid rgb(101, 126, 253); border-radius: 8px;"));
    //}
  //  else{
  //      ui->pushButton_10->setStyleSheet(QString::fromUtf8("background-color: rgb(234, 237, 253); border: 0.5px solid rgb(101, 126, 253); border-radius: 8px;"));
  //  }
}
