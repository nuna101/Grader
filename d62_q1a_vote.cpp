#include <iostream>
#include <queue>
#include <map>
using namespace std;

int main() {
    int n,k; cin >> n >> k;
    map<string,int> vote;
    priority_queue<int> pq;
    while(n--) {
        string name; cin >> name;
        if(vote.find(name) == vote.end()) {
            vote[name] = 1;
        } else vote[name]++;
    }
    for(auto kv : vote) {
        pq.push(kv.second);
    }
    int min;
    for(int i = 0; i < k; ++i) {
        if(pq.size() == 0) break;
        min = pq.top();
        pq.pop();
    }
    cout << min;
}