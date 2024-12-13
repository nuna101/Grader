#include <bits/stdc++.h>
using namespace std;

bool checkVirus(string dna, int k, bool rev) {
    if(k == 2) {
        if(rev) return (dna == "10" || dna == "01");
        return (dna == "01");
    }

    int mid = dna.size()/2;
    string x = dna.substr(0, mid), y = dna.substr(mid, mid);
    string reverseDna = x;
    reverse(reverseDna.begin(), reverseDna.end());
    bool firstHalf = checkVirus(x, k/2, 0), backHalf = checkVirus(y, k/2, 0), reverseChk = checkVirus(reverseDna, k/2, 1);
    
    return (firstHalf  || reverseChk) && backHalf;

}


int main() {
    int n, k; cin >> n >> k;

    for(int i = 0; i < n; ++i) {
        string code = "";
        for(int j = 0; j < (1<<k); ++j) {
            char c; cin >> c;
            code += c;
        }   

        bool check;
        if(k == 1) {
            check = (code == "01");
        } else {
            check = checkVirus(code, 1<<k, 0);
        }

        if(check) cout << "yes";
        else cout << "no";

        cout << '\n';
    }

}