#include <iostream>
using namespace std;
int main()
{long x;
cout<<"enter  a positive integer";
cin>>x;
cout<<"Fabonacci series "<<x<<" 0,1";
long f0=0,f1=1;
while(true)
{long f2=f1+f0 ;
if(f2>x)exit(0);
cout<<","<<f2;
f0=f1;
f1=f2;

}

}
