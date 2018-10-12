#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    struct Node* left, *right ;
};
struct Node *head=(struct Node*)NULL;
struct Node *searchin(int x){
    bool found=false;
    struct Node *p ,*q;
    p=(struct Node *)malloc(sizeof(struct Node));
    q=(struct Node *)malloc(sizeof(struct Node));
    p=head;
    q=(struct Node*)NULL
    while(p!=(struct Node*)NULL){
            q=p;
            if(x==(p->val)) return (struct Node*)true;
            else if(x>(p->val)) p=p->left;
            else p=p->right;
    }
    return q;
}
void insertion(int x){
    //searching Value
    struct Node *leaf, *noder;
    leaf=(struct Node *)malloc(sizeof(struct Node));
    noder=(struct Node *)malloc(sizeof(struct Node));
    leaf=searchin(x);
    if(leaf!=(struct Node*)true){
                noder->val=x;
                noder->left=(struct Node*)NULL;
                noder->right=(struct Node*)NULL;
            if(leaf==(struct Node*)NULL){
                head=noder;
            }
            else{
                if(x>(leaf->val)){
                    leaf->left=noder;
                }
                else leaf->right=noder;
            }
            cout<<"ITEM ADDED SUCCESSFULLY!!!!!!!!!!!!!!\n";
    }
    else cout<<"ITEM Already EXISTS!!!!!!!\n";
}
void tree_traversal(struct Node* ptr){
    if(head==(struct Node*)NULL){
            cout<<"Tree is Empty!";
    }
    else if(ptr!=(struct Node*)NULL){
        tree_traversal(ptr->left);
        cout<<ptr->val<<"  ";
        tree_traversal(ptr->right);
    }
}

int main(){
    insertion(3);
    insertion(4);
    insertion(14);
    insertion(4);
    insertion(44);
    tree_traversal(head);
return 0;
}
