#ifndef MAINWINDOW_2_H
#define MAINWINDOW_2_H

#include <QMainWindow>

namespace Ui {
class MainWindow_2;
}

class MainWindow_2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow_2(QWidget *parent = nullptr);
    ~MainWindow_2();

private slots:
    void on_ccomments_btn_clicked();

    void on_back_btn_clicked();

    void on_vphistory_btn_clicked();

    void on_addproduct_btn_clicked();

    void on_editproducts_btn_clicked();

    void on_deleteproducts_btn_clicked();

    void on_discount_btn_clicked();

private:
    Ui::MainWindow_2 *ui;
};

#endif // MAINWINDOW_2_H
