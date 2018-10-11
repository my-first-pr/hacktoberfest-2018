#include<bits/stdc++.h>

using namespace std;


int main()
{
    int batas,n;

///batas = limit of maximum prime number, n = count total number will be checked, x = number of prime will be checked
    cin>>batas>>n;
    int prime=0;
    vector<bool> bilangan;
    for(int i = 0;i<=batas;i++)
    {
        bilangan.push_back(true);
    }
    bilangan[0] = false;
    bilangan[1] = false;
    for(int i = 2;i<=batas;i++)
    {
        if(bilangan[i])
        {
            prime++;
            for(int j = 2*i; j<=batas;j+=i)
            {

                bilangan[j] = false;
            }
        }
    }
    cout<<prime<<endl;
    while(n--)
    {
        int x;
        cin>>x;

        if(bilangan[x])
        {
            cout<<"1"<<endl;
        }
        else
        {
            cout<<"0"<<endl;
        }
    }
    return 0;
}
