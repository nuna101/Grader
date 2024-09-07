#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long n; cin >> n;
    int dvd = 2;
    while(dvd <= n) {
        if(n % dvd == 0) {
            n = n / dvd;
            if(n == 1) {
                cout << dvd;
            } else {
                cout << dvd << "*";
            }
        } else {
            dvd++;
        }
    }
}