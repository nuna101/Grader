#include <bits/stdc++.h>
using namespace std;

void findFriend(map<int, vector<int>> &adj, int n, int k, int deg, int mem, set<int> &s) {
    s.insert(mem);
    if(deg == k) return;
    for(auto v : adj[mem]) {
        findFriend(adj, n, k, deg+1, v, s);
    }
}


int main() {
    int n, e, k; cin >> n >> e >> k;
    map<int, vector<int>> adj;

    for(int i = 0; i < e; ++i) {
        int e1, e2; cin >> e1 >> e2;
        adj[e1].push_back(e2);
        adj[e2].push_back(e1);
    }

    int max = 0;
    for(int i = 0; i < n; ++i) {
        set<int> s;
        findFriend(adj, n, k, 0, i, s);
        int friends = s.size();
        if(friends > max) max = friends;
    }
    cout << max;
}