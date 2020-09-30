//To find if a number 'n' is exist in the fibonnaci sequence

#include<iostream>

using std:: cin;
using std:: cout;
int isFibonacci(int n){
	vector<int> v(n);
	v[0]=0;
	v[1]=1;
	int i=2;
	while(1){
		v[i] = v[i-1] + v[i-2];
		if(v[i] > n)
			return -1;
		if(v[i] == n)
			return i+1;
		i++;
	}
	
}
int main(void)
{
  int n,found = 0,a=0,b=1,c=0,i,j;
  cout<<"Enter that innocent number : ";
  cin>>n;
  cout<<"OK Now find that number here : "<<endl;
	
int res = isFibonacci(n);
if(res!=-1)
	cout<<"\nCongratulation , You find it on term no "+res;
else
	cout<<"\nI know that you dont find that number in series because it is not exist in fibnoicci series"
	
//   while(c-a<=n)
//   {
//   	i++;
//     cout<<a<<" , ";
//     if(a==n)
//     {
//      found=1; 
//      j=i;
// 	  }
//     c=a+b;
//     a=b;
// 	b=c;
//   }
//   if(found==0)
//   {
//    cout<<"\nI know that you dont find that number in series because it is not exist in fibnoicci series"; 
//   }
//   else
//   {
//   	cout<<"\nCongratulation , You find it on term no"<<j;
//   }
  return 0;
}
 
