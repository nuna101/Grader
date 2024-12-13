#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>

template <typename T>
void CP::queue<T>::move_to_front(size_t pos) {
    //your code here
    if(mCap < mSize+mFront+1) expand(mSize*2);
    T move = mData[(mFront+pos)%mCap];
    int j = pos;
    for(int i = 0 ; i < pos; ++i) {
        mData[(mFront+j)%mCap] = mData[(mFront+j-1+mCap)%mCap];
        j--;
    }

    mData[mFront] = move;
}

#endif
