#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main() {
    long long int sub,Sub; cin >> sub;
    Sub = sub;
    int i=0,j;
    double x;
    while (sub > 10) {
        sub = sub/10;
        i++;
    }
    j = i;
    if (i == 4 || i == 5) i = 3;
    if (i == 7 || i == 8) i = 6;
    if (i >= 10) i = 9;
    x = Sub / pow(10, i);
    double new_x;

    if (j == 3 || j == 6 || j == 9) {
        new_x = round(x*10)/10;
    } else {
        new_x = round(x);
    }
    
    if (Sub < 1000) {
        cout << Sub;
    } else if(i == 3) {
        cout << new_x << "K";
    } else if(i == 6) {
        cout << new_x << "M";
    } else {
        cout << new_x << "B";
    }
    
}