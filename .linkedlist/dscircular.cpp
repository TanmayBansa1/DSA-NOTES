#include <iostream>
#include <string>
using namespace std;

// Structure to represent an emp
struct emp {
    string emp_name;
    int emp_no;
    double emp_salary;
};

class Node {
public:
    emp data;
    Node* next;

    Node(const emp& employee) : data(employee), next(NULL) {}
};

class circularlist {
private:
    Node* header;

public:
    circularlist() : header(NULL) {}

    // Function to insert a node before the node with the given key
    void insert1(const emp& value, int key) {
        Node* newNode = new Node(value);

        if (!header) {
            header = newNode;
            header->next = header;
        } else {
            Node* current = header;
            while (current->next != header && current->next->data.emp_no != key) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    // Function to insert a node after the node with the given key
    void insert2(const emp& value, int key) {
        Node* newNode = new Node(value);

        if (!header) {
            header = newNode;
            header->next = header;
        } else {
            Node* current = header;
            while (current->data.emp_no != key) {
                current = current->next;
                if (current == header) {
                    cout << "employee with emp_no " << key << " not found in the list." << endl;
                    return;
                }
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    // Function to access a node (find the position w.r.t. the header)
    int access(int key) {
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

        cout << "employee with emp_no " << key << " not found in the list." << endl;
        return -1;
    }

    // Function to remove a node with a particular key value
    void Delete(int key) {
        if (!header) {
            cout << "List is empty." << endl;
            return;
        }

        if (header->data.emp_no == key) {
            if (header->next == header) {
                delete header;
                header = NULL;
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
            cout << "employee with emp_no " << key << " not found in the list." << endl;
            return;
        }

        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }

    // Function to complete deletion of the list
    void clear() {
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
        header = NULL;
    }

    // Function to display the current list
    void print() {
        if (!header) {
            cout << "List is empty." << endl;
            return;
        }

        Node* current = header;
        do {
            cout << "Emp No: " << current->data.emp_no << ", Name: " << current->data.emp_name << ", Salary: " << current->data.emp_salary << endl;
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
                    emp temp = current->data;
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
    circularlist employeeList;

    emp employee1 = { "Tanmay", 101, 50000.0 };
    emp employee2 = { "Shivansh", 102, 60000.0 };
    emp employee3 = { "Viplove", 103, 55000.0 };
    emp employee4 = { "Stuti", 104, 65000.0 };

    employeeList.insert1(employee1, 102);
    employeeList.insert2(employee2, 101);
    employeeList.insert1(employee3, 101);
    employeeList.insert2(employee4, 101);

    cout << "Current List:" << endl;
    employeeList.print();

    int position = employeeList.access(103);
    if (position != -1) {
        cout << "emp with emp_no 103 is at position " << position << " w.r.t. the header." << endl;
    }

    employeeList.Delete(102);
    cout << "List after removing emp with emp_no 102:" << endl;
    employeeList.print();

    employeeList.sort();
    cout << "Sorted List:" << endl;
    employeeList.print();

    employeeList.clear();
    cout << "List after complete deletion:" << endl;
    employeeList.print();

    return 0;
}
