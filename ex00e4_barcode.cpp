#include <iostream>
#include <vector>
#include <set>
using namespace std;

void genBarcode(int b, int a, int len, vector<int> &ans, int countWhite) {
    if(len == b) {
        if(countWhite == a) {
            for(auto v : ans) cout << v;
            cout << '\n';
        }
        return;
    }
    ans[len] = 0;
    genBarcode(b, a, len+1, ans, countWhite);
    ans[len] = 1;
    genBarcode(b, a, len+1, ans, countWhite+1);

}

int main() {
    int a,b; cin >> a >> b;
    vector<int> ans(b);
    int countWhite = 0, countBlack = 0;
    genBarcode(b, a, 0, ans, countWhite);
}