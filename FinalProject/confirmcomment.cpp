#include "confirmcomment.h"
#include "ui_confirmcomment.h"
#include "comment.h"
#include "fstream"
#include "mainwindow_2.h"
#include <QMessageBox>
using namespace std;
vector<Comment> comments;
ConfirmComment::ConfirmComment(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConfirmComment)
{
    ui->setupUi(this);
    ifstream commentf("comments.txt");
    Comment c;
    char ch;
    comments.clear();
    while(commentf)
    {
        commentf>>c;
        if(!c._show)
            comments.push_back(c);
        commentf>>ch;
    }
    if(comments[comments.size()-1]==comments[comments.size()-2])
        comments.pop_back();
    string str;
    ui->comments_table->setRowCount(comments.size());
    for(unsigned int i=0;i<comments.size();i++)
    {
        str=to_string(comments[i]._id);
        ui->comments_table->setItem(i,0,new QTableWidgetItem(QString::fromStdString(str)));
        ui->comments_table->setItem(i,1,new QTableWidgetItem(QString::fromStdString(comments[i]._username)));
        ui->comments_table->setItem(i,2,new QTableWidgetItem(QString::fromStdString(comments[i]._comment)));
        str=to_string(comments[i]._star);
        ui->comments_table->setItem(i,3,new QTableWidgetItem(QString::fromStdString(str)));
    }
}

ConfirmComment::~ConfirmComment()
{
    delete ui;
}

void ConfirmComment::on_back_btn_clicked()
{
    this->close();
    MainWindow_2 *m=new MainWindow_2();
    m->show();
}


void ConfirmComment::on_pushButton_clicked()
{
    QMessageBox m;
    string str=ui->cnum_le->text().toStdString();
    bool flag=true;
    for(unsigned int i=0;i<str.size();i++)
        if(!(str[i]>='0' && str[i]<='9'))
            flag=false;
    if(flag)
    {
        int row=stoi(str);
        ifstream commentf("comments.txt");
        Comment c;
        vector<Comment>temp;
        while(!commentf.eof())
        {
            bool flag=true;
            commentf>>c;
            if(c==comments[row-1])
                c._show=1;
            for(unsigned int i=0;i<temp.size();i++)
                if(temp[i]==c)
                    flag=false;
            if(flag)
                temp.push_back(c);
        }
        commentf.close();
        comments.clear();
        ofstream out("comments.txt",ios::trunc | ios::out);
        if(temp[temp.size()-1]==temp[temp.size()-2])
            temp.pop_back();
        for(unsigned int i=0;i<temp.size();i++)
        {
            out<<temp[i];
            if(i!=temp.size()-1)
                out<<endl<<endl;
        }
        char ch;
        while(commentf)
        {
            commentf>>c;
            if(!c._show)
                comments.push_back(c);
            commentf>>ch;
        }
        if(comments[comments.size()-1]==comments[comments.size()-2])
            comments.pop_back();
        string str2;
        ui->comments_table->setRowCount(comments.size());
        for(unsigned int i=0;i<comments.size();i++)
        {
            str2=to_string(comments[i]._id);
            ui->comments_table->setItem(i,0,new QTableWidgetItem(QString::fromStdString(str2)));
            ui->comments_table->setItem(i,1,new QTableWidgetItem(QString::fromStdString(comments[i]._username)));
            ui->comments_table->setItem(i,2,new QTableWidgetItem(QString::fromStdString(comments[i]._comment)));
            str2=to_string(comments[i]._star);
            ui->comments_table->setItem(i,3,new QTableWidgetItem(QString::fromStdString(str2)));
        }
        m.setText("done");
        m.show();
        m.exec();
    }
    else
    {
        m.setText("pleas inter valid row");
        m.setWindowTitle("error");
        m.show();
        m.exec();
    }
}

