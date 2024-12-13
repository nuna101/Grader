#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "map_bst.h"

template <typename KeyT,
        typename MappedT,
        typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::my_recur(node* n, int &aux){
	// You MAY use this function
    //aux is the furthest distance
    if(n == nullptr) return 0;
    //find most left + most right of each subtree
    int l = my_recur(n->left, aux);
    int r = my_recur(n->right, aux);

    if(l+r > aux) aux = l+r;
    return 1 + std::max(l,r);
    
}

template <typename KeyT,
        typename MappedT,
        typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::furthest_distance() {
	// write your code here
    if(mRoot == nullptr) return -1;
    if(mRoot->left == nullptr && mRoot->right == nullptr) return 0;
    int aux = 0;
    my_recur(mRoot,aux);
    return aux;
	
}

#endif
