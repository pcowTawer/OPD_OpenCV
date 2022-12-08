#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_10_toggled(bool checked);

    void on_pushButton_10_clicked(bool checked);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
