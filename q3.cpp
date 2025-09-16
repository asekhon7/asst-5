//1024030287
// q3
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

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

void display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL) cout << "->";
        temp = temp->next;
    }
    cout << "\n";
}

void findMiddle() {
    if (head == NULL) {
        cout << "List empty\n";
        return;
    }
    Node* slow = head;
    Node* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << "Middle Element: " << slow->data << "\n";
}

int main() {
    int n, val;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        insertAtEnd(val);
    }

    cout << "Linked List: ";
    display();

    findMiddle();

    return 0;
}
