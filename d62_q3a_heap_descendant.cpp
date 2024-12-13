#include <iostream>
#include <set>
#include <queue>
using namespace std;

set<int> des;

// void count(int k, int n) {
//     if((k*2)+1 >= n) return;
//     int child = (k*2)+1;
//     if(child < n) des.insert(child);
//     if(child+1 < n) des.insert(child+1);
//     count(child, n);
//     count(child+1, n);
// }

int main() {
    int n,a; cin >> n >> a;
    queue<int> q;
    q.push(a);
    while(!q.empty()) {
        int child = (q.front()*2)+1;
        if(child < n) {
            q.push(child);
            des.insert(child);
            if(child+1 < n) {
                q.push(child+1);
                des.insert(child+1);
            }
        }
        q.pop();
    }
    //count(a,n);
    
    cout << des.size()+1 << endl;
    cout << a << ' ';
    for(auto s : des) {
        cout << s << ' ';
    }
}