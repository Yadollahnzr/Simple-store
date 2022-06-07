#include "addproduct.h"
#include "ui_addproduct.h"
#include "productlist.h"
#include <QMessageBox>
#include <fstream>
#include "mainwindow_2.h"
AddProduct::AddProduct(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddProduct)
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

AddProduct::~AddProduct()
{
    delete ui;
}

void AddProduct::on_add_btn_clicked()
{
    QMessageBox m;
    string id,name,description,category,city,amount,price;
    id=ui->id_le->text().toStdString();
    name=ui->name_le->text().toStdString();
    description=ui->des_le->text().toStdString();
    category=ui->cat_le->text().toStdString();
    city=ui->city_le->text().toStdString();
    amount=ui->amount_le->text().toStdString();
    price=ui->price_le->text().toStdString();
    if(id.size()==0 || name.size()==0 || description.size()==0 || category.size()==0 || city.size()==0 || amount.size()==0 || price.size()==0)
    {
        m.setWindowTitle("error");
        m.setText("enter all info");
        m.show();
        m.exec();
    }
    else
    {
        Product p;
        p._id=stoi(id);
        p._name=name;
        p._amount=stoi(amount);
        p._city=city;
        p._category=category;
        p._price=stoi(price);
        p._description=description;
        if(products.size()==0)
            readproducts();
        bool flag=true;
        for(unsigned int i=0;i<products.size()-1;i++)
            if(products[i]._id==p._id || (products[i]._name==p._name && products[i]._city==p._city))
                flag=false;
        if(flag)
        {
            products.push_back(p);
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
            m.setText("adding a new product");
            m.show();
            m.exec();
        }
        else
        {
            m.setWindowTitle("error");
            m.setText("this product is exist");
            m.show();
            m.exec();
        }
    }
}


void AddProduct::on_back_btn_clicked()
{
    this->close();
    MainWindow_2 *m=new MainWindow_2();
    m->show();
}

