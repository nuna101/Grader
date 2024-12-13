#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T1,typename T2>
bool CP::pair<T1,T2>::operator>=(const pair<T1,T2>& other) const {
  return(
    ((first == other.first) && (second == other.second)) 
    ||  
    ((first > other.first) || ((first == other.first) && (second > other.second))));
  //write your code here

}

#endif
