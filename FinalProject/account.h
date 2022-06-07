#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "user.h"
#include <vector>
#include "invoice.h"
#include <fstream>
using namespace std;
extern User account;
extern int product_id;
extern vector<Invoice> factors;
inline void readfactors()
{
    ifstream file("factors.txt");
    while(!file.eof())
    {
        Invoice inv;
        file>>inv;
        factors.push_back(inv);
    }
    if(factors[factors.size()-1]==factors[factors.size()-2])
        factors.pop_back();
    if(factors[factors.size()-1].username=="")
        factors.pop_back();
    file.close();
}
#endif // ACCOUNT_H
