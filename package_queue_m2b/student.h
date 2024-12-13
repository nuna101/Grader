#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>
using namespace std;

template <typename T>
void CP::queue<T>::move_to_back(size_t pos) {
  //write your code here
  if(mCap < mSize+mFront+1) expand(mSize*2);
  T add = mData[mFront+pos];
  for(int i = mFront+pos; i < mFront+mSize; ++i) {
    mData[i] = mData[i+1];
  }
  mData[mFront+mSize-1] = add;
}

#endif
