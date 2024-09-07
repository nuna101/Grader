#include <iostream>
using namespace std;

int main() {
    int x; cin >> x;
    bool pos, neg, even, odd, zero;
    pos = neg = even = odd = zero = false;
    if(x == 0) {
        zero = true;
        even = true;
    } else {
        if(x % 2 == 0) even = true; else odd = true;
        if(x > 0) pos = true; else neg = true;  
    }
    

    if(pos) cout << "positive" << endl; else if(neg) cout << "negative" << endl; else if(zero) cout << "zero" << endl;
    if(even) cout << "even"; else if(odd) cout << "odd"; 
    
}