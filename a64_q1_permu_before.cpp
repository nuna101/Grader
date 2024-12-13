#include <iostream>
#include <vector>
using namespace std;


void permutation(int n, vector<int> ans, int len, vector<bool> used, vector<int> &check) {
    if(len == n) {
        for(auto v : ans) {
            cout << v << ' ';
        }
        cout << '\n';
    }
    
    for(int i = 0; i < n; ++i) {
        if(!used[i] && (check[i] == -1 || used[check[i]])) {
            used[i] = true;
            ans[len] = i;
            permutation(n, ans, len + 1, used, check);
            used[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; cin >> n >> m;
    vector<int> ans(n), check(n,-1);
    vector<bool> used(n);
    for(int i = 0; i < m; ++i) {
        int before,after;
        cin >> before >> after;
        check[after] = before;
    }

    permutation(n, ans, 0, used, check);
    
}
