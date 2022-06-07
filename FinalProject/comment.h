#ifndef COMMENT_H
#define COMMENT_H
#include<string>
#include<iostream>
using namespace std;

class Comment
{
    friend ostream &operator<<(ostream &out,const Comment &c);
    friend istream &operator>>(istream &in,Comment &c);
public:
    Comment();
    bool operator==(const Comment &c);
public:
    bool _show;
    int _id;
    string _username;
    string _comment;
    int _star;
};

#endif // COMMENT_H
