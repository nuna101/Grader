#include <iostream>
using namespace std;

int main() {
    string tel; cin >> tel;
    bool num = false;
    
    if(tel.length() == 10) {
        if(tel[0] == '0') {
            if(tel[1] == '6' || tel[1] =='8' || tel[1] == '9') {
                num = true;
            }
        }
    } 

    if(num) cout << "Mobile number"; else cout << "Not a mobile number";
}