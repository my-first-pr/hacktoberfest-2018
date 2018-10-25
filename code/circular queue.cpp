#include<stdio.h>
#define Max_Size 10
int ar[Max_Size];
int top=-1,rear=-1;
void insertion(int n){
    if(top==-1&&rear==-1){
        top=0;
        rear=0;
        ar[0]=n;
    }
    else{
        rear=(rear+1)%Max_Size;
        ar[rear]=n;
    }
    printf("element added\n");
}
void traverse(){
    if(top==rear&&rear==-1){
        printf("Queue Empty!\n");
    }
    else{
        for(int i=top;i<=rear;){
            printf("%d ",ar[i]);
            i=(i+1)%Max_Size;
        }
    }
}
void del(){
    if(top==-1){
        printf("List already empty\n");
    }
    else
        top=(top+1)%Max_Size;
    if(top==rear){
        top=-1;
        rear=-1;
    }
}
int main(){
int n,t;
char ch;
do{
    printf("Enter The choice \n 1:Insertion \n 2:traverse \n 3: deletion\n");
    scanf("%d",&t);
    switch(t){
    case 1:printf("Enter Queue Element\n");
       scanf("%d",&n);
       insertion(n);
       break;
    case 2:traverse();
       break;
    case 3:del();
        break;
    default:printf("Incorrect VAlue\n");
    }
    printf("Do you want to enter more:: y or n\n");
    scanf("%c",&ch);
}while(ch!='n');
}
