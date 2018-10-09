#include <iostream>
#include<vector>

using namespace std;

int main() {
    int m;
	cin>>m;
    int *arr = new int[m*m];
	for(int i=0;i<m;i++)
	{  
	    for(int j=0;j<m;j++)
	    {
	        cin>>arr[i*m+j];
	    }
	}
    for(int i=0;i<m;i++)
    {
        cout<<endl;
    for(int j=0;j<m;j++)
    {
    cout<<arr[i*m+j]<<"\t";
    }
    }
}

