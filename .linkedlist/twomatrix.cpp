#include <iostream>
using namespace std;

class Node {
public:
    int row, col, value;
    Node* next;

    Node(int r, int c, int v) : row(r), col(c), value(v), next(nullptr) {}
};

// Function to add a node to a linked list
Node* insertNode(Node* head, int row, int col, int value) {
    Node* newNode = new Node(row, col, value);

    if (!head) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
    return head;
}

// Function to display a linked list representing a sparse matrix
void displayMatrix(Node* head) {
    if (!head) {
        cout << "Matrix is empty" << endl;
        return;
    }

    Node* current = head;
    while (current) {
        cout << "(" << current->row << ", " << current->col << ") = " << current->value << "\t";
        current = current->next;
    }
    cout << endl;
}

// Function to add two sparse matrices
Node* addMatrices(Node* matrix1, Node* matrix2, int numRows, int numCols) {
    Node* result = nullptr;

    while (matrix1 && matrix2) {
        if (matrix1->row == matrix2->row && matrix1->col == matrix2->col) {
            int sum = matrix1->value + matrix2->value;
            if (sum != 0) {
                result = insertNode(result, matrix1->row, matrix1->col, sum);
            }
            matrix1 = matrix1->next;
            matrix2 = matrix2->next;
        } else if (matrix1->row < matrix2->row || (matrix1->row == matrix2->row && matrix1->col < matrix2->col)) {
            result = insertNode(result, matrix1->row, matrix1->col, matrix1->value);
            matrix1 = matrix1->next;
        } else {
            result = insertNode(result, matrix2->row, matrix2->col, matrix2->value);
            matrix2 = matrix2->next;
        }
    }

    while (matrix1) {
        result = insertNode(result, matrix1->row, matrix1->col, matrix1->value);
        matrix1 = matrix1->next;
    }

    while (matrix2) {
        result = insertNode(result, matrix2->row, matrix2->col, matrix2->value);
        matrix2 = matrix2->next;
    }

    return result;
}

int main() {
    int numRows = 3, numCols = 4;

    // Create the first sparse matrix
    Node* matrix1 = nullptr;
    matrix1 = insertNode(matrix1, 0, 1, 3);
    matrix1 = insertNode(matrix1, 0, 3, 5);
    matrix1 = insertNode(matrix1, 1, 0, 7);
    matrix1 = insertNode(matrix1, 2, 2, 2);
    matrix1 = insertNode(matrix1, 2, 3, 8);

    cout << "Matrix 1:" << endl;
    displayMatrix(matrix1);

    // Create the second sparse matrix
    Node* matrix2 = nullptr;
    matrix2 = insertNode(matrix2, 0, 1, 2);
    matrix2 = insertNode(matrix2, 0, 3, 1);
    matrix2 = insertNode(matrix2, 1, 0, 4);
    matrix2 = insertNode(matrix2, 2, 2, 6);
    matrix2 = insertNode(matrix2, 2, 4, 9);

    cout << "Matrix 2:" << endl;
    displayMatrix(matrix2);

    // Add the matrices
    Node* result = addMatrices(matrix1, matrix2, numRows, numCols);

    cout << "Resultant Matrix:" << endl;
    displayMatrix(result);

    return 0;
}
