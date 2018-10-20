//To find if a number 'n' is exist in the fibonnaci sequence

#include<iostream>

using std:: cin;
using std:: cout;

int main(void)
{
  int n,found = 0,a=0,b=1,c=0,i,j;
  cout<<"Enter that innocent number : ";
  cin>>n;
  cout<<"OK Now find that number here : "<<endl;
  while(c-a<=n)
  {
  	i++;
    cout<<a<<" , ";
    if(a==n)
    {
     found=1; 
     j=i;
	  }
    c=a+b;
    a=b;
	b=c;
  }
  if(found==0)
  {
   cout<<"\nI know that you dont find that number in series because it is not exist in fibnoicci series"; 
  }
  else
  {
  	cout<<"\nCongratulation , You find it on term no"<<j;
  }
  return 0;
}
 
