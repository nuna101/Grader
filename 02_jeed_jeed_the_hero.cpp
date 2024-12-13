#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m; cin >> n >> m;
    vector<vector<int>> path(n, vector<int> (m)), dist(n, vector<int> (m, 0));
    vector<pair<int,int>> dir = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    vector<vector<bool>> visited(n, vector<bool> (m, false));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> path[i][j];
        }
    }


    queue<pair<int,int>> q;
    q.push({0,0});

    while(!q.empty()) {
        auto [x,y] = q.front();
        q.pop();

        if(visited[x][y]) continue;
        visited[x][y] = true;

        for(int i = 0; i < 4; ++i) {
            int nx = x + dir[i].first;
            int ny = y + dir[i].second;

            if(nx >= 0 && nx < n && ny >= 0 && ny < m ) {
                if(path[nx][ny] == 0) continue;
                if(visited[nx][ny]) continue;
                dist[nx][ny] = dist[x][y] + 1;
                //if(path[nx][ny] == 2) path[nx][ny] = 0;
                q.push({nx,ny});
                
            }
        }
    }
    long long sum = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(path[i][j] == 2) sum += 2*dist[i][j];
        }
    }
    cout << sum;
}