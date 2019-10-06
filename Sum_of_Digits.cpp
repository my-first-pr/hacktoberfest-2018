#include <iostream>  
using namespace std;  
int main()  
{  
int n,m;
int s=0;    
cout<<"Enter a number: "<<endl;    
cin>>n;    
while(n>0)    
{    
m=n%10;    
s=s+m;    
n=n/10;    
}    
cout<<"Sum of digits is: "<<s<<endl;    
return 0;  
}  
