#include <iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int A[n];
	int sum = 0;
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
		sum = sum +A[i];
	}
	cout<<"sum is "<<sum<<endl;
}