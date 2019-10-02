#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *next;
};
struct node *start=NULL;
void insertion(int item,int n){
    struct node * PTR = (node *)malloc(sizeof(struct node));
    if(start==NULL){
        start = PTR;
        PTR->next=NULL;
    }
    else{
        struct node *temp=start;
        int i=0;
        while(i!=n){
            i++;
            temp=temp->next;
        }
        PTR->next=temp->next;
        temp->next=PTR;
    }
    PTR->data=item;
}

void insertion_in_middle(int item,int n){
    struct node * PTR = (node *)malloc(sizeof(struct node));
    if(start==NULL){
        start = PTR;
        PTR->next=NULL;
    }
    else{
        struct node *temp=start;
        int i=0;
        while(i!=n){
            i++;
            temp=temp->next;
        }
        PTR->next=temp->next;
        temp->next=PTR;
    }
    PTR->data=item;
}
int show_list(){
    struct node *temp=start;
    if(temp==NULL){
        cout<<"List Empty\n";
        return 0;
    }
    do{
        cout<<temp->data;
        temp=temp->next;
    }while(temp!=NULL);
    return 1;
}
int main(){
insertion(3,0);
insertion(4,1);
insertion(5,2);
show_list();
return 0;
}
