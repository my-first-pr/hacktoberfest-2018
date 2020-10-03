#include<iostream>
using namespace std;
class Complex
{
    int a,b;
public:
    void inputdata(int x,int y)
    {
        a=x;
        b=y;
    }
    void displaydata()
    {
        cout<<"Value of a is "<<a<<"."<<"\nValue of b is "<<b<<".";
    }
    friend Complex operator+(Complex,Complex);
};
Complex operator+(Complex m,Complex n)
{
    Complex temp;
    temp.a=m.a+n.a;
    temp.b=m.b+n.b;
    return temp;
}
int main()
{
    Complex c1,c2,c3;
    c1.inputdata(3,5);
    c2.inputdata(7,8);
    c3=c1+c2;                              //Here as operator+ is a friend function so no caller object so the call would be like operator+(c1,c2) i.e c1 and c2 are arguments here.
    c3.displaydata();
}
