#include <iostream>
#include <string>
using namespace std;

int find_min(int num[], int n) {
    int min_num = num[0];
    for(int i = 1; i < n; i++) {
        if(num[i] < min_num) min_num = num[i];
    }
    return min_num;
}

int find_max(int num[], int n) {
    int max_num = num[0];
    for(int i = 1; i < n; i++) {
        if(num[i] > max_num) max_num = num[i];
    }
    return max_num;
}

int main() {
    int c = 0;
    int num_arr[100];
    int act = 0;

    while(true) {
        int num; cin >> num;

        if((num != -998) && (num != -999)) {
            num_arr[c] = num;
            c++;
        } else if(num == -998 || num == -999){
            act = num;
            break;
        } 
    }

    int n = c/2;
    int arr_num[n][2];
    int arr_index = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 2; j++) {
            arr_num[i][j] = num_arr[arr_index];
            arr_index++;
        }
    }

    int red[n], blue[n];
    for(int i = 0; i < n; i++) {
        if(i%2 == 0) {
            red[i] = arr_num[i][0];
            blue[i] = arr_num[i][1];
        } else {
            red[i] = arr_num[i][1];
            blue[i] = arr_num[i][0];
        }
    }
    
    int min_num, max_num;
    if(act == -998) {
        min_num = find_min(red, n);
        max_num = find_max(blue, n);
    } else if(act == -999) {
        min_num = find_min(blue, n);
        max_num = find_max(red, n);
    }

    cout << min_num << " " << max_num;
}