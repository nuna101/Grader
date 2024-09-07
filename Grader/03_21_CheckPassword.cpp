#include <iostream>
#include <string>
using namespace std;

int main() {
    string pass;
    int i = 0;
    string result[50]; 
    while(getline(cin, pass)) {
        bool upc = false, lwc = false, spc = false, num = false;
        for(char c : pass) {
            if(c >= 'a' && c <= 'z') lwc = true;
            else if(c >= 'A' && c <= 'Z') upc = true;
            else if(c >= '0' && c <= '9') num = true;
            else spc = true;
        }
        if(pass.length() >= 12 && upc && lwc && num && spc) {
            result[i] = ">> strong";
        } else if(pass.length() >= 8 && upc && lwc && num) {
            result[i] = ">> weak";
        } else {
            result[i] = ">> invalid";
        }
        
        i+=1;
    }
    for(int j = 0; j < i; j++) {
        cout << result[j] << endl;
    }
}