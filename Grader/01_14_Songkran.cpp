#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int year;
    cin >> year;
    int ad = year - 543;
    int y = ad % 100;
    
    int day = y + floor(y/4) + 11;
    int result = day % 7;
    cout << result;
}