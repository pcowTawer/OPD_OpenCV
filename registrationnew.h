#ifndef REGISTRATIONNEW_H
#define REGISTRATIONNEW_H

#include <QDialog>

namespace Ui {
class registrationNew;
}

class registrationNew : public QDialog
{
    Q_OBJECT

public:
    explicit registrationNew(QWidget *parent = nullptr);
    ~registrationNew();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::registrationNew *ui;
};

#endif // REGISTRATIONNEW_H
