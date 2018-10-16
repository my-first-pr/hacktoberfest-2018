#include<iostream>
using namespace std;

class node{
public:
    int data;
    node*left;
    node*right;
    node(int d){
        data=d;
        left=right=NULL;
    }
};

node*insertInBst(node*root,int data){
    node*n;
    if(root==NULL){
        n=new node(data);
        return n;
    }
    else if(root->data<data){
        root->right=insertInBst(root->right,data);
    }
    else{
        root->left=insertInBst(root->left,data);
    }
    return root;
}



node* takeInput(){
    int d;
    cin>>d;
    node*root=NULL;
    while(d!=-1){
        root=insertInBst(root,d);
        cin>>d;
    }
    return root;
}

void printInorder(node*root){
    if(root==NULL){
        return;
    }
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

void printPostorder(node*root){
    if(root==NULL){
        return;
    }
    printPostorder(root->left);
    printPostorder(root->right);
    cout<<root->data<<" ";
}

node*searchInBst(node*root,int data){
    if(root==NULL){
        cout<<"Not found";
        return NULL;
    }
    if(root->data==data){
        return root;
    }
    else if(root->data<data){
        return searchInBst(root->right,data);
    }
    else return searchInBst(root->left,data);
}

node*smallestNode(node*root){
    node*temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}


node*deleteInBst(node*root,int data){
    if(root==NULL){
        return NULL;
    }
    else if(root->data==data){
        ///1. no child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;    ///to return to its parent
        }

        ///2. single child
        else if(root->left!=NULL &&root->right==NULL){
            node*temp=root->left;
            delete root;
            return temp;
        }
        else if(root->left==NULL && root->right!=NULL){
            node*temp=root->right;
            delete root;
            return temp;
        }

        ///3. two children
        else{
            node*minNode=smallestNode(root->right); ///going one right then all left till lead node
            root->data=minNode->data;

            root->right=deleteInBst(root->right,data);
            return root;
        }


    }

    else if(root->data>data){
        root->left=deleteInBst(root->left,data);
    }
    else{
        root->right=deleteInBst(root->right,data);
    }
    return root;
}

class linkedList{
public:
    node*head;
    node*tail;
};


linkedList convertTree2LL(node*root){
    linkedList l;
    if(root==NULL){
        l.head=l.tail=NULL;
        return l;
    }

    if(root->left==NULL && root->right==NULL){
        l.head=l.tail=root;
        return l;
    }

    ///left subtree exists
    if(root->left!=NULL && root->right==NULL){
        linkedList leftLL=convertTree2LL(root->left);
        leftLL.tail->right=root;
        l.head=leftLL.head;
        l.tail=root;
    }
    ///right subtree exists
    if(root->left==NULL && root->right!=NULL){
        linkedList rightLL=convertTree2LL(root->right);
        root->right=rightLL.head;
        l.head=root;
        l.tail=rightLL.tail;
    }
    ///both exist
    else{
        linkedList leftLL=convertTree2LL(root->left);
        linkedList rightLL=convertTree2LL(root->right);

        leftLL.tail->right=root;
        root->right=rightLL.head;

        l.head=leftLL.head;
        l.tail=rightLL.tail;
    }

return l;
}

///checking if bt is a bst or not
bool isBst(node*root,int minV=INT_MIN,int maxV=INT_MAX){
    if(root==NULL){
        return true;
    }

    if(isBst(root->left,minV,root->data)&&isBst(root->right,root->data,maxV)&&root->data>=minV&&root->data<=maxV){
        return true;
    }
    return false;
}

node*arrayToBst(int *a,int s,int e){
    if(s>e){
        return NULL;
    }
    int mid=(s+e)>>1;
    node*root=new node(a[mid]);
    root->left=arrayToBst(a,s,mid-1);
    root->right=arrayToBst(a,mid+1,e);
    return root;
}

int i=0;
int n=7;
node*travToBst(int pre[],int in[],int s,int e){
    if(s>e){
        return NULL;
    }
    node*root=new node(pre[i]);

    ///linear searching
    int j;
    for(j=0;j<n;j++){
        if(in[j]==pre[i]){
            break;
        }
    }
    i++;
    root->left=travToBst(pre,in,s,j-1);
    root->right=travToBst(pre,in,j+1,e);
    return root;
}



int main(){
    node*root=takeInput();
    printInorder(root);
    /*cout<<endl<<"Enter element to search: ";
    int item;
    cin>>item;
    node*ele=searchInBst(root,item);*/

    /*linkedList l=convertTree2LL(root);
    node*temp=l.head;
    cout<<endl;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->right;
    }*/

    int a[]={1,2,3,4,5,6,8,9,10};
    int n=sizeof(a)/sizeof(int);
    node*root2=arrayToBst(a,0,n-1);
    cout<<endl<<endl;
    printInorder(root2);
    cout<<endl<<endl;
    int pre[]={4,2,1,3,5,6,7};
    int in[]={1,2,3,4,5,6,7};
    n=sizeof(pre)/sizeof(int);

    node*root3=travToBst(pre,in,0,n-1);
    printInorder(root3);

    return 0;
}
