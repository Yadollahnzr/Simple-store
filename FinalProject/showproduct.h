#ifndef SHOWPRODUCT_H
#define SHOWPRODUCT_H

#include <QDialog>

namespace Ui {
class ShowProduct;
}

class ShowProduct : public QDialog
{
    Q_OBJECT

public:
    explicit ShowProduct(QWidget *parent = nullptr);
    ~ShowProduct();

private slots:
    void on_show_btn_clicked();

    void on_addcomment_btn_clicked();

    void on_addchart_btn_clicked();

private:
    Ui::ShowProduct *ui;
};

#endif // SHOWPRODUCT_H
