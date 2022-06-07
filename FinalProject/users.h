#ifndef USERS_H
#define USERS_H
#include "user.h"
#include "vector"
#include "fstream"
using namespace std;
extern vector<User>users;
inline void readusers()
{
    User u;
    ifstream userf("users.txt");
    char ch;
    while(!userf.eof())
    {
        userf>>u;
        bool flag=true;
        for(unsigned int i=0;flag && i<users.size();i++)
            if(users[i]._username==u._username || users[i]._password==u._password || users[i]._email==u._email || users[i]._id==u._id)
                flag=false;
        bool vp=u.valid_password(u._password);
        if(flag && vp)
            users.push_back(u);
        userf>>ch;
    }
    if(users[users.size()-1]==users[users.size()-2])
        users.pop_back();
    userf.close();
}
inline void print_in_file()
{
    ofstream userf("users.txt",ios::trunc | ios::out);
    for(unsigned int i=0;i<users.size();i++)
    {
        userf<<users[i];
        if(i!=users.size()-1)
            userf<<endl<<endl;
    }
}
#endif // USERS_H
