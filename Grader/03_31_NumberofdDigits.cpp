#include <iostream>
#include <cmath>
#include <string>
using namespace std;

long long count_digit(long long x) {
    int k = 1;
    long long sum = 1;
    long long power = 10;
    while(x >= pow(10, k)) {
        sum += (k * (9 * (power/10)));
        power *= 10;
        k++;
    }
    sum += (k * ((x - (power/10)) + 1));
    return sum;
}
int main() {
    long long m,n; cin >> m >> n;
    cout << count_digit(n) - count_digit(m-1);
}