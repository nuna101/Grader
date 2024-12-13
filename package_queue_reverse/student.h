#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <cassert>

template <typename T>
void CP::queue<T>::reverse(int a,int b) {
  //your code here
  for(int i = 0; i < (b-a+1)/2; ++i) {
    size_t left = (mFront+a+i)%mCap;
    size_t right = (mFront+b-i)%mCap;
    T tmp = mData[left];
    mData[left] = mData[right];
    mData[right] = tmp;
  }
}

#endif
