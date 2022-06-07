#include "mainwindow_2.h"
#include "ui_mainwindow_2.h"
#include "login.h"
#include "confirmcomment.h"
#include "userfactors.h"
#include "addproduct.h"
#include "editproduct.h"
#include "deleteproduct.h"
#include "discount.h"
MainWindow_2::MainWindow_2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow_2)
{
    ui->setupUi(this);
}

MainWindow_2::~MainWindow_2()
{
    delete ui;
}

void MainWindow_2::on_ccomments_btn_clicked()
{
    this->close();
    ConfirmComment *c=new ConfirmComment();
    c->show();
}


void MainWindow_2::on_back_btn_clicked()
{
    this->close();
    Login l;
    l.show();
    l.exec();
}


void MainWindow_2::on_vphistory_btn_clicked()
{
    this->close();
    Userfactors *u=new Userfactors();
    u->show();
}


void MainWindow_2::on_addproduct_btn_clicked()
{
    this->close();
    AddProduct *p=new AddProduct();
    p->show();
}


void MainWindow_2::on_editproducts_btn_clicked()
{
    this->close();
    EditProduct *e=new EditProduct();
    e->show();
}


void MainWindow_2::on_deleteproducts_btn_clicked()
{
    this->close();
    DeleteProduct *d=new DeleteProduct();
    d->show();
}


void MainWindow_2::on_discount_btn_clicked()
{
    this->close();
    Discount *d=new Discount();
    d->show();
}

