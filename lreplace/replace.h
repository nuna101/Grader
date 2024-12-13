void replace(const T& x, list<T>& y) {
  auto it = begin();
  for(; it != end(); ++it){
    if(*it == x) {
      auto idx = it;
      for(auto idxY = y.begin(); idxY != y.end(); ++idxY) {
        insert(idx, *idxY);
      }
      it = erase(idx);
      it--;
    }
  }//write your code here
  // 9 3 2 1 2 4 2 7
  //9 3 2 1 3 2 1 4 3 2 1 7
}
