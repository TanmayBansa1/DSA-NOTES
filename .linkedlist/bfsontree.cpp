#include <iostream>
#include <queue>

using namespace std;

class Tnode {
public:
    int data;
    Tnode* left;
    Tnode* right;

    Tnode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class Btree {
public:
    Tnode* root;

    Btree() : root(nullptr) {}

    void bfs() {
        if (root == nullptr) {
            return;
        }

        queue<Tnode*> q;
        q.push(root);

        while (!q.empty()) {
            Tnode* current = q.front();
            q.pop();

            cout << current->data << " ";

            if (current->left) {
                q.push(current->left);
            }

            if (current->right) {
                q.push(current->right);
            }
        }
    }
};

int main() {
    Btree tree;

    
    tree.root = new Tnode(1);
    tree.root->left = new Tnode(2);
    tree.root->right = new Tnode(3);
    tree.root->left->left = new Tnode(4);
    tree.root->left->right = new Tnode(5);
    tree.root->right->left = new Tnode(6);
    tree.root->right->right = new Tnode(7);

    cout << "Breadth-First Search: ";
    tree.bfs();
    cout << endl;

    return 0;
}
