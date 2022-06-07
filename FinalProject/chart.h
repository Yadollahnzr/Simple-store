#ifndef CHART_H
#define CHART_H

#include <QDialog>
#include <vector>
#include "product.h"
extern vector<Product> chart;
namespace Ui {
class Chart;
}

class Chart : public QDialog
{
    Q_OBJECT

public:
    explicit Chart(QWidget *parent = nullptr);
    ~Chart();

private slots:
    void on_back_btn_clicked();

    void on_remove_btn_clicked();

    void on_id_le_editingFinished();

    void on_buy_btn_clicked();

    void on_id_le_inputRejected();

    void on_id_le_selectionChanged();

private:
    Ui::Chart *ui;
};

#endif // CHART_H
