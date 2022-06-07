#include "purchase.h"
#include "ui_purchase.h"
#include "mainwindow.h"
#include "account.h"
#include "invoice.h"
Purchase::Purchase(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Purchase)
{
    ui->setupUi(this);
    if(factors.size()==0)
        readfactors();
    vector<Invoice> f=factors;
    for(unsigned int i=0;i<factors.size();i++)
    {
        string str;
        int total=0;
        if(factors[i].username==account._username)
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

Purchase::~Purchase()
{
    delete ui;
}

void Purchase::on_back_btn_clicked()
{
    this->close();
    MainWindow *m=new MainWindow();
    m->show();
}

