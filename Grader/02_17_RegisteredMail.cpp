#include <iostream>
using namespace std;

int main() {
    int w; cin >> w;
    if (w <= 100) {
        cout << 18;
    } else if(100 < w && w <= 250) {
        cout << 22;
    } else if(250 < w && w <= 500) {
        cout << 28;
    } else if(500 < w && w <= 1000) {
        cout << 38;
    } else if(1000 < w && w <= 2000) {
        cout << 58;
    } else {
        cout << "Reject";
    }
}