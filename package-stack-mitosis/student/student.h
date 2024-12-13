#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"
using namespace std;

template <typename T>
void CP::stack<T>::mitosis(int a, int b) {
    int newSize = mSize - (b - a + 1) + (2 * (b - a + 1));
    int copySize = mSize;
    int n = b-a+1;
    if(newSize > mCap) expand(mCap*2);

    for (int i = 0; i < a; ++i){
        mData[mSize+n-1-i] = mData[mSize-1-i];
    }

    int change = mSize-a+n-1;
    int tg = mSize-a-1;
    while (tg >= mSize-b-1) {
        mData[change--] = mData[tg];
        mData[change--] = mData[tg];
        if(tg == 0){
            break;
        }
        --tg;
    }

    mSize+=n;

}

#endif

