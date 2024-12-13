#include <iostream>
#include <vector>
using namespace std;

int search(int val, vector<int> &arr, int start, int stop) {
    if(val < arr[0]) return -1;

    int l = start, r = stop;
    while(l < r) {
        int mid = (r+l)/2;
        if(arr[mid] < val) {
            l = mid + 1;
        } else r = mid;
        if(arr[l] > val) return l-1;
    }

    return l;

}

int main() {
    int n,m; cin >> n >> m;
    vector<int> arr(n), findVal(m);
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    for(int i = 0; i < m; ++i) {
        cin >> findVal[i];
    }

    for(auto val : findVal) {
        int found = search(val, arr, 0, n-1);
        if(found == -1) cout << found << '\n';
        else cout << arr[found] << '\n';
    }


}