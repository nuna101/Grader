#include <bits/stdc++.h>
using namespace std;

void dfs(int i, map<int, vector<int>> &adj, vector<int> &visited, int ccNum) {
    visited[i] = ccNum;
    if(adj.find(i) != adj.end()) {
        for(auto v : adj[i]) {
            if(visited[v] == -1) {
                dfs(v, adj, visited, ccNum);
            }
        }
    }
}

int findCC(int n, map<int, vector<int>> &adj) {
    int ccNum = 0;
    vector<int> visited(n+1, -1);
    for(int i = 1; i <= n; ++i) {
        if(visited[i] == -1) {
            ccNum += 1;
            dfs(i, adj, visited, ccNum);
        }
    }
    return ccNum;
}

int main() {
    int v, e; cin >> v >> e;
    map<int, vector<int>> adj;
    for(int i = 0; i < e; ++i) {
        int e1,e2; cin >> e1 >> e2;
        adj[e1].push_back(e2);
        adj[e2].push_back(e1);
    }

    int cc = findCC(v, adj);
    cout << cc;
}
