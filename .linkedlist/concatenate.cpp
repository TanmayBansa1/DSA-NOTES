#include <iostream>
using namespace std;
class Node {
    public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

Node* concatenateSortedAscending(Node* list1, Node* list2) {
    Node* result = nullptr;
    Node* tail = nullptr;

    while (list1 && list2) {
        if (list1->data < list2->data) {
            if (!result) {
                result = list1;
                tail = list1;
            } else {
                tail->next = list1;
                tail = list1;
            }
            list1 = list1->next;
        } else {
            if (!result) {
                result = list2;
                tail = list2;
            } else {
                tail->next = list2;
                tail = list2;
            }
            list2 = list2->next;
        }
    }

    if (list1) {
        tail->next = list1;
    }

    if (list2) {
        tail->next = list2;
    }

    return result;
}

void print(Node* head){
    if(head == NULL){
        cout<<"Empty list"<<endl;
        return;
    }
    Node* temp = head;
    while(temp != NULL){
        cout<< temp ->data<<" ";
        temp = temp ->next;
    }
    cout<<endl;
}   


int main() {
    Node* list1 = nullptr;
    Node* list2 = nullptr;

    insertAtEnd(list1, 1);
    insertAtEnd(list1, 3);
    insertAtEnd(list1, 5);

    insertAtEnd(list2, 2);
    insertAtEnd(list2, 4);

    cout << "List 1: ";
    print(list1);

    cout << "List 2: ";
    print(list2);

    Node* concatenatedList = concatenateSortedAscending(list1, list2);

    cout << "Concatenated List (Ascending Order): ";
    print(concatenatedList);

    return 0;
}
