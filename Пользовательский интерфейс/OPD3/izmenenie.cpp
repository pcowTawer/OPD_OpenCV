#include "izmenenie.h"
#include "ui_izmenenie.h"
#include <QMessageBox>

izmenenie::izmenenie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::izmenenie)
{
    ui->setupUi(this);
    ui->pushButton_4->setStyleSheet("QPushButton{background-color: rgb(234, 237, 253); border: 0.5px solid rgb(101, 126, 253); border-radius: 8px; color: rgb(105, 127, 254); text-align: center; font: 75 20pt \"MS Shell Dlg 2\";}"
                                  "QPushButton:hover{background-color: rgb(186, 195, 242); border: 0.5px solid rgb(101, 126, 253); border-radius: 8px; color: rgb(240, 248, 255)}");
    ui->pushButton_4->setCheckable(true);

    ui->pushButton_5->setStyleSheet("QPushButton{background-color: rgb(234, 237, 253); border: 0.5px solid rgb(101, 126, 253); border-radius: 8px; color: rgb(105, 127, 254); text-align: center; font: 75 20pt \"MS Shell Dlg 2\";}"
                                  "QPushButton:hover{background-color: rgb(186, 195, 242); border: 0.5px solid rgb(101, 126, 253); border-radius: 8px; color: rgb(240, 248, 255)}");
    ui->pushButton_5->setCheckable(true);
}

izmenenie::~izmenenie()
{
    delete ui;
}

void izmenenie::on_pushButton_4_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Отменить изменения", "Вы уверены, что хотите отменить все изменения?", QMessageBox::Yes | QMessageBox::No);
    if(reply==QMessageBox::Yes){
        close();
    }
}

void izmenenie::on_pushButton_5_clicked()
{
    QMessageBox::about(this, "Распознавание лиц", "Информация успешно изменена!");
    close();
}
