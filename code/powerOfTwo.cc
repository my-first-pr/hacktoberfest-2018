/*****************************************************************************
  NAME
    powerOfTwo.cc
  PURPOSE
    The program get an input and determine if the input is power of two.
*****************************************************************************/
#include<iostream>
using namespace std;
/* This function takes a number and checks
 * if the number is power of two.
 */
bool isPowerOfTwo(int n) {
    if(n<=0)
        return false;
    bool ans=true;
    while(n>1){
        if(n%2==1){
            ans=false;
            break;
        }
        n /=2;
    }
    return ans;
}

int main(){
    int input=0;
    /* Get input */
    cout << "Enter a number:";
    cin >> input;
    /* Print the result */
    cout << input << " is " << (isPowerOfTwo(input)?"":"not ") 
        << "power of two." << endl;
    return 0;
}
