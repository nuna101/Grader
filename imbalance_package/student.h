// Your code here
int countHeight(node *ptr) {
    if(ptr == nullptr) return -1;
    return 1 + std::max(countHeight(ptr->left), countHeight(ptr->right));
}
void imbalance(node* &min, node *ptr) {
    if(ptr == nullptr) return;
    int im1 = std::abs(countHeight(min->left) - countHeight(min->right));
    int im2 = std::abs(countHeight(ptr->left) - countHeight(ptr->right));
    if(im2 > im1) min = ptr;
    else if(im1 == im2) {
        if(ptr->data.first < min->data.first) min = ptr;
    }
    imbalance(min,ptr->left);
    imbalance(min,ptr->right);
}

KeyT getValueOfMostImbalanceNode() {
    // Your code here
    node *p = mRoot;
    int height = countHeight(p);
    node *min = mRoot;
    imbalance(min, mRoot);
    return min->data.first;
}
