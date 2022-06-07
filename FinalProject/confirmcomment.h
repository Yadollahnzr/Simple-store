#ifndef CONFIRMCOMMENT_H
#define CONFIRMCOMMENT_H

#include <QDialog>

namespace Ui {
class ConfirmComment;
}

class ConfirmComment : public QDialog
{
    Q_OBJECT

public:
    explicit ConfirmComment(QWidget *parent = nullptr);
    ~ConfirmComment();

private slots:

    void on_back_btn_clicked();

    void on_pushButton_clicked();

private:
    Ui::ConfirmComment *ui;
};

#endif // CONFIRMCOMMENT_H
