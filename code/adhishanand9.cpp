#include <iostream>
#include <string>
#include<stdio.h>
#include<cstring>
using namespace std;
class GoodString
{
    int t;
public:
    GoodString(int x)
    {
        t=x;
    }

    void newstring(string str)
    {
        for(int i=0;i<t;i++)
            cout<<str.at(i);
    }
};
int main ()
{
    int n;
    cin>>n;
    GoodString ob(n);
    string str;
    getchar();
    getline(cin,str);
    ob.newstring(str);
    return 0;
}
