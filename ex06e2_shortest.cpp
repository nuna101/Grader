#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, e, s; cin >> n >> e >> s;
    int inf = 1e9;
    vector<vector<int>> adj(n, vector<int> (n,inf));
    
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(i == j) adj[i][j] = 0;
        }
    }
    while(e--) {
        int a, b, c; cin >> a >> b >> c;
        adj[a][b] = c;
    }

    for(int k = 0; k < n; ++k) {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(adj[i][k] < inf && adj[k][j] < inf) {
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }
    }

    bool negCycle = false;
    for(int i = 0; i < n; ++i) {
        if(adj[i][i] < 0) {
            negCycle = true;
            break;
        }
    }
    if(negCycle) cout << -1;
    else {
        for(int i = 0; i < n; ++i) {
            cout << adj[s][i] << ' ';
        }
    }
}