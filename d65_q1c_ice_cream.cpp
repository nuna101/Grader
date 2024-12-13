#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n, m, start; cin >> n >> m >> start;
    map<int, int> daily;
    vector<int> rateM(100001), ans;
    for(int i = 0; i < n; ++i) {
        int day, save;
        cin >> day >> save;
        daily[day] = save;
    }
    int curRate = start;
    rateM[0] = start;
    for(int i = 1; i < 100001; ++i) {
        if(i != 0) {
            auto found = daily.find(i);
            if(found != daily.end()) curRate = (*found).second;
        }
        rateM[i] = rateM[i-1] + curRate;
    }
    for(int i = 0; i < m; ++i) {
        int price, dDay;
        cin >> price >> dDay;
        int ans = price + rateM[dDay];
        if(price <= rateM[dDay]){
            ans = price;
        }
        int pos = lower_bound(rateM.begin(),rateM.end(),ans) - rateM.begin();
        cout << pos << ' ';
    }
}

