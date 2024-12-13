#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,k; cin >> n >> k;
    vector<int> S(k), ways(n+1, 0);
    for(int i = 0; i < k; ++i) {
        cin >> S[i];
    }
    ways[0] = 1;
    for(int i = 0; i <= n; ++i) {
        for(auto s : S) {
            if(i >= s) {
                ways[i] = (ways[i] + ways[i - s]) % 1000003;
            }
        }
    }
    cout << ways[n];
}
