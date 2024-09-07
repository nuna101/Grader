#include <iostream>
using namespace std;

int main() {
    double p; cin >> p;
    double k = 1, t = 1;
    
    while(1-t < p) {
        k+=1;
        t = (t*(365-(k-1)))/365;
    }
    cout << k;
}