#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
using namespace std;
class Product
{
    friend istream &operator>>(istream &input,Product& p);
    friend ostream &operator<<(ostream &output,const Product& p);
public:
    Product();
    Product(string name,string description,string category,string city,int id,int price,int amount);
    bool operator==(const Product &p);
public:
    int _id;
    string _name;
    int _price;
    string _description;
    int _amount;
    string _category;
    string _city;
};

#endif // PRODUCT_H
