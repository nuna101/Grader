#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n,q; cin >> n >> q;
    vector<pair<int,int>> num;
    //map<int,int> num;
    vector<long long> allSum;
    for(int i = 0; i < n; ++i) {
        int x,c; cin >> x >> c;
        // if(num.find(x) != num.end()) num[x] += c;
        // else num[x] = c;
        num.push_back(make_pair(x,c));
    }

    sort(num.begin(), num.end());
    long long sum = 0;
    for(auto m : num) {
        sum += m.second;
        allSum.push_back(sum);
    } 

    for(int i = 0; i < q; ++i) {
        int idx; cin >> idx;
        auto it = lower_bound(allSum.begin(), allSum.end(), idx);
        int pos = distance(allSum.begin(), it);
        cout << num[pos].first << '\n';
    }


}