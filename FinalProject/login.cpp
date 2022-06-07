#include "login.h"
#include "ui_login.h"
#include "register.h"
#include "mainwindow.h"
#include <string>
#include <vector>
#include <fstream>
#include <QMessageBox>
#include "account.h"
#include "users.h"
#include "mainwindow_2.h"
using namespace std;
Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_register_btn_clicked()
{
    this->close();
    Register r;
    r.show();
    r.exec();

}


vector<User>users;
void Login::on_login_btn_clicked()
{
    string username=ui->username_le->text().toStdString();
    string password=ui->password_le->text().toStdString();
    readusers();
    int flag=-1;
    for(unsigned int i=0;i<users.size() && flag==-1;i++)
    {
        if(username==users[i]._username && password==users[i]._password)
            flag=i;
    }
    if(flag!=-1)
        account=users[flag];
    if(flag!=-1 && users[flag]._type=="user")
    {
        this->close();
        MainWindow *m=new MainWindow();
        m->show();
    }
    else if(flag!=-1 && users[flag]._type=="admin")
    {
        this->close();
        MainWindow_2 *m=new MainWindow_2();
        m->show();
    }
    else
    {
        QMessageBox m;
        m.setWindowTitle("Error");
        m.setText("username or password is incrroct!");
        m.show();
        m.exec();
    }
}
