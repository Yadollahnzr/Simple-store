#include "userfactors.h"
#include "ui_userfactors.h"
#include <string>
#include "account.h"
#include <QMessageBox>
#include "mainwindow_2.h"
#include "users.h"
using namespace std;
Userfactors::Userfactors(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Userfactors)
{
    ui->setupUi(this);
}

Userfactors::~Userfactors()
{
    delete ui;
}

void Userfactors::on_showuname_btn_clicked()
{
    ui->factorslist->clear();
    string username=ui->username_le->text().toStdString();
    if(username.size()!=0)
    {
        if(factors.size()==0)
            readfactors();
        vector<Invoice> f=factors;
        for(unsigned int i=0;i<factors.size();i++)
        {
            string str;
            int total=0;
            if(factors[i].username==username)
            {
                for(unsigned int j=0;j<factors[i].id.size();j++)
                {
                    str+="id = ";
                    str+=to_string(factors[i].id[j]);
                    str+=" , count = ";
                    str+=to_string(factors[i].count[j]);
                    str+=" , price = ";
                    str+=to_string(factors[i].price[j]);
                    str+='\n';
                    total+=factors[i].price[j]*factors[i].count[j];
                }
                str+="total price = ";
                str+=to_string(total);
                str+="\n";
                ui->factorslist->addItem(QString::fromStdString(str));
            }
        }
    }
    else
    {
        QMessageBox m;
        m.setText("pleas enter a username");
        m.setWindowTitle("error");
        m.show();
        m.exec();
    }
}


void Userfactors::on_showid_btn_clicked()
{
    ui->factorslist->clear();
    string s=ui->id_le->text().toStdString();
    bool flag=true;
    for(unsigned int i=0;i<s.size();i++)
        if(!(s[i]<='9' && s[i]>='0'))
            flag=false;
    if(flag && s.size()>0)
    {
        int id=stoi(s);
        bool flag=true;
        if(users.size()==0)
            readusers();
        for(unsigned int i=0;flag && i<users.size();i++)
            if(id==users[i]._id)
            {
                s=users[i]._username;
                ui->username_le->setText(QString::fromStdString(s));
                flag=false;
            }
        if(factors.size()==0)
            readfactors();
        vector<Invoice> f=factors;
        for(unsigned int i=0;i<factors.size();i++)
        {
            string str;
            int total=0;
            if(factors[i].username==s)
            {
                for(unsigned int j=0;j<factors[i].id.size();j++)
                {
                    str+="id = ";
                    str+=to_string(factors[i].id[j]);
                    str+=" , count = ";
                    str+=to_string(factors[i].count[j]);
                    str+=" , price = ";
                    str+=to_string(factors[i].price[j]);
                    str+='\n';
                    total+=factors[i].price[j]*factors[i].count[j];
                }
                str+="total price = ";
                str+=to_string(total);
                str+="\n";
                ui->factorslist->addItem(QString::fromStdString(str));
            }
        }
    }
    else
    {
        QMessageBox m;
        m.setText("enter a valid id");
        m.setWindowTitle("error");
        m.show();
        m.exec();
    }
}


void Userfactors::on_back_btn_clicked()
{
    this->close();
    MainWindow_2 *m=new MainWindow_2();
    m->show();
}

