#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int r,c; cin >> r >> c;
    vector<vector<int>> path(r, vector<int> (c)), dist(r, vector<int>(c, -1));
    vector<pair<int,int>> dir = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    queue<pair<int, int>> q;
    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            cin >> path[i][j];
            if(path[i][j] == 1) {
                q.push({i,j});
                dist[i][j] = 0;
            }
        }
    }

    while(!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for(int i = 0; i < 4; ++i) {
            int nx = x + dir[i].first;
            int ny = y + dir[i].second;

            if(nx >= 0 && nx < r && ny >= 0 && ny < c && path[nx][ny] != 3 && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx,ny});
                if(path[nx][ny] == 2) {
                    cout << dist[nx][ny] + 1;
                    return 0;
                }
            }
        }
    }

    



}