#include<bits/stdc++.h>
using namespace std;

int ternary_search(int l,int r, int x)
{
    if(r>=l)
    {
        int mid1 = l + (r-l)/3;
        int mid2 = r -  (r-l)/3;
        if(ar[mid1] == x)
            return mid1;
        if(ar[mid2] == x)
            return mid2;
        if(x<ar[mid1])
            return ternary_search(l,mid1-1,x);
        else if(x>ar[mid2])
            return ternary_search(mid2+1,r,x);
        else
            return ternary_search(mid1+1,mid2-1,x);

    }
    return -1;
}
int main()
{
int n,i,x;
scanf("%d",&n);
int a[n];
for(i=0;i<n;i++)
scanf("%d",&n);
printf("Enter number to be found\n");
scanf("%d",&x);
printf("%d",ternary_search(0,n-1,x));
}
