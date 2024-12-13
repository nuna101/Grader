#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
T CP::queue<T>::operator[](int idx) {
  //write something here
  if(idx >= 0) {
    return mData[(mFront+idx)%mCap];
  } else {
    return mData[(mFront+(mSize-(-1*idx)))%mCap];
  }
  
  // you need to return something
  // return 
}

#endif
