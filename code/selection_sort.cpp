#include <iostream>
#include <cstdlib>
#include "selection_sort.h"

#define max_size 10

using namespace std;

int main(int argc, char const *argv[])
{
	int arr[max_size];
	for(int i = 0;i < max_size;i++){
		arr[i] = random()%100;
	}

	cout<<"Array before sorting:"<<endl;
	print_array(arr,max_size);
	cout<<endl;

	selection_sort(arr,0,max_size-1);

	cout<<"Array after sorting: "<<endl;
	print_array(arr,max_size);
	return 0;
}