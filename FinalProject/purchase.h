#ifndef PURCHASE_H
#define PURCHASE_H

#include <QDialog>

namespace Ui {
class Purchase;
}

class Purchase : public QDialog
{
    Q_OBJECT

public:
    explicit Purchase(QWidget *parent = nullptr);
    ~Purchase();

private slots:
    void on_back_btn_clicked();

private:
    Ui::Purchase *ui;
};

#endif // PURCHASE_H
