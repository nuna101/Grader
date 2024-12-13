#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> A(n), K(m);
    unordered_map<int, int> count;

    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> K[i];
    }

    vector<int> temp;
    for(int i = 0; i < n; ++i) {
        int tmp = A[i];
        auto it = lower_bound(temp.begin(), temp.end(), tmp);
        count[tmp] = distance(it, temp.end());
        temp.insert(it, tmp);
    }


    for (int i = 0; i < m; ++i) {
        cout << count[K[i]] << '\n';
    }

    return 0;
}
