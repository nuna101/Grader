#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double Xe,Ye,Re,Rp,Xm,Ym,Xp,Yp,A,B,C,a,b,c;
    cin >> Xe >> Ye >> Re >> Rp >> Xm >> Ym;
    c = Re - Rp;
    A = abs(Xm - Xe);
    B = abs(Ym - Ye);
    C = sqrt(pow(Xm-Xe, 2) + pow(Ym-Ye, 2));
    a = c/C * A;
    b = c/C * B;

    if (Xm >= Xe) Xp = Xe + a; else Xp = Xe - a;
    if (Ym <= Ye) Yp = Ye - b; else Yp = Ye + b;

    cout << round(Xp) << " " << round(Yp) << endl;
}