#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::erase_many(const std::vector<int> &pos) {
  int newSize = mSize-pos.size();
  int count = 0;
  for(int i = 0; i < pos.size(); ++i) {
    erase(begin()+pos[i]-count);
    count++;
    mSize--;
  }
  mCap = newSize;
  
  // T* newData = new T[newSize];
  // int pst = 0, index = 0;
  // for (size_t i = 0; i < mSize; ++i) {
  //   if(i != pos[index] || index >= pos.size()) {
  //     newData[pst] = mData[i];
  //     pst++;
  //     continue;
  //   }
  //   index++;
  // }
  // delete [] mData;
  // mData = newData;
  // mSize = newSize;
  // mCap = newSize;

}

#endif
