#include <iostream>
#include <vector>
#include <set>
using namespace std;

//set<string> allSet;
void route(vector<int> &table, string sol, int now, int r, int c) {
    
    if(now == (r*c)-1) {
        cout << sol << '\n';
        return;
    }

    if(now%c != c-1 && table[now+1] == 0) {
        table[now+1] = 1;
        route(table, sol + 'A', now+1, r, c);
        table[now+1] = 0;
    }

    if(now < r * c - c && table[now+c] == 0) {
        table[now+c] = 1;
        route(table, sol + 'B', now+c, r, c);
        table[now+c] = 0;
    }

    if(now >= c && table[now-c] == 0) {
        table[now-c] = 1;
        route(table, sol + 'C', now-c, r, c);
        table[now-c] = 0;
    }
}



int main() {
    int r,c; cin >> r >> c;
    vector<int> table(r*c);
    for(int i = 0; i < r*c; ++i) {
        cin >> table[i];
    }
    string sol = "";
    table[0] = 1;
    route(table, sol, 0, r, c);
    cout << "DONE";
}