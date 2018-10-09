#include<stdio.h>
int main()
{
	int t;
	while(1){
		scanf("%d",&t);
		if (t!=42)
		{
			printf("%d\n",t);
		}
		else
			exit(0);
	}
	return 0;
}