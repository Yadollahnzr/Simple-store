#include "discount.h"
#include "ui_discount.h"
#include <mainwindow_2.h>
#include "productlist.h"
#include <QMessageBox>
#include <string>
#include <vector>
#include "account.h"
#include "mainwindow_2.h"
using namespace std;
struct ProductCount
{
    Product p;
    int count=0;
};
vector<ProductCount> pc;
Discount::Discount(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Discount)
{
    ui->setupUi(this);
    if(factors.size()==0)
        readfactors();
    if(products.size()==0)
        readproducts();
    int rowcount=products.size();
    ui->products_table->setRowCount(rowcount);
    for (unsigned int i{0};i<products.size();i++)
    {
        string str;
        str=to_string(products.at(i)._id);
        ui->products_table->setItem(i,0,new QTableWidgetItem((QString::fromStdString(str))));
        ui->products_table->setItem(i,1,new QTableWidgetItem((QString::fromStdString(products.at(i)._name))));
        str=to_string(products.at(i)._price);
        ui->products_table->setItem(i,2,new QTableWidgetItem((QString::fromStdString(str))));
        ui->products_table->setItem(i,3,new QTableWidgetItem((QString::fromStdString(products.at(i)._description))));
        str=to_string(products.at(i)._amount);
        ui->products_table->setItem(i,4,new QTableWidgetItem((QString::fromStdString(str))));
        ui->products_table->setItem(i,5,new QTableWidgetItem((QString::fromStdString(products.at(i)._category))));
        ui->products_table->setItem(i,6,new QTableWidgetItem((QString::fromStdString(products.at(i)._city))));
    }
    int max;
    for(unsigned int i=0;i<products.size();i++)
    {
        int count=0;
        for(unsigned int j=0;j<factors.size();j++)
        {
            for(unsigned int k=0;k<factors[j].id.size();k++)
                if(products[i]._id==factors[j].id[k])
                    count+=factors[j].count[k];
        }
        ProductCount temp;
        temp.count=count;
        temp.p=products[i];
        pc.push_back(temp);
        if(i==0)
        {
            max=pc[i].count;
        }
        if(max<pc[i].count)
        {
            max=pc[i].count;
        }
    }
    for(unsigned int i=0;i<pc.size();i++)
    {
        if((10*pc[i].count)<(4*max))
            pc[i].p._price*=0.85;

    }
    rowcount=pc.size();
    ui->products_table_2->setRowCount(rowcount);
    for (unsigned int i{0};i<pc.size();i++)
    {
        string str;
        str=to_string(pc.at(i).p._id);
        ui->products_table_2->setItem(i,0,new QTableWidgetItem((QString::fromStdString(str))));
        ui->products_table_2->setItem(i,1,new QTableWidgetItem((QString::fromStdString(pc.at(i).p._name))));
        str=to_string(pc.at(i).p._price);
        ui->products_table_2->setItem(i,2,new QTableWidgetItem((QString::fromStdString(str))));
        ui->products_table_2->setItem(i,3,new QTableWidgetItem((QString::fromStdString(pc.at(i).p._description))));
        str=to_string(pc.at(i).p._amount);
        ui->products_table_2->setItem(i,4,new QTableWidgetItem((QString::fromStdString(str))));
        ui->products_table_2->setItem(i,5,new QTableWidgetItem((QString::fromStdString(pc.at(i).p._category))));
        ui->products_table_2->setItem(i,6,new QTableWidgetItem((QString::fromStdString(pc.at(i).p._city))));
    }
}

Discount::~Discount()
{
    delete ui;
}

void Discount::on_back_btn_clicked()
{
    this->close();
    MainWindow_2 *m=new MainWindow_2();
    m->show();
}


void Discount::on_done_btn_clicked()
{
    QMessageBox m;
    products.clear();
    for(unsigned int i=0;i<pc.size();i++)
        products.push_back(pc[i].p);
    pc.clear();
    ofstream file("products.txt",ios::trunc | ios::out);
    for(unsigned int i=0;i<products.size()-1;i++)
        file<<products[i]<<endl<<endl;
    file<<products[products.size()-1];
    m.setText("Discount was applied");
    m.setWindowTitle("done");
    m.show();
    m.exec();
    int rowcount=products.size();
    ui->products_table->setRowCount(rowcount);
    for (unsigned int i{0};i<products.size();i++)
    {
        string str;
        str=to_string(products.at(i)._id);
        ui->products_table->setItem(i,0,new QTableWidgetItem((QString::fromStdString(str))));
        ui->products_table->setItem(i,1,new QTableWidgetItem((QString::fromStdString(products.at(i)._name))));
        str=to_string(products.at(i)._price);
        ui->products_table->setItem(i,2,new QTableWidgetItem((QString::fromStdString(str))));
        ui->products_table->setItem(i,3,new QTableWidgetItem((QString::fromStdString(products.at(i)._description))));
        str=to_string(products.at(i)._amount);
        ui->products_table->setItem(i,4,new QTableWidgetItem((QString::fromStdString(str))));
        ui->products_table->setItem(i,5,new QTableWidgetItem((QString::fromStdString(products.at(i)._category))));
        ui->products_table->setItem(i,6,new QTableWidgetItem((QString::fromStdString(products.at(i)._city))));
    }
    ui->products_table_2->clear();
    ui->done_btn->setEnabled(false);
}

