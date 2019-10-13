#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int N;
    cin>>N;
    if(N<=2){
        cout<<"-1"<<endl;
    }
    else if(N%2!=0){
       long long int m=(N+1)/2;
        long long int n=(N-1)/2;
        long long int X=2*m*n;
       long long int Y=pow(m,2)+pow(n,2);
        cout<<min(X,Y)<<" "<<max(X,Y)<<endl;
    }
    else{
       long long int m=N/2;
        long long int X=pow(m,2)-1;
       long long int Y=pow(m,2)+1;
        cout<<min(X,Y)<<" "<<max(X,Y)<<endl;
    }
    return 0;
}