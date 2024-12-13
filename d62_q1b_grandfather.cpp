#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m; cin >> n >> m;
    map<long long, long long> relative;
    while(n--) {
        long long father, son;
        cin >> father >> son;
        relative[son] = father;
    }

    while(m--) {
        long long chk1, chk2; 
        cin >> chk1 >> chk2;
        auto fat1 = relative.find(chk1), fat2 = relative.find(chk2);
        if(fat1 == relative.end() || fat2 == relative.end()) {
            cout << "NO" << endl;
        } else {
            auto anc1 = relative.find((*fat1).second), anc2 = relative.find((*fat2).second);
            if(((*anc1).second == (*anc2).second) && anc1 != relative.end() && anc2 != relative.end() && chk1 != chk2) cout << "YES" << endl;
            else cout << "NO" << endl;
        }

    }
}
