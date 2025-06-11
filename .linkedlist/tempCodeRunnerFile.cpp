#include <iostream>
#include <string>
using namespace std;

// Structure to represent an Employee
struct Employee {
    string employee_name;
    int emp_no;
    double emp_salary;
};

class Node {
public:
    Employee data;
    Node* next;

    Node(const Employee& employee) : data(employee), next(nullptr) {}
};

class CircularSinglyLinkedList {
private:
    Node* header;

public:
    CircularSinglyLinkedList() : header(nullptr) {}

    // Function to insert a node before the node with the given key
    void insertBefore(const Employee& newValue, int givenKey) {
        Node* newNode = new Node(newValue);

        if (!header) {
            header = newNode;
            header->next = header;
        } else {
            Node* current = header;
            while (current->next != header && current->next->data.emp_no != givenKey) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    // Function to insert a node after the node with the given key
    void insertAfter(const Employee& newValue, int givenKey) {
        Node* newNode = new Node(newValue);

        if (!header) {
            header = newNode;
            header->next = header;
        } else {
            Node* current = header;
            while (current->data.emp_no != givenKey) {
                current = current->next;
                if (current == header) {
                    cout << "Employee with emp_no " << givenKey << " not found in the list." << endl;
                    return;
                }
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    // Function to access a node (find the position w.r.t. the header)
    int findPosition(int key) {
        if (!header) {
            cout << "List is empty." << endl;
            return -1;
        }

        int position = 1;
        Node* current = header;
        do {
            if (current->data.emp_no == key) {
                return position;
            }
            current = current->next;
            position++;
        } while (current != header);

        cout << "Employee with emp_no " << key << " not found in the list." << endl;
        return -1;
    }

    // Function to remove a node with a particular key value
    void removeNode(int key) {
        if (!header) {
            cout << "List is empty." << endl;
            return;
        }

        if (header->data.emp_no == key) {
            if (header->next == header) {
                delete header;
                header = nullptr;
            } else {
                Node* current = header;
                while (current->next != header) {
                    current = current->next;
                }
                Node* temp = header;
                header = header->next;
                current->next = header;
                delete temp;
            }
            return;
        }

        Node* current = header;
        while (current->next != header && current->next->data.emp_no != key) {
            current = current->next;
        }

        if (current->next == header) {
            cout << "Employee with emp_no " << key << " not found in the list." << endl;
            return;
        }

        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }

    // Function to complete deletion of the list
    void deleteList() {
        if (!header) {
            cout << "List is already empty." << endl;
            return;
        }

        Node* current = header;
        while (current->next != header) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        delete current;
        header = nullptr;
    }

    // Function to display the current list
    void displayList() {
        if (!header) {
            cout << "List is empty." << endl;
            return;
        }

        Node* current = header;
        do {
            cout << "Emp No: " << current->data.emp_no << ", Name: " << current->data.employee_name << ", Salary: " << current->data.emp_salary << endl;
            current = current->next;
        } while (current != header);
    }

    // Function to sort the list
    void sort() {
        if (!header) {
            cout << "List is empty." << endl;
            return;
        }

        Node* current = header;
        do {
            Node* nextNode = current->next;
            do {
                if (current->data.emp_no > nextNode->data.emp_no) {
                    Employee temp = current->data;
                    current->data = nextNode->data;
                    nextNode->data = temp;
                }
                nextNode = nextNode->next;
            } while (nextNode != header);
            current = current->next;
        } while (current->next != header);
    }
};

int main() {
    CircularSinglyLinkedList employeeList;

    Employee employee1 = { "Alice", 101, 50000.0 };
    Employee employee2 = { "Bob", 102, 60000.0 };
    Employee employee3 = { "Charlie", 103, 55000.0 };
    Employee employee4 = { "David", 104, 65000.0 };

    employeeList.insertBefore(employee1, 102);
    employeeList.insertAfter(employee2, 101);
    employeeList.insertBefore(employee3, 101);
    employeeList.insertAfter(employee4, 101);

    cout << "Current List:" << endl;
    employeeList.displayList();

    int position = employeeList.findPosition(103);
    if (position != -1) {
        cout << "Employee with emp_no 103 is at position " << position << " w.r.t. the header." << endl;
    }

    employeeList.removeNode(102);
    cout << "List after removing Employee with emp_no 102:" << endl;
    employeeList.displayList();

    employeeList.sort();
    cout << "Sorted List:" << endl;
    employeeList.displayList();

    employeeList.deleteList();
    cout << "List after complete deletion:" << endl;
    employeeList.displayList();

    return 0;
}
