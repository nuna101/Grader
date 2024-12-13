#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> nodeVal(n);
    for(int i = 0; i < n; ++i) {
        cin >> nodeVal[i];     
    }

    vector<bool> visited(n, false);
    vector<int> maxPath(n, INT_MIN);
    maxPath[0] = 0;

    unsigned long long maxVal = 0;

    for(int i = 0; i < n; ++i) {
        int u = -1;
        for(int j = 0; j < n; ++j) {
            if(!visited[j] && (u == -1 || maxPath[j] > maxPath[u])) u = j;
        }
        visited[u] = true;
        maxVal += maxPath[u];
        for(int k = 0; k < n; ++k) {
            if(!visited[k]) {
                int tmp = nodeVal[u] ^ nodeVal[k];
                if(tmp > maxPath[k]) maxPath[k] = tmp;
            }
        }
    }


    cout << maxVal;
}