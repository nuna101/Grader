#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n,k,v; cin >> n >> k >> v;
    vector<int> beads;
    for(int i = 0; i < n; ++i) {
        int bead; cin >> bead;
        beads.push_back(bead); // 1 1 4 4 4 4 1 1
    }
    beads.insert(beads.begin()+k, v);
    n += 1;
    int first = k-1, last = k+1, left = n, right = n;
    int target = beads[k];
    while(true) {
        if(beads[first] != target && beads[last] != target) break;
        while(beads[first] == target && first >= 0) first--;
        while(beads[last] == target && last < n) last++;
        first++; last--;
        if(last - first + 1 >= 3) {
            left = first;
            right = last;
        } else break;
        if(first-1 < 0 || last+1 >= n) break;
        first--; last++;
        if(beads[first] != beads[last]) break;
        target = beads[first];
    }
    for(int i = 0; i < n; ++i) {
        if(i >= left && i <= right) continue;
        cout << beads[i] << ' ';
    }
}
