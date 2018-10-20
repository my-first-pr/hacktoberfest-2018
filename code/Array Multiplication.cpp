#include<iostream>
using namespace std;
int main()
{
int a[5][4], b[4][3];

// This takes input for matrix A
for(int i=0;i<5;i++)
{
	for(int j=0;j<4;j++)
	{
		cin>>a[i][j];
	}
}

// This takes input for matrix B
for(int i=0;i<4;i++)
{
	for(int j=0;j<3;j++)
	{
		cin>>b[i][j];
	}
}

int multiply[5][3]; // The multiplied Matrix
int sum=0; // This will give an element which we will put in multiply[][]

for(int i=0;i<5;i++)
{
	for(int j=0;j<3;j++)
	{
		for(int k=0;k<4;k++)
		{
			sum+=a[i][k]*b[k][j];   // The main algo
		}
		multiply[i][j]=sum;
		sum=0;	// Note this, you made an error in this!
	}
}

//This will display the multiplied matrix
for(int i=0;i<5;i++)
{
	for(int j=0;j<3;j++)
	{
		cout<<multiply[i][j]<<" ";
	}
	cout<<endl;
}

}

