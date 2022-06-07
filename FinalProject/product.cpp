#include "product.h"
#include <iostream>
#include <vector>
using namespace std;
enum{id,name,price,description,amount,category,city};
Product::Product()
{
    _name="";
    _description="";
    _category="";
    _city="";
    _id=0;
    _price=0;
    _amount=0;
}

Product::Product(string name, string description, string category, string city, int id, int price, int amount)
{
   _name=name;
   _description=description;
   _category=category;
   _city=city;
   _id=id;
   _price=price;
   _amount=amount;
}

bool Product::operator==(const Product &p)
{
    if(_id==p._id && _name==p._name && _price==p._price && _description==p._description &&
            _amount==p._amount && _category==p._category && _city==p._city)
        return true;
    return false;
}
istream &operator>>(istream &input,Product& p)
{
    string str1,str2;
    vector<char> temp1;
    getline(input,str1);
    getline(input,str2);
    int count=0;
    for(unsigned int i=0;i<str1.size();i++)
    {
        if(str1[i]=='=')
        {
            i+=2;
            unsigned int j;
            for(j=i;str1[j]!=',' && j<str1.size();j++)
            {
                temp1.push_back(str1[j]);
            }
            i=j;
            if(temp1[temp1.size()-1]==' ')
                temp1.pop_back();
            char *temp2=new char[temp1.size()];
            for(unsigned int k=0;k<temp1.size();k++)
                temp2[k]=temp1[k];
            string s=temp2;
            s.resize(temp1.size());
            delete [] temp2;
            if(count==id)
            {
                p._id=stoi(s);
                count++;
            }
            else if(count==name)
            {
                p._name=s;
                p._name.resize(temp1.size());
                count++;
            }
            else if(count==price)
            {
                p._price=stoi(s);
                count++;
            }
            else if(count==description)
            {
                p._description=s;
                p._description.resize(temp1.size());
                count++;
            }
            temp1.clear();
        }

    }//end loop for str1

    for(unsigned int i=0;i<str2.size();i++)
    {
        if(str2[i]=='=')
        {
            i+=2;
            unsigned int j;
            for(j=i;str2[j]!=',' && j<str2.size();j++)
            {
                temp1.push_back(str2[j]);
            }
            i=j;
            if(temp1[temp1.size()-1]==' ')
            temp1.pop_back();
            char temp2[temp1.size()];
            for(unsigned int k=0;k<temp1.size();k++)
                temp2[k]=temp1[k];
            string s=temp2;
            s.resize(temp1.size());
            if(count==amount)
            {
                p._amount=stoi(s);
                count++;
            }
            else if(count==category)
            {
                p._category=s;
                p._category.resize(temp1.size());
                count++;
            }
            else if(count==city)
            {
                p._city=s;
                p._city.resize(temp1.size());
                count++;
            }
            temp1.clear();
        }

    }
    return input;
}
ostream &operator<<(ostream &output,const Product& p)
{
    string str=to_string(p._id);
    output<<"id = "<<str<<" , name = "<<p._name<<" , price = ";
    str=to_string(p._price);
    output<<str<<" , description = "<<p._description;
    str=to_string(p._amount);
    output<<endl<<"amount = "<<str<<" , category = "<<p._category<<" , city = "<<p._city;
    return output;
}
