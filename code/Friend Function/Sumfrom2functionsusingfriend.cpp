#include<iostream>
using namespace std;
class B;
class A
{
    int a;
    public:
    void inputdata(int x)
    {
        a=x;
    }
    void displaydata()
    {
        cout<<"Value of a is "<<a<<endl;
    }
    friend void sum(A,B);
};
class B
{
    int b;
    public:
    void inputdata(int y)
    {
        b=y;
    }
    void displaydata()
    {
        cout<<"Value of b is "<<b<<endl;
    }
    friend void sum(A,B);
};
void sum(A m,B n)
{
    cout<<"The sum of two values a and b is "<<m.a+n.b<<endl;
}
int main()
{
    A obj1;
    B obj2;
    obj1.inputdata(3);
    obj2.inputdata(4);
    obj1.displaydata();
    obj2.displaydata();
    sum(obj1,obj2);
}
