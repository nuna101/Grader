#include <iostream>
#include <string>

using namespace std;

int main() {
    string sum = "";
    while(true) {
        string num;
        cin >> num;
        if(num == "END") {
            break;
        }
        sum += stoll(num);
    }
}