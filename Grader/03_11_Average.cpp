#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double sum = 0;
    int count = 0;
    while(true) {
        double num;
        cin >> num;
        if(num == -1) {
            break;
        }
        sum += num;
        count++;
    }
    if (count == 0) cout << "No Data";
    else {
        double avg = sum/count;
        cout << round(avg*100)/100;
    }
    
}