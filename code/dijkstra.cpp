#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > adj[100];
#define inf 1000000
vector<int> dist( 101 , inf);
vector<int> parent(101);
void dijkstra(int s){
priority_queue<pair<int,int> > q;
q.push(make_pair(0,s));
dist[s]=0;
parent[s]=-1;
	while(!q.empty()){
		pair<int,int> node= q.top();
		int d,v;
                                d=node.first;   v=node.second;	//NODE
 		q.pop();
		if(dist[v]<d) continue;
		for(int i=0 ;i<adj[v].size();i++)
		{int a=adj[v][i].first ;		//	NODE
	                 int b=adj[v][i].second;		//	DIST
		if( dist[a] > dist[v] + b ){
		dist[a] = dist[v] +b;
		parent[a]=v;
	                 q.push( make_pair( dist[a] , a ));}}}}
int main(){
	int u,v,n,w,m;
	cout<<"ENTER the number of nodes and edges \n";
	cin>>n;
	cin>>m;
	cout<<"enter the edges"<<endl;
	for(int i=0;i<m;i++){
		cin>>u>>v>>w;
		adj[u].push_back( make_pair(v,w) );
		adj[v].push_back( make_pair(u,w) );
	}cout<<" enter the source  "<<endl;
	cin>>m;
	dijkstra(m);
	for(int i =1;i<=n;i++)
	cout<<dist[i]<<" ";
                cout<<endl;
	cout<<"enter the target"<<endl;
	cin>>m;
	cout<<m;
	for(int i=parent[m];i!=-1;i=parent[i])
	cout<<"<----"<<i;}

