#include <bits/stdc++.h>
using namespace std;

int main() {
    int r,c; cin >> r >> c;
    int inf = 1e9;
    vector<vector<int>> city(r, vector<int>(c)), cost(r, vector<int> (c, inf));
    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            cin >> city[i][j];
        }
    }

    vector<vector<int>> direction = {{-1,0} , {1,0}, {0, -1}, {0,1}};
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

    pq.push({0, {0,0}});
    while(!pq.empty()) {
        int nowCost = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        if(nowCost > cost[x][y]) continue;

        for(int i = 0; i < 4; ++i) {
            int nextX = direction[i][0] + x;
            int nextY = direction[i][1] + y;

            if(nextX >= 0 && nextX < r && nextY >= 0 && nextY < c) {
                int newCost = nowCost + city[nextX][nextY];
                if(newCost < cost[nextX][nextY]) {
                    cost[nextX][nextY] = newCost;
                    pq.push({newCost, {nextX, nextY}});
                }
            }
        }
    }

    cost[0][0] = 0; 
    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            cout << cost[i][j] << ' ';
        }
        cout << endl;
    }

}