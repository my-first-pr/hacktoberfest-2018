#include<iostream>
#include<algorithm>
#define ll long long int

/*

Author : monsijb


*/


using namespace std;

int main()
{
	ll x,y,z;
	cout << "Enter three numbers: ";
	cin >> x >> y >> z;
	ll arr[3];
	arr[0]=x;
	arr[1]=y;
	arr[2]=z;
	sort(arr,arr+3);
	cout << "\nThe numbers in ascending order are: ";
	cout << arr[0] << " " << arr[1] << " " << arr[2] << "\n";
	cout << "The numbers in descending order are: ";
	cout << arr[2] << " " << arr[1] << " " << arr[0] << "\n";
	return 0;
}