#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; cin >> n >> m;
    vector<int> ci(n), co(n);
    vector<vector<bool>> path(n, vector<bool> (n,0));
    map<int, vector<int>> adj;

    for(int i = 0; i < n; ++i) cin >> ci[i];
    for(int i = 0; i < n; ++i) cin >> co[i];

    while(m--) {
        int a, b; cin >> a >> b;
        path[a][b] = true;
        adj[a].push_back(b);
    }

    int inf = 1e9;
    vector<int> cost(n, inf);
    vector<vector<int>> direction = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    cost[0] = 0;

    

    pq.push({0,0});
    while(!pq.empty()) {
        int nowCost = pq.top().first;
        int nowStt = pq.top().second;
        pq.pop();

        if(cost[nowStt] < nowCost) continue;

        for(auto nextStt : adj[nowStt]) {
            int newCost = nowCost + co[nowStt] + ci[nextStt];
            if(newCost < cost[nextStt]) {
                cost[nextStt] = newCost;
                pq.push({newCost, nextStt});
            }
        }
    }

    for(auto x : cost) {
        if(x == inf) x = -1;
        cout << x << ' ';
    }
}