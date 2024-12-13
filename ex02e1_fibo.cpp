#include <bits/stdc++.h>
using namespace std;


int fibo(int n, vector<int> &order) {
    if(n == 0 || n == 1) return n;
    if(n >= 2) {
        if(order[n] > 0) {
            return order[n];
        } 
        int res = fibo(n-1, order) + fibo(n-2, order);
        order[n] = res;
        return res;
    }
}

int main() {
    int n; cin >> n;
    vector<int> order(n+1, 0);
    int ans = fibo(n, order);
    cout << ans;
}