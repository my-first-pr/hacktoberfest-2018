#include <iostream>

using namespace std;

int main()
{
    int result = 0;
    int carry = 0;
    int a[]= {1,0,0,1,1};
    int b[]= {1,0,1,0,1};
    int c[6];
    for(int i=4;i>=0;i--){
        c[i+1] = (a[i]+b[i]+carry) %2;
        if(a[i]+b[i]+carry >=2){
            carry=1;
        }
        else{
            carry=0;
        }
        
    }
    if(carry){
        c[0] = 1;
    } 
    else{
        c[0] = 0;
    }
    for(int k=0;k<6;k++){
        cout << c[k];
    }
}
