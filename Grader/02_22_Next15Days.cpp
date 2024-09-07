#include <iostream>
using namespace std;

int main() {
    int d, m, y, n; cin >> d >> m >> y;
    y = y - 543;
    n = 31;

    int d_30[4] = {4, 6, 9, 11};
    if(m != 2) {
        for(int i = 0; i < 4; i++) {
            if(d_30[i] == m) n = 30;
        }
    } else {
        if(y % 400 == 0) {
            n = 29;
        } else if((y % 4 == 0) && (y % 100 != 0)) {
            n = 29;
        } else {
            n = 28;
        }
    }
    d = d + 15;
    if(d > n) {
        d = d - n;
        m = m + 1;
    }
    if(m > 12) {
        m = m - 12;
        y = y + 1;
    }
    y = y + 543;
    cout << d << "/" << m << "/" << y;

}