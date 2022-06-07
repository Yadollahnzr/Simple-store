#include "comment.h"
#include <vector>
using namespace std;
enum{id,username,comment,star,show};
Comment::Comment()
{
    _id=0;
    _username="";
    _comment="";
    _star=0;
    _show=0;
}

bool Comment::operator==(const Comment &c)
{
    if(_id==c._id && _username==c._username && _comment==c._comment && _show==c._show && _star==c._star)
        return true;
    return false;

}
ostream &operator<<(ostream &out,const Comment &c)
{
    string str;
    str=to_string(c._id);
    out<<"id = "<<str;
    out<<" , username = "<<c._username<<" , comment = "<<c._comment<<" , star = ";
    str=to_string(c._star);
    out<<c._star<<" , show = ";
    str=to_string(c._show);
    out<<str;
    return out;
}


istream &operator>>(istream &in,Comment &c)
{
    string str;
    getline(in,str);
    vector<char> temp;
    int count=0;
    for(unsigned int i=0;i<str.size();i++)
    {
        if(str[i]=='=')
        {
            i+=2;
            while (str[i]!=',' && i<str.size())
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
            delete [] temp2;
            if(count==id)
                c._id=stoi(s);
            else if(count==username)
            {
                c._username=s;
                c._username.resize(temp.size());
            }
            else if(count==comment)
             {
                c._comment=s;
                c._comment.resize(temp.size());
            }
            else if(count==star)
                c._star=stoi(s);
            else if(count==show)
                c._show=stoi(s);
            count++;
            temp.clear();
        }
    }
    return in;
}
