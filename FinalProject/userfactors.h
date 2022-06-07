#ifndef USERFACTORS_H
#define USERFACTORS_H

#include <QDialog>

namespace Ui {
class Userfactors;
}

class Userfactors : public QDialog
{
    Q_OBJECT

public:
    explicit Userfactors(QWidget *parent = nullptr);
    ~Userfactors();

private slots:
    void on_show_btn_clicked();

    void on_showuname_btn_clicked();

    void on_showid_btn_clicked();

    void on_back_btn_clicked();

private:
    Ui::Userfactors *ui;
};

#endif // USERFACTORS_H
