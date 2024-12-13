#include <bits/stdc++.h>
using namespace std;

bool dfs(int i, map<int, vector<int>> &adj, vector<bool> &visited, int parent) {
    visited[i] = true;
    for(auto v : adj[i]) {
        if(visited[v] == false) {
            if(dfs(v, adj, visited, i)) return true;
        } else if(v != parent) return true;
    }
    return false;
}
bool checkCycle(map<int, vector<int>> &adj, int v) {
    vector<bool> visited(v, false);
    for(int i = 0; i < v; ++i) {
        if(visited[i] == false) {
            if(dfs(i, adj, visited, -1)) return true;
        }
    }
    return false;
}



int main() {
    int t; cin >> t;

    while(t--) {
        map<int, vector<int>> adj;
        int N,E; cin >> N >> E;
        for(int i = 0; i < E; ++i) {
            int e1,e2; cin >> e1 >> e2;
            adj[e1].push_back(e2);
            adj[e2].push_back(e1);
        }
        bool check = checkCycle(adj, N);
        if(check) cout << "YES";
        else cout << "NO";
        cout << '\n';
    }
}