#include "registrationnew.h"
#include "ui_registrationnew.h"
#include <QMessageBox>

registrationNew::registrationNew(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registrationNew)
{
    ui->setupUi(this);
    ui->pushButton_2->setStyleSheet("QPushButton{background-color: rgb(234, 237, 253); border: 0.5px solid rgb(101, 126, 253); border-radius: 8px; color: rgb(105, 127, 254); text-align: center; font: 75 20pt \"MS Shell Dlg 2\";}"
                                  "QPushButton:hover{background-color: rgb(186, 195, 242); border: 0.5px solid rgb(101, 126, 253); border-radius: 8px; color: rgb(240, 248, 255)}");
    ui->pushButton_2->setCheckable(true);

    ui->pushButton_3->setStyleSheet("QPushButton{background-color: rgb(234, 237, 253); border: 0.5px solid rgb(101, 126, 253); border-radius: 8px; color: rgb(105, 127, 254); text-align: center; font: 75 20pt \"MS Shell Dlg 2\";}"
                                  "QPushButton:hover{background-color: rgb(186, 195, 242); border: 0.5px solid rgb(101, 126, 253); border-radius: 8px; color: rgb(240, 248, 255)}");
    ui->pushButton_3->setCheckable(true);
}

registrationNew::~registrationNew()
{
    delete ui;
}

void registrationNew::on_pushButton_2_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Отменить регистрацию", "Вы уверены, что хотите отменить все изменения?", QMessageBox::Yes | QMessageBox::No);
    if(reply==QMessageBox::Yes){
        close();
    }
}

void registrationNew::on_pushButton_3_clicked()
{
    QMessageBox::about(this, "Распознавание лиц", "Пользователь успешно зарагистрирован!");
    close();
}
