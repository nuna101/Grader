#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include "map_bst.h"
using namespace std;

int main()
{
    /*
    int cases[10] = {1,10,3,200,5,6,1000,20000,100,2};

    for (int i = 0; i < 10; i++) {
        char fname[200];
        sprintf(fname,"%d.in",i+1);
        ofstream f(fname);
        f<<cases[i]<<endl;
        for (int j = 0; j < cases[i]; j++) {
            f<<rand() % 1000000<<" ";
        }
        f<<endl;
        f.close();
    }
    return 0;
*/
    CP::map_bst<int, int> m;
    int n = 0;
    cin>>n;
    int tmp = 0;
    for (int i = 0; i < n; i++) {
        cin>>tmp;
        m[tmp] = 1;
    }
    /*
    m[50] = 1;
    m[17] = 1;
    m[76] = 1;
    m[9] = 1;
    m[23] = 1;
    m[54] = 1;
    m[14] = 1;
    m[19] = 1;
    m[72] = 1;
    m[12] = 1;
    m[67] = 1;

    m[50] = 1;
    m[17] = 1;
    m[72] = 1;
    m[12] = 1;
    m[23] = 1;
    m[54] = 1;
    m[76] = 1;
    m[9] = 1;
    m[14] = 1;
    m[19] = 1;
    m[67] = 1;
    */
    //m.print();
    std::cout<<m.getValueOfMostImbalanceNode()<<endl;
    return 0;
}
