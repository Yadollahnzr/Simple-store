#include "user.h"
#include "iostream"
#include <string>
#include <vector>
#include <ctime>
using namespace std;
enum{id,name,city,address,email,username,password,type};
User::User()
{
    _firstname="";
    _lastname="";
    _city="";
    _address="";
    _username="";
    _password="";
    _type="";
    _email="";
    setid();
}

bool User::valid_password(string str)
{
    bool has_letter=false;
    bool has_num=false;
    bool has_sign=false;
    for(unsigned int i=0;i<str.size() && (!has_letter || !has_num || !has_sign);i++)
    {
        bool flag1=str[i]<='9' && str[i]>='0';
        bool flag2=(str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z');
        if(flag1)
            has_num=true;
        if(flag2)
            has_letter=true;
        if(!(flag1 || flag2))
            has_sign=true;
    }
    if(has_letter && has_num && has_sign)
        return true;
    else
        return false;
}

bool User::operator==(const User &u)
{
    if(_id==u._id && _firstname==u._firstname && _lastname==u._lastname && _city==u._city
            && _address==u._address && _email==u._email && _username==u._username
            && _password==u._password && _type==u._type)
        return true;
    return false;

}

int User::setid()
{
    srand(static_cast<unsigned int>(time(0)));
    int id=rand()%100+1;
    return id;
}
ostream &operator<<(ostream &output,const User &u)
{
    output<<"id = ";
    string str=to_string(u._id);
    output<<str<<" , name = "<<u._firstname<<" "<<u._lastname<<" , city = "<<u._city;
    output<<" , address = "<<u._address<<endl<<"email = "<<u._email<<" , username = "<<u._username
         <<" , pass = "<<u._password<<" , type = "<<u._type;
    return output;
}

istream &operator>>(istream &input,User &u)
{
    string str1,str2;
    getline(input,str1);
    getline(input,str2);
    vector<char> temp;
    int count=0;
    for(unsigned int i=0;i<str1.size();i++)
    {
        if(str1[i]=='=')
        {
            i+=2;
            if(count==address)
            {
                while(i<str1.size())
                {
                    temp.push_back(str1[i]);
                    i++;
                }
                if(temp[temp.size()-1]==' ')
                    temp.pop_back();
                char *array=new char[temp.size()];
                for(unsigned int j=0;j<temp.size();j++)
                    array[j]=temp[j];
                u._address=array;
                u._address.resize(temp.size());
                delete [] array;
                count++;
            }
            else if(count== name)
            {
                while (str1[i]!=' ')
                {
                    temp.push_back(str1[i]);
                    i++;
                }
                if(temp[temp.size()-1]==' ')
                    temp.pop_back();
                char *array=new char[temp.size()];
                for(unsigned int j=0;j<temp.size();j++)
                    array[j]=temp[j];
                u._firstname=array;
                u._firstname.resize(temp.size());
                delete [] array;
                temp.clear();
                i++;
                while (str1[i]!=',')
                {
                    temp.push_back(str1[i]);
                    i++;
                }
                if(temp[temp.size()-1]==' ')
                    temp.pop_back();
                char *array2=new char[temp.size()];
                for(unsigned int j=0;j<temp.size();j++)
                    array2[j]=temp[j];
                u._lastname=array2;
                u._lastname.resize(temp.size());
                delete [] array2;
                temp.clear();
                count++;
            }
            else
            {
                while (str1[i]!=',')
                {
                    temp.push_back(str1[i]);
                    i++;
                }
                if(temp[temp.size()-1]==' ')
                    temp.pop_back();
                char *array=new char[temp.size()];
                for(unsigned int j=0;j<temp.size();j++)
                    array[j]=temp[j];
                if(count==id)
                    u._id=stoi(array);
                else if(count==city)
                {
                    u._city=array;
                    u._city.resize(temp.size());
                }
                delete [] array;
                temp.clear();
                count++;
            }
        }
    }
    temp.clear();
    for(unsigned int i=0;i<str2.size();i++)
    {
        if(str2[i]=='=')
        {
            i+=2;
            unsigned int j;
            for(j=i;str2[j]!=',' && j<str2.size();j++)
            {
                temp.push_back(str2[j]);
            }
            i=j;
            if(temp[temp.size()-1]==' ')
                temp.pop_back();
            char *temp2=new char[temp.size()];
            for(unsigned int k=0;k<temp.size();k++)
                temp2[k]=temp[k];
            if(count==email)
            {
                u._email=temp2;
                u._email.resize(temp.size());
                count++;
            }
            else if(count==username)
            {
                u._username=temp2;
                u._username.resize(temp.size());
                count++;
            }
            else if(count==password)
            {
                u._password=temp2;
                u._password.resize(temp.size());
                count++;
            }
            else if(count==type)
            {
                u._type=temp2;
                u._type.resize(temp.size());
                count++;
            }
            temp.clear();
            delete [] temp2;
        }

    }
    return input;
}
