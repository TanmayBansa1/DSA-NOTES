#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int x){
        this -> data = x;   
        this -> next = NULL; 
    }
    ~Node(){}
};


void deleteNode(int position, Node* &head){

    if(position == 1){
        Node* temp = head;
        head = head->next;
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

        prev->next = curr->next;
        curr->next =NULL;
        delete curr;

    }
}

void insertatHead(Node* &head, int d){
    Node * temp = new Node(d);
    temp ->next = head;
    head = temp;

}
void insertatTail(Node* &tail, int d){
    Node * temp = new Node(d);
    tail -> next = temp;
    tail = temp;

}
void insertatMiddle(Node* &tail, Node* &head, int position, int d){

    if(position == 1){
        insertatHead(head,d);
        return;
    }

    Node* temp = head;
    int cnt =1;
    while(cnt<position-1){

        temp = temp ->next;
        cnt++;
    }
    if(temp ->next == NULL){
        insertatTail(tail,d);
        return;
    }
    
    Node* nodetobeinserted = new Node(d);
    nodetobeinserted ->next = temp->next;
    temp ->next = nodetobeinserted;
    
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
bool search(Node* &head, int d){

    Node* temp = head;

    while(temp != NULL){

        if(temp->data == d){
            
            return 1;
            cout<<endl;
        }
        temp = temp ->next;
        
    }
    cout<<endl;
    return 0;
}
void access(Node* &head, int position){
    if(position == 1){
        cout<<"The value of the head is ->"<<head->data<<endl;
    }
    else if(head == NULL){
        cout<<"Empty list"<<endl;

    }
    else if(position != 0){
        Node* temp = head;
        int cnt = 1;
        while(cnt<position && temp!= NULL){
            temp = temp->next;
            if(temp == NULL){
                cout<<"Not found"<<endl;
                break;
            }
            cnt++;
        }
        cout<<"The value of the node "<<position<<"is ->"<<temp->data<<endl;
    }
}
void clear(Node* &head){
    
    while(head!=NULL){
        Node* temp = head;
        head = head->next;
        temp =NULL;
    }
    cout<<"List cleared"<<endl;
}
Node* copyLinkedList(Node* head) {
    if (head == NULL) {
        return NULL; 
    }

    Node* newHead = new Node(head->data); 
    Node* current = head; 
    Node* newCurrent = newHead; 

    while (current->next!=NULL) {
        current = current->next;
        newCurrent->next = new Node(current->data); 
        newCurrent = newCurrent->next; 
    }

    return newHead;
}
void reverse(Node* &head){
    Node* curr = head;
    Node* prev = NULL;
    Node* next1 = NULL;

    while(curr!= NULL){
        next1 = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next1;
    }
    head = prev;
}
void reverseWithAuxiliary(Node* &head) {
        if (!head) {
            return;
        }

        Node* prev = nullptr;
        Node* current = head;
        while (current) {
            Node* nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        head = prev;
        cout<<"Reversed using auxilliary pointer "<<endl;
        cout<<"The reverse list is -> ";
        print(head);
}
void reverseWithoutAuxiliary(Node* &head) {
        if (!head || !head->next) {
            print(head);
            return;
        }

        Node* current = head;
        while (current->next) {
            Node* nextNode = current->next;
            current->next = nextNode->next;
            nextNode->next = head;
            head = nextNode;
        }
        cout<<"Reversed without using auxilliary pointer "<<endl;
        cout<<"The reverse list is -> ";
        print(head);
    }

    void swapPairs(Node* &head) {
        Node* current = head;
        while (current && current->next) {
           
            int temp = current->data;
            current->data = current->next->data;
            current->next->data = temp;

            
            current = current->next->next;
        }
        cout<<"The list after swapping pairs -> ";
        print(head);
    }
    void findSecondLastNode(Node* &head) {
        if (!head || !head->next) {
            return; 
        }

        Node* current = head;
        while (current->next->next) {
            current = current->next;
        }
        cout<<"The second last node is ->";
        cout<<current->data<<endl;
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
/*int main(){
    
    Node* node1 = new Node(50);

    Node* head = node1;
    Node* tail = node1;
    print(head);
    insertatHead(head,12);
    print(head);
    insertatTail(tail,15);
    print(head);
    insertatMiddle(tail,head ,3,13);
    print(head);
    deleteNode(4, head);
    print(head);
   // cout<<search(head,15)<<endl;
    access(head,3);
    Node* list = copyLinkedList(head);
    print(list);
    clear(head);
    print(head);

} */
void sort(Node* &head) {
        Node* current = head;
        Node* minNode;

        while (current) {
            minNode = current;
            Node* temp = current->next;

            while (temp) {
                if (temp->data < minNode->data) {
                    minNode = temp;
                }
                temp = temp->next;
            }

            
            int tempData = current->data;
            current->data = minNode->data;
            minNode->data = tempData;

            current = current->next;
        }
        cout<<"The sorted linked list is -> ";
        print(head);
    }

 int main(){
    Node* head = new Node(50);
    insertatHead(head, 12);
    insertatHead(head, 13);
    insertatHead(head, 14);
    insertatHead(head, 15);
    insertatHead(head, 16);
    print(head);
    sort(head);
  //  reverseWithAuxiliary(head);
   reverseWithoutAuxiliary(head);
   // print(head);
   // swapPairs(head);

  //  findSecondLastNode(head);
    

}