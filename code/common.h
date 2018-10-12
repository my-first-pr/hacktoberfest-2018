/*************************** Common functions **********************
****				Implementation by: Saurabh Banore    		 ****
					    
********************************************************************/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

//Swaps two numbers
template<typename T>
void swapper(T &a, T &b){
	T temp;
	temp = a;
	a = b;
	b = temp;
}


//Prints an given array 
template<typename T>
void print_array(T arr[],int no_of_elements){
	for (int i = 0; i < no_of_elements; ++i)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

template<typename T>
void inp_array(vector<T> &vec,unsigned long long int n){
	T inp;
	for(unsigned long long int i = 0; i < n; ++i){
		cin>>inp;
		vec.push_back(inp);
	}
}