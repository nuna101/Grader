#include <iostream>
#include <string>
using namespace std;

string remove_space(string t) {
    string txt;
    for(int i = 0; i < t.length(); i+=2) {
        txt += t[i];
    }
    return txt;
}

bool check_R(string t) {
    bool stt = true;
    for(int i = 0; i < t.length(); i++) {
        if((t[i] == 'R') && (t[i+1] == 'R')) {
            return stt = false;
        }
    }
    return stt;
}

int score_cal(string t, string color, string sc) {
    int sum = 0;
    for(char c : t) {
        int found = color.find(c);
        sum += sc[found] - '0';
    }
    return sum;
}

int main() {
    int n; cin >> n; cin.ignore();
    string result[n];
    string wrong = "WRONG_INPUT";
    string color = "RYGNBPK";
    string color_score = "1234567";

    for(int i = 0; i < n; i++) {
        string t; getline(cin, t);
        string txt = remove_space(t);
        bool R_stt = check_R(txt);
        int sum = 0;

        if(txt[0] == 'R') {
            if(R_stt) {
                int index = 0;
                for(int j = 0; j < txt.length(); j+=2) {
                    if((txt[j] == 'R') && (txt[j-2] == 'R')) {
                        index = j;
                    }
                }
                if((index == txt.length()-1) || (txt.length() == 2)) {
                    sum = score_cal(txt, color, color_score);
                    result[i] = to_string(sum);
                } else {
                    bool order = true;
                    int count = 1;
                    for(int k = index+2; k < txt.length(); k++) {
                        
                        if(txt[k] != color[count]) {
                            order = false;
                            break;
                        }
                        count++;
                    }
                    
                    if(order) {
                        sum = score_cal(txt, color, color_score);
                        result[i] = to_string(sum);
                    } else {
                        result[i] = wrong;
                    }
                }
            } else {
                result[i] = wrong;
            }
        } else {
            result[i] = wrong;
        }
    }  

    for(int i = 0; i < n; i++) {
        cout << result[i] << endl;
    }
}