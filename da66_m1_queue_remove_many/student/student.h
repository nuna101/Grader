#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>
#include <algorithm>
#include "queue.h"

template <typename T>
void CP::queue<T>::remove_many(std::vector<size_t> pos)
{
  // your code here
  size_t newSize = mSize - pos.size(), copySize = mSize;
  int count = 0, idx = 0;
  std::sort(pos.begin(), pos.end());
  T *tmp = new T[newSize];
  for(int i = 0; i < mSize; ++i) {
    if(i != pos[count]) {
      tmp[idx++] = mData[(mFront+i)%mCap];
    } else count++;
  }

  delete [] mData;
  mData = tmp;
  mSize = newSize;
  mCap = newSize;
  mFront = 0;
}

#endif
