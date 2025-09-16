// 1024030287
//asst5q1
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertAtBeginning(int x) {
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int x) {
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertBefore(int value, int x) {
    if (head == NULL) {
        cout << "List empty\n"; return;
    }
    if (head->data == value) {
        insertAtBeginning(x); return;
    }
    Node* temp = head;
    while (temp->next != NULL && temp->next->data != value) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        cout << "Value not found\n"; return;
    }
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = temp->next;
    temp->next = newNode;
}

void insertAfter(int value, int x) {
    Node* temp = head;
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Value not found\n"; return;
    }
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteFromBeginning() {
    if (head == NULL) {
        cout << "List empty\n"; return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteFromEnd() {
    if (head == NULL) {
        cout << "List empty\n"; return;
    }
    if (head->next == NULL) {
        delete head; head = NULL; return;
    }
    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
}

void deleteNode(int value) {
    if (head == NULL) {
        cout << "List empty\n"; return;
    }
    if (head->data == value) {
        deleteFromBeginning(); return;
    }
    Node* temp = head;
    while (temp->next != NULL && temp->next->data != value) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        cout << "Value not found\n"; return;
    }
    Node* del = temp->next;
    temp->next = temp->next->next;
    delete del;
}

void searchNode(int value) {
    Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == value) {
            cout << "Node " << value << " found at position " << pos << "\n";
            return;
        }
        temp = temp->next; pos++;
    }
    cout << "Value not found\n";
}

void display() {
    if (head == NULL) {
        cout << "List empty\n"; return;
    }
    Node* temp = head;
    cout << "Linked List: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

int main() {
    int choice, val, key;
    do {
        cout << "\n---- Singly Linked List Menu ----\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert before a value\n";
        cout << "4. Insert after a value\n";
        cout << "5. Delete from beginning\n";
        cout << "6. Delete from end\n";
        cout << "7. Delete specific node\n";
        cout << "8. Search for a node\n";
        cout << "9. Display\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value: "; cin >> val;
            insertAtBeginning(val);
        }
        else if (choice == 2) {
            cout << "Enter value: "; cin >> val;
            insertAtEnd(val);
        }
        else if (choice == 3) {
            cout << "Insert value: "; cin >> val;
            cout << "Before which value? "; cin >> key;
            insertBefore(key, val);
        }
        else if (choice == 4) {
            cout << "Insert value: "; cin >> val;
            cout << "After which value? "; cin >> key;
            insertAfter(key, val);
        }
        else if (choice == 5) {
            deleteFromBeginning();
        }
        else if (choice == 6) {
            deleteFromEnd();
        }
        else if (choice == 7) {
            cout << "Enter value to delete: "; cin >> val;
            deleteNode(val);
        }
        else if (choice == 8) {
            cout << "Enter value to search: "; cin >> val;
            searchNode(val);
        }
        else if (choice == 9) {
            display();
        }
        else if (choice == 0) {
            cout << "Exiting...\n";
        }
        else {
            cout << "Invalid choice\n";
        }
    } while (choice != 0);

    return 0;
}
