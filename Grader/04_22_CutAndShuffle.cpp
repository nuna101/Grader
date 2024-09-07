#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void print(string a[], int n) {
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}

int main() {
    int n; cin >> n;
    string card[n];
    string copy[n];

    
    for(int i = 0; i < n; i++) {
        cin >> card[i];
    }
    
    string act; getline(cin >> ws, act);
    
    
    for(int j = 0; j < act.length(); j++) {
        if(act[j] == 'C') {
            for(int k = 0; k < n/2; k++) {
                swap(card[k], card[n/2+k]);
            }
        } else if(act[j] == 'S') {
            int c = 0;
            for(int y = 0; y < n; y++) {
                copy[y] = card[y];
            }
            for(int x = 0; x < n/2; x++) {
                card[c] = copy[x];
                c+=2;
            }
            c = 1;
            for(int z = 0; z < n/2; z++) {
                card[c] = copy[n/2+z];
                c+=2;
            }
        }
    }

    print(card, n);
}