#include <iostream>
#include <vector>
#include <list>
#include <math.h>
#include <queue>
#include <iterator>

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

vector < list <int> > G;
vector <int> Dis,Par;
vector <char> Color;

double f = INFINITY;

void BFS(vector < list <int> > &G , int s) {
    Dis.resize(G.size());
    Par.resize(G.size());
    Color.resize(G.size());

    // initialisation
    for(int i=1;i<G.size();i++) {
        Dis[i] = f;
        Par[i] = 0;
        Color[i] = 'W';
    }

    // set distance of source node to the source node 0
    Dis[s] = 0;
    // maintain queue for nodes order as it is FIFO
    queue <int> Q;
    Q.push(s);
    Color[s] = 'G';

    // W for white not visited
    // G for node in the queue
    // B for visited the node

    while(!Q.empty()) {
        int p = Q.front();
        Q.pop();
        for(list <int> :: iterator it=G[p].begin();it!=G[p].end();it++) {
            if(Color[*it] == 'W') { // chk whether node is visited or not
                Par[*it] = p; // set parent of current node to previous one
                Dis[*it] = Dis[p] + 1; // inc dis by 1
                Q.push(*it); // push tthe node in queue
                Color[*it] = 'G'; // mark the corresponding color
                }
            }
            Color[p] = 'B';
        }

}

void printPath(int s , int d) {
    if(s==d) cout << s << " ";
    else if(Par[d]==NULL) cout << "error!!!";
    else {
        printPath(s,Par[d]);
        cout << d << " ";
    }
}


int main() {
    fast
    // A 1 , B 2 , C 3 , D 4 , E 5
    int n,m;
    cin >> n; // no of vertices
    cin >> m; // no of edges
    G.resize(n+1);
    // making of undirected graph

    for(int i=0;i<m;i++) {
        int x,y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    BFS(G,1);
    printPath(1,5);
    cout << endl;
    
    // to print level of a graph 
    for(int i=1;i<Dis.size();i++) cout << Dis[i] << " ";
    cout << endl;


    // to print adjacency list
    // for(int i=1;i<n+1;i++) {
    //     cout << i << " ";
    //     for(list <int> :: iterator it=G[i].begin();it!=G[i].end();it++) {
    //         cout << (char)(*it + 64) << " ";
    //     }
    //     cout << endl;
    // }


    return 0;
}
