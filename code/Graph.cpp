#include<bits/stdc++.h>
using namespace std;
void add_node(vector<pair<int , int > > lis[],int u,int v,int wieght){
        lis[u].push_back(make_pair(v,wieght));
        lis[v].push_back(make_pair(u,wieght));
}
void printGraph(vector<pair<int ,int> > lis[],int I){
    int v,w;
    for(int i=0;i<I;i++){
        cout<<"Node"<<i<<"Makes Edge with ::\n";
        for(auto it=lis[i].begin();it!=lis[i].end();it++){
                cout<<(it->first)<<"------"<<(it->second)<<endl;
        }
    }
}
int main(){
vector<pair<int , int > > lis[10];
add_node(lis,0,1,10);
add_node(lis,0,4,20);
add_node(lis,1, 2, 30);
add_node(lis,1, 3, 40);
add_node(lis,1, 4, 50);
add_node(lis,2, 3, 60);
add_node(lis,3, 4, 70);
printGraph(lis,7);
return 0;
}
