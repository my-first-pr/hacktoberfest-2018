/*************************** Bubble sort**************************
****				Implementation by: Saurabh Banore  		 ****
					    Complexity : O(n^2)
********************************************************************/

#include <iostream>
#include <cstdio>
#include "common.h"

using namespace std;

template<typename T>
void bubble_sort(T arr[],int start,int end){
	int flag=0;
	do{
		flag=0;
		for(int i = start+1;i < end+1;++i){
			if(arr[i]<arr[i-1]){
				swapper(arr[i],arr[i-1]);				//from common.h
				flag++;
			}
		}
	}while(flag);
}