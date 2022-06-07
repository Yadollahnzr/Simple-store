#include "seeproduct.h"
#include "ui_seeproduct.h"
#include "product.h"
#include <fstream>
#include "mainwindow.h"
#include <QMessageBox>
using namespace std;
vector<Product> products;
SeeProduct::SeeProduct(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SeeProduct)
{
    ui->setupUi(this);
    ifstream productf("products.txt");
    Product p;
    products.clear();
    while(productf)
    {
        productf>>p;
        products.push_back(p);
    }
    productf.close();
    if(products[products.size()-1]==products[products.size()-2])
        products.pop_back();
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

SeeProduct::~SeeProduct()
{
    delete ui;
}

void SeeProduct::on_back_btn_clicked()
{
    this->close();
    MainWindow *m=new MainWindow();
    m->show();
}


void SeeProduct::on_resfresh_btn_clicked()
{
    vector<Product> temp;
    int minprice=ui->min_spinBox->value();
    int maxprice=ui->max_spinBox->value();
    string category=ui->category_le->text().toStdString();
    string city=ui->city_le->text().toStdString();
    bool min_max=false;
    bool catsize=false;
    bool citsize=false;
    bool cat=true;
    bool cit=true;
    if(category.size()>0)
        catsize=true;
    if(city.size()>0)
        citsize=true;
    unsigned psize=products.size();
    temp.clear();
    for(unsigned int i=0;i<psize;i++)
    {
        cat=true;
        cit=true;
        min_max=false;
        if(minprice<=products[i]._price && maxprice>=products[i]._price)
            min_max=true;
        if(catsize)
            if(category!=products[i]._category)
                cat=false;
        if(citsize)
            if(city!=products[i]._city)
                cit=false;
        if(min_max && cat && cit)
            temp.push_back(products[i]);
    }
    if(temp.size()==0)
    {
       ui->products_table->setRowCount(0);
       QMessageBox m;
       m.setWindowTitle("Error");
       m.setText("notfound!");
       m.show();
       m.exec();
    }
    else
    {
        ui->products_table->setRowCount(temp.size());
        for (unsigned int i{0};i<temp.size();i++)
        {
            string str;
            str=to_string(temp.at(i)._id);
            ui->products_table->setItem(i,0,new QTableWidgetItem((QString::fromStdString(str))));
            ui->products_table->setItem(i,1,new QTableWidgetItem((QString::fromStdString(temp.at(i)._name))));
            str=to_string(temp.at(i)._price);
            ui->products_table->setItem(i,2,new QTableWidgetItem((QString::fromStdString(str))));
            ui->products_table->setItem(i,3,new QTableWidgetItem((QString::fromStdString(temp.at(i)._description))));
            str=to_string(temp.at(i)._amount);
            ui->products_table->setItem(i,4,new QTableWidgetItem((QString::fromStdString(str))));
            ui->products_table->setItem(i,5,new QTableWidgetItem((QString::fromStdString(temp.at(i)._category))));
            ui->products_table->setItem(i,6,new QTableWidgetItem((QString::fromStdString(temp.at(i)._city))));
        }
    }

}

