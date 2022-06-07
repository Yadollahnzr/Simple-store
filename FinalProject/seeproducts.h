#ifndef SEEPRODUCTS_H
#define SEEPRODUCTS_H

#include <QMainWindow>

namespace Ui {
class SeeProducts;
}

class SeeProducts : public QMainWindow
{
    Q_OBJECT

public:
    explicit SeeProducts(QWidget *parent = nullptr);
    ~SeeProducts();

private slots:
    void on_back_btn_clicked();

    void on_refresh_btn_clicked();

    void on_show_btn_clicked();

private:
    Ui::SeeProducts *ui;
};

#endif // SEEPRODUCTS_H
