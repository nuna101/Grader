#include <iostream>
#include <cmath>
using namespace std;

int main() {
    string n; cin >> n;
    char a[12];
    for (int i = 0; i < 12; i++) {
        a[i] = n[i] - '0';
    }
    int sum = 0,digit;
    // int digit = (11 - ((13*a[0])+(12*a[1])+(11*a[2])+(10*a[3])+(9*a[4])+(8*a[5])+(7*a[6])+(6*a[7])+(5*a[8])+(4*a[9])+(3*a[10])+(2*a[11]))%11)%10;
    // cout << n[0] << "-" << n[1] << n[2] << n[3] << n[4] << "-" << n[5] << n[6] << n[7] << n[8] << n[9] << "-" << n[10] << n[11] << "-" << digit;
    for(int j = 0; j < 12; j++) {
        sum += (13-j)*a[j];
    }
    digit = (11 - (sum%11))%10;

    for (int k = 0; k < 13; k++) {
        if (k == 1 || k == 5 || k == 10) {
            cout << "-" << n[k];
        } else if (k == 12) {
            cout << "-" << digit;
        } else {
            cout << n[k];
        }
    }
    
    
}