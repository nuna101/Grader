#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<vector<int>> adj(n, vector<int> (n, 0));
    map<int, int> ans;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> adj[i][j];
        }
        int deg = count(adj[i].begin(), adj[i].end(), 1);
        if(ans.find(deg) == ans.end()) ans[deg] = 0;
        ans[deg]++;
    }

    auto maxIt = ans.end(); maxIt--;
    for(int i = 0; i < (*maxIt).first + 1; ++i) {
        if(ans.find(i) == ans.end()) cout << 0 << ' ';
        else cout << ans[i] << ' ';
    }
}