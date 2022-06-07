#ifndef SEEPRODUCT_H
#define SEEPRODUCT_H

#include <QWidget>

namespace Ui {
class SeeProduct;
}

class SeeProduct : public QWidget
{
    Q_OBJECT

public:
    explicit SeeProduct(QWidget *parent = nullptr);
    ~SeeProduct();

private:
    Ui::SeeProduct *ui;
};

#endif // SEEPRODUCT_H
