#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n,m,k; cin >> n >> m >> k;
    long long sum = 0, sumGrass = 0;
    vector<long long> allGrass(n), price(n);
    for(int i = 0; i < n; ++i) {
        long long grass; cin >> grass;
        sum += grass + k;
        price[i] = sum;
        sumGrass += grass;
        allGrass[i] = sumGrass;
    }

    for(int i = 0; i < m; ++i) {
        long long start, budget;
        cin >> start >> budget;
        if(budget < price[0]) {
            cout << 0 << '\n';
            continue;
        }
        if(start != 0) budget += price[start-1];
        auto it = upper_bound(price.begin(), price.end(), budget);
        if(it == price.end()) it = price.end();
        it--;
        int pos = distance(price.begin(), it);
        if(start != 0) cout << allGrass[pos] - allGrass[start-1] << '\n';
        else cout << allGrass[pos] << '\n';
    }
    
}