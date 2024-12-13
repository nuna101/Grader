#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> modFormat;

int modIdx(vector<vector<int>> &v, int count, int n, int k) {
    for(int i = 0; i < n; ++i) {
        int a00 = ((v[i][0] * v[0][0]) + (v[i][1] * v[0][2])) % k;
        int a01 = ((v[i][0] * v[0][1]) + (v[i][1] * v[0][3])) % k;
        int a10 = ((v[i][2] * v[0][0]) + (v[i][3] * v[0][2])) % k;
        int a11 = ((v[i][2] * v[0][1]) + (v[i][3] * v[0][3])) % k;
        if(a00 == v[0][0] && a01 == v[0][1] && a10 == v[0][2] && a11 == v[0][3]) {
            return n % count;
        } else {
            v.push_back({a00,a01,a10,a11});
            count++;
        }
        if(i > 1e6) return n%k;
    }
    return n;
}

int main() {
    long long n,k; cin >> n >> k;
    int x0, x1, x2, x3; 
    cin >> x0 >> x1 >> x2 >> x3;
    modFormat.push_back({x0,x1,x2,x3});

    int idx = modIdx(modFormat, 1, n, k);
    for(int i = 0; i < 4; ++i) {
        cout << modFormat[idx-1][i] << ' ';
    }
}
