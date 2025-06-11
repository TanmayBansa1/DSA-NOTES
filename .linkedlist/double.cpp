#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }
    ~Node(){
        cout<<"deleted"<<endl;
    }
};

void print(Node *head)
{

    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int getLength(Node *head)
{
    Node *temp = head;
    int len = 0;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}
void deleteNode(Node* &head,Node* &tail, int position){
    
    if(position == 1){
        Node* temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    
    else{
        Node* prev = NULL;
        Node* curr = head;

        int cnt = 1;
        while(cnt<position){
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        if(curr->next == NULL){
            prev->next = NULL;
            curr->prev = NULL;
            tail = prev;
            delete curr;
            return;
        }
        curr->prev = NULL;
        prev->next = curr->next;
        curr->next->prev = prev;
        curr->next = NULL;
        delete curr;
    }
}
void insertatHead(Node *&head,Node* &tail, int d)
{
    if(head == NULL){
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else{
    Node *temp = new Node(d);

    temp->next = head;
    head->prev = temp;
    head = temp;
    }

}
void insertatTail(Node *&tail,Node* &head, int d)
{   
    if(tail == NULL){
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else{
    Node *temp = new Node(d);

    tail->next = temp;
    temp->prev = tail;
    tail = temp;
    }

}
void insertatMiddle(Node* &tail, Node* &head, int position, int d)
{

    if (position == 1)
    {
        insertatHead(head,tail, d);
    }
    else if (position == getLength(head)+1)
    {
        insertatTail(tail,head, d);
    }

    else
    {
        Node* temp = head;
        int cnt = 1;
        while (cnt < position - 1)
            {temp = temp->next;
                cnt++;
            }
        Node* newnode = new Node(d);
        newnode ->next = temp->next;
        temp->next->prev = newnode;
        temp->next = newnode;
        newnode->prev = temp;
         

    }
}
int main()
{
    
    Node *head = NULL;
    Node *tail = NULL;

    print(head);
    cout << getLength(head) << endl;
    insertatHead(head,tail, 15);
    print(head);
    insertatTail(tail,head, 20);
    print(head);
    insertatTail(tail,head, 30);
    print(head);
    insertatMiddle(tail,head,4,5);
    print(head);
    insertatTail(tail,head, 20);
    print(head);
    deleteNode(head,tail,5);
    print(head);
    cout<<tail -> data;
}
