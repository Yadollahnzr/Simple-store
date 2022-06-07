#include "invoice.h"
#include <iostream>
#include <vector>
using namespace std;
enum inv_feilds{id,price,count,username};
Invoice::Invoice()
{
}

bool Invoice::operator==(const Invoice &inv)
{
    if(username==inv.username && id==inv.id && count==inv.count && price==inv.price)
        return true;
    return false;
}

ostream &operator<<(ostream &out,const Invoice &inv)
{
    string str;
    str+="id = ";
    for(unsigned int i=0;i<inv.id.size();i++)
    {
        str+=to_string(inv.id[i]);
        if(i!=inv.id.size()-1)
            str+=',';
    }
    str+=" , price = ";
    for(unsigned int i=0;i<inv.price.size();i++)
    {
        str+=to_string(inv.price[i]);
        if(i!=inv.price.size()-1)
            str+=',';
    }
    str+=" , count = ";
    for(unsigned int i=0;i<inv.count.size();i++)
    {
        str+=to_string(inv.count[i]);
        if(i!=inv.count.size()-1)
            str+=',';
    }
    str+=" , username = "+inv.username;
    out<<str;
    return out;
}

istream &operator>>(istream &in,Invoice &inv)
{
    string str;
    getline(in,str);
    vector<char>temp;
    int count=0;
    for(unsigned int i=0;i<str.size();i++)
    {
        if(str[i]=='=')
        {
            i+=2;
            if(count!=username)
            {
                while(str[i]!=' ')
                {
                    while(str[i]!=',')
                    {
                        temp.push_back(str[i]);
                        i++;
                    }
                    if(temp[temp.size()-1]==' ')
                        temp.pop_back();
                    char *temp2=new char[temp.size()];
                    for(unsigned int j=0;j<temp.size();j++)
                        temp2[j]=temp[j];
                    string s=temp2;
                    s.resize(temp.size());
                    if(count==id)
                        inv.id.push_back(stoi(s));
                    else if(count==price)
                        inv.price.push_back(stoi(s));
                    else if(count==inv_feilds::count)
                        inv.count.push_back(stoi(s));
                    delete [] temp2;
                    temp.clear();
                    i++;
                }
                count++;
            }
            else if(count==username)
            {
                while(i<str.size())
                {
                    temp.push_back(str[i]);
                    i++;
                }
                if(temp[i]==' ')
                    temp.pop_back();
                char *temp2=new char[temp.size()];
                for(unsigned int j=0;j<temp.size();j++)
                    temp2[j]=temp[j];
                inv.username=temp2;
                inv.username.resize(temp.size());
                delete [] temp2;
                temp.clear();
                count++;
            }
        }
    }
    return in;
}
