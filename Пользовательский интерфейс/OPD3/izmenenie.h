#ifndef IZMENENIE_H
#define IZMENENIE_H

#include <QDialog>

namespace Ui {
class izmenenie;
}

class izmenenie : public QDialog
{
    Q_OBJECT

public:
    explicit izmenenie(QWidget *parent = nullptr);
    ~izmenenie();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::izmenenie *ui;
};

#endif // IZMENENIE_H
