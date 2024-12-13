#include <bits/stdc++.h>
using namespace std;

bool check(int arr[], int val, int n) {
    int left = 0, right = n-1;
    while(left < right) {
        int sum = arr[left] + arr[right];
        if(sum == val) {
            return true;
        } else if(sum < val) {
            left++;
        } else {
            right--;
        }
    }
    return false;
}

int main() {
    int n,m; cin >> n >> m;
    int A[n];
    for(int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    sort(A, A+n);
    for(int i = 0; i < m; ++i) {
        int val; cin >> val;
        if(check(A, val, n)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
