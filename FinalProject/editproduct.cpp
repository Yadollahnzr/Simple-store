#include "editproduct.h"
#include "ui_editproduct.h"
#include "mainwindow_2.h"
#include "productlist.h"
#include <string>
#include <vector>
#include <fstream>
#include <QMessageBox>
using namespace std;
EditProduct::EditProduct(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditProduct)
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

EditProduct::~EditProduct()
{
    delete ui;
}

void EditProduct::on_back_btn_clicked()
{
    this->close();
    MainWindow_2 *m=new MainWindow_2();
    m->show();
}


void EditProduct::on_show_btn_clicked()
{
    string str=ui->id_le->text().toStdString();
    int id=stoi(str);
    Product p;
    bool flag=true;;
    for(unsigned int i=0;flag && i<products.size();i++)
        if(products[i]._id==id)
        {
            p=products[i];
            flag=false;
        }
    ui->amount_le->setText(QString::fromStdString(to_string(p._amount)));
    ui->cat_le->setText(QString::fromStdString(p._category));
    ui->des_le->setText(QString::fromStdString(p._description));
    ui->city_le->setText(QString::fromStdString(p._city));
    ui->price_le->setText(QString::fromStdString(to_string(p._price)));
    ui->name_le->setText(QString::fromStdString(p._name));
    ui->edit_btn->setEnabled(true);
}


void EditProduct::on_edit_btn_clicked()
{
    QMessageBox m;
    Product p;
    vector<Product> temp;
    p._id=stoi(ui->id_le->text().toStdString());
    p._amount=stoi(ui->amount_le->text().toStdString());
    p._category=ui->cat_le->text().toStdString();
    p._city=ui->city_le->text().toStdString();
    p._name=ui->name_le->text().toStdString();
    p._description=ui->des_le->text().toStdString();
    p._price=stoi(ui->price_le->text().toStdString());
    for(unsigned int i=0;i<products.size();i++)
        if(products[i]._id!=p._id)
            temp.push_back(products[i]);
    temp.push_back(p);
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
    m.setText("edited the product");
    m.show();
    m.exec();

}

