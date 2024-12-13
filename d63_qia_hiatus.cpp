#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

using YearMonth = pair<int, int>;

int toInt(const YearMonth& ym) {
    return ym.first * 12 + ym.second;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<YearMonth> yearList(n);
    for (int i = 0; i < n; ++i) {
        int year, month;
        cin >> year >> month;
        yearList[i] = {year, month};
    }

    sort(yearList.begin(), yearList.end());

    vector<int> results;
    for (int i = 0; i < m; ++i) {
        int findY, findM;
        cin >> findY >> findM;
        YearMonth queryDate = {findY, findM};
        
        
        auto it = lower_bound(yearList.begin(), yearList.end(), queryDate);
        if (it != yearList.end() && *it == queryDate) {
            results.push_back(0);
            results.push_back(0);
        }
        else if (it == yearList.begin()) {
            results.push_back(-1);
            results.push_back(-1);
        } 
        else {
            --it; 
            results.push_back(it->first);
            results.push_back(it->second);
        }
    }

    for (size_t i = 0; i < results.size(); i += 2) {
        cout << results[i] << ' ' << results[i + 1] << ' ';
    }
    
    return 0;
}
