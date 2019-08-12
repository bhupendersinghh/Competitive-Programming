#include<bits/stdc++.h>
using namespace std;

class Graph {
    int v;
    vector<int> *adj;
    public:
        Graph(int v) {
            this->v = v;
            adj = new vector<int>[v];
        }
        void addEdge(int a, int b);
        bool isCyclic();
        bool isCyclicUtil(int v, bool visited[], int p);
};

void Graph::addEdge(int s, int d) {
    adj[s].push_back(d);
    adj[d].push_back(s);
    return;
}

bool Graph::isCyclicUtil(int v, bool visited[], int parent) {
    visited[v] = true;
    for(auto it = adj[v].begin(); it != adj[v].end(); it++) {
        if(!visited[*it]) {
            if(isCyclicUtil(*it, visited, v))
                return true;
        }
        else if(*it != parent)
            return true;
    }
    return false;
}

bool Graph::isCyclic() {
    bool *visited = new bool[v];
    for(int i = 0; i < v; i++)
        visited[i] = false;

    for(int i = 0; i < v; i++) {
        if(!visited[i]) {
            if(isCyclicUtil(i, visited, -1))
                return true;
        }
    }
    return false;
}

int main() {
    int n, m;
    cin>>n>>m;
    Graph g(n);
    int x, y;
    for(int i = 0; i < m; i++) {
        cin>>x>>y;
        g.addEdge(x, y);
    }
    g.isCyclic() ? cout<<"Cyclic Graph" : cout<<"Acyclic graph";
    return 0;
}
