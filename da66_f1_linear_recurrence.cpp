#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; cin >> k >> n;
    vector<int> c(n+1,0), a(n+1,0), R(n+1,0);

    int mod = 32717;
    for(int i = 0; i < k; ++i) cin >> c[i+1];
    for(int i = 0; i < k; ++i) {
        cin >> a[i];
        R[i] = a[i];
    }

    for(int i = k; i <= n; ++i) {
        for(int j = 1; j <= k; ++j) {
            R[i] = ((R[i] % mod) + (((c[j] % mod)*(R[i-j] % mod)) % mod)) % mod;
        }
    }

    cout << R[n];
}