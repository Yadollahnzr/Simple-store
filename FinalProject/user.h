#ifndef USER_H
#define USER_H
#include <string>
using namespace std;
class User
{
    friend ostream &operator<<(ostream &output,const User &u);
    friend istream &operator>>(istream &input,User &u);
public:
    User();
    bool valid_password(string);
    bool operator==(const User &u);
    static int setid();
public:
    int _id;
    string _firstname;
    string _lastname;
    string _city;
    string _email;
    string _username;
    string _password;
    string _type;
    string _address;
};


#endif // USER_H
