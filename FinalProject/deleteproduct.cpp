#include "deleteproduct.h"
#include "ui_deleteproduct.h"
#include <mainwindow_2.h>
#include "productlist.h"
#include <QMessageBox>
#include <string>
#include <vector>
using namespace std;
DeleteProduct::DeleteProduct(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteProduct)
{
    ui->setupUi(this);
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
}

DeleteProduct::~DeleteProduct()
{
    delete ui;
}

void DeleteProduct::on_back_btn_clicked()
{
    this->close();
    MainWindow_2 *m=new MainWindow_2;
    m->show();
}


void DeleteProduct::on_show_btn_clicked()
{
    QMessageBox m;
    string str=ui->id_le->text().toStdString();
    bool flag=true;
    for(unsigned int i=0;i<str.size();i++)
        if(!(str[i]<='9' && str[i]>='0'))
            flag=false;
    if(flag && str.size()>0)
    {
        int id=stoi(str);
        vector<Product> temp;
        for(unsigned int i=0;i<products.size();i++)
            if(products[i]._id!=id)
                temp.push_back(products[i]);
        products.clear();
        products=temp;
        ofstream file("products.txt",ios::trunc | ios::out);
        for(unsigned int i=0;i<products.size()-1;i++)
            file<<products[i]<<endl<<endl;
        file<<products[products.size()-1];
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
        m.setWindowTitle("done");
        m.setText("deleted the product");
        m.show();
        m.exec();
    }
    else
    {
        m.setWindowTitle("error");
        m.setText("enter a valid id");
        m.show();
        m.exec();
    }
}

