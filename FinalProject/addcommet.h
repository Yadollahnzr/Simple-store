#ifndef ADDCOMMET_H
#define ADDCOMMET_H

#include <QDialog>

namespace Ui {
class AddCommet;
}

class AddCommet : public QDialog
{
    Q_OBJECT

public:
    explicit AddCommet(QWidget *parent = nullptr);
    ~AddCommet();

private slots:
    void on_add_btn_clicked();

private:
    Ui::AddCommet *ui;
};

#endif // ADDCOMMET_H
