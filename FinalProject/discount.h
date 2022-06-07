#ifndef DISCOUNT_H
#define DISCOUNT_H

#include <QDialog>

namespace Ui {
class Discount;
}

class Discount : public QDialog
{
    Q_OBJECT

public:
    explicit Discount(QWidget *parent = nullptr);
    ~Discount();

private slots:
    void on_back_btn_clicked();

    void on_done_btn_clicked();

private:
    Ui::Discount *ui;
};

#endif // DISCOUNT_H
