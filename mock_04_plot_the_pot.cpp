#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n; cin >> n;
    long long f1 = 1, f2 = 3, mod = 1e9+7;
    if(n >= 3) {
        for(long long i = 3; i <= n; ++i) {
            long long fn = ((2*f1) + f2) % mod;
            f1 = f2;
            f2 = fn;
        }
        cout << f2;
    } else if(n == 1) {
        cout << 1;
    } else if(n == 2) {
        cout << 3;
    }


}