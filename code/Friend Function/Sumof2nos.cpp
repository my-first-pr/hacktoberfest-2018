#include<iostream>
using namespace std;
class Number
{
    int a,b;
public:
    void inputdata(int x,int y)
    {
        a=x;
        b=y;
    }
    friend void sum(Number);
};
void sum(Number c)
{
    cout<<"The sum of a and b is "<<c.a+c.b<<".";
}
int main()
{
    Number n1,n2,n3;
    n1.inputdata(3,4);
    sum(n1);
}
