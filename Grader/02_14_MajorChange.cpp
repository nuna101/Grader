#include <iostream>
using namespace std;

int main() {
    double gpa_1, gpa_2;
    string id_1, id_2;
    char com_1, com_2, cal1_1, cal1_2, cal2_1, cal2_2;
    cin >> id_1 >> gpa_1 >> com_1 >> cal1_1 >> cal2_1;
    cin >> id_2 >> gpa_2 >> com_2 >> cal1_2 >> cal2_2;

    bool status_1 = true, status_2 = true;
    if(com_1 != 'A' || cal1_1 > 'C' || cal2_1 > 'C') status_1 = false;
    if(com_2 != 'A' || cal1_2 > 'C' || cal2_2 > 'C') status_2 = false;

    
    if((status_1 && status_2)) {
        if(gpa_1 == gpa_2) {
            if(cal1_1 == cal1_2) {
                if(cal2_1 == cal2_2) {
                    cout << "Both";
                } else if(cal2_1 > cal2_2) {
                    cout << id_2;
                } else {
                    cout << id_1;
                }
            } else if(cal1_1 > cal1_2) {
                cout << id_2;
            } else {
                cout << id_1;
            }
        } else if(gpa_1 > gpa_2) {
            cout << id_1;
        } else {
            cout << id_2;
        }
    } else if((!status_1 && !status_2)) {
        cout << "None";
    } else if(status_1) {
        cout << id_1;
    } else {
        cout << id_2;
    }
    
}