#ifndef SNIMOKCAM_H
#define SNIMOKCAM_H

#include <QDialog>

namespace Ui {
class snimokCam;
}

class snimokCam : public QDialog
{
    Q_OBJECT

public:
    explicit snimokCam(QWidget *parent = nullptr);
    ~snimokCam();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::snimokCam *ui;
};

#endif // SNIMOKCAM_H
