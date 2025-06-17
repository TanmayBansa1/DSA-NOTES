#include <iostream>
#include<bits/stdc++.h>
using namespace std;


struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
 
    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};


TreeNode* insert(TreeNode* root, int value) {
    if (root == nullptr) {
        return new TreeNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}


void inorderTraversal(TreeNode*& root) {
    if (root) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
    else{
        return;
    }
}
void cinorderTraversal(TreeNode*& root) {
    if (root) {
        cinorderTraversal(root->right);
        cout << root->data << " ";
        cinorderTraversal(root->left);
        
    }
    else{
        return;
    }
}

void preorderTraversal(TreeNode*& root) {
    if (root) {
        cout << root->data << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
    else{
        return;
    }
}
void cpreorderTraversal(TreeNode* root){
    if(root){
        cpreorderTraversal(root->right);
        cpreorderTraversal(root->left);
        cout<<root->data<<" ";
    }
}

void postorderTraversal(TreeNode*& root) {
    if (root) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->data << " ";
    }
    else{
        return;
    }
}
void cpostorderTraversal(TreeNode*& root) {
    if (root) {
        cout << root->data << " ";
        cpostorderTraversal(root->right);
        cpostorderTraversal(root->left);
    }
    else{
        return;
    }
}

int main() {
    TreeNode* root = nullptr;
    int elements[7] = {4, 2, 1, 3, 6, 5, 7}; 

    for (int element : elements) {
        root = insert(root, element);
    }

    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Preorder Traversal: ";
    preorderTraversal(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    postorderTraversal(root);
    cout << endl;

   cout << "Converse Postorder Traversal: ";
    cpostorderTraversal(root);
    cout << endl;

    cout << "Converse inorder Traversal: ";
    cinorderTraversal(root);
    cout << endl;

    cout << "Converse Preorder Traversal: ";
    cpreorderTraversal(root);
    cout << endl;

    return 0;

}
