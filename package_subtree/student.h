#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "map_bst.h"

template <typename KeyT,typename MappedT, typename CompareT >
size_t CP::map_bst<KeyT,MappedT,CompareT>::process(node* n) {
  if(n == nullptr) return 0;
  return 1 + process(n->left) + process(n->right);
  //write your code here
  //return 0;
}

template <typename KeyT,typename MappedT, typename CompareT >
std::pair<KeyT,MappedT> CP::map_bst<KeyT,MappedT,CompareT>::subtree(map_bst<KeyT,MappedT,CompareT> &left, map_bst<KeyT,MappedT,CompareT> &right) {
  //write your code here
  if(mRoot == nullptr) return std::pair<KeyT,MappedT>();
  delete_all_nodes(left.mRoot);
  delete_all_nodes(right.mRoot);
  size_t leftSize = process(mRoot->left);
  size_t rightSize = process(mRoot->right);
  left.mRoot = mRoot->left;
  right.mRoot = mRoot->right;
  left.mSize = leftSize;
  right.mSize = rightSize;
  mSize = 1;
  mRoot->right= nullptr;
  mRoot->left = nullptr;
  return mRoot->data;
}

#endif

