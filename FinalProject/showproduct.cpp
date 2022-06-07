#include "showproduct.h"
#include "ui_showproduct.h"
#include "string"
#include "chart.h"
#include "productlist.h"
#include <fstream>
#include <QMessageBox>
#include "comment.h"
#include "account.h"
#include "addcommet.h"
vector<Product> chart;
Product product;
using namespace std;
ShowProduct::ShowProduct(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowProduct)
{
    ui->setupUi(this);
}

ShowProduct::~ShowProduct()
{
    delete ui;
}

void ShowProduct::on_show_btn_clicked()
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
    int id=stoi(ui->id_le->text().toStdString());
    product_id=id;
    bool flag=true;
    for(unsigned int i=0;flag && i<products.size();i++)
        if(products[i]._id==id)
        {
            product=products[i];
            ui->addchart_btn->setEnabled(true);
            ui->addcomment_btn->setEnabled(true);
            ui->count_spinBox->setMaximum(products[i]._amount);
            ui->count_spinBox->setEnabled(true);
            string str;
            ui->name_le->setText(QString::fromStdString(products[i]._name));
            str=to_string(products[i]._price);
            ui->price_le->setText(QString::fromStdString(str));
            ui->desc_le->setText(QString::fromStdString(products[i]._description));
            str=to_string(products[i]._amount);
            ui->amount_le->setText(QString::fromStdString(str));
            ui->cat_le->setText(QString::fromStdString(products[i]._category));
            ui->city_le->setText(QString::fromStdString(products[i]._city));
            flag=false;
        }
    ui->comment_list->clear();
    for(unsigned int i=0;!flag && i<comments.size();i++)
    {
        if(comments[i]._id==id && comments[i]._show)
        {
            string c;
            c+=comments[i]._username;
            c+=": ";
            c+=comments[i]._comment;
            c+=" ( star ";
            c+=to_string(comments[i]._star);
            c+=" )";
            ui->comment_list->addItem(QString::fromStdString(c));
        }
    }
    if(flag)
    {
        QMessageBox m;
        m.setText("product not fount!");
        m.setWindowTitle("Error");
        m.show();
        m.exec();
    }
}

void ShowProduct::on_addcomment_btn_clicked()
{
    AddCommet *ac=new AddCommet();
    ac->show();
}


void ShowProduct::on_addchart_btn_clicked()
{
    bool flag=true;
    int count=ui->count_spinBox->value();
    for(unsigned int i=0;flag && i<chart.size();i++)
    {
        if(chart[i]._id==product._id)
            flag=false;
    }
    QMessageBox m;
    if(flag)
    {
        product._amount=count;
        chart.push_back(product);
        m.setWindowTitle("Add in chart");
        m.setText("Successfully add");
        m.show();
        m.exec();
    }
    else if(!flag)
    {
        m.setWindowTitle("Add in chart");
        m.setText("Can't add this product in your chart");
        m.show();
        m.exec();
    }
    this->close();
}

