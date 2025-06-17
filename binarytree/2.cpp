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

node *buildtree(node *root)
{

    cout << "enter data " << endl;
    int data;
    cin >> data;

    root = new node(data);

    if (data == -1)
    {
        return nullptr;
    }

    cout << "enter the left root data of " << data << endl;
    root->left = buildtree(root->left);

    cout << "enter the right root data" << data << endl;
    root->right = buildtree(root->right);

    return root;
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
void inorder(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
void buildfromLevelorderTraversal(node *&root)
{
    cout << "Enter data for root" << endl;
    int data;
    cin >> data;

    root = new node(data);

    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {

        node *temp = q.front();
        q.pop();

        cout << "Enter the left node data for " << temp->data << endl;

        int leftdata;
        cin >> leftdata;

        if (leftdata != -1)
        {
            temp->left = new node(leftdata);
            q.push(temp->left);
        }

        cout << "Enter the right node data for " << temp->data << endl;

        int rightdata;
        cin >> rightdata;

        if (rightdata != -1)
        {
            temp->right = new node(rightdata);
            q.push(temp->right);
        }
    }
}

int main()
{
    node *root = nullptr;
    // buildfromLevelorderTraversal(root);
    root = buildtree(root);
    levelOrderTraversal(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
    postorder(root);
    cout << endl;

   // buildfromLevelorderTraversal(root);
    

    return 0;
}