#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, c, d; cin >> a >> b >> c >> d;
    if(a>b) swap(a,b);
    if(c>d) swap(c,d);
    if(b>d) b = d;
    if(a<c) a = c;
    double sum = (a+b)/2;
    cout << round(sum*100.0)/100.0;
}