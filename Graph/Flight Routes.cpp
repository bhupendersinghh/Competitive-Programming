/*
    You are given flights route map of a country consisting of N cities and M undirected flight routes. Each city has an airport and each airport can work as layover. The airport will be in two states, Loading and Running. In loading state, luggage is loaded into the planes. In the running state, planes will leave the airport for the next city. All the airports will switch their states from Loading to Running and vice versa after every T minutes. You can cross a city if its airport state is running. Initially, all the airports are in running state. At an airport, if its state is loading, you have to wait for it to switch its state to running. The time taken to travel through any flight route is C minutes. Find the lexicographically smallest path which will take the minimum amount of time (in minutes) required to move from city X to city Y.

    It is guaranteed that the given flight route map will be connected. Graph won't contain multiple edges and self loops. A self loop is an edge that connects a vertex to itself.

    Input Format:
    The first line contains 4 space separated integers, N, M, T and C. Next M lines contains two space separated integers each, U and V denoting that there is a bidirectional road between city U and city V. Next line contains two space separated integers, X and Y.

    Output Format:
    In the first line print an integer K, denoting the number of city you need to go through to reach city Y from the city X. In next line, print K space separated integers denoting the path which will take the minimum amount of time (in minutes) required by to move from city X to city Y. There can be multiple paths. Print the lexicographically smallest one.

    Sample Input:
        5 5 3 5
        1 2
        1 3
        2 4
        1 4
        2 5
        1 5

    Sample Output:
        3
        1 2 5
*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj(1005);
bool visited[1005];
int pred[1005];

void addEdge(int s, int d) {
    adj[s].push_back(d);
    adj[d].push_back(s);
}

void bfs(int s, int d, int n) {
    queue<int> q;
    for(int i = 0; i < n; i++) {
        pred[i] = -1;
        visited[i] = false;
    }

    visited[s] = true;
    q.push(s);
    while(!q.empty()) {
        int x = q.front();
        q.pop();

        for(int i = 0; i < adj[x].size(); i++) {
            if(!visited[adj[x][i]]) {
                visited[adj[x][i]] = true;
                pred[adj[x][i]] = x;
                q.push(adj[x][i]);
                if(adj[x][i] == d) {
                    return;
                }
            }
        }
    }
    return;
}

vector<int> path(int d, int s) {
    vector<int> p;
    p.push_back(d);
    while(pred[d] != s) {
        p.push_back(pred[d]);
        d = pred[d];
    }
    p.push_back(s);
    vector<int> x;
    for(int i = p.size() - 1; i >= 0; i--) {
        x.push_back(p[i]);
    }
    return x;
}

int main() {
    int n, m, t, c;
    cin>>n>>m>>t>>c;
    adj.resize(n);
    int x, y;
    for(int i = 0; i < m; i++) {
        cin>>x>>y;
        addEdge(x, y);
    }
    cin>>x>>y;
    if(n == 1) {
        cout<<1<<endl<<1;
        return 0;
    }
    for(int i = 0; i < n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }
    bfs(x, y, n);
    cout<<endl;
    vector<int> p = path(y, x);
    cout<<p.size()<<endl;
    for(int i = 0; i < p.size(); i++) {
        if(i == p.size() - 1) {
            cout<<p[i];
        }
        else {
            cout<<p[i]<<" ";
        }
    }
    return 0;
}

