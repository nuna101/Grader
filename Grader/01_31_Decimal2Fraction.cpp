#include <iostream>
#include <cmath>
#include <string>
using namespace std;

long gcd(long a, long b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    string a,b,c; cin >> a >> b >> c;
    string dvd,allnum;
    int devider,set,hrm;
    for (int j = 0; j < c.length(); j++) {
        dvd += "9";
    }
    for (int k = 0; k < b.length(); k++) {
        dvd += "0";
    }
    devider = stoi(dvd);
    allnum = b + c;
    set = (stoi(a)*devider) + (stoi(allnum) - stoi(b));
    
    hrm = gcd(set, devider);
    cout << set/hrm << " / " << devider/hrm;

}