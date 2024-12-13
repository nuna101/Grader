#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<vector<int>> v(n, vector<int> (n,0));
    int maxVal;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            int x; cin >> x;
            if(i == 0 && j == 0) maxVal = x;
            if(i-1 >= 0 && j-1 >= 0) {
                v[i][j] = max(v[i-1][j-1]+x, x);
            } else {
                v[i][j] = x;
            }

            if(v[i][j] > maxVal) maxVal = v[i][j];
        }
    }

    cout << maxVal;
}