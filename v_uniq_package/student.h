#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <unordered_set>
using namespace std;

//you can include any other file here
//you are allow to use any data structure


template <typename T>
void CP::vector<T>::uniq() {
    T* newData = new T[mSize];
    int pos = 0;
    unordered_set<T> s;
    for(int i = 0; i < mSize; ++i) {
        if(s.find(mData[i]) != s.end()) continue;
        s.insert(mData[i]);
        newData[pos++] = mData[i];
    }
    delete [] mData;
    mData = newData;
    mSize = pos;
    mCap = pos;
}

#endif

