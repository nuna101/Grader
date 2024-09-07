#include <iostream>
#include <string>
using namespace std;

int main() {
    string name[10] = {"Robert", "William", "James", "John", "Margaret", "Edward", "Sarah", "Andrew", "Anthony", "Deborah"};
    string nickname[10] = {"Dick", "Bill", "Jim", "Jack", "Peggy", "Ed", "Sally", "Andy", "Tony", "Debbie"};
    int count; cin >> count;
    string search[count];
    string result[count];
    for(int i = 0; i < count; i++) {
        cin >> search[i];
    }
    for(int j = 0; j < count; j++) {
        bool stt = false;
        for(int k = 0; k < 10; k++) {
            if(search[j] == name[k]) {
                result[j] = nickname[k];
                stt = true;
            }
            else if(search[j] == nickname[k]) {
                result[j] = name[k];
                stt = true;
            }
        }
        if(!stt) {
            result[j] = "Not found";
        }
    }

    for(int x = 0; x < count; x++) {
        cout << result[x] << endl;
    }
}