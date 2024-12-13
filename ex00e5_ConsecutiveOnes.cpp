#include <bits/stdc++.h>
using namespace std;

set<vector<int>> allAns;

void genBit(int n, int k, int max0, int len, vector<int> &ans, int count0) {
    if(len == n) {
        
        int count1 = 0;
        for(int i = 0; i < n; i++) {
            if(ans[i] == 1) {
                count1++;
                
            } else count1 = 0;
            if(count1 >= k) {
                allAns.insert(ans);
            }
        }
        
        return;
    }

    ans[len] = 1;
    genBit(n, k, max0, len+1, ans, count0);
    if(count0 >= max0) return;
    ans[len] = 0;
    genBit(n, k, max0, len+1, ans, count0+1);
}


int main() {
    int n,k; cin >> n >> k;
    int max0 = n-k, count0 = 0;
    vector<int> ans(n);
    genBit(n, k, max0, 0, ans, count0);

    for(auto s : allAns) {
        for(auto v : s) {
            cout << v;
        }
        cout << '\n';
    }
}