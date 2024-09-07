#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main() {
    string t; cin >> t;
    string new_t;
    int k; cin >> k;
    int x = t.length();
    int c = 1;
    int start = 0;
    bool stt = false;
    bool loop_stt = true;
    int i = 1;

    while(loop_stt) {
        while((t[i] == t[i-1])) {
            if(!stt) {
                start = i-1;
                stt = true;
                c++;
            } else {
                c++;
            }
            i++;
        }
        int count = i;
        if(c >= k) {
            t.erase(start, c);
            // stt = false;
            // c = 1;
            i = count - c;
        }
        if(i == t.length()) {
            loop_stt = false;
        }
        c = 1;
        i++;
        stt = false;
    }

    cout << t;
    

}