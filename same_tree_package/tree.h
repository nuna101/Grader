#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

class Tree{
    class Node{
        public:
            friend class Tree;
            Node() {data = -1; left = NULL; right = NULL;}
            Node(const int x, Node* left, Node* right) : data(x), left(left), right(right) {}

        protected:
            int data;
            Node* left;
            Node* right;
    };
public:

    Tree() {
        mRoot = NULL;
        mSize = 0;
    }

    ~Tree() {
        clear(mRoot);
    }

    void clear(Node*& r) {
        if (!r) return;
        clear(r->left);
        clear(r->right);
        delete r;
    }

    void insert(int x) {
        insertAt(mRoot, x);
    }
    bool isSameBinaryTree(Tree& t) {
        if(mRoot == NULL && t.mRoot == NULL) return true;
        else if((mRoot == NULL && t.mRoot != NULL) || (mRoot != NULL && t.mRoot == NULL)) return false;
        
        return checkSubtree(mRoot, t.mRoot);
    }
    bool checkSubtree(Node *ptr1, Node *ptr2) {
        if (ptr1 == nullptr && ptr2 == nullptr) return true;
        if (ptr1 == nullptr || ptr2 == nullptr) return false;
        if (ptr1->data != ptr2->data) return false;
        return checkSubtree(ptr1->left, ptr2->left) && 
        checkSubtree(ptr1->right, ptr2->right);
    }
    // You can also put your code here

protected:
    void insertAt(Node*& r, int x) {
        if (!r) {
            r = new Node(x, NULL, NULL);
            mSize++;
            return;
        }
        if (r->data == x) return; // Do nothing
        if (x < r->data) insertAt(r->left, x); else
        insertAt(r->right, x);
    }
    Node* mRoot;
    int mSize;

};

#endif // TREE_H_INCLUDE
