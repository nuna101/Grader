#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    int dot_in = 1;
    for(int r = 1; r <= n; r++) {
        int dot_out = n - r;
        for(int i = 1; i <= dot_out; i++) {
            cout << ".";
        }
        if(r == 1) {
            cout << "*" << endl;
            continue;
        } else if(r == n){
            for(int k = 1; k <= (2*n)-1; k++) {
                cout << "*";
            }
            break;
        } else {
            cout << "*";
        }
        for(int j = 1; j <= dot_in; j++) {
            cout << ".";
        }
        dot_in += 2;
        cout << "*" << endl;
    }
}