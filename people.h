#ifndef PEOPLE_H
#define PEOPLE_H

#include <QDialog>

namespace Ui {
class people;
}

class people : public QDialog
{
    Q_OBJECT

public:
    explicit people(QWidget *parent = nullptr);
    ~people();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::people *ui;
};

#endif // PEOPLE_H
