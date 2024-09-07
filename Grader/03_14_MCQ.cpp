#include <iostream>
#include <string>
using namespace std;

int main() {
    string ans, std_ans;
    int count = 0;
    getline(cin, ans);
    getline(cin, std_ans);

    if(ans.length() != std_ans.length()) {
        cout << "Incomplete answer";
    } else {
        for(int i = 0; i < ans.length(); i++) {
            if(ans[i] == std_ans[i]) {
                count++;
            }
            
        }
        cout << count;
    }

}