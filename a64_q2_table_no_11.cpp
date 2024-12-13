#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n; cin >> n;
    long long ans[n+1];
    ans[0] = 1;
    ans[1] = 3;

    long long mod = 100000007;
    if(n >= 2) {
        for(int i = 2; i <= n; ++i) {
            ans[i] = ((ans[i-1]*2) + ans[i-2] + mod) % mod;
        }
    }
    cout << ans[n];

    // long long dp[4] = {1, 1, 1, 0}; // Initial states: {00, 01, 10, 11 (invalid)}

    // for (int i = 2; i <= n; ++i) {
    //     long long new_dp[4] = {0};
    //     // Transition rules
    //     new_dp[0] = (dp[0] + dp[1] + dp[2]) % MOD; // 00 -> 00, 01, 10
    //     new_dp[1] = (dp[0] + dp[2]) % MOD;         // 01 -> 00, 10
    //     new_dp[2] = (dp[0] + dp[1]) % MOD;         // 10 -> 00, 01
    //     new_dp[3] = 0;                             // 11 -> invalid

    //     // Update dp
    //     for (int j = 0; j < 4; ++j)
    //         dp[j] = new_dp[j];
    // }

    // // Sum all valid states
    // long long result = (dp[0] + dp[1] + dp[2]) % MOD;
    // cout << result << endl;
}
