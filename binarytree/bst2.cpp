#include <iostream>
#include <queue>

using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};
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

bool search(node *root, int x)
{

    if (root == nullptr)
    {
        return false;
    }
    if (root->data == x)
    {
        return true;
    }

    if (root->data < x)
    {
        return search(root->right, x);
    }
    else
    {
        return search(root->left, x);
    }

    /*
    node* temp = root;
    while(temp!=nullptr){

        if(temp->data == x){
            return true;

        }
        if(temp->data<x){
            temp = temp->right;
        }
        else{
            temp = temp->left;
        }

    }
    return false;
    */
}
node *minval(node *root)
{
    node *temp = root;
    while (temp->left != nullptr)
    {
        temp = temp->left;
    }
    return temp;
}
node *minmax(node *root)
{
    cout << "enter your choice" << endl;
    cout << "1. for min and 2. for max" << endl;
    int choice;
    cin >> choice;
    node *temp = root;
    switch (choice)
    {
    case 1:
    {

        while (temp->left != nullptr)
        {
            temp = temp->left;
        }

        break;
    }
    case 2:
    {

        while (temp->right != nullptr)
        {
            temp = temp->right;
        }

        break;
    }
    }
    return temp;
}
node *deletenode(node *root, int value)
{

    if (root == nullptr)
    {
        return root;
    }

    if (root->data == value)
    {

        // 0 child
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            return nullptr;
        }

        // 1 child
        if (root->left != nullptr && root->right == nullptr)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }
        if (root->left == nullptr && root->right != nullptr)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }

        // 2 child
        if(root->left != nullptr && root->right != nullptr)
        {
            int mini = minval(root->right)->data;
            root->data = mini;
            root->right = deletenode(root->right,mini);
            return root;
        }
    }
    else if(root->data < value){
        root->right = deletenode(root->right, value);
        return root;
    }
    else{
        root->left = deletenode(root->left, value);
        return root;
    }
}
void postorder(node *&root)
{
    if (root == nullptr)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{
    node *root = nullptr;
    takeinput(root);
    cout << "printing the bst" << endl;
    levelOrderTraversal(root);
    // cout << endl;
    // postorder(root);
    // cout << endl;
    // cout << search(root, 21);
    // cout << minmax(root)->data;

    
    // root = deletenode(root, 70);

    // cout << "printing the bst" << endl;
    // levelOrderTraversal(root);
    // cout << endl;
    // postorder(root);
    // cout << endl;
    // cout << search(root, 21);
    // cout << minmax(root)->data;
    // return 0;
    
}