#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"
#include "seeproducts.h"
#include "chart.h"
#include "productlist.h"
#include <vector>
#include "information.h"
#include "purchase.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_back_btn_clicked()
{
    this->close();
    Login l;
    l.show();
    l.exec();
}


void MainWindow::on_sprduct_btn_clicked()
{
    this->close();
    SeeProducts *s=new SeeProducts();
    s->show();
}


void MainWindow::on_cart_btn_clicked()
{
    this->close();
    Chart *c=new Chart();
    c->show();
}


void MainWindow::on_ch_info_btn_clicked()
{
    this->close();
    Information *i=new Information();
    i->show();
}


void MainWindow::on_phistory_btn_clicked()
{
    this->close();
    Purchase *p=new Purchase();
    p->show();
}

