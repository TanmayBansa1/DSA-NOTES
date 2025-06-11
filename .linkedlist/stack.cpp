#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
    
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    bool IsEmpty() {
        return top == nullptr;
    }

    void Push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    void Pop() {
        if (IsEmpty()) {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    void Peek() {
        if (IsEmpty()) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Top element: " << top->data << endl;
        }
    }
};

int main() {
    Stack stack;

    stack.Push(1);
    stack.Push(2);
    stack.Push(3);

    stack.Peek(); 

    stack.Pop();
    stack.Peek(); 

    stack.Pop();
    stack.Peek(); 
    stack.Pop();
    stack.Peek(); 
    stack.Pop(); 

    return 0;
}
