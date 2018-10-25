#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *next;
};
struct node *start=NULL;
void insertion(int item){
    struct node * PTR = (node *)malloc(sizeof(struct node));
    if(start==NULL){
        start = PTR;
        PTR->next=NULL;
    }
    else{
        struct node *temp=start;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=PTR;
        PTR->next=NULL;
    }
    PTR->data=item;
}
int deletion(){
    if(start==NULL){
        cout<<"List is already empty\n";
    }
    if(start->next==NULL){
        start=NULL;
    }
    start=start->next;
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
insertion(3);
insertion(4);
insertion(5);
deletion();
deletion();
show_list();
return 0;
}
