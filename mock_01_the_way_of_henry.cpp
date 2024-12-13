#include <bits/stdc++.h>
using namespace std;

int findParent(vector<int> &parent, int val) {
    while(parent[val] != -1) {
        val = parent[val];
    }
    return val;
}

bool checkSet(vector<int> &parent, int x1, int x2) {
    int parent1 = findParent(parent, x1), parent2 = findParent(parent, x2);
    if(parent1 == parent2) return false;
    return true;
}


// set<set<int>>::iterator findSet(set<set<int>> &used, int val) {
//     for(auto it = used.begin(); it != used.end(); ++it) {
//         if((*it).find(val) != (*it).end()) return it;
//     }
//     return used.end();
// }

// void merge(set<set<int>> &used, int x1, int x2) {
//     auto it1 = findSet(used, x1), it2 = findSet(used, x2);
//     set<int> merged = *it1;
//     merged.insert((*it2).begin(), (*it2).end());
//     used.erase(it1);
//     used.erase(it2);
//     used.insert(merged);
// }

int main() {
    int n,m; cin >> n >> m;
    set<pair<int, pair<int,int>>> path;
    vector<int> parent(n+1, -1);
    //set<set<int>> used;
    while(m--) {
        int cost, n1, n2; cin >> cost >> n1 >> n2;
        if(n2 < n1) swap(n1,n2);
        path.insert({cost, {n1,n2}});
    }
    // for(int i = 1; i <= n; ++i) {
    //     used.insert({i});
    // }

    int sum = 0, len = 0;
    for(auto p : path) {
        int node1 = p.second.first, node2 = p.second.second;
        if(checkSet(parent, node1, node2)) {
            sum += p.first;
            parent[findParent(parent, node1)] = findParent(parent, node2);
            len++;
        }
        if(len == n-1) break;
    }
    cout << sum;
}