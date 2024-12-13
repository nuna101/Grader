#include <bits/stdc++.h>
using namespace std;

vector<set<int>> line;

bool checkLine(map<int, vector<int>> &adj, set<int> &s) {
    if(s.size() == 1) return true;
    int end = 0;
    for(auto n : s) {
        int deg = adj[n].size();
        if(deg > 2) return false;
        if(deg == 1) end++;
    }
    return (end == 2);
}

void dfs(map<int, vector<int>> &adj, int node, vector<bool> &visited, set<int> &s) {
    if(visited[node]) return;
    s.insert(node);
    visited[node] = true;
    for(auto x : adj[node]) {
        dfs(adj, x, visited, s);
    }
}

int main() {
    int v,e; cin >> v >> e;
    map<int, vector<int>> adj;
    while(e--) {
        int e1, e2;
        cin >> e1 >> e2;
        adj[e1].push_back(e2);
        adj[e2].push_back(e1);
    }

    vector<bool> visited(v, false);
    for(int i = 0; i < v; ++i) {
        if(visited[i] == false) {
            set<int> s;
            dfs(adj, i, visited, s);
            if(checkLine(adj, s)) line.push_back(s);
        }
    }

    cout << line.size();
}