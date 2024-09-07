#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    int n; cin >> n;
    string type[n];
    string fee[n];
    for(int i = 0; i < n; i++) {
        cin >> type[i];
        cin >> fee[i];
    }

    string path; getline(cin >> ws, path);
    string path_list[20];
    int count = 0;
    for(int j = 0; j <= floor(path.length()/7); j++) {
        path_list[j] = path.substr(count, 6);
        count+=7;
    }
    
    int path_size = sizeof(path_list)/sizeof(path_list[0]);
    for(int k = 0; k < path_size; k++) {
        if(path_list[k].length() == 0) {
            break;
        }
        string txt = path_list[k];
        path_list[k] = txt.substr(4,2);
    }
    int sum = 0;
    for(int x = 1; x < path_size; x++) {
        for(int y = 0; y < n; y++) {
            if(path_list[x] != path_list[x-1]) {
                if(path_list[x] == type[y]) {
                    sum += stoi(fee[y]);
                }
            }
            
        }
    }
    cout << sum;
}