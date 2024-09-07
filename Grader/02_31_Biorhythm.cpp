#include <iostream>
#include <cmath>
using namespace std;

int check_feb(int month, int year) {
    if(year % 400 == 0) {
        return 29;
    } else if((year % 4 == 0) && (year % 100 != 0)) {
        return 29;
    } else {
        return 28;
    }
}

int main() {
    int bd, bm, by, d, m, y;
    cin >> bd >> bm >> by >> d >> m >> y;
    by -= 543;
    y -= 543;

    int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    
    int red, black, blue;
    red = blue = black = 0;
    month[1] = check_feb(bm, by);
    red = month[bm-1] - bd + 1;

    for(int i = bm; i < 12; i++) {
        red += month[i];
    }

    black = (y - by - 1)*365;

    month[1] = check_feb(m, y);
    for(int j = 0; j < m-1; j++) { 
        blue += month[j];
    }
    blue = blue + d - 1;

    int t = red + black + blue;
    double phy, emo, intel;
    double pi = M_PI;
    phy = sin((2*pi*t)/23); phy = round(phy*100.0)/100.0;
    emo = sin((2*pi*t)/28); emo = round(emo*100.0)/100.0;
    intel = sin((2*pi*t)/33); intel = round(intel*100.0)/100.0;
    
    cout << t << " " << phy << " " << emo << " " << intel;

}