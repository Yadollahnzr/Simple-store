#ifndef PRODUCTLIST_H
#define PRODUCTLIST_H
#include"product.h"
#include"vector"
#include"fstream"
using namespace std;
extern vector<Product> products;
inline void readproducts()
{
    ifstream productf("products.txt");
    Product p;
    char ch;
    products.clear();
    while(productf)
    {
        productf>>p;
        bool flag=true;
        for(unsigned int i=0;i<products.size();i++)
            if(products[i]._id==p._id || (products[i]._name==p._name && products[i]._city==p._city))
                flag=false;
        if(flag)
            products.push_back(p);
        productf>>ch;
    }
    productf.close();
    if(products[products.size()-1]==products[products.size()-2])
        products.pop_back();
}
#endif // PRODUCTLIST_H
