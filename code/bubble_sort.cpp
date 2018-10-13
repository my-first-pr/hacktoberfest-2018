/*************************** Bubble sort*****************************/

#include <bits/stdc++.h>
#include "bubble_sort.h"

#define max_size 10

using namespace std;

int main(int argc, char const *argv[])
{
	cout<<endl;
	int arr[max_size],i;
	for (int i = 0; i < max_size; ++i)
	{
		arr[i] = random()%100;
	}

	cout<<"Array before sorting: "<<endl;
	print_array(arr,max_size);						//from common.h
	cout<<endl;
	
	bubble_sort(arr,0,max_size-1);
	
	cout<<"Array after sorting: "<<endl;
	print_array(arr,max_size);

	return 0;
}