#ifndef INFORMATION_H
#define INFORMATION_H

#include <QDialog>

namespace Ui {
class Information;
}

class Information : public QDialog
{
    Q_OBJECT

public:
    explicit Information(QWidget *parent = nullptr);
    ~Information();

private slots:
    void on_pushButton_clicked();

    void on_back_btn_clicked();

    void on_username_btn_clicked();

    void on_password_btn_clicked();

    void on_name_btn_clicked();

    void on_email_btn_clicked();

    void on_address_btn_clicked();

    void on_city_btn_clicked();

    void on_fname_btn_clicked();

    void on_lname_btn_clicked();

private:
    Ui::Information *ui;
};

#endif // INFORMATION_H
