#include <iostream>
#include <string>
using namespace std;

int main() {
    string txt; getline(cin, txt);
    string num = "0123456789";
    string check[10];
    for(int i = 0; i < txt.length(); i++) {
        if(txt[i] == txt[i+1]) {
            txt.erase(txt.begin() + (i+1));
            i--;
        } else if(!(isdigit(txt[i]))) {
            txt.erase(txt.begin() + (i));
            i--;
        }
    }

    for(int k = 0; k < txt.length(); k++) {
        for(int x = 0; x < 10; x++) {
            if(txt[k] == num[x]) {
                num.erase(num.begin() + x);
            }
        }
    }
    int com = num.length();
    if(com == 0) {
        cout << "None";
    } else {
        for(int y = 0; y < com; y++) {
            cout << num[y];
            if(y == com-1) break;
            cout << ",";
        }
    }
}
