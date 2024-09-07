#include <iostream>
#include <string>
using namespace std;

int main() {
    string word, sentence;
    int count = 0;
    getline(cin, word);
    getline(cin, sentence);

    for(int i = 0; i < sentence.length(); i++) {
        if(sentence.substr(i, word.length()) == word) {
            if(i == 0) {
                if(!isalpha(sentence[i+word.length()])) {
                    count += 1;
                }
            } else if(!isalpha(sentence[i-1]) && !isalpha(sentence[i+word.length()])) {
                count += 1;
            }
            
        }
    }

    cout << count;
}