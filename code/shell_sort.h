/*************************** Shell sort**************************
****				Implementation by: Saurabh Banore  		 ****
					    Complexity : O( n^(3/2) )
*****************************************************************/
#include "common.h"

template<typename T>
void shell_sort(T arr[], int start, int end){
	
	long long h = 1,i,j;
	int n = end - start  + 1;
	while(h < n/3){
		h = 3*h + 1 ;    // 1, 4, 13, 40, 121, 364......                (3x + 1) increment sequence
	}

	while(h >= 1){														//Insertion sort (h-sort)
		for(i = h; i < end; i++){
			for(j = i; j>0 && arr[j] < arr[j-1] ; j -= h) swapper(arr[j],arr[j-1]);
		}
		
		h /= 3;
	}
}
