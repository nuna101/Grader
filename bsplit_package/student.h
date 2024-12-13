#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename KeyT,
          typename MappedT,
          typename CompareT >
CP::map_bst<KeyT,MappedT,CompareT> CP::map_bst<KeyT,MappedT,CompareT>::split(KeyT val) {
  //your code here
  CP::map_bst<KeyT,MappedT,CompareT> result;
  node *ptr = mRoot, *parent = nullptr;
  while(mLess(ptr->data.first, val)) {
    ptr = ptr->right;
  }

  node *tmp = ptr, *found = ptr;
  while(mLess(val, found->data.first)) {
    found = found->left;
  }

  if(found->data.first != val) {
    tmp->parent->right = found;
    result.mRoot = tmp;
  } else {
    tmp->parent->right = found->left;
    result.mRoot = found;
    result.mRoot->left = nullptr;
  }
  return result;
}

#endif
