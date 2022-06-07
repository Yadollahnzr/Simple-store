#include "register.h"
#include "ui_register.h"
#include "login.h"
#include "users.h"
#include <string>
#include <QMessageBox>
#include <fstream>
#include "login.h"
using namespace std;
Register::Register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
}

Register::~Register()
{
    delete ui;
}

void Register::on_login_btn_clicked()
{
    this->close();
    Login l;
    l.show();
    l.exec();
}


void Register::on_register_btn_clicked()
{
    QMessageBox m;
    User u;
    if(users.size()==0)
        readusers();
    string fname,lname,address,email,city,password,username;
    fname=ui->fname_le->text().toStdString();
    lname=ui->lname_le->text().toStdString();
    address=ui->address_le->text().toStdString();
    email=ui->email_le->text().toStdString();
    city=ui->city_le->text().toStdString();
    password=ui->password_le->text().toStdString();
    username=ui->username_le->text().toStdString();
    bool flag=true;
    for(unsigned int i=0;flag && i<users.size();i++)
        if(users[i]._username==username || users[i]._password==password || users[i]._email==email)
            flag=false;
    bool vp=u.valid_password(password);
    if(vp && flag)
    {
        u._address=address;
        u._city=city;
        u._email=email;
        u._firstname=fname;
        u._lastname=lname;
        u._password=password;
        u._type="user";
        u._username=username;
        bool flag2=true;
        int id;
        while(flag2)
        {
            id=User::setid();
            for(unsigned int i=0;flag && i<users.size();i++)
                if(users[i]._id==id)
                    flag2=false;
            if(flag2)
            {
                u._id=id;
                flag2=false;
            }
            else
                flag2=true;
        }
        users.push_back(u);
        print_in_file();
        m.setText("successfully registered");
        m.setWindowTitle("done");
        m.show();
        m.exec();
        this->close();
        Login *l=new Login();
        l->show();
    }
    else
    {
        print_in_file();
        m.setText("can't registered");
        m.setWindowTitle("error");
        m.show();
        m.exec();
    }
}

