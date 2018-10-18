/*************************** Selection sort**************************
****				Implementation by: Saurabh Banore    		 ****
					   Worst case Complexity : O(n^2)
					   Best case complexity : O(n)
********************************************************************/

#include <iostream>
#include "common.h"

using namespace std;

template<typename T>
void selection_sort(T arr[],T start,T end){
	int i,j;
	for(i = start; i < end + 1; ++i){
		int min = i;
		for(j = i+1; j < end + 1; ++j){
			if(arr[j] < arr[min]){
				min = j;
			}
		}
		if(min != i)
			swapper(arr[min],arr[i]);
	}
}