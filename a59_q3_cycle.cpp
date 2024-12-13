#include <bits/stdc++.h>
using namespace std;

void clearMap(map<int, vector<int>> &adj, int tmp) {
    for(auto m : adj) {
        auto it = find(m.second.begin(), m.second.end(), tmp);
        if(it != m.second.end()) m.second.erase(it);
    }
}

void findCycle(map<int, vector<int>> &adj) {
    queue<int> tmp;
    for(auto m : adj) {
        if(m.second.size() == 1) {
            tmp.push(m.first);
        }
    }

    while(!tmp.empty()) {
        int t = tmp.front();
        tmp.pop();
        
        if(adj.count(t) == 0) continue;
        int neighbor = adj[t][0];
        adj[t].clear();
        adj.erase(t);

        auto& neighbors = adj[neighbor];
        neighbors.erase(remove(neighbors.begin(), neighbors.end(), t), neighbors.end());
        if (neighbors.size() == 1) tmp.push(neighbor);
    }
}


int main() {
    int n; cin >> n;
    map<int, vector<int>> adj;
    for(int i = 0; i < n; ++i) {
        int e1,e2; cin >> e1 >> e2;
        adj[e1].push_back(e2);
        adj[e2].push_back(e1);
    }

    findCycle(adj);
    cout << adj.size();

}