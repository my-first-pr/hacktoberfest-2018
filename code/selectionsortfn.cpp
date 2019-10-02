#include<iostream>
using namespace std;
void selectionsort(int a[],int n)
{
    int i,smallest,j,temp;
    for(int i=0;i<n-1;i++)
    {
        int smallest=i;
        
        for(int j=i+1;j<=n-1;j++)
        {
            if(a[smallest]>a[j])
            {
                smallest=j;
            }
        }
        if(smallest!=i)
        {
            temp=a[i];
            a[i]=a[smallest];
            a[smallest]=temp;
        }
    }
}
int main()
{
    int a[100],n,i;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    selectionsort(a,n);
    i=0;
    while(i<n)
    {
        cout<<a[i]<<' ';
        i++;
    }
    return 0;
}
