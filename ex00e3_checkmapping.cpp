#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    set<int> S;
    bool injective = true, onto = true;
    for(int i = 0; i < n; ++i) {
        int num; cin >> num;
        if(S.find(num) == S.end()) S.insert(num);
        else {
            injective = false;
            break;
        }

        if(num < 1 || num > n) {
            onto = false;
            break;
        }
    }

    if(injective && onto) cout << "YES" << endl;
    else cout << "NO" << endl;
    
}