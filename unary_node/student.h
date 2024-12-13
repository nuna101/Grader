#ifndef __STUDENT_H__
#define __STUDENT_H__

template <typename KeyT,
          typename MappedT,
          typename CompareT>
size_t CP::map_bst<KeyT,MappedT,CompareT>::process(node* ptr) const {
  if(ptr == nullptr) return 0;
  if(ptr->left == nullptr && ptr->right == nullptr) return 0;
  if(ptr->left != nullptr && ptr->right != nullptr) return 0 + process(ptr->left) + process(ptr->right);
  return 1 + process(ptr->left) + process(ptr->right);
  //you may write additional code here
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
size_t CP::map_bst<KeyT,MappedT,CompareT>::count_unary() const {
  //write your code here
  if(mRoot == nullptr) return 0;
  return process(mRoot);
}

#endif
