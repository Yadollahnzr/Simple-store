#ifndef ADDPRODUCT_H
#define ADDPRODUCT_H

#include <QDialog>

namespace Ui {
class AddProduct;
}

class AddProduct : public QDialog
{
    Q_OBJECT

public:
    explicit AddProduct(QWidget *parent = nullptr);
    ~AddProduct();

private slots:
    void on_add_btn_clicked();

    void on_back_btn_clicked();

private:
    Ui::AddProduct *ui;
};

#endif // ADDPRODUCT_H
