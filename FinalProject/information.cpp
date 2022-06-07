#include "information.h"
#include "ui_information.h"
#include "mainwindow.h"
#include "account.h"
#include "fstream"
#include "users.h"
#include <string>
#include "comment.h"
#include "invoice.h"
#include <QMessageBox>
using namespace std;
Information::Information(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Information)
{
    ui->setupUi(this);
}

Information::~Information()
{
    delete ui;
}
void Information::on_back_btn_clicked()
{
    this->close();
    MainWindow *m=new MainWindow();
    m->show();
}
void Information::on_username_btn_clicked()
{
    QMessageBox m;
    bool flag=true;
    string str=ui->username_le->text().toStdString();
    for(unsigned int i=0;flag && i<users.size();i++)
        if(users[i]._username==str)
            flag=false;
    if(flag)
    {
        vector<Comment> comments;
        ifstream commentf("comments.txt");
        Comment c;
        char ch;
        while(commentf)
        {
            commentf>>c;
            commentf>>ch;
            comments.push_back(c);
        }
        if(comments[comments.size()-1]==comments[comments.size()-2])
            comments.pop_back();
        for(unsigned int i=0;i<comments.size();i++)
            if(comments[i]._username==account._username)
                comments[i]._username=str;
        ofstream commentout("comments.txt",ios::trunc | ios::out);
        for(unsigned int i=0;i<comments.size()-1;i++)
            commentout<<comments[i]<<endl<<endl;
        commentout<<comments[comments.size()-1];
        factors.clear();
        readfactors();
        for(unsigned int i=0;i<factors.size();i++)
            if(factors[i].username==account._username)
                factors[i].username=str;
        ofstream factorsout("factors.txt",ios::trunc | ios::out);
        for(unsigned int i=0;i<factors.size()-1;i++)
            factorsout<<factors[i]<<endl;
        factorsout<<factors[factors.size()-1];
        vector<User>temp;
        account._username=str;
        for(unsigned int i=0;i<users.size();i++)
            if(account._id!=users[i]._id)
                temp.push_back(users[i]);
        temp.push_back(account);
        users=temp;
        print_in_file();
        m.setText("username changed");
        m.setWindowTitle("done");
        m.show();
        m.exec();
    }
    else
    {
        m.setText("input username is already exist");
        m.setWindowTitle("error");
        m.show();
        m.exec();
    }
}


void Information::on_password_btn_clicked()
{
    QMessageBox m;
    bool flag=true;
    string str=ui->password_le->text().toStdString();
    for(unsigned int i=0;flag && i<users.size();i++)
        if(users[i]._password==str)
            flag=false;
    if(flag)
    {
        vector<User>temp;
        account._password=str;
        for(unsigned int i=0;i<users.size();i++)
            if(account._id!=users[i]._id)
                temp.push_back(users[i]);
        temp.push_back(account);
        users=temp;
        print_in_file();
        m.setText("password changed");
        m.setWindowTitle("done");
        m.show();
        m.exec();
    }
    else
    {
        m.setText("input password is already exist");
        m.setWindowTitle("error");
        m.show();
        m.exec();

    }
}


void Information::on_name_btn_clicked()
{
}


void Information::on_email_btn_clicked()
{
    QMessageBox m;
    bool flag=true;
    string str=ui->email_le->text().toStdString();
    for(unsigned int i=0;flag && i<users.size();i++)
        if(users[i]._email==str)
            flag=false;
    if(flag)
    {
        vector<User>temp;
        account._email=str;
        for(unsigned int i=0;i<users.size();i++)
            if(account._id!=users[i]._id)
                temp.push_back(users[i]);
        temp.push_back(account);
        users=temp;
        print_in_file();
        m.setText("email changed");
        m.setWindowTitle("done");
        m.show();
        m.exec();
    }
    else
    {
        m.setText("input email is already exist");
        m.setWindowTitle("error");
        m.show();
        m.exec();
    }
}


void Information::on_address_btn_clicked()
{
    QMessageBox m;
    bool flag=true;
    string str=ui->address_le->text().toStdString();
    for(unsigned int i=0;flag && i<users.size();i++)
        if(users[i]._id==account._id)
        {
            users[i]._address=str;
            account._address=str;
            print_in_file();
            m.setText("address changed");
            m.setWindowTitle("done");
            m.show();
            m.exec();
            flag=false;
        }
    if(flag)
    {
        m.setText("address isn't change");
        m.setWindowTitle("error");
        m.show();
        m.exec();
    }
}


void Information::on_city_btn_clicked()
{
    QMessageBox m;
    bool flag=true;
    string str=ui->city_le->text().toStdString();
    for(unsigned int i=0;flag && i<users.size();i++)
        if(users[i]._id==account._id)
        {
            users[i]._city=str;
            account._city=str;
            print_in_file();
            m.setText("city changed");
            m.setWindowTitle("done");
            m.show();
            m.exec();
            flag=false;
        }
    if(flag)
    {
        m.setText("city isn't change");
        m.setWindowTitle("error");
        m.show();
        m.exec();
    }
}


void Information::on_fname_btn_clicked()
{
    QMessageBox m;
    bool flag=true;
    string str=ui->fname_le->text().toStdString();
    for(unsigned int i=0;flag && i<users.size();i++)
        if(users[i]._id==account._id)
        {
            users[i]._firstname=str;
            account._firstname=str;
            print_in_file();
            m.setText("first name changed");
            m.setWindowTitle("done");
            m.show();
            m.exec();
            flag=false;
        }
    if(flag)
    {
        m.setText("first name is'n change");
        m.setWindowTitle("error");
        m.show();
        m.exec();
    }
}


void Information::on_lname_btn_clicked()
{
    QMessageBox m;
    bool flag=true;
    string str=ui->lname_le->text().toStdString();
    for(unsigned int i=0;flag && i<users.size();i++)
        if(users[i]._id==account._id)
        {
            users[i]._lastname=str;
            account._lastname=str;
            print_in_file();
            m.setText("last name changed");
            m.setWindowTitle("done");
            m.show();
            m.exec();
            flag=false;
        }
    if(flag)
    {
        m.setText("last name is'n change");
        m.setWindowTitle("error");
        m.show();
        m.exec();
    }
}

