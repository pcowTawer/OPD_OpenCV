#include "people.h"
#include "ui_people.h"
#include "registrationnew.h"
#include "izmenenie.h"

people::people(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::people)
{
    ui->setupUi(this);
}

people::~people()
{
    delete ui;
}

void people::on_pushButton_clicked()
{
    izmenenie window;
    window.setModal(true);
    window.setWindowTitle("Распознавание лиц");
    window.exec();
}

void people::on_pushButton_2_clicked()
{
    izmenenie window;
    window.setModal(true);
    window.setWindowTitle("Распознавание лиц");
    window.exec();
}

void people::on_pushButton_3_clicked()
{
    registrationNew window;
    window.setModal(true);
    window.setWindowTitle("Распознавание лиц");
    window.exec();
}
