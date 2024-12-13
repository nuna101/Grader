#include <iostream>
#include <set>
using namespace std;

void removeChild(set<int> &ans, int m, int n) {
    if(m < 0 || m >= n) return;
    int left = (m*2)+1, right = (m*2)+2;
    ans.erase(left);
    ans.erase(right);
    removeChild(ans, left, n);
    removeChild(ans, right, n);
    
}

int main() {
    int n, m; cin >> n >> m;
    set<int> ans;

    for(int i = 0; i < n; ++i) {
        ans.insert(i);
    }

    removeChild(ans, m, n);
    cout << ans.size()-1 << endl;
    for(auto s : ans) {
        if(s == m) continue;
        cout << s << ' ';
    }
    
}

