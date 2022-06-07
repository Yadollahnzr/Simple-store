#include "addcommet.h"
#include "ui_addcommet.h"
#include "account.h"
#include "comment.h"
#include <string>
#include <fstream>
using namespace std;
AddCommet::AddCommet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddCommet)
{
    ui->setupUi(this);
}

AddCommet::~AddCommet()
{
    delete ui;
}
User account;
int product_id;
void AddCommet::on_add_btn_clicked()
{
    int star=ui->star_spinBox->value();
    string comment=ui->comment_te->toPlainText().toStdString();
    Comment c;
    c._id=product_id;
    c._username = account._username;
    c._star=star;
    c._show=0;
    c._comment=comment;
    ofstream commentf("comments.txt",ios::app);
    commentf<<endl<<endl<<c;
    commentf.close();
    this->close();
}
