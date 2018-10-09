/*************************** Insertion sort**************************
****				Implementation by: Saurabh Banore    		 ****
					    Complexity : O(n^2)
********************************************************************/
#include "common.h"

template<typename T>
void insertion_sort(T arr[], T start, T end){
	int i,j;
	for(i = 0; i < end+1 ; i++){
		for(j = i; j > 0; j--){
			if(arr[j] < arr[j-1])
				swapper(arr[j],arr[j-1]);
			else
				break;
		}
	}
}