#ifndef EDITPRODUCT_H
#define EDITPRODUCT_H

#include <QDialog>

namespace Ui {
class EditProduct;
}

class EditProduct : public QDialog
{
    Q_OBJECT

public:
    explicit EditProduct(QWidget *parent = nullptr);
    ~EditProduct();

private slots:
    void on_back_btn_clicked();

    void on_show_btn_clicked();

    void on_edit_btn_clicked();

private:
    Ui::EditProduct *ui;
};

#endif // EDITPRODUCT_H
