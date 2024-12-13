#ifndef __STUDENT_H_
#define __STUDENT_H_

using namespace std;

template <typename T,typename Comp>
size_t CP::priority_queue<T,Comp>::get_rank(size_t pos) const {
  //write your code here
  T tg = mData[pos];
  int count = 0;
  for(int i = 0; i < mSize; ++i) {
    if(i != pos) {
      if(mLess(tg, mData[i])) count++;
    }
  }
  return count;
}

#endif
