#include <bits/stdc++.h>
using namespace std;

int co;
void spread(vector<vector<int>> &city, vector<vector<bool>> &visited, int posI, int posJ, int r, int c, int len) {
    if(posI < 0 || posI >= r || posJ < 0 || posJ >= c ) return;
    if(visited[posI][posJ] != false) return;
    if(len > 1) return;
    
    if (city[posI][posJ] == 0) {
        city[posI][posJ] = 1;
        co++; 
    }
    spread(city, visited, posI-1, posJ, r, c, len+1);
    spread(city, visited, posI+1, posJ, r, c, len+1);
    spread(city, visited, posI, posJ+1, r, c, len+1);
    spread(city, visited, posI, posJ-1, r, c, len+1);
    visited[posI][posJ] = false;
}


int main() {
    int r, c, t; cin >> r >> c >> t;
    vector<vector<int>> city(r, vector<int> (c, 0));
    vector<vector<bool>> visited(r, vector<bool> (c, false));
    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            int x; cin >> x;
            city[i][j] = x;
            if(x == 1) co++;
            if(x == 2) visited[i][j] = true;
        }
    }

    for(int d = 1; d <= t; ++d) {
        vector<vector<int>> next = city;
        for(int i = 0; i < r; ++i) {
            for(int j = 0; j < c; ++j) {
                if(city[i][j] == 1 ) spread(next, visited, i, j, r, c, 0);
            }
        }
        city = next;
    }

    cout << co;
}