/*
Header_Interface:
   insert_heap()
   delete_heap()
   sift_up() // return value valid only if started with already heapified array
*/

#include<stdio.h>


#define N 1000

typedef struct heap_struct
{
	int val;
	// all other data;
} heapst;


int sift_up(int pos,heapst heaparr[])
{
	if (pos == 0) return 0;
	int p= (pos-1)/2;
	int a=heaparr[p].val;
	int b=heaparr[p*2+1].val;
	int c=heaparr[p*2+2].val;
	if (a>=b && a>=c) return pos;
	heapst temp= heaparr[p];
	if (a>=b && a<c)
	{
		heaparr[p]=heaparr[p*2+2];
		heaparr[p*2+2]=temp;
		return sift_up(p,heaparr);
	}
	if (a>=c && a<b)
	{
		heaparr[p]=heaparr[p*2+1];
		heaparr[p*2+1]=temp;
		return sift_up(p,heaparr);
	}
	else
	{
		printf("This part of the header to buildmax hasn't been coded yet\n");
		return -pos;
	}
}


int insert_heap(int ptr, heapst heaparr[])
{
	int v;
	scanf("%d",&v);
	heaparr[ptr].val=v;
	return sift_up(ptr, heaparr);
}

void sift_down(int pos, int ptr,heapst heaparr[])
{
	if (pos*2+1 >= ptr) return;
	int a=heaparr[pos].val;
	int b=heaparr[pos*2+1].val;
	if (ptr == pos*2+2)
	{
		if(a>=b) return;
		heapst temp= heaparr[pos];
		heaparr[pos]= heaparr[pos*2+1];
		heaparr[pos*2+1]=temp;
		return;
	}
	int c=heaparr[pos*2+2].val;
	if (a>=b && a>=c) return;
	heapst temp= heaparr[pos];
	if (b>=c)
	{
		heaparr[pos]= heaparr[pos*2+1];
		heaparr[pos*2+1]=temp;
		sift_down(pos*2+1,ptr,heaparr);
	}
	else
	{		
		heaparr[pos]= heaparr[pos*2+2];
		heaparr[pos*2+2]=temp;
		sift_down(pos*2+2,ptr,heaparr);
	}
}

void delete_heap(int pos,int ptr, heapst heaparr[])
{
	heaparr[pos]=heaparr[ptr];
	sift_down(pos,ptr,heaparr);
	return ;
}

int main()
{
	heapst heaparr[N];
	int ptr=0,i,j,n;
	scanf("%d",&n);
	for (j=0;j<n;j++)
	{
		insert_heap(ptr,heaparr);
		ptr++;
		for (i=0;i<ptr;i++)
		{
			printf("%d ",heaparr[i].val);
		}
		printf("\n");
	}
	for (j=0;j<n;j++)
	{
		ptr--;
		delete_heap(0,ptr,heaparr);
		for (i=0;i<ptr;i++)
		{
			printf("%d ",heaparr[i].val);
		}
		printf("\n");
	}

	return 0;
}
