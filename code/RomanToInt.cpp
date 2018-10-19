#include<bits/stdc++.h>
using namespace std;

int valueOf(char a)
{
    int value;
    switch(a)
            {
            case 'I':
                value=1;
                break;
            case 'V':
                value=5;
                break;
            case 'X':
                value=10;
                break;
            case 'L':
                value=50;
                break;
            case 'C':
                value=100;
                break;
            case 'D':
                value=500;
                break;
            case 'M':
                value=1000;
                break;
            }
            return value;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        cin>>a;
        int value1,value2,sum=0;
        for(int i=0;i<a.length();i++)
        {
            value1=valueOf(a[i]);
            if(i+1<a.length())
            {
                value2=valueOf(a[i+1]);
                if(value1>=value2)
                    sum+=value1;
                else {sum+=value2-value1;
                i++;}
            }
            else sum+=value1;

        }
        cout<<sum<<endl;

    }
}
/*

I             1
IV            4
V             5
IX            9
X             10
XL            40
L             50
XC            90
C             100
CD            400
D             500
CM            900
M             1000

*/
