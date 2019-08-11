#include<bits/stdc++.h>
using namespace std;

class Graph {
    public:
        vector<vector<int> > adj;
        Graph(int n) {
            adj.resize(n);
        }
        void addEdge(int s, int d) {
            adj[s].push_back(d);
            adj[d].push_back(s);
        }
};

int main() {
    int n, m;
    cin>>n>>m;
    Graph g(n);
    int x, y;
    for(int i = 0; i < m; i++) {
        cin>>x>>y;
        g.addEdge(x, y);
    }
    int q;
    cin>>q;
    for(int i = 0; i < q; i++) {
        cin>>x>>y;
        if(find(g.adj[x].begin(), g.adj[x].end(), y) != g.adj[x].end()) {
            cout<<"YES"<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}