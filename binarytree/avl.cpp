#include<iostream>
#include<queue>

using namespace std;

int max(int a, int b){
    return a>b?a:b;
}
class node
{
public:
    int data;
    node *left;
    node *right;
    int height;

    node(int data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};
int getHeight(node* root){
    if(root == nullptr){
        return 0;

    }
    else{
        return root->height;
    }
}
int getBalanceFactor(node* root){
    if(root == nullptr){
        return 0;
    }
    return getHeight(root->left)-getHeight(root->right);
}

node* leftrotate(node* x){
    node* y = x->right;
    node* T2 = y->left;

    y->left = x;
    x->right = T2;

    y->height = 1+max(getHeight(y->left), getHeight(y->right));
    x->height = 1+max(getHeight(x->left), getHeight(x->right));

    return y;

}
node* rightrotate(node* y){
    node* x = y->left;
    node* T2 = x->right;

    y->left = T2;
    x->right = y;

    y->height = 1+max(getHeight(y->left), getHeight(y->right));
    x->height = 1+max(getHeight(x->left), getHeight(x->right));


    return x;
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
/*node *insertintoAVL(node *root, int d)
{

    if (root == nullptr)
    {
        root = new node(d);
        return root;
    }

    if (d < root->data)
    {
        root->left = insertintoAVL(root->left, d);
    }
    else
    {
        root->right = insertintoAVL(root->right, d);
    }
    root->height = 1+max(getHeight(root->left), getHeight(root->right));
    int bf = getBalanceFactor(root);

    if(bf>1 && d < root->left->data){
        return leftrotate(root);
    }
    if(bf < -1 && d > root->right->data){
        return rightrotate(root);
    }
    if(bf > 1 && d > root->left->data){
        root->left = leftrotate(root->left);
        return rightrotate(root);
    }
    if(bf < -1 && d < root->right->data){
        root->right = rightrotate(root->right);
        return leftrotate(root);
    }
    return root;
}*/

node *insertintoAVL(node *root, int d)
{
    if (root == nullptr)
    {
        root = new node(d);
        return root;
    }

    if (d < root->data)
    {
        root->left = insertintoAVL(root->left, d);
    }
    else
    {
        root->right = insertintoAVL(root->right, d);
    }

    // Update height of the current node
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // Check balance factor and perform rotations if necessary
    int bf = getBalanceFactor(root);

    // Left Heavy
    if (bf > 1)
    {
        // Left-Left case
        if (d < root->left->data)
        {
            return rightrotate(root);
        }
        // Left-Right case
        else
        {
            root->left = leftrotate(root->left);
            return rightrotate(root);
        }
    }
    // Right Heavy
    else if (bf < -1)
    {
        // Right-Right case
        if (d > root->right->data)
        {
            return leftrotate(root);
        }
        // Right-Left case
        else
        {
            root->right = rightrotate(root->right);
            return leftrotate(root);
        }
    }

    return root;
}

void takeinput(node *&root)
{
    cout << "enter data for the AVL" << endl;
    int data;
    cin >> data;

    while (data != -1)
    {

        root = insertintoAVL(root, data);
        cin >> data;
    }
}
int main()
{
    node* root = nullptr;
    takeinput(root);
    
    
    levelOrderTraversal(root);
    return 0;
}