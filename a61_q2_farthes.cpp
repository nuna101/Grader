#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<vector<int>> adj(n, vector<int> (n));
    int inf = 1e9;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            int x; cin >> x;
            if(x == -1) x = inf;
            adj[i][j] = x;
        }
    }

    vector<vector<int>> dist = adj;
    int maxPath = -1; 

    for(int k = 0; k < n; ++k) {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(dist[i][k] < inf && dist[k][j] < inf) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    for(int i = 1; i < n; ++i) {
        if(dist[0][i] > maxPath) maxPath = dist[0][i];
    }

    if(maxPath == inf) maxPath = -1;
    cout << maxPath;
}