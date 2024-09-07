#include <iostream>
using namespace std;
int main() {
    string x; cin >> x;
    bool found = false;
    string code[27] = {"01", "02", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31", "32", "33", "34", "35", "36" , "37", "38", "39", "40", "51", "53", "55", "58"};
    for (int i = 0; i < 27; i++) {
        if(code[i] == x) {
            found = true;
            break;
        }
    }
    if(found) cout << "OK"; else cout << "Error";
}