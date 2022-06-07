#ifndef INVOICE_H
#define INVOICE_H
#include <string>
#include <vector>
using namespace std;
class Invoice
{
    friend istream &operator>>(istream &in,Invoice &inv);
    friend ostream &operator<<(ostream &out,const Invoice &inv);
public:
    Invoice();
    bool operator==(const Invoice &inv);
public:
    string username;
    vector<int> id;
    vector<int>count;
    vector<int>price;
};

#endif // INVOICE_H
