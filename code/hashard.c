#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define n 10
	int num,count,i,sum;
	char buff[n];
	int  a[n];
 	int main(){
 	
 	   printf("Enter a number: ");
 	   scanf("%d",&num);
 	   snprintf(buff,n,"%d\n",num);
printf("%s\n",buff);
count =strlen(buff)-1;
printf("%d\n",count);
snprintf(num,n,"%s\n",buff);
 	for(i=0;i<(count-1);i++){
 	 a[i] = buff[i];
 	}
 		for(i=0;i<(count-1);i++){
 	 	printf("%d\n",a[i]);
 	}

         printf("A hashard num is one which is divisibe by the sum of its individual digits\n");
         printf("e.g 27 is hashard bc 27/(2+7) = \"0\"\n");  
   
   return 0;      
 	}
 	
