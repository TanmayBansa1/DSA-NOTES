#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d){
        this->data = d;
        this->next = NULL;

    }
    ~Node(){}
};

void insertNode(Node* &tail, int element, int d){

    if(tail == NULL){
        Node* temp = new Node(d);
        tail = temp;
        temp->next = temp;
        
    }
    else{
        Node* curr= tail;
        while(curr->data != element){
            curr = curr->next;
        }
        Node* temp = new Node(d);

        temp-> next = curr-> next;
        curr-> next = temp;
    }
}
void print(Node* tail){

    Node* temp = tail;
    do{
        cout<<tail->data<<" ";
        tail = tail->next;
    } while(tail!=temp);

    
}
void deleteNode(Node* &tail, int value){
    if(tail == NULL){
        cout<<"empty list"<<endl;
        return;
    }
    else{
        Node* prev = tail;
        Node* curr = prev-> next;

        while(curr->data != value){
            prev = curr;
            curr = curr-> next;

        }

        prev->next = curr->next;
        if(tail == curr){
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}

int main(){

    Node* tail = new Node(5);
    
    insertNode(tail,5,3);
    
    insertNode(tail,3,8);
    
    insertNode(tail,3,6);
    insertNode(tail,3,5);
    insertNode(tail,3,4);
    insertNode(tail,3,2);

    
    cout<<"t";
    deleteNode(tail,6);
    print(tail);
    
}