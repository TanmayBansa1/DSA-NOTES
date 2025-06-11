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

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    bool IsEmpty() {
        return front == nullptr;
    }

    void Insert(int value) {
        Node* newNode = new Node(value);
        if (IsEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void Delete() {
        if (IsEmpty()) {
            cout << "Queue is empty. Cannot delete." << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        delete temp;
    }

    int Front() {
        if (IsEmpty()) {
            cout << "Queue is empty." << endl;
            return -1; 
        }
        return front->data;
    }
};

int main() {
    Queue q;

    q.Insert(1);
    q.Insert(2);
    q.Insert(3);
    cout << "Front element: " << q.Front() << endl;
    q.Delete();

    if (!q.IsEmpty()) {
        cout << "Front element: " << q.Front() << endl;
    } else {
        cout << "Queue is empty." << endl;
    }

    q.Delete();
    

    if (!q.IsEmpty()) {
        cout << "Front element: " << q.Front() << endl;
    } else {
        cout << "Queue is empty." << endl;
    }
    q.Delete();

    if (!q.IsEmpty()) {
        cout << "Front element: " << q.Front() << endl;
    } else {
        cout << "Queue is empty." << endl;
    }

    return 0;
}
