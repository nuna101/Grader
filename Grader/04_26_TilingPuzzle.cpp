#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    int m; cin >> m;
    int arrSize = (m*m);
    int arr[arrSize];

    for(int i = 0; i < arrSize; i++) {
        cin >> arr[i];
    }
    
    int newSize = (m*m)-1;
    int newArr[newSize];
    int c = 0;

    for(int j = 0; j < arrSize; j++) {
        if(arr[j] != 0) {
            newArr[c] = arr[j];
            c++;
        }
    }

    int inversion = 0;
    int round = newSize;

    for(int k = 0; k < newSize; k++) {
        for(int l = k; l < round; l++) {
            if((newArr[k] > newArr[l]) && (newArr[k] != newArr[l])) {
                inversion++;
            }
        }

    }

    int pos = 0;

    for(int x = 0; x < arrSize; x++) {
        if(arr[x] == 0) {
            pos = ceil(x/m);
            break;
        }
    }

    string yes = "YES";
    string no = "NO";
    if(m%2 != 0) {
        if(inversion%2 == 0) {
            cout << yes;
        } else cout << no;
    } else {
        if(inversion%2 != 0) {
            if(pos%2 == 0) cout << yes;
            else cout << no;
        } else {
            if(pos%2 != 0) cout << yes;
            else cout << no;
        }
    }
}