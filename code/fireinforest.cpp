#include<bits/stdc++.h>
using namespace std;
void fire_in_forest(int ar[5][5],int n,int x,int y){
    if(ar[x][y]==1&&x<5&&y<5){
        ar[x][y]=2;
        fire_in_forest(ar,5,x-1,y);
        fire_in_forest(ar,5,x+1,y);
        fire_in_forest(ar,5,x,y-1);
        fire_in_forest(ar,5,x,y+1);
    }

}
int main(){
int n=5;
int ar[5][5];
cout<<"Enter the forest::\n";
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++)
        cin>>ar[i][j];
}
int fire_x,fire_y;
cout<<"Enter the Starting point of Fire:::\n";
cin>>fire_x>>fire_y;
fire_in_forest(ar,5,fire_x,fire_y);
cout<<"The new array is::\n";
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cout<<ar[i][j]<<" ";
    }
    cout<<endl;
}
return 0;
}
