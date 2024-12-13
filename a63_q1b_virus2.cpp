#include <iostream>
using namespace std;

int count1(string dna) {
    int count = 0;
    for(int i = 0; i < dna.size(); ++i) {
        if(dna[i] == '1') count++;
    }
    return count;
}

bool checkVirus(string dna, int k) {
    if(k == 2) return true;

    int mid = dna.size()/2;
    string front = dna.substr(0, mid), back = dna.substr(mid);
    if(abs(count1(front) - count1(back)) > 1) return false;

    return checkVirus(front, k/2) && checkVirus(back, k/2);
}


int main() {
    int n,k; cin >> n >> k;

    for(int i = 0; i < n; ++i) {
        string code = "";
        for(int j = 0; j < (1<<k); ++j) {
            char c; cin >> c;
            code += c;
        }
        bool check = checkVirus(code, 1<<k);
        if(check) cout << "yes";
        else cout << "no";
        cout << '\n';
    }
}