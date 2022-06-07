#include "chart.h"
#include "ui_chart.h"
#include "chart.h"
#include <string>
#include "mainwindow.h"
#include <QMessageBox>
#include "invoice.h"
#include "productlist.h"
#include <fstream>
#include <iostream>
#include "product.h"
#include "account.h"
#include "purchase.h"
using namespace std;
Chart::Chart(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Chart)
{
    ui->setupUi(this);
    ui->chart_table->setRowCount(chart.size());
    for(unsigned int i=0;i<chart.size();i++)
    {
        string str;
        str=to_string(chart[i]._id);
        ui->chart_table->setItem(i,0,new QTableWidgetItem(QString::fromStdString(str)));
        ui->chart_table->setItem(i,1,new QTableWidgetItem(QString::fromStdString(chart[i]._name)));
        str=to_string(chart[i]._price);
        ui->chart_table->setItem(i,2,new QTableWidgetItem(QString::fromStdString(str)));
        ui->chart_table->setItem(i,3,new QTableWidgetItem(QString::fromStdString(chart[i]._description)));
        ui->chart_table->setItem(i,4,new QTableWidgetItem(QString::fromStdString(chart[i]._category)));
        ui->chart_table->setItem(i,5,new QTableWidgetItem(QString::fromStdString(chart[i]._city)));
        str=to_string(chart[i]._amount);
        ui->chart_table->setItem(i,6,new QTableWidgetItem(QString::fromStdString(str)));
    }
    if(chart.size()>0)
        ui->buy_btn->setEnabled(true);
}

Chart::~Chart()
{
    delete ui;
}

void Chart::on_back_btn_clicked()
{
    this->close();
    MainWindow *m=new MainWindow();
    m->show();
}

int index=-1;

void Chart::on_remove_btn_clicked()
{
     index=-1;
     QMessageBox m;
     string str=ui->id_le->text().toStdString();
     bool flag=true;
     int id=0;
     for(unsigned int i=0;flag && i<str.size();i++)
     {
         if(!(str[i]<='9' && str[i]>='0'))
             flag=false;
     }
     if(flag)
     {
         id=stoi(str);
         for(unsigned int i=0;index==-1 && i<chart.size();i++)
             if(chart[i]._id==id)
                 index=i;
         ui->count_spinBox->setMaximum(chart[index]._amount);
         int count=ui->count_spinBox->value();
         if(chart[index]._amount==count)
             chart.erase(chart.begin()+index);
         else if(chart[index]._amount>count)
             chart[index]._amount-=count;
         ui->chart_table->setRowCount(chart.size());
         for(unsigned int i=0;i<chart.size();i++)
         {
             string str;
             str=to_string(chart[i]._id);
             ui->chart_table->setItem(i,0,new QTableWidgetItem(QString::fromStdString(str)));
             ui->chart_table->setItem(i,1,new QTableWidgetItem(QString::fromStdString(chart[i]._name)));
             str=to_string(chart[i]._price);
             ui->chart_table->setItem(i,2,new QTableWidgetItem(QString::fromStdString(str)));
             ui->chart_table->setItem(i,3,new QTableWidgetItem(QString::fromStdString(chart[i]._description)));
             ui->chart_table->setItem(i,4,new QTableWidgetItem(QString::fromStdString(chart[i]._category)));
             ui->chart_table->setItem(i,5,new QTableWidgetItem(QString::fromStdString(chart[i]._city)));
             str=to_string(chart[i]._amount);
             ui->chart_table->setItem(i,6,new QTableWidgetItem(QString::fromStdString(str)));
         }
         if(chart.size()>0)
             ui->buy_btn->setEnabled(true);
         else
             ui->buy_btn->setEnabled(false);
         ui->id_le->setText("");
         ui->count_spinBox->setValue(0);
     }
     else
     {
         m.setWindowTitle("Error");
         m.setText("Pleas enter valid id");
         m.show();
         m.exec();
         ui->id_le->clear();
     }

}
vector<Invoice>factors;
vector<Product>products;
void Chart::on_buy_btn_clicked()
{
    vector<Product>p=products;
    bool flag=true;
    for(unsigned int i=0;i<chart.size();i++)
    {
        flag=true;
        for(unsigned int j=0;flag && j<products.size();j++)
            if(chart[i]._id==products[j]._id)
            {
                products[j]._amount-=chart[i]._amount;
                if(products[j]._amount==0)
                {
                    vector<Product>temp;
                    for(unsigned int k=0;k<products.size();k++)
                        if(k!=j)
                            temp.push_back(products[k]);
                    products=temp;
                }
                flag=false;
            }
    }
    p=products;
    ofstream outfile("products.txt",ios::trunc | ios::out);
    for(unsigned int i=0;i<products.size();i++)
    {
        outfile<<products[i];
        if(i!=products.size()-1)
            outfile<<endl<<endl;
    }
    Invoice inv;
    inv.username=account._username;
    for(unsigned int i=0;i<chart.size();i++)
    {
        inv.id.push_back(chart[i]._id);
        inv.price.push_back(chart[i]._price);
        inv.count.push_back(chart[i]._amount);
    }
    if(factors.size()==0)
        readfactors();
    vector<Invoice>in=factors;
    factors.push_back(inv);
    in=factors;
    ofstream factorf("factors.txt",ios::trunc | ios::out);
    for(unsigned int i=0;i<factors.size();i++)
    {
        factorf<<factors[i];
        if(i!=factors.size()-1)
            factorf<<endl;
    }
    chart.clear();
    ui->chart_table->setRowCount(chart.size());
    ui->buy_btn->setEnabled(false);
    Purchase *pur=new Purchase();
    pur->show();
}
