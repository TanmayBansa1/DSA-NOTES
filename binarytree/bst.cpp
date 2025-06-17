#include <iostream>
#include <string>
using namespace std;

// Structure for a BST node
struct TreeNode {
    string data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(const string& value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    TreeNode* root;

public:
    BinarySearchTree() : root(nullptr) {}

    // Function to insert a string into the BST
    void insert(const string& value) {
        root = insertRec(root, value);
    }

    TreeNode* insertRec(TreeNode* node, const string& value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }

        if (value < node->data) {
            node->left = insertRec(node->left, value);
        } else if (value > node->data) {
            node->right = insertRec(node->right, value);
        }

        return node;
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

    // Function to search for a string in the BST
    bool search(const string& value) {
        return searchRec(root, value);
    }

    bool searchRec(TreeNode* node, const string& value) {
        if (node == nullptr) {
            return false;
        }

        if (value == node->data) {
            return true;
        }

        if (value < node->data) {
            return searchRec(node->left, value);
        } else {
            return searchRec(node->right, value);
        }
    }

    // Function to delete a string from the BST
    void remove(const string& value) {
        root = removeRec(root, value);
    }

    TreeNode* removeRec(TreeNode* node, const string& value) {
        if (node == nullptr) {
            return node;
        }

        if (value < node->data) {
            node->left = removeRec(node->left, value);
        } else if (value > node->data) {
            node->right = removeRec(node->right, value);
        } else {
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }

            TreeNode* temp = minValueNode(node->right);
            node->data = temp->data;
            node->right = removeRec(node->right, temp->data);
        }
        return node;
    }

    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    // Function to find the inorder-predecessor of a node
    TreeNode* findPredecessor(TreeNode* node) {
        return findPredecessorRec(root, node);
    }

    TreeNode* findPredecessorRec(TreeNode* current, TreeNode* target) {
        if (current == nullptr) {
            return nullptr;
        }

        if (target->data == current->data) {
            if (current->left != nullptr) {
                TreeNode* maxNode = findMax(current->left);
                return maxNode;
            }
        } else if (target->data < current->data) {
            return findPredecessorRec(current->left, target);
        } else {
            TreeNode* pred = findPredecessorRec(current->right, target);
            if (pred == nullptr) {
                return current;
            } else {
                return pred;
            }
        }

        return nullptr;
    }

    TreeNode* findMax(TreeNode* node) {
        while (node->right != nullptr) {
            node = node->right;
        }
        return node;
    }

    // Function to find the inorder-successor of a node
    TreeNode* findSuccessor(TreeNode* node) {
        return findSuccessorRec(root, node);
    }

    TreeNode* findSuccessorRec(TreeNode* current, TreeNode* target) {
        if (current == nullptr) {
            return nullptr;
        }

        if (target->data == current->data) {
            if (current->right != nullptr) {
                TreeNode* minNode = findMin(current->right);
                return minNode;
            }
        } else if (target->data > current->data) {
            return findSuccessorRec(current->right, target);
        } else {
            TreeNode* succ = findSuccessorRec(current->left, target);
            if (succ == nullptr) {
                return current;
            } else {
                return succ;
            }
        }

        return nullptr;
    }

    TreeNode* findMin(TreeNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    // Function to find the height of the BST
    int findHeight() {
        return findHeightRec(root);
    }

    int findHeightRec(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }

        int leftHeight = findHeightRec(node->left);
        int rightHeight = findHeightRec(node->right);

        return max(leftHeight, rightHeight) + 1;
    }

    // Function to find the number of levels in the BST
    int findLevels() {
        return findHeight() + 1;
    }

    // Function to find the number of leaf nodes in the BST
    int findLeafNodes() {
        return findLeafNodesRec(root);
    }

    int findLeafNodesRec(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }

        if (node->left == nullptr && node->right == nullptr) {
            return 1;
        }

        return findLeafNodesRec(node->left) + findLeafNodesRec(node->right);
    }

    // Function to find the number of internal nodes in the BST
    int findInternalNodes() {
        return findInternalNodesRec(root);
    }

    int findInternalNodesRec(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }

        if (node->left == nullptr && node->right == nullptr) {
            return 0;
        }

        return findInternalNodesRec(node->left) + findInternalNodesRec(node->right) + 1;
    }

    // Function to find the total number of nodes in the BST
    int findTotalNodes() {
        return findTotalNodesRec(root);
    }

    int findTotalNodesRec(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }

        return findTotalNodesRec(node->left) + findTotalNodesRec(node->right) + 1;
    }
    TreeNode* getRoot() {
    return root;
} 
};

int main() {
    BinarySearchTree bst;

    bst.insert("Alice");
    bst.insert("Bob");
    bst.insert("Charlie");
    bst.insert("David");
    bst.insert("Eve");
    bst.insert("Frank");
    TreeNode* root1 = bst.getRoot();
    cout << "Inorder traversal of the BST: ";
    bst.inorderTraversal(root1);
    cout<<endl;
    // Implement an inorder traversal function or use an existing one to print the BST.

    string searchString = "Charlie";
    bool isFound = bst.search(searchString);
    if (isFound) {
        cout << searchString << " is in the BST." << endl;
    } else {
        cout << searchString << " is not in the BST." << endl;
    }

    bst.remove("Charlie");
    cout << "Inorder traversal of the BST after removing Charlie: ";
    bst.inorderTraversal(root1);
    cout<<endl;

    TreeNode* root = bst.getRoot();
    TreeNode* predecessor = bst.findPredecessor(root);
    cout << "Inorder-predecessor of " << root->data << " is " << (predecessor ? predecessor->data : "N/A") << endl;

    TreeNode* successor = bst.findSuccessor(root);
    cout << "Inorder-successor of " << root->data << " is " << (successor ? successor->data : "N/A") << endl;

    int height = bst.findHeight();
    cout << "Height of the BST: " << height << endl;

    int levels = bst.findLevels();
    cout << "Number of levels in the BST: " << levels << endl;

    int leafNodes = bst.findLeafNodes();
    cout << "Number of leaf nodes in the BST: " << leafNodes << endl;

    int internalNodes = bst.findInternalNodes();
    cout << "Number of internal nodes in the BST: " << internalNodes << endl;

    int totalNodes = bst.findTotalNodes();
    cout << "Total number of nodes in the BST: " << totalNodes << endl;

    return 0;
}
