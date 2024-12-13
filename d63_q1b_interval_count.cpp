#include <bits/stdc++.h>
using namespace std;


int main() {
    int n,m,k; cin >> n >> m >> k;
    vector<int> number, ans;
    for(int i = 0; i < n; ++i) {
        int num; cin >> num;
        number.push_back(num);
    } 
    sort(number.begin(), number.end());
    for(int i = 0; i < m; ++i) {
        int q; cin >> q;
        int left = q-k, right = q+k;
        auto lwb = lower_bound(number.begin(), number.end(), left);
        auto upb = upper_bound(number.begin(), number.end(), right);
        int count = upb-lwb;
        ans.push_back(count);
    }

    for(auto a : ans) {
        cout << a << " ";
    }
}

