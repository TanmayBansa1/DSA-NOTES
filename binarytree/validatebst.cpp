#include <bits/stdc++.h> 
#include<iostream>

using namespace std;

class node 
    {
    public : 
        int data;
        node *left;
        node *right;

        node(int data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
node *insertintoBST(node *root, int d)
{

    if (root == nullptr)
    {
        root = new node(d);
        return root;
    }

    if (d < root->data)
    {
        root->left = insertintoBST(root->left, d);
    }
    else
    {
        root->right = insertintoBST(root->right, d);
    }
}
void takeinput(node *&root)
{
    cout << "enter data for the bst" << endl;
    int data;
    cin >> data;

    while (data != -1)
    {

        root = insertintoBST(root, data);
        cin >> data;
    }
}   
void inorder(node* root, vector<int> &treeArray){

    if(root == NULL){
        return;
    }

    inorder(root->left,treeArray);
    treeArray.push_back(root->data);
    inorder(root->right, treeArray);


}
int kthSmallest(node* root, int k) {
    vector<int> treeArray;
    inorder(root,treeArray);
    // Write your code here.

    return treeArray[k];
}
void levelOrderTraversal(node *root)
{

    queue<node *> q;
    q.push(root);
    q.push(nullptr);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == nullptr)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(nullptr);
            }
        }
        else
        {
            cout << temp->data << " ";

            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

int main()
{
    node *root = nullptr;
    takeinput(root);
    cout << "printing the bst" << endl;
    levelOrderTraversal(root);

    vector<int> treeArray;
    inorder(root,treeArray);

    for(auto i:treeArray){
        cout<<i<<" ";
    }


}

//6521171 5650934 9278816 899375 -1 8989449 -1 -1 -1 -1 -1 
9615950
6521171 5650934 9278816 899375 -1 8989449 -1 -1 -1 -1 -1 
9615950

