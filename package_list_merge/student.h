#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <algorithm>

template <typename T>
void CP::list<T>::merge(CP::list<CP::list<T>> &ls) {
  //write your code here
  auto outList = ls.begin();
  for(; outList != ls.end(); ++outList) {
    CP::list<T> &subList = *outList;
    if(subList.mSize > 0) {
      subList.mHeader->next->prev = mHeader->prev;
      mHeader->prev->next = subList.mHeader->next;

      subList.mHeader->prev->next = mHeader;
      mHeader->prev = subList.mHeader->prev;

      mSize += subList.mSize;

      subList.mSize = 0;
      subList.mHeader->next = subList.mHeader;
      subList.mHeader->prev = subList.mHeader;
    }
  }
  
}

#endif
