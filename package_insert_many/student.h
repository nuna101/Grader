#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <vector>
#include <algorithm>
using namespace std;


template <typename T>
void CP::vector<T>::insert_many(CP::vector<std::pair<int,T>> data) {
  int newSize = mSize + data.size();
  sort(data.begin(), data.end());
  T* newData = new T[newSize];
  int pos = 0, index = 0, dataIndex = 0;
  for(int i = 0; i < newSize; ++i) {
    if(dataIndex == data[index].first) {
      newData[pos++] = data[index].second;
      index++;
    } else {
      newData[pos++] = mData[dataIndex];
      dataIndex++;
    }
  }
  delete [] mData;
  mData = newData;
  mSize = newSize;
  mCap = newSize;
  
}

#endif

