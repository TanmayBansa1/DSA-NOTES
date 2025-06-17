#include <iostream>

using namespace std;

struct Tnode {
    int data;
    Tnode* child;
    Tnode* sibling;

    Tnode(int value) : data(value), child(nullptr), sibling(nullptr) {}
};

struct Btreenode {
    int data;
    Btreenode* left;
    Btreenode* right;

    Btreenode(int value) : data(value), left(nullptr), right(nullptr) {}
};

Btreenode* transformToBST(Tnode* root) {
    if (root == nullptr) {
        return nullptr;
    }

    Btreenode* bstRoot = new Btreenode(root->data);

    Tnode* currChild = root->child;
    Btreenode* currBSTchild = nullptr;
    Btreenode* prevBSTchild = bstRoot;

    while (currChild) {
        currBSTchild = transformToBST(currChild);

        prevBSTchild->right = currBSTchild;
        prevBSTchild = currBSTchild;

        currChild = currChild->sibling;
    }

    return bstRoot;
}

void inordertraversal(Btreenode* root) {
    if (root) {
        inordertraversal(root->left);
        cout << root->data << " ";
        inordertraversal(root->right);
    }
}

int main() {
    Tnode* treeRoot = new Tnode(10);
    treeRoot->child = new Tnode(5);
    treeRoot->child->sibling = new Tnode(8);
    treeRoot->child->child = new Tnode(3);
    treeRoot->child->sibling->sibling = new Tnode(9);

    Btreenode* bstRoot = transformToBST(treeRoot);

    cout << "Inorder Traversal of the BST created here is ->  ";
    inordertraversal(bstRoot);
    cout << endl;

    return 0;
}
