#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
void CP::stack<T>::deep_push(size_t pos,const T& value) {
  //write your code here
  vector<T> dummy;
  int copySize = mSize;
  for(int i = 0; i < copySize; ++i) {
    dummy.push_back(top());
    pop();
  }
  reverse(dummy.begin(),dummy.end());
  size_t tg = copySize-pos;
  int count = 0;
  for(size_t i = 0; i < copySize+1; ++i) {
    if(i == tg) {
      push(value);
    } else {
      push(dummy[count]);
      count++;
    }
  }
  
}

#endif
