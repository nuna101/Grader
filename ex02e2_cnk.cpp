#include <bits/stdc++.h>
using namespace std;

int bcf(int n, int r, vector<vector<int>> &table) {
    if(n == r) return 1;
    if(r == 0) return 1;
    
    if(table[n][r] != -1) return table[n][r];

    int ans = bcf(n-1, r, table) + bcf(n-1, r-1, table);
    table[n][r] = ans;
    return ans;

}
int main() {
    int n, r; cin >> n >> r;
    vector<vector<int>> table(n+1, vector<int> (n+1, -1));
    int res = bcf(n, r, table);
    cout << res;
}