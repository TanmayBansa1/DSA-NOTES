#include <iostream>
#include <string>
using namespace std;

// Structure to represent a faculty
struct faculty {
    string faculty_name;
    int faculty_ID;
    string subject_codes;
    string class_names;
};

class Node {
public:
    faculty data;
    Node* next;
    Node* prev;

    Node(const faculty& faculty) : data(faculty), next(NULL), prev(NULL) {}
};

class doublelist {
private:
    Node* header;

public:
    doublelist() : header(NULL) {}

    // Function to insert a node before the node with the given key
    void insert1(const faculty& value, int key) {
        Node* newNode = new Node(value);

        if (!header) {
            header = newNode;
        } else {
            Node* current = header;
            while (current->next && current->data.faculty_ID != key) {
                current = current->next;
            }
            newNode->next = current;
            newNode->prev = current->prev;
            if (current->prev) {
                current->prev->next = newNode;
            } else {
                header = newNode;
            }
            current->prev = newNode;
        }
    }

    // Function to insert a node after the node with the given key
    void insert2(const faculty& value, int key) {
        Node* newNode = new Node(value);

        if (!header) {
            header = newNode;
        } else {
            Node* current = header;
            while (current && current->data.faculty_ID != key) {
                current = current->next;
            }
            if (!current) {
                cout << "faculty with faculty_ID " << key << " not found in the list." << endl;
                return;
            }
            newNode->next = current->next;
            newNode->prev = current;
            if (current->next) {
                current->next->prev = newNode;
            }
            current->next = newNode;
        }
    }

    // Function to insert a node at the i-th location w.r.t. header (assuming header is at the 1st location)
    void insertAtLocation(const faculty& value, int location) {
        if (location < 1) {
            cout << "Invalid location. Location should be greater than or equal to 1." << endl;
            return;
        }

        Node* newNode = new Node(value);

        if (location == 1) {
            newNode->next = header;
            if (header) {
                header->prev = newNode;
            }
            header = newNode;
        } else {
            Node* current = header;
            int currentPosition = 1;
            while (current && currentPosition < location - 1) {
                current = current->next;
                currentPosition++;
            }
            if (!current) {
                cout << "Invalid location. Location exceeds the length of the list." << endl;
                return;
            }
            newNode->next = current->next;
            newNode->prev = current;
            if (current->next) {
                current->next->prev = newNode;
            }
            current->next = newNode;
        }
    }

    // Function to access a node (find the position w.r.t. header)
    int access(int key) {
        int position = 1;
        Node* current = header;
        while (current) {
            if (current->data.faculty_ID == key) {
                return position;
            }
            current = current->next;
            position++;
        }
        cout << "faculty with faculty_ID " << key << " not found in the list." << endl;
        return -1;
    }

    // Function to remove a node with a particular key value
    void Delete(int key) {
        Node* current = header;
        while (current && current->data.faculty_ID != key) {
            current = current->next;
        }
        if (!current) {
            cout << "faculty with faculty_ID " << key << " not found in the list." << endl;
            return;
        }

        if (current->prev) {
            current->prev->next = current->next;
        } else {
            header = current->next;
        }

        if (current->next) {
            current->next->prev = current->prev;
        }

        delete current;
    }

    // Function to complete deletion of the list
    void clear() {
        while (header) {
            Node* temp = header;
            header = header->next;
            delete temp;
        }
    }

    // Function to display the current list in clockwise fashion
    void displayClockwise() {
        if(header == NULL){
            cout<<"empty list"<<endl;
            return;
        }
        Node* current = header;
        while (current) {
            cout << "Faculty_ID: " << current->data.faculty_ID << ", Name: " << current->data.faculty_name << ", Subject Codes: " << current->data.subject_codes << ", Class Names: " << current->data.class_names << endl;
            current = current->next;
        }
    }

    // Function to display the current list in anti-clockwise fashion
    void displayAntiClockwise() {
        if(header == NULL){
            cout<<"empty list"<<endl;
            return;
        }
        Node* current = header;
        while (current && current->next) {
            current = current->next;
        }

        while (current) {
            cout << "Faculty_ID: " << current->data.faculty_ID << ", Name: " << current->data.faculty_name << ", Subject Codes: " << current->data.subject_codes << ", Class Names: " << current->data.class_names << endl;
            current = current->prev;
        }
    }

    // Function to sort the list
    void sort() {
        Node* current = header;
        while (current) {
            Node* nextNode = current->next;
            while (nextNode) {
                if (current->data.faculty_ID > nextNode->data.faculty_ID) {
                    faculty temp = current->data;
                    current->data = nextNode->data;
                    nextNode->data = temp;
                }
                nextNode = nextNode->next;
            }
            current = current->next;
        }
    }
};

int main() {
    doublelist facultyList;

    faculty faculty1 = { "Tanmay", 101, "SC101, MA201", "Physics, Mathematics" };
    faculty faculty2 = { "Shivansh", 102, "CS301, CS401", "Computer Science" };
    faculty faculty3 = { "Viplove", 103, "CH101, CH201", "Chemistry" };
    faculty faculty4 = { "raunal", 104, "ME101, ME201", "Mechanical Engineering" };

    facultyList.insert1(faculty1, 102);
    facultyList.insert2(faculty2, 101);
    facultyList.insert1(faculty3, 101);
    facultyList.insert2(faculty4, 101);

    cout << "Current List in Clockwise Fashion:" << endl;
    facultyList.displayClockwise();

    int position = facultyList.access(103);
    if (position != -1) {
        cout << "faculty with faculty_ID 103 is at position " << position << " w.r.t. the header." << endl;
    }

    facultyList.Delete(102);
    cout << "List after removing faculty with faculty_ID 102:" << endl;
    facultyList.displayClockwise();

    facultyList.sort();
    cout << "Sorted List in Clockwise Fashion:" << endl;
    facultyList.displayClockwise();

    cout << "Sorted List in Anti-Clockwise Fashion:" << endl;
    facultyList.displayAntiClockwise();

    facultyList.clear();
    cout << "List after complete deletion:" << endl;
    facultyList.displayClockwise();

    return 0;
}
