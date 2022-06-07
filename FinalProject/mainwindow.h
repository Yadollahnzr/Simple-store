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
    void on_back_btn_clicked();

    void on_sprduct_btn_clicked();

    void on_refresh_btn_clicked();

    void on_cart_btn_clicked();

    void on_ch_info_btn_clicked();

    void on_phistory_btn_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
