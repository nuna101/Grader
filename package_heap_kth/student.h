#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "priority_queue.h"
using namespace std;

template <typename T,typename Comp >
T CP::priority_queue<T,Comp>::get_kth(size_t k) const {
  if(k == 1) return mData[0];
  else {
    size_t tmp;
    if(mLess(mData[1],mData[2])) tmp = 2;
    else tmp = 1;

    if(k == 2) return mData[tmp];
    else {
      size_t tmp2 = 3;
      for(int i = 3; i < 7; ++i) {
        if(mLess(mData[tmp2], mData[i])) tmp2 = i;
      }
      if(mLess(mData[3-tmp],mData[tmp2])) return mData[tmp2];
      else return mData[3-tmp];
    }
  }
}

#endif
