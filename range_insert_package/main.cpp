#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::insert(iterator position,iterator first,iterator last) {
  int newSize = mSize + last - first;
  T* newData = new T[newSize];
  size_t pos = position - begin();
  for(size_t i = 0; i < pos; ++i ) {
    newData[i] = mData[i];
  }
  for (size_t i = 0; i < last-first; ++i) {
    newData[pos + i] = *(first + i);
  }
  for (size_t i = pos; i < mSize; ++i) {
    newData[i + last-first] = mData[i];
  }
  delete [] mData;
  mData = newData;
  mSize = newSize;
  mCap = newSize;
}

#endif
