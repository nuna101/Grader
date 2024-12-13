#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m; cin >> n >> m;
    vector<int> v;
    while(m--) {
        int x; cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());
    long long minTime = 0;
    long long left = 0, right = 1e20;

    while(left <= right) {
        long long mid = (right + left)/2;
        long long sum = 0;
        for(auto x : v) {
            sum += mid/x;
            if(sum >= n) break;
        }
        if(sum >= n) {
            minTime = mid;
            right = mid-1;
        } else {
            left = mid+1;
        }
    }
    cout << minTime;
    
    
}