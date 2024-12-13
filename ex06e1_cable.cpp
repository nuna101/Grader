#include <bits/stdc++.h>
using namespace std;

set<set<int>>::iterator findSet(set<set<int>> &used, int val) {
    for(auto it = used.begin(); it != used.end(); ++it) {
        if((*it).find(val) != (*it).end()) return it;
    }
    return used.end();
}

void merge(set<set<int>> &used, int x1, int x2) {
    auto it1 = findSet(used, x1), it2 = findSet(used, x2);
    if (it1 == used.end() || it2 == used.end() || it1 == it2) return;

    set<int> merged = *it1; 
    merged.insert((*it2).begin(), (*it2).end()); 

    used.erase(it1);
    used.erase(it2);
    used.insert(merged);
}

int main() {
    set<pair<int, pair<int,int>>> center;
    int n; cin >> n;
    set<set<int>> used;
    for(int i = 0; i < n-1; ++i) {
        for(int j = 0; j < n-i-1; ++j) {
            int cost; cin >> cost;
            center.insert(make_pair(cost, make_pair(i, j+1+i)));
        }
        used.insert({i});
    }
    used.insert({n-1});
    int len = 0, path = 0;
    
    for(auto p : center) {
        int x1 = p.second.first, x2 = p.second.second;
        if(findSet(used, x1) != findSet(used, x2)) {
            path += p.first;
            merge(used, x1, x2);
            len++;
        }
        if(len == n-1) break;
    }
    cout << path;

    // for(auto p : center) {
    //     cout << p.second.first << " - " << p.second.second << " : " << p.first << endl;
    // }
}